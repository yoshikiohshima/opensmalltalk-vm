'From Squeak3.2gamma of 15 January 2002 [latest update: #4823] on 4 May 2002 at 10:46:06 am'!
"Change Set:		Gnuifier
Date:			1 January 2002
Author:			acg

Some code to automate building a VM under GCC.  To run, fileIn and execute:

	(Gnuifier on: aFileDirectory) gnuify

For example, try something like the following: 

	(Gnuifier on: 
		((FileDirectory default 
			directoryNamed: 'src') 
				directoryNamed: 'vm') pathName) gnuify

"!

Object subclass: #Gnuifier
	instanceVariableNames: 'directory '
	classVariableNames: ''
	poolDictionaries: ''
	category: 'VMConstruction-Building'!

!Gnuifier commentStamp: '<historical>' prior: 0!
My instances automate the translation of a Squeak interpreter for use with GCC.  In the specified FileDirectory, I copy 'interp.c' to 'interp.c.old'; translate a gnuified interpreter back into 'interp.c'; and save a working copy of sqGnu.h.

To gnuify an interpreter, try something like one of the following:

	(Gnuifier on: 
		((FileDirectory default 
			directoryNamed: 'src') 
				directoryNamed: 'vm') pathName) gnuify

	(Gnuifier on: 
		'powercow X:Users:werdna:Desktop:squeak:Squeak3.2a-4599 Folder:src:vm') gnuify


Structure:
 directory		FileDirectory -- specifying where I should do my gnuification

I can attempt to undo my damage with #deGnuify.!


!Gnuifier methodsFor: 'as yet unclassified' stamp: 'acg 12/30/2001 14:16'!
copyFrom: inFileStream to: outFileStream

"convert interp.c to use GNU features"

|  inData |

	Cursor read showWhile:
		[inData := inFileStream upToEnd withSqueakLineEndings].
	Cursor write showWhile:
		[outFileStream nextPutAll: inData].
	outFileStream close! !

!Gnuifier methodsFor: 'as yet unclassified' stamp: 'acg 1/1/2002 10:10'!
deGnuify

	(directory fileExists: 'interp.c.old')
		ifFalse: [^Error signal: 'Cannot deGnuify.  The old "interp.c" was not found.'].

	(directory fileExists: 'interp.c')
		ifTrue: [directory deleteFileNamed: 'interp.c'].

	self	
		copyFrom: 	(directory oldFileNamed: 'interp.c.old')
		to:			(directory newFileNamed: 'interp.c').

	(directory fileExists: 'sqGnu.h')
		ifTrue: [directory deleteFileNamed: 'sqGnu.h'].
	
	directory deleteFileNamed: 'interp.c.old'! !

