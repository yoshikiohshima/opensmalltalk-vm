/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
   from
	AsynchFilePlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
 */
static char __buildInfo[] = "AsynchFilePlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef " __DATE__ ;



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

#include "AsynchFilePlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
static AsyncFile * asyncFileValueOf(sqInt oop);
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
EXPORT(sqInt) primitiveAsyncFileClose(void);
EXPORT(sqInt) primitiveAsyncFileOpen(void);
EXPORT(sqInt) primitiveAsyncFileReadResult(void);
EXPORT(sqInt) primitiveAsyncFileReadStart(void);
EXPORT(sqInt) primitiveAsyncFileWriteResult(void);
EXPORT(sqInt) primitiveAsyncFileWriteStart(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classByteArray)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*integerObjectOf)(sqInt value);
static void * (*ioLoadFunctionFrom)(char *functionName, char *moduleName);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classByteArray(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt integerObjectOf(sqInt value);
extern void * ioLoadFunctionFrom(char *functionName, char *moduleName);
extern sqInt isBytes(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"AsynchFilePlugin VMMaker.oscog-eem.1602 (i)"
#else
	"AsynchFilePlugin VMMaker.oscog-eem.1602 (e)"
#endif
;
static void * sCOAFfn;



/*	Answer a pointer to the first byte of the async file record within the
	given Smalltalk bytes object, or fail and answer nil if oop is not an
	async file record. */

	/* AsynchFilePlugin>>#asyncFileValueOf: */
static AsyncFile *
asyncFileValueOf(sqInt oop)
{
	if ((isBytes(oop))
	 && ((byteSizeOf(oop)) == (sizeof(AsyncFile)))) {
		return ((AsyncFile *) (firstIndexableField(oop)));
	}
	primitiveFailFor(PrimErrBadArgument);
	return null;
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


/*	Initialise the module */

	/* AsynchFilePlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	sCOAFfn = ioLoadFunctionFrom("secCanOpenAsyncFileOfSizeWritable", "SecurityPlugin");
	return asyncFileInit();
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

	/* AsynchFilePlugin>>#moduleUnloaded: */
EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	if ((strcmp(aModuleName, "SecurityPlugin")) == 0) {

		/* The security plugin just shut down. How odd. Zero the function pointer we have into it */
		sCOAFfn = 0;
	}
}

	/* AsynchFilePlugin>>#primitiveAsyncFileClose: */
EXPORT(sqInt)
primitiveAsyncFileClose(void)
{
	AsyncFile *f;
	sqInt fh;

	fh = stackValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fh))
	 && ((byteSizeOf(fh)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fh)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	asyncFileClose(f);
	if (failed()) {
		return null;
	}
	pop(1);
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileOpen:forWrite:semaIndex: */
EXPORT(sqInt)
primitiveAsyncFileOpen(void)
{
	AsyncFile *f;
	char *fileName;
	sqInt fileNameSize;
	sqInt fOop;
	sqInt okToOpen;
	sqInt semaIndex;
	sqInt writeFlag;

	success(isBytes(stackValue(2)));
	fileName = ((char *) (firstIndexableField(stackValue(2))));
	writeFlag = booleanValueOf(stackValue(1));
	semaIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	   If not, assume it's ok */
	fileNameSize = byteSizeOf(((sqInt)((fileName) - BaseHeaderSize)));
	if (sCOAFfn != 0) {
		okToOpen = ((sqInt (*) (char *, sqInt, sqInt)) sCOAFfn)(fileName, fileNameSize, writeFlag);
		if (!okToOpen) {
			primitiveFail();
			return null;
		}
	}
	fOop = instantiateClassindexableSize(classByteArray(), sizeof(AsyncFile));
	/* begin asyncFileValueOf: */
	if ((isBytes(fOop))
	 && ((byteSizeOf(fOop)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fOop)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	if (!(failed())) {
		asyncFileOpen(f, fileName, fileNameSize, writeFlag, semaIndex);
	}
	if (failed()) {
		return null;
	}
	popthenPush(4, fOop);
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileReadResult:intoBuffer:at:count: */
EXPORT(sqInt)
primitiveAsyncFileReadResult(void)
{
	sqInt buffer;
	sqInt bufferPtr;
	sqInt bufferSize;
	sqInt count;
	AsyncFile *f;
	sqInt fhandle;
	sqInt num;
	sqInt r;
	sqInt start;
	sqInt startIndex;
	sqInt _return_value;

	fhandle = stackValue(3);
	buffer = stackValue(2);
	start = stackIntegerValue(1);
	num = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fhandle))
	 && ((byteSizeOf(fhandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fhandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	count = num;
	startIndex = start;

	/* in bytes or words */
	bufferSize = slotSizeOf(buffer);
	if (isWords(buffer)) {

		/* covert word counts to byte counts */
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= bufferSize));
	if (failed()) {
		return null;
	}
	bufferPtr = ((((sqInt) (firstIndexableField(buffer)))) + startIndex) - 1;
	r = asyncFileReadResult(f, ((void *)bufferPtr), count);
	_return_value = integerObjectOf(r);
	if (failed()) {
		return null;
	}
	popthenPush(5, _return_value);
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileReadStart:fPosition:count: */
EXPORT(sqInt)
primitiveAsyncFileReadStart(void)
{
	sqInt count;
	AsyncFile *f;
	sqInt fHandle;
	sqInt fPosition;

	fHandle = stackValue(2);
	fPosition = stackIntegerValue(1);
	count = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	asyncFileReadStart(f, fPosition, count);
	if (failed()) {
		return null;
	}
	pop(3);
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileWriteResult: */
EXPORT(sqInt)
primitiveAsyncFileWriteResult(void)
{
	AsyncFile *f;
	sqInt fHandle;
	sqInt r;
	sqInt _return_value;

	fHandle = stackValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	r = asyncFileWriteResult(f);
	_return_value = integerObjectOf(r);
	if (failed()) {
		return null;
	}
	popthenPush(2, _return_value);
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileWriteStart:fPosition:fromBuffer:at:count: */
EXPORT(sqInt)
primitiveAsyncFileWriteStart(void)
{
	sqInt buffer;
	sqInt bufferPtr;
	sqInt bufferSize;
	sqInt count;
	AsyncFile *f;
	sqInt fHandle;
	sqInt fPosition;
	sqInt num;
	sqInt start;
	sqInt startIndex;

	fHandle = stackValue(4);
	fPosition = stackIntegerValue(3);
	buffer = stackValue(2);
	start = stackIntegerValue(1);
	num = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
l1:	/* end asyncFileValueOf: */;
	count = num;
	startIndex = start;

	/* in bytes or words */
	bufferSize = slotSizeOf(buffer);
	if (isWords(buffer)) {

		/* covert word counts to byte counts */
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= bufferSize));
	if (failed()) {
		return null;
	}
	bufferPtr = ((((sqInt) (firstIndexableField(buffer)))) + startIndex) - 1;
	asyncFileWriteStart(f, fPosition, ((void *)bufferPtr), count);
	if (failed()) {
		return null;
	}
	pop(5);
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
		classByteArray = interpreterProxy->classByteArray;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		integerObjectOf = interpreterProxy->integerObjectOf;
		ioLoadFunctionFrom = interpreterProxy->ioLoadFunctionFrom;
		isBytes = interpreterProxy->isBytes;
		isWords = interpreterProxy->isWords;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Initialise the module */

	/* AsynchFilePlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return asyncFileShutdown();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* AsynchFilePlugin_exports[][3] = {
	{"AsynchFilePlugin", "getModuleName", (void*)getModuleName},
	{"AsynchFilePlugin", "initialiseModule", (void*)initialiseModule},
	{"AsynchFilePlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"AsynchFilePlugin", "primitiveAsyncFileClose\000\000", (void*)primitiveAsyncFileClose},
	{"AsynchFilePlugin", "primitiveAsyncFileOpen\000\000", (void*)primitiveAsyncFileOpen},
	{"AsynchFilePlugin", "primitiveAsyncFileReadResult\000\000", (void*)primitiveAsyncFileReadResult},
	{"AsynchFilePlugin", "primitiveAsyncFileReadStart\000\000", (void*)primitiveAsyncFileReadStart},
	{"AsynchFilePlugin", "primitiveAsyncFileWriteResult\000\000", (void*)primitiveAsyncFileWriteResult},
	{"AsynchFilePlugin", "primitiveAsyncFileWriteStart\000\000", (void*)primitiveAsyncFileWriteStart},
	{"AsynchFilePlugin", "setInterpreter", (void*)setInterpreter},
	{"AsynchFilePlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveAsyncFileCloseAccessorDepth = 0;
signed char primitiveAsyncFileOpenAccessorDepth = 0;
signed char primitiveAsyncFileReadResultAccessorDepth = 0;
signed char primitiveAsyncFileReadStartAccessorDepth = 0;
signed char primitiveAsyncFileWriteResultAccessorDepth = 0;
signed char primitiveAsyncFileWriteStartAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
