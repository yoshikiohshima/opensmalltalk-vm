/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
   from
	JPEGReadWriter2Plugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
 */
static char __buildInfo[] = "JPEGReadWriter2Plugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef " __DATE__ ;



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

#include "JPEGReadWriter2Plugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primImageHeight(void);
EXPORT(sqInt) primImageWidth(void);
EXPORT(sqInt) primJPEGCompressStructSize(void);
EXPORT(sqInt) primJPEGDecompressStructSize(void);
EXPORT(sqInt) primJPEGErrorMgr2StructSize(void);
EXPORT(sqInt) primJPEGPluginIsPresent(void);
EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void);
EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void);
EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*failed)(void);
static sqInt (*falseObject)(void);
static sqInt (*fetchIntegerofObject)(sqInt fieldIndex, sqInt objectPointer);
static sqInt (*fetchPointerofObject)(sqInt index, sqInt oop);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*integerObjectOf)(sqInt value);
static sqInt (*isKindOf)(sqInt oop, char *aString);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWordsOrBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt failed(void);
extern sqInt falseObject(void);
extern sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchPointerofObject(sqInt index, sqInt oop);
extern void * firstIndexableField(sqInt oop);
extern sqInt integerObjectOf(sqInt value);
extern sqInt isKindOf(sqInt oop, char *aString);
extern sqInt isBytes(sqInt oop);
extern sqInt isWordsOrBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JPEGReadWriter2Plugin VMMaker.oscog-eem.1602 (i)"
#else
	"JPEGReadWriter2Plugin VMMaker.oscog-eem.1602 (e)"
#endif
;



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

	/* JPEGReadWriter2Plugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return 1;
}

	/* JPEGReadWriter2Plugin>>#primImageHeight: */
