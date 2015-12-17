/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
   from
	RePlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
 */
static char __buildInfo[] = "RePlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "rePlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
static sqInt allocateByteArrayAndSetRcvrExtraPtrFrom(sqInt anExtraPtr);
static sqInt allocateByteArrayAndSetRcvrPCREPtrFromPCRE(sqInt aPCREPtr);
static sqInt allocateStringAndSetRcvrErrorStrFromCStr(const char *aCStrBuffer);
EXPORT(const char*) getModuleName(void);
static sqInt loadRcvrFromStackAt(sqInt stackInteger);
EXPORT(sqInt) primLastAlloc(void);
EXPORT(sqInt) primNetMemory(void);
EXPORT(sqInt) primNumAllocs(void);
EXPORT(sqInt) primNumFrees(void);
EXPORT(sqInt) primPCRECompile(void);
EXPORT(sqInt) primPCREExec(void);
EXPORT(sqInt) primPCREExecfromto(void);
EXPORT(sqInt) primPCRENumSubPatterns(void);
static sqInt rcvrCompileFlags(void);
static sqInt rcvrErrorOffsetFrom(sqInt anInteger);
static sqInt rcvrErrorStrFrom(sqInt aString);
static sqInt rcvrExtraPtr(void);
static sqInt rcvrExtraPtrFrom(sqInt aByteArrayOrNilObject);
static sqInt rcvrMatchFlags(void);
static int * rcvrMatchSpacePtr(void);
static sqInt rcvrMatchSpaceSize(void);
static char * rcvrPatternStrPtr(void);
static sqInt rcvrPCREBufferFrom(sqInt aByteArray);
static sqInt rcvrPCREBufferPtr(void);
static void rePluginFree(void *  aPointer);
static void * rePluginMalloc(size_t  anInteger);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/
static sqInt compileFlags;
static sqInt errorOffset;
static sqInt errorStr;
static const char *  errorStrBuffer;
static sqInt extraPtr;

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classByteArray)(void);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*fetchArrayofObject)(sqInt fieldIndex, sqInt objectPointer);
static sqInt (*fetchIntegerofObject)(sqInt fieldIndex, sqInt objectPointer);
static sqInt (*fetchPointerofObject)(sqInt index, sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*nilObject)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*pushInteger)(sqInt integerValue);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*storeIntegerofObjectwithValue)(sqInt index, sqInt oop, sqInt integer);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classByteArray(void);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchPointerofObject(sqInt index, sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt nilObject(void);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt pushInteger(sqInt integerValue);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt storeIntegerofObjectwithValue(sqInt index, sqInt oop, sqInt integer);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static int lastAlloc = 0;
static sqInt matchFlags;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"RePlugin VMMaker.oscog-eem.1602 (i)"
#else
	"RePlugin VMMaker.oscog-eem.1602 (e)"
#endif
;
static int netMemory = 0;
static int numAllocs = 0;
static int numFrees = 0;
static sqInt patternStr;
static const char *  patternStrPtr;
static sqInt pcrePtr;
static sqInt rcvr;


	/* RePlugin>>#allocateByteArrayAndSetRcvrExtraPtrFrom: */
static sqInt
allocateByteArrayAndSetRcvrExtraPtrFrom(sqInt anExtraPtr)
{
	void *extraByteArrayPtr;
	sqInt extraObject;

	extraByteArrayPtr = 0;
	if (anExtraPtr) {

		/* Allocate a Smalltalk ByteArray -- lastAlloc contains the length */
		extraObject = instantiateClassindexableSize(classByteArray(), sizeof(real_pcre_extra));
		/* begin loadRcvrFromStackAt: */
		rcvr = stackObjectValue(0);
		extraByteArrayPtr = arrayValueOf(extraObject);
		memcpy(extraByteArrayPtr, (void *) anExtraPtr, sizeof(real_pcre_extra));
	}
	else {
		extraObject = nilObject();
	}
	/* begin rcvrExtraPtrFrom: */
	storePointerofObjectwithValue(3, rcvr, extraObject);
	return extraObject;
}

	/* RePlugin>>#allocateByteArrayAndSetRcvrPCREPtrFromPCRE: */
static sqInt
allocateByteArrayAndSetRcvrPCREPtrFromPCRE(sqInt aPCREPtr)
{
	void *patByteArrayPtr;
	sqInt patObject;


	/* Allocate a Smalltalk ByteArray -- lastAlloc contains the length */
	patObject = instantiateClassindexableSize(classByteArray(), lastAlloc);
	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(0);
	patByteArrayPtr = arrayValueOf(patObject);
	memcpy(patByteArrayPtr, (void *) aPCREPtr, lastAlloc);
	/* begin rcvrPCREBufferFrom: */
	storePointerofObjectwithValue(2, rcvr, patObject);
	return patObject;
}

	/* RePlugin>>#allocateStringAndSetRcvrErrorStrFromCStr: */
static sqInt
allocateStringAndSetRcvrErrorStrFromCStr(const char *aCStrBuffer)
{
	sqInt errorStrObj;
	void *errorStrObjPtr;
	sqInt length;


	/* Allocate errorStrObj */
	length = strlen(aCStrBuffer);
	errorStrObj = instantiateClassindexableSize(classString(), length);
	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(0);
	errorStrObjPtr = arrayValueOf(errorStrObj);
	memcpy(errorStrObjPtr,aCStrBuffer,length);
	/* begin rcvrErrorStrFrom: */
	storePointerofObjectwithValue(4, rcvr, errorStrObj);
	return errorStrObj;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* RePlugin>>#loadRcvrFromStackAt: */
static sqInt
loadRcvrFromStackAt(sqInt stackInteger)
{
	rcvr = stackObjectValue(stackInteger);
}

	/* RePlugin>>#primLastAlloc */
EXPORT(sqInt)
primLastAlloc(void)
{
	pop(1);
	pushInteger(lastAlloc);
}

	/* RePlugin>>#primNetMemory */
EXPORT(sqInt)
primNetMemory(void)
{
	pop(1);
	pushInteger(netMemory);
}

	/* RePlugin>>#primNumAllocs */
EXPORT(sqInt)
primNumAllocs(void)
{
	pop(1);
	pushInteger(numAllocs);
}

	/* RePlugin>>#primNumFrees */
EXPORT(sqInt)
primNumFrees(void)
{
	pop(1);
	pushInteger(numFrees);
}


/*	<rcvr primPCRECompile>, where rcvr is an object with instance variables:
	
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Compile the regular expression in patternStr, and if the compilation is
	successful, attempt to optimize the compiled expression. Store the results
	in <pcrePtr> and <extratr>, or fill errorStr with a meaningful errorString
	and errorOffset with an indicator where the error was found, applying
	compileFlags throughout. Answer nil with a clean compile (regardless of
	whether an optimization is possible, and answer with the string otherwise.
 */

	/* RePlugin>>#primPCRECompile */
EXPORT(sqInt)
primPCRECompile(void)
{
	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(0);
	patternStrPtr = ((char *) (fetchArrayofObject(0, rcvr)));
	compileFlags = fetchIntegerofObject(1, rcvr);
	if (failed()) {
		return null;
	}
	pcrePtr = (sqInt) pcre_compile(patternStrPtr, compileFlags, &errorStrBuffer, &errorOffset, NULL);
	if (pcrePtr) {
		allocateByteArrayAndSetRcvrPCREPtrFromPCRE(pcrePtr);
		extraPtr = (sqInt) pcre_study((pcre *)pcrePtr, compileFlags, &errorStrBuffer);
		allocateByteArrayAndSetRcvrExtraPtrFrom(extraPtr);
		/* begin rePluginFree: */
		numFrees += 1;
		if ((((void *)pcrePtr)) != null) {
			free(((void *)pcrePtr));
		}
		if (extraPtr) {
			/* begin rePluginFree: */
			numFrees += 1;
			if ((((void *)extraPtr)) != null) {
				free(((void *)extraPtr));
			}
		}
		if (failed()) {
			return null;
		}
		popthenPush(1, nilObject());
	}
	else {
		errorStr = allocateStringAndSetRcvrErrorStrFromCStr(errorStrBuffer);
		/* begin rcvrErrorOffsetFrom: */
		storeIntegerofObjectwithValue(5, rcvr, errorOffset);
		if (failed()) {
			return null;
		}
		popthenPush(1, errorStr);
	}
}


/*	<rcvr primPCREExec: searchObject>, where rcvr is an object with instance
	variables: 
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Apply the regular expression (stored in <pcrePtr> and <extratr>, generated
	from calls to primPCRECompile), to smalltalk String searchObject using
	<matchOptions>. If there is no match, answer nil. Otherwise answer a
	ByteArray of offsets representing the results of the match.
 */

	/* RePlugin>>#primPCREExec */
EXPORT(sqInt)
primPCREExec(void)
{
	sqInt extraObj;
	sqInt length;
	int *matchSpacePtr;
	sqInt matchSpaceSize;
	sqInt result;
	char *searchBuffer;
	sqInt searchObject;


	/* Load Parameters */
	searchObject = stackObjectValue(0);
	searchBuffer = arrayValueOf(searchObject);
	length = byteSizeOf(searchObject);
	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(1);
	pcrePtr = ((sqInt) (fetchArrayofObject(2, rcvr)));
	/* begin rcvrExtraPtr */
	extraObj = fetchPointerofObject(3, rcvr);
	extraPtr = ((sqInt) ((!(extraObj == (nilObject()))
	? arrayValueOf(extraObj)
	: 0)));
	matchFlags = fetchIntegerofObject(6, rcvr);
	/* begin rcvrMatchSpacePtr */
	matchSpacePtr = ((int *) (fetchArrayofObject(7, rcvr)));
	matchSpaceSize = (byteSizeOf(fetchPointerofObject(7, rcvr))) / 4;
	if (failed()) {
		return null;
	}
	result = pcre_exec((pcre *)pcrePtr, (pcre_extra *)extraPtr, 
				searchBuffer, length, 0, matchFlags, matchSpacePtr, matchSpaceSize);
	pop(2);
	pushInteger(result);
	}


/*	<rcvr primPCREExec: searchObject from: fromInteger to: toInteger>, where
	rcvr is an object with instance variables:
	
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Apply the regular expression (stored in <pcrePtr> and <extratr>, generated
	from calls to primPCRECompile), to smalltalk String searchObject using
	<matchOptions>, beginning at offset <fromInteger> and continuing until
	offset <toInteger>. If there is no match, answer nil. Otherwise answer a
	ByteArray of offsets representing the results of the match.
 */

	/* RePlugin>>#primPCREExecfromto */
EXPORT(sqInt)
primPCREExecfromto(void)
{
	sqInt extraObj;
	sqInt fromInteger;
	sqInt length;
	int *matchSpacePtr;
	sqInt matchSpaceSize;
	sqInt result;
	char *searchBuffer;
	sqInt searchObject;
	sqInt toInteger;


	/* Load Parameters */
	toInteger = stackIntegerValue(0);
	fromInteger = stackIntegerValue(1);
	searchObject = stackObjectValue(2);
	searchBuffer = arrayValueOf(searchObject);
	length = byteSizeOf(searchObject);
	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(3);
	success(1 <= fromInteger);
	success(toInteger <= length);

	/* Smalltalk offsets are 1-based */
	fromInteger -= 1;
	success(fromInteger <= toInteger);
	length = toInteger - fromInteger;

	/* Load Instance Variables */
	searchBuffer += fromInteger;
	pcrePtr = ((sqInt) (fetchArrayofObject(2, rcvr)));
	/* begin rcvrExtraPtr */
	extraObj = fetchPointerofObject(3, rcvr);
	extraPtr = ((sqInt) ((!(extraObj == (nilObject()))
	? arrayValueOf(extraObj)
	: 0)));
	matchFlags = fetchIntegerofObject(6, rcvr);
	/* begin rcvrMatchSpacePtr */
	matchSpacePtr = ((int *) (fetchArrayofObject(7, rcvr)));
	matchSpaceSize = (byteSizeOf(fetchPointerofObject(7, rcvr))) / 4;
	if (failed()) {
		return null;
	}
	result = pcre_exec((pcre *)pcrePtr, (pcre_extra *)extraPtr, 
				searchBuffer, length, 0, matchFlags, matchSpacePtr, matchSpaceSize);
	pop(4);
	pushInteger(result);
	}


/*	<rcvr primPCRENumSubPatterns>, where rcvr is an object with instance
	variables: 
	'patternStr compileFlags pcrePtr extraPtr errorStr errorOffset
	matchFlags'	 
	Return the number of subpatterns captured by the compiled pattern.
 */
/*	Load Parameters */

	/* RePlugin>>#primPCRENumSubPatterns */
EXPORT(sqInt)
primPCRENumSubPatterns(void)
{
	sqInt ncap;

	/* begin loadRcvrFromStackAt: */
	rcvr = stackObjectValue(0);
	pcrePtr = ((sqInt) (fetchArrayofObject(2, rcvr)));
	pcre_fullinfo((const pcre *)pcrePtr, NULL, PCRE_INFO_CAPTURECOUNT, &ncap);
	pop(1);
	pushInteger(ncap);
}

	/* RePlugin>>#rcvrCompileFlags */
static sqInt
rcvrCompileFlags(void)
{
	return fetchIntegerofObject(1, rcvr);
}

	/* RePlugin>>#rcvrErrorOffsetFrom: */
static sqInt
rcvrErrorOffsetFrom(sqInt anInteger)
{
	storeIntegerofObjectwithValue(5, rcvr, anInteger);
}

	/* RePlugin>>#rcvrErrorStrFrom: */
static sqInt
rcvrErrorStrFrom(sqInt aString)
{
	storePointerofObjectwithValue(4, rcvr, aString);
}

	/* RePlugin>>#rcvrExtraPtr */
static sqInt
rcvrExtraPtr(void)
{
	sqInt extraObj;

	extraObj = fetchPointerofObject(3, rcvr);
	return ((sqInt) ((!(extraObj == (nilObject()))
	? arrayValueOf(extraObj)
	: 0)));
}

	/* RePlugin>>#rcvrExtraPtrFrom: */
static sqInt
rcvrExtraPtrFrom(sqInt aByteArrayOrNilObject)
{
	storePointerofObjectwithValue(3, rcvr, aByteArrayOrNilObject);
}

	/* RePlugin>>#rcvrMatchFlags */
static sqInt
rcvrMatchFlags(void)
{
	return fetchIntegerofObject(6, rcvr);
}

	/* RePlugin>>#rcvrMatchSpacePtr */
static int *
rcvrMatchSpacePtr(void)
{
	return ((int *) (fetchArrayofObject(7, rcvr)));
}

	/* RePlugin>>#rcvrMatchSpaceSize */
static sqInt
rcvrMatchSpaceSize(void)
{
	return (byteSizeOf(fetchPointerofObject(7, rcvr))) / 4;
}

	/* RePlugin>>#rcvrPatternStrPtr */
static char *
rcvrPatternStrPtr(void)
{
	return ((char *) (fetchArrayofObject(0, rcvr)));
}

	/* RePlugin>>#rcvrPCREBufferFrom: */
static sqInt
rcvrPCREBufferFrom(sqInt aByteArray)
{
	storePointerofObjectwithValue(2, rcvr, aByteArray);
}

	/* RePlugin>>#rcvrPCREBufferPtr */
static sqInt
rcvrPCREBufferPtr(void)
{
	return ((sqInt) (fetchArrayofObject(2, rcvr)));
}


/*	Free a block of fixed memory allocated with rePluginMalloc. Instrumented
	version of C free() to facilitate leak analysis from Smalltalk.
	OS-specific variations on malloc/free, such as with MacOS, are handled by
	adding a C macro to the header file redefining malloc/free -- see the
	class comment
 */

	/* RePlugin>>#rePluginFree: */
static void
rePluginFree(void *  aPointer)
{
	numFrees += 1;
	if (aPointer != null) {
		free(aPointer);
	}
}


/*	Allocate a block of fixed memory using C calls to malloc(). Instrumented
	to facilitate leak analysis from Smalltalk. Set global lastAlloc to
	anInteger. OS-specific variations on malloc/free, such as with MacOS, are
	handled by adding a C macro to the header file redefining malloc/free --
	see the class comment
 */

	/* RePlugin>>#rePluginMalloc: */
static void *
rePluginMalloc(size_t  anInteger)
{
	void *aPointer;

	numAllocs += 1;
	if (((aPointer = malloc(anInteger))) != null) {
		lastAlloc = anInteger;
	}
	return aPointer;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		arrayValueOf = interpreterProxy->arrayValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classByteArray = interpreterProxy->classByteArray;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		fetchArrayofObject = interpreterProxy->fetchArrayofObject;
		fetchIntegerofObject = interpreterProxy->fetchIntegerofObject;
		fetchPointerofObject = interpreterProxy->fetchPointerofObject;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		nilObject = interpreterProxy->nilObject;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		pushInteger = interpreterProxy->pushInteger;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackObjectValue = interpreterProxy->stackObjectValue;
		storeIntegerofObjectwithValue = interpreterProxy->storeIntegerofObjectwithValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* RePlugin_exports[][3] = {
	{"RePlugin", "getModuleName", (void*)getModuleName},
	{"RePlugin", "primLastAlloc\000\377", (void*)primLastAlloc},
	{"RePlugin", "primNetMemory\000\377", (void*)primNetMemory},
	{"RePlugin", "primNumAllocs\000\377", (void*)primNumAllocs},
	{"RePlugin", "primNumFrees\000\377", (void*)primNumFrees},
	{"RePlugin", "primPCRECompile\000\000", (void*)primPCRECompile},
	{"RePlugin", "primPCREExec\000\001", (void*)primPCREExec},
	{"RePlugin", "primPCREExecfromto\000\001", (void*)primPCREExecfromto},
	{"RePlugin", "primPCRENumSubPatterns\000\000", (void*)primPCRENumSubPatterns},
	{"RePlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primPCRECompileAccessorDepth = 0;
signed char primPCREExecAccessorDepth = 1;
signed char primPCREExecfromtoAccessorDepth = 1;
signed char primPCRENumSubPatternsAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