!Gnuifier methodsFor: 'as yet unclassified' stamp: 'acg 1/1/2002 11:16'!
gnuify

	(directory fileExists: 'interp.c.old') ifTrue:
		[(PopUpMenu 
			confirm: 'Interpreter probably guified (interp.c.old exists).
Do you want to gnuify anyway?') ifFalse: [^nil].
		directory deleteFileNamed: 'interp.c.old'].
		
	self
		copyFrom: 	(directory oldFileNamed: 'interp.c')
		to: 			(directory newFileNamed: 'interp.c.old').

	directory deleteFileNamed: 'interp.c'.
	self
		gnuifyFrom:(directory oldFileNamed: 'interp.c.old')
		to: 			(directory newFileNamed: 'interp.c').
	
	directory fileExists: 'sqGnu.h'.
	self
		copyFrom: 	(ReadStream on: (self sqGnuFile))
		to: 			(directory newFileNamed: 'sqGnu.h')! !

!Gnuifier methodsFor: 'as yet unclassified' stamp: 'JMM 5/4/2002 10:46'!
gnuifyFrom: inFileStream to: outFileStream

"convert interp.c to use GNU features"

|  inData beforeInterpret inInterpret inInterpretVars beforePrimitiveResponse inPrimitiveResponse |

	Cursor read showWhile:
		[inData := inFileStream upToEnd withSqueakLineEndings.
		 inFileStream close].

	Cursor write showWhile:
		["print a header"
		outFileStream
			nextPutAll: '/* This file has been post-processed for GNU C */';
			cr; cr; cr.

		beforeInterpret := true.    "whether we are before the beginning of interpret()"
		inInterpret := false.     "whether we are in the middle of interpret"
		inInterpretVars := false.    "whether we are in the variables of interpret"
		beforePrimitiveResponse := true.  "whether we are before the beginning of primitiveResponse()"
		inPrimitiveResponse := false.   "whether we are inside of primitiveResponse"
		inData linesDo: [ :inLine |
			| outLine extraOutLine |
			outLine := inLine. 	"print out one line for each input line; by default, print out the line that was input, but some rules modify it"
			extraOutLine := nil.   "occasionally print a second output line..."
			beforeInterpret ifTrue: [
				(inLine findString: 'inline:') > 0 ifTrue: [
					"oops!!!!"
					outFileStream nextPutAll: '#error interp was not inlined, so cannot be gnuified'.
					Smalltalk snapshot: false andQuit: true. ].
				(inLine = '#include "sq.h"') ifTrue: [
					outLine := '#include "sqGnu.h"'. ].
				(inLine = 'int interpret(void) {') ifTrue: [
					"reached the beginning of interpret"
					beforeInterpret := false.
					inInterpret := true.
					inInterpretVars := true. ] ]
			ifFalse: [
			inInterpretVars ifTrue: [
				(inLine findString: ' localIP;') > 0 ifTrue: [
					outLine := '#ifdef FOO_REG
    struct foo * foo  = &fum;
#endif
    register char* localIP IP_REG;' ].
				(inLine findString: ' localSP;') > 0 ifTrue: [
					outLine := '    register char* localSP SP_REG;'. ].
				(inLine findString: ' currentBytecode;') > 0 ifTrue: [
					outLine := '    register int currentBytecode CB_REG;' ].
				inLine isEmpty ifTrue: [
					"reached end of variables"
					inInterpretVars := false.
					outLine := '    JUMP_TABLE;'. ] ]
			ifFalse: [
			inInterpret ifTrue: [
				"working inside interpret(); translate the switch statement"
				(inLine beginsWith: '		case ') ifTrue: [
					| caseLabel |
					caseLabel := (inLine findTokens: '	 :') second.
					outLine := '		CASE(', caseLabel, ')' ].
				inLine = '			break;' ifTrue: [
					outLine := '			BREAK;' ].
				inLine = '}' ifTrue: [
					"all finished with interpret()"
					inInterpret := false. ] ]
			ifFalse: [
			beforePrimitiveResponse ifTrue: [
				(inLine beginsWith: 'int primitiveResponse(') ifTrue: [
					"into primitiveResponse we go"
					beforePrimitiveResponse := false.
					inPrimitiveResponse := true.
					extraOutLine := '    PRIM_TABLE;'.  ] ]
			ifFalse: [
			inPrimitiveResponse ifTrue: [
				(inLine = '	switch (primitiveIndex) {') ifTrue: [
					extraOutLine := outLine.
					outLine := '	PRIM_DISPATCH;' ].
				(inLine beginsWith: '	case ') ifTrue: [
					| caseLabel |
					caseLabel := (inLine findTokens: '	 :') second.
					outLine := '	CASE(', caseLabel, ')' ].
				inLine = '}' ifTrue: [
					inPrimitiveResponse := false ] ].
			] ] ] ].

			outFileStream nextPutAll: outLine; cr.
			extraOutLine ifNotNil: [
				outFileStream nextPutAll: extraOutLine; cr ]]].

		outFileStream close! !

!Gnuifier methodsFor: 'as yet unclassified' stamp: 'acg 12/30/2001 14:12'!
setDirectory: aFileDirectory

	directory _ aFileDirectory! !

!Gnuifier methodsFor: 'as yet unclassified' stamp: 'acg 1/1/2002 09:54'!
sqGnuFile

^'/* Definitions for "gnuified" interp.c
 * 
 *   Copyright (C) 1996 1997 1998 1999 2000 Ian Piumarta and any individual
 *   authors/contributors listed elsewhere in this file.
 *   All rights reserved.
 *   
 *   This file is part of Unix Squeak.
 * 
 *   This file is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *   
 *   You may use and/or distribute this file ONLY as part of Squeak, under
 *   the terms of the Squeak License as described in ''LICENSE'' in the base of
 *   this distribution, subject to the following restrictions:
 * 
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software.  If you use this software
 *      in a product, an acknowledgment to the original author(s) (and any
 *      other contributors mentioned herein) in the product documentation
 *      would be appreciated but is not required.
 * 
 *   2. This notice may not be removed or altered in any source distribution.
 * 
 *   Using or modifying this file for use in any context other than Squeak
 *   changes these copyright conditions.  Read the file ''COPYING'' in the base
 *   of the distribution before proceeding with any such use.
 * 
 *   You are STRONGLY DISCOURAGED from distributing a modified version of
 *   this file under its original name without permission.  If you must
 *   change it, rename it first.
 */

/* Author: Ian.Piumarta@inria.fr
 *
 * Last edited: Fri Aug 11 08:20:28 2000 by piumarta (Ian Piumarta) on emilia
 *
 * NOTES:
 *	this file is #included IN PLACE OF sq.h
 */

#include "sq.h"

#define CASE(N)	case N: _##N:
#define BREAK		goto *jumpTable[currentBytecode]
#define PRIM_DISPATCH	goto *jumpTable[primitiveIndex]
#define JUMP_TABLE \
  static void *jumpTable[256]= { \
      &&_0,   &&_1,   &&_2,   &&_3,   &&_4,   &&_5,   &&_6,   &&_7,   &&_8,   &&_9, \
     &&_10,  &&_11,  &&_12,  &&_13,  &&_14,  &&_15,  &&_16,  &&_17,  &&_18,  &&_19, \
     &&_20,  &&_21,  &&_22,  &&_23,  &&_24,  &&_25,  &&_26,  &&_27,  &&_28,  &&_29, \
     &&_30,  &&_31,  &&_32,  &&_33,  &&_34,  &&_35,  &&_36,  &&_37,  &&_38,  &&_39, \
     &&_40,  &&_41,  &&_42,  &&_43,  &&_44,  &&_45,  &&_46,  &&_47,  &&_48,  &&_49, \
     &&_50,  &&_51,  &&_52,  &&_53,  &&_54,  &&_55,  &&_56,  &&_57,  &&_58,  &&_59, \
     &&_60,  &&_61,  &&_62,  &&_63,  &&_64,  &&_65,  &&_66,  &&_67,  &&_68,  &&_69, \
     &&_70,  &&_71,  &&_72,  &&_73,  &&_74,  &&_75,  &&_76,  &&_77,  &&_78,  &&_79, \
     &&_80,  &&_81,  &&_82,  &&_83,  &&_84,  &&_85,  &&_86,  &&_87,  &&_88,  &&_89, \
     &&_90,  &&_91,  &&_92,  &&_93,  &&_94,  &&_95,  &&_96,  &&_97,  &&_98,  &&_99, \
    &&_100, &&_101, &&_102, &&_103, &&_104, &&_105, &&_106, &&_107, &&_108, &&_109, \
    &&_110, &&_111, &&_112, &&_113, &&_114, &&_115, &&_116, &&_117, &&_118, &&_119, \
    &&_120, &&_121, &&_122, &&_123, &&_124, &&_125, &&_126, &&_127, &&_128, &&_129, \
    &&_130, &&_131, &&_132, &&_133, &&_134, &&_135, &&_136, &&_137, &&_138, &&_139, \
    &&_140, &&_141, &&_142, &&_143, &&_144, &&_145, &&_146, &&_147, &&_148, &&_149, \
    &&_150, &&_151, &&_152, &&_153, &&_154, &&_155, &&_156, &&_157, &&_158, &&_159, \
    &&_160, &&_161, &&_162, &&_163, &&_164, &&_165, &&_166, &&_167, &&_168, &&_169, \
    &&_170, &&_171, &&_172, &&_173, &&_174, &&_175, &&_176, &&_177, &&_178, &&_179, \
    &&_180, &&_181, &&_182, &&_183, &&_184, &&_185, &&_186, &&_187, &&_188, &&_189, \
    &&_190, &&_191, &&_192, &&_193, &&_194, &&_195, &&_196, &&_197, &&_198, &&_199, \
    &&_200, &&_201, &&_202, &&_203, &&_204, &&_205, &&_206, &&_207, &&_208, &&_209, \
    &&_210, &&_211, &&_212, &&_213, &&_214, &&_215, &&_216, &&_217, &&_218, &&_219, \
    &&_220, &&_221, &&_222, &&_223, &&_224, &&_225, &&_226, &&_227, &&_228, &&_229, \
    &&_230, &&_231, &&_232, &&_233, &&_234, &&_235, &&_236, &&_237, &&_238, &&_239, \
    &&_240, &&_241, &&_242, &&_243, &&_244, &&_245, &&_246, &&_247, &&_248, &&_249, \
    &&_250, &&_251, &&_252, &&_253, &&_254, &&_255 \
  }

#define PRIM_TABLE \
  static void *jumpTable[700]= { \
      &&_0,   &&_1,   &&_2,   &&_3,   &&_4,   &&_5,   &&_6,   &&_7,   &&_8,   &&_9, \
     &&_10,  &&_11,  &&_12,  &&_13,  &&_14,  &&_15,  &&_16,  &&_17,  &&_18,  &&_19, \
     &&_20,  &&_21,  &&_22,  &&_23,  &&_24,  &&_25,  &&_26,  &&_27,  &&_28,  &&_29, \
     &&_30,  &&_31,  &&_32,  &&_33,  &&_34,  &&_35,  &&_36,  &&_37,  &&_38,  &&_39, \
     &&_40,  &&_41,  &&_42,  &&_43,  &&_44,  &&_45,  &&_46,  &&_47,  &&_48,  &&_49, \
     &&_50,  &&_51,  &&_52,  &&_53,  &&_54,  &&_55,  &&_56,  &&_57,  &&_58,  &&_59, \
     &&_60,  &&_61,  &&_62,  &&_63,  &&_64,  &&_65,  &&_66,  &&_67,  &&_68,  &&_69, \
     &&_70,  &&_71,  &&_72,  &&_73,  &&_74,  &&_75,  &&_76,  &&_77,  &&_78,  &&_79, \
     &&_80,  &&_81,  &&_82,  &&_83,  &&_84,  &&_85,  &&_86,  &&_87,  &&_88,  &&_89, \
     &&_90,  &&_91,  &&_92,  &&_93,  &&_94,  &&_95,  &&_96,  &&_97,  &&_98,  &&_99, \
    &&_100, &&_101, &&_102, &&_103, &&_104, &&_105, &&_106, &&_107, &&_108, &&_109, \
    &&_110, &&_111, &&_112, &&_113, &&_114, &&_115, &&_116, &&_117, &&_118, &&_119, \
    &&_120, &&_121, &&_122, &&_123, &&_124, &&_125, &&_126, &&_127, &&_128, &&_129, \
    &&_130, &&_131, &&_132, &&_133, &&_134, &&_135, &&_136, &&_137, &&_138, &&_139, \
    &&_140, &&_141, &&_142, &&_143, &&_144, &&_145, &&_146, &&_147, &&_148, &&_149, \
    &&_150, &&_151, &&_152, &&_153, &&_154, &&_155, &&_156, &&_157, &&_158, &&_159, \
    &&_160, &&_161, &&_162, &&_163, &&_164, &&_165, &&_166, &&_167, &&_168, &&_169, \
    &&_170, &&_171, &&_172, &&_173, &&_174, &&_175, &&_176, &&_177, &&_178, &&_179, \
    &&_180, &&_181, &&_182, &&_183, &&_184, &&_185, &&_186, &&_187, &&_188, &&_189, \
    &&_190, &&_191, &&_192, &&_193, &&_194, &&_195, &&_196, &&_197, &&_198, &&_199, \
    &&_200, &&_201, &&_202, &&_203, &&_204, &&_205, &&_206, &&_207, &&_208, &&_209, \
    &&_210, &&_211, &&_212, &&_213, &&_214, &&_215, &&_216, &&_217, &&_218, &&_219, \
    &&_220, &&_221, &&_222, &&_223, &&_224, &&_225, &&_226, &&_227, &&_228, &&_229, \
    &&_230, &&_231, &&_232, &&_233, &&_234, &&_235, &&_236, &&_237, &&_238, &&_239, \
    &&_240, &&_241, &&_242, &&_243, &&_244, &&_245, &&_246, &&_247, &&_248, &&_249, \
    &&_250, &&_251, &&_252, &&_253, &&_254, &&_255, &&_256, &&_257, &&_258, &&_259, \
    &&_260, &&_261, &&_262, &&_263, &&_264, &&_265, &&_266, &&_267, &&_268, &&_269, \
    &&_270, &&_271, &&_272, &&_273, &&_274, &&_275, &&_276, &&_277, &&_278, &&_279, \
    &&_280, &&_281, &&_282, &&_283, &&_284, &&_285, &&_286, &&_287, &&_288, &&_289, \
    &&_290, &&_291, &&_292, &&_293, &&_294, &&_295, &&_296, &&_297, &&_298, &&_299, \
    &&_300, &&_301, &&_302, &&_303, &&_304, &&_305, &&_306, &&_307, &&_308, &&_309, \
    &&_310, &&_311, &&_312, &&_313, &&_314, &&_315, &&_316, &&_317, &&_318, &&_319, \
    &&_320, &&_321, &&_322, &&_323, &&_324, &&_325, &&_326, &&_327, &&_328, &&_329, \
    &&_330, &&_331, &&_332, &&_333, &&_334, &&_335, &&_336, &&_337, &&_338, &&_339, \
    &&_340, &&_341, &&_342, &&_343, &&_344, &&_345, &&_346, &&_347, &&_348, &&_349, \
    &&_350, &&_351, &&_352, &&_353, &&_354, &&_355, &&_356, &&_357, &&_358, &&_359, \
    &&_360, &&_361, &&_362, &&_363, &&_364, &&_365, &&_366, &&_367, &&_368, &&_369, \
    &&_370, &&_371, &&_372, &&_373, &&_374, &&_375, &&_376, &&_377, &&_378, &&_379, \
    &&_380, &&_381, &&_382, &&_383, &&_384, &&_385, &&_386, &&_387, &&_388, &&_389, \
    &&_390, &&_391, &&_392, &&_393, &&_394, &&_395, &&_396, &&_397, &&_398, &&_399, \
    &&_400, &&_401, &&_402, &&_403, &&_404, &&_405, &&_406, &&_407, &&_408, &&_409, \
    &&_410, &&_411, &&_412, &&_413, &&_414, &&_415, &&_416, &&_417, &&_418, &&_419, \
    &&_420, &&_421, &&_422, &&_423, &&_424, &&_425, &&_426, &&_427, &&_428, &&_429, \
    &&_430, &&_431, &&_432, &&_433, &&_434, &&_435, &&_436, &&_437, &&_438, &&_439, \
    &&_440, &&_441, &&_442, &&_443, &&_444, &&_445, &&_446, &&_447, &&_448, &&_449, \
    &&_450, &&_451, &&_452, &&_453, &&_454, &&_455, &&_456, &&_457, &&_458, &&_459, \
    &&_460, &&_461, &&_462, &&_463, &&_464, &&_465, &&_466, &&_467, &&_468, &&_469, \
    &&_470, &&_471, &&_472, &&_473, &&_474, &&_475, &&_476, &&_477, &&_478, &&_479, \
    &&_480, &&_481, &&_482, &&_483, &&_484, &&_485, &&_486, &&_487, &&_488, &&_489, \
    &&_490, &&_491, &&_492, &&_493, &&_494, &&_495, &&_496, &&_497, &&_498, &&_499, \
    &&_500, &&_501, &&_502, &&_503, &&_504, &&_505, &&_506, &&_507, &&_508, &&_509, \
    &&_510, &&_511, &&_512, &&_513, &&_514, &&_515, &&_516, &&_517, &&_518, &&_519, \
    &&_520, &&_521, &&_522, &&_523, &&_524, &&_525, &&_526, &&_527, &&_528, &&_529, \
    &&_530, &&_531, &&_532, &&_533, &&_534, &&_535, &&_536, &&_537, &&_538, &&_539, \
    &&_540, &&_541, &&_542, &&_543, &&_544, &&_545, &&_546, &&_547, &&_548, &&_549, \
    &&_550, &&_551, &&_552, &&_553, &&_554, &&_555, &&_556, &&_557, &&_558, &&_559, \
    &&_560, &&_561, &&_562, &&_563, &&_564, &&_565, &&_566, &&_567, &&_568, &&_569, \
    &&_570, &&_571, &&_572, &&_573, &&_574, &&_575, &&_576, &&_577, &&_578, &&_579, \
    &&_580, &&_581, &&_582, &&_583, &&_584, &&_585, &&_586, &&_587, &&_588, &&_589, \
    &&_590, &&_591, &&_592, &&_593, &&_594, &&_595, &&_596, &&_597, &&_598, &&_599, \
    &&_600, &&_601, &&_602, &&_603, &&_604, &&_605, &&_606, &&_607, &&_608, &&_609, \
    &&_610, &&_611, &&_612, &&_613, &&_614, &&_615, &&_616, &&_617, &&_618, &&_619, \
    &&_620, &&_621, &&_622, &&_623, &&_624, &&_625, &&_626, &&_627, &&_628, &&_629, \
    &&_630, &&_631, &&_632, &&_633, &&_634, &&_635, &&_636, &&_637, &&_638, &&_639, \
    &&_640, &&_641, &&_642, &&_643, &&_644, &&_645, &&_646, &&_647, &&_648, &&_649, \
    &&_650, &&_651, &&_652, &&_653, &&_654, &&_655, &&_656, &&_657, &&_658, &&_659, \
    &&_660, &&_661, &&_662, &&_663, &&_664, &&_665, &&_666, &&_667, &&_668, &&_669, \
    &&_670, &&_671, &&_672, &&_673, &&_674, &&_675, &&_676, &&_677, &&_678, &&_679, \
    &&_680, &&_681, &&_682, &&_683, &&_684, &&_685, &&_686, &&_687, &&_688, &&_689, \
    &&_690, &&_691, &&_692, &&_693, &&_694, &&_695, &&_696, &&_697, &&_698, &&_699, \
  }

  /*
     IP_REG, SP_REG, CB_REG
        the machine registers in which to place localIP, localSP and
        currentBytecode.  Wins big on register-deficient architectures --
        especially Intel.
  */
#if defined(__mips__)
# define IP_REG asm("$16")
# define SP_REG asm("$17")
# define CB_REG asm("$18")
#endif
#if defined(__sparc__)
# define IP_REG asm("%l0")
# define SP_REG asm("%l1")
# define CB_REG asm("%l2")
#endif
#if defined(__alpha__)
# define IP_REG asm("$9")
# define SP_REG asm("$10")
# define CB_REG asm("$11")
#endif
#if defined(__i386__)
# define IP_REG asm("%esi")
# define SP_REG asm("%edi")
# define CB_REG	/* asm("%ebx") ; avoid undue register pressure */
#endif
#if defined(PPC) || defined(_POWER) || defined(_IBMR2) || defined(__MACH__)
# define IP_REG asm("26")
# define SP_REG asm("27")
# define CB_REG asm("28")
#endif
#if defined(__hppa__)
# define IP_REG asm("%r18")
# define SP_REG asm("%r17")
# define CB_REG asm("%r16")
#endif
#if defined(__mc68000__)
# define IP_REG asm("a5")
# define SP_REG asm("a4")
# define CB_REG asm("d7")
#endif'! !


!Gnuifier class methodsFor: 'as yet unclassified' stamp: 'acg 12/30/2001 14:13'!
on: aFilePathString

	^self new setDirectory: (FileDirectory on: aFilePathString)! !