EXPORT(sqInt)
primImageHeight(void)
{
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	success(isBytes(stackValue(0)));
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	
	_return_value = integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_height));
	if (failed()) {
		return null;
	}
	popthenPush(2, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primImageWidth: */
EXPORT(sqInt)
primImageWidth(void)
{
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	success(isBytes(stackValue(0)));
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	
	_return_value = integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_width));
	if (failed()) {
		return null;
	}
	popthenPush(2, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGCompressStructSize */
EXPORT(sqInt)
primJPEGCompressStructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct jpeg_compress_struct)));
	if (failed()) {
		return null;
	}
	popthenPush(1, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGDecompressStructSize */
EXPORT(sqInt)
primJPEGDecompressStructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct jpeg_decompress_struct)));
	if (failed()) {
		return null;
	}
	popthenPush(1, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGErrorMgr2StructSize */
EXPORT(sqInt)
primJPEGErrorMgr2StructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct error_mgr2)));
	if (failed()) {
		return null;
	}
	popthenPush(1, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGPluginIsPresent */
EXPORT(sqInt)
primJPEGPluginIsPresent(void)
{
	sqInt _return_value;

	_return_value = ((1) ? trueObject() : falseObject());
	if (failed()) {
		return null;
	}
	popthenPush(1, _return_value);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGReadHeader:fromByteArray:errorMgr: */
EXPORT(sqInt)
primJPEGReadHeaderfromByteArrayerrorMgr(void)
{
	char *aJPEGDecompressStruct;
	char *aJPEGErrorMgr2Struct;
	j_decompress_ptr  pcinfo;
	error_ptr2  pjerr;
	char *source;
	sqInt sourceSize;

	success(isBytes(stackValue(2)));
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(2))));
	success(isBytes(stackValue(1)));
	source = ((char *) (firstIndexableField(stackValue(1))));
	success(isBytes(stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	sourceSize = null;
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(2))) >= (sizeof(struct jpeg_decompress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	
	
		sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(1));
		pcinfo = (j_decompress_ptr)aJPEGDecompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		if (sourceSize) {
			pcinfo->err = jpeg_std_error(&pjerr->pub);
			pjerr->pub.error_exit = error_exit;
			if (setjmp(pjerr->setjmp_buffer)) {
				jpeg_destroy_decompress(pcinfo);
				sourceSize = 0;
			}
			if (sourceSize) {
				jpeg_create_decompress(pcinfo);
				jpeg_mem_src(pcinfo, source, sourceSize);
				jpeg_read_header(pcinfo, TRUE);
			}
		}
	
	if (failed()) {
		return null;
	}
	pop(3);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGReadImage:fromByteArray:onForm:doDithering:errorMgr: */
EXPORT(sqInt)
primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void)
{
	char *aJPEGDecompressStruct;
	char *aJPEGErrorMgr2Struct;
	sqInt b1;
	sqInt b2;
	sqInt bOff;
	sqInt bOff2;
	JSAMPARRAY  buffer;
	sqInt di;
	sqInt ditherFlag;
	sqInt dmi;
	sqInt dmo;
	sqInt dmv1;
	sqInt dmv2;
	sqInt form;
	unsigned *  formBits;
	sqInt formBitsOops;
	sqInt formBitsSize;
	sqInt formDepth;
	sqInt formHeight;
	sqInt formPitch;
	sqInt formPix;
	sqInt formWidth;
	sqInt g1;
	sqInt g2;
	sqInt gOff;
	sqInt gOff2;
	sqInt i;
	sqInt j;
	sqInt ok;
	j_decompress_ptr  pcinfo;
	sqInt pixPerWord;
	error_ptr2  pjerr;
	sqInt r1;
	sqInt r2;
	sqInt rOff;
	sqInt rOff2;
	sqInt rowStride;
	char *source;
	sqInt sourceSize;

	success(isBytes(stackValue(4)));
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(4))));
	success(isBytes(stackValue(3)));
	source = ((char *) (firstIndexableField(stackValue(3))));
	success(isKindOf(stackValue(2), "Form"));
	form = stackValue(2);
	ditherFlag = booleanValueOf(stackValue(1));
	success(isBytes(stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	buffer = null;
	rowStride = null;
	formDepth = null;
	formBits = null;
	i = null;
	j = null;
	formPix = null;
	ok = null;
	rOff = null;
	gOff = null;
	bOff = null;
	rOff2 = null;
	gOff2 = null;
	bOff2 = null;
	sourceSize = null;
	r1 = null;
	r2 = null;
	g1 = null;
	g2 = null;
	b1 = null;
	b2 = null;
	dmv1 = null;
	dmv2 = null;
	di = null;
	dmi = null;
	dmo = null;
	formBitsOops = fetchPointerofObject(0, form);

	/* Various parameter checks */
	formDepth = fetchIntegerofObject(3, form);
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(4))) >= (sizeof(struct jpeg_decompress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	
	formWidth = ((j_decompress_ptr)aJPEGDecompressStruct)->image_width;
	formHeight = ((j_decompress_ptr)aJPEGDecompressStruct)->image_height;
	pixPerWord = 32 / formDepth;
	formPitch = ((formWidth + (pixPerWord - 1)) / pixPerWord) * 4;
	formBitsSize = byteSizeOf(formBitsOops);
	success((isWordsOrBytes(formBitsOops))
	 && (formBitsSize == (formPitch * formHeight)));
	if (failed()) {
		return null;
	}
	formBits = firstIndexableField(formBitsOops);
	
		sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(3));
		if (sourceSize == 0) {
			interpreterProxy->success(false);
			return null;
		}
		pcinfo = (j_decompress_ptr)aJPEGDecompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		pcinfo->err = jpeg_std_error(&pjerr->pub);
		pjerr->pub.error_exit = error_exit;
		ok = 1;
		if (setjmp(pjerr->setjmp_buffer)) {
			jpeg_destroy_decompress(pcinfo);
			ok = 0;
		}
		if (ok) {
			ok = jpeg_mem_src_newLocationOfData(pcinfo, source, sourceSize);
			if (ok) {
				/* Dither Matrix taken from Form>>orderedDither32To16, but rewritten for this method. */
				int ditherMatrix1[] = { 2, 0, 14, 12, 1, 3, 13, 15 };
				int ditherMatrix2[] = { 10, 8, 6, 4, 9, 11, 5, 7 };
 				jpeg_start_decompress(pcinfo);
				rowStride = pcinfo->output_width * pcinfo->output_components;
				if (pcinfo->out_color_components == 3) {
					rOff = 0; gOff = 1; bOff = 2;
					rOff2 = 3; gOff2 = 4; bOff2 = 5;
				} else {
					rOff = 0; gOff = 0; bOff = 0;
					rOff2 = 1; gOff2 = 1; bOff2 = 1;
				}
				/* Make a one-row-high sample array that will go away when done with image */
				buffer = (*(pcinfo->mem)->alloc_sarray)
					((j_common_ptr) pcinfo, JPOOL_IMAGE, rowStride, 1);

				/* Step 6: while (scan lines remain to be read) */
				/*           jpeg_read_scanlines(...); */

				/* Here we use the library state variable cinfo.output_scanline as the
				 * loop counter, so that we dont have to keep track ourselves.
				 */
				while (pcinfo->output_scanline < pcinfo->output_height) {
					/* jpeg_read_scanlines expects an array of pointers to scanlines.
					 * Here the array is only one element long, but you could ask for
					 * more than one scanline at a time if thats more convenient.
					 */
					(void) jpeg_read_scanlines(pcinfo, buffer, 1);

					switch (formDepth) {
						case 32:
							for(i = 0, j = 0; i < rowStride; i +=(pcinfo->out_color_components), j++) {
								formPix = (255 << 24) | (buffer[0][i+rOff] << 16) | (buffer[0][i+gOff] << 8) | buffer[0][i+bOff];
								if (formPix == 0) formPix = 1;
								formBits [ ((pcinfo->output_scanline - 1) * (pcinfo->image_width)) + j ] = formPix;
							}
							break;

						case 16:
							for(i = 0, j = 0; i < rowStride; i +=(pcinfo->out_color_components*2), j++) {
								r1 = buffer[0][i+rOff];
								r2 = buffer[0][i+rOff2];
								g1 = buffer[0][i+gOff];
								g2 = buffer[0][i+gOff2];
								b1 = buffer[0][i+bOff];
								b2 = buffer[0][i+bOff2];

								if (!ditherFlag) {
									r1 = r1 >> 3;
									r2 = r2 >> 3;
									g1 = g1 >> 3;
									g2 = g2 >> 3;
									b1 = b1 >> 3;
									b2 = b2 >> 3;
								} else {
									/* Do 4x4 ordered dithering. Taken from Form>>orderedDither32To16 */
									dmv1 = ditherMatrix1[ ((pcinfo->output_scanline & 3 )<< 1) | (j&1) ];
									dmv2 = ditherMatrix2[ ((pcinfo->output_scanline & 3 )<< 1) | (j&1) ];

									di = (r1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { r1 = dmo+1; } else { r1 = dmo; };
									di = (g1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { g1 = dmo+1; } else { g1 = dmo; };
									di = (b1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { b1 = dmo+1; } else { b1 = dmo; };

									di = (r2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { r2 = dmo+1; } else { r2 = dmo; };
									di = (g2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { g2 = dmo+1; } else { g2 = dmo; };
									di = (b2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { b2 = dmo+1; } else { b2 = dmo; };
								}

								formPix = (r1 << 10) | (g1 << 5) | b1;
								if (!formPix) formPix = 1;
								formPix = (formPix << 16) | (r2 << 10) | (g2 << 5) | b2;
								if (!(formPix & 65535)) formPix = formPix | 1;
								formBits [ ((pcinfo->output_scanline - 1) * (pcinfo->image_width)) / 2 + j ] = formPix;
							}
							break;
					}
				}
				jpeg_finish_decompress(pcinfo);
			}
			jpeg_destroy_decompress(pcinfo);
		}
	
	if (failed()) {
		return null;
	}
	pop(5);
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGWriteImage:onByteArray:form:quality:progressiveJPEG:errorMgr: */
EXPORT(sqInt)
primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void)
{
	char *aJPEGCompressStruct;
	char *aJPEGErrorMgr2Struct;
	JSAMPARRAY  buffer;
	char *destination;
	unsigned int destinationSize;
	sqInt form;
	unsigned *  formBits;
	sqInt formBitsOops;
	sqInt formBitsSize;
	sqInt formDepth;
	sqInt formHeight;
	sqInt formPitch;
	sqInt formPix;
	sqInt formWidth;
	sqInt i;
	sqInt j;
	j_compress_ptr  pcinfo;
	sqInt pixPerWord;
	error_ptr2  pjerr;
	sqInt progressiveFlag;
	sqInt quality;
	sqInt rowStride;
	sqInt _return_value;

	success(isBytes(stackValue(5)));
	aJPEGCompressStruct = ((char *) (firstIndexableField(stackValue(5))));
	success(isBytes(stackValue(4)));
	destination = ((char *) (firstIndexableField(stackValue(4))));
	success(isKindOf(stackValue(3), "Form"));
	form = stackValue(3);
	quality = stackIntegerValue(2);
	progressiveFlag = booleanValueOf(stackValue(1));
	success(isBytes(stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	buffer = null;
	rowStride = null;
	formBits = null;
	formWidth = null;
	formHeight = null;
	formDepth = null;
	i = null;
	j = null;
	formPix = null;
	destinationSize = null;
	formBitsOops = fetchPointerofObject(0, form);
	formWidth = fetchIntegerofObject(1, form);
	formHeight = fetchIntegerofObject(2, form);

	/* Various parameter checks */
	formDepth = fetchIntegerofObject(3, form);
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(5))) >= (sizeof(struct jpeg_compress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	
	pixPerWord = 32 / formDepth;
	formPitch = ((formWidth + (pixPerWord - 1)) / pixPerWord) * 4;
	formBitsSize = byteSizeOf(formBitsOops);
	success((isWordsOrBytes(formBitsOops))
	 && (formBitsSize == (formPitch * formHeight)));
	if (failed()) {
		return null;
	}
	formBits = firstIndexableField(formBitsOops);
	
		destinationSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(4));
		pcinfo = (j_compress_ptr)aJPEGCompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		if (destinationSize) {
			pcinfo->err = jpeg_std_error(&pjerr->pub);
			pjerr->pub.error_exit = error_exit;
			if (setjmp(pjerr->setjmp_buffer)) {
				jpeg_destroy_compress(pcinfo);
				destinationSize = 0;
			}
			if (destinationSize) {
				jpeg_create_compress(pcinfo);
				jpeg_mem_dest(pcinfo, destination, &destinationSize);
				pcinfo->image_width = formWidth;
				pcinfo->image_height = formHeight;
				pcinfo->input_components = 3;
				pcinfo->in_color_space = JCS_RGB;
				jpeg_set_defaults(pcinfo);
				if (quality > 0)
					jpeg_set_quality (pcinfo, quality, 1);
				if (progressiveFlag)
					jpeg_simple_progression(pcinfo);
				jpeg_start_compress(pcinfo, TRUE);
				rowStride = formWidth * 3;

				/* Make a one-row-high sample array that will go away 
				  when done with image */
				buffer = (*(pcinfo->mem)->alloc_sarray)
					((j_common_ptr) pcinfo, JPOOL_IMAGE, rowStride, 1);

				while (pcinfo->next_scanline < pcinfo->image_height) {
					switch (formDepth) {
						case 32:
							for(i = 0, j = 0; i < rowStride; i +=3, j++) {
								formPix = formBits [ ((pcinfo->next_scanline) * formWidth) + j ];
								buffer[0][i] = (formPix >> 16) & 255;
								buffer[0][i+1] = (formPix >> 8) & 255;
								buffer[0][i+2] = formPix & 255;
							}
							break;
						case 16:
							for(i = 0, j = 0; i < rowStride; i +=6, j++) {
								formPix = formBits [ ((pcinfo->next_scanline) * formWidth) / 2 + j ];
								buffer[0][i] = (formPix >> 23) & 248;
								buffer[0][i+1] = (formPix >> 18) & 248;
								buffer[0][i+2] = (formPix >> 13) & 248;
								buffer[0][i+3] = (formPix >> 7) & 248;
								buffer[0][i+4] = (formPix >> 2) & 248;
								buffer[0][i+5] = (formPix << 3) & 248;
							}
							break;
					}
					(void) jpeg_write_scanlines(pcinfo, buffer, 1);

				}
				jpeg_finish_compress(pcinfo);
				jpeg_destroy_compress(pcinfo);
			}
		}
	
	_return_value = integerObjectOf((destinationSize));
	if (failed()) {
		return null;
	}
	popthenPush(7, _return_value);
	return null;
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
		booleanValueOf = interpreterProxy->booleanValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		failed = interpreterProxy->failed;
		falseObject = interpreterProxy->falseObject;
		fetchIntegerofObject = interpreterProxy->fetchIntegerofObject;
		fetchPointerofObject = interpreterProxy->fetchPointerofObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
		integerObjectOf = interpreterProxy->integerObjectOf;
		isKindOf = interpreterProxy->isKindOf;
		isBytes = interpreterProxy->isBytes;
		isWordsOrBytes = interpreterProxy->isWordsOrBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* JPEGReadWriter2Plugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return 1;
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* JPEGReadWriter2Plugin_exports[][3] = {
	{"JPEGReadWriter2Plugin", "getModuleName", (void*)getModuleName},
	{"JPEGReadWriter2Plugin", "initialiseModule", (void*)initialiseModule},
	{"JPEGReadWriter2Plugin", "primImageHeight\000\377", (void*)primImageHeight},
	{"JPEGReadWriter2Plugin", "primImageWidth\000\377", (void*)primImageWidth},
	{"JPEGReadWriter2Plugin", "primJPEGCompressStructSize\000\377", (void*)primJPEGCompressStructSize},
	{"JPEGReadWriter2Plugin", "primJPEGDecompressStructSize\000\377", (void*)primJPEGDecompressStructSize},
	{"JPEGReadWriter2Plugin", "primJPEGErrorMgr2StructSize\000\377", (void*)primJPEGErrorMgr2StructSize},
	{"JPEGReadWriter2Plugin", "primJPEGPluginIsPresent\000\377", (void*)primJPEGPluginIsPresent},
	{"JPEGReadWriter2Plugin", "primJPEGReadHeaderfromByteArrayerrorMgr\000\377", (void*)primJPEGReadHeaderfromByteArrayerrorMgr},
	{"JPEGReadWriter2Plugin", "primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr\000\002", (void*)primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr},
	{"JPEGReadWriter2Plugin", "primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr\000\002", (void*)primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr},
	{"JPEGReadWriter2Plugin", "setInterpreter", (void*)setInterpreter},
	{"JPEGReadWriter2Plugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgrAccessorDepth = 2;
signed char primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgrAccessorDepth = 2;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
