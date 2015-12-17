/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
   from
	VMProfileMacSupportPlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef
 */
static char __buildInfo[] = "VMProfileMacSupportPlugin VMMaker.oscog-eem.1602 uuid: 16ff1141-4cce-41a9-a9f5-742da38970ef " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>

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

#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
static sqInt positiveMachineIntegerFor(unsigned long value);
EXPORT(sqInt) primitiveDLSym(void);
EXPORT(sqInt) primitiveExecutableModulesAndOffsets(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*nilObject)(void);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(sqInt integerValue);
static sqInt (*positive64BitIntegerFor)(sqLong integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushRemappableOop)(sqInt oop);
static sqInt (*signed32BitIntegerFor)(sqInt integerValue);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
static sqInt (*topRemappableOop)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt nilObject(void);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(sqInt integerValue);
extern sqInt positive64BitIntegerFor(sqLong integerValue);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushRemappableOop(sqInt oop);
extern sqInt signed32BitIntegerFor(sqInt integerValue);
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern sqInt topRemappableOop(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"VMProfileMacSupportPlugin VMMaker.oscog-eem.1602 (i)"
#else
	"VMProfileMacSupportPlugin VMMaker.oscog-eem.1602 (e)"
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

	/* InterpreterPlugin>>#positiveMachineIntegerFor: */
static sqInt
positiveMachineIntegerFor(unsigned long value)
{
	return (BytesPerWord == 8
		? positive64BitIntegerFor(value)
		: positive32BitIntegerFor(value));
}


/*	Answer the address of the argument in the current process or nil if none. */

	/* VMProfileMacSupportPlugin>>#primitiveDLSym */
EXPORT(sqInt)
primitiveDLSym(void)
{
    void *addr;
    sqInt i;
    char *name;
    sqInt nameObj;
    char *namePtr;
    sqInt sz;

	nameObj = stackValue(0);
	if (!(isBytes(nameObj))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	sz = byteSizeOf(nameObj);
	name = malloc(sz + 1);
	namePtr = firstIndexableField(nameObj);
	for (i = 0; i < sz; i += 1) {
		name[i] = (namePtr[i]);
	}
	name[sz] = 0;
	addr = dlsym(RTLD_SELF,name);
	free(name);
	return methodReturnValue((addr == 0
		? nilObject()
		: (BytesPerWord == 8
				? positive64BitIntegerFor(((unsigned long)addr))
				: positive32BitIntegerFor(((unsigned long)addr)))));
}


/*	Answer an Array of quads for executable modules (the VM executable
	and loaded libraries). Each quad is the module's name, its vm address
	relocation in memory, the (unrelocated) start address, and the size. */

	/* VMProfileMacSupportPlugin>>#primitiveExecutableModulesAndOffsets */
EXPORT(sqInt)
primitiveExecutableModulesAndOffsets(void)
{
    const struct mach_header *h;
    sqInt i;
    const char *name;
    char *nameObjData;
    sqInt nimages;
    sqInt present;
    sqInt resultObj;
    const struct section *s;
    unsigned long size;
    sqInt slide;
    unsigned long start;
    sqInt valueObj;

	present = _dyld_present();
	if (!present) {
		return primitiveFail();
	}
	nimages = _dyld_image_count();
	resultObj = instantiateClassindexableSize(classArray(), nimages * 4);
	if (resultObj == 0) {
		return primitiveFail();
	}
	pushRemappableOop(resultObj);
	for (i = 0; i < nimages; i += 1) {

		/* impossible start & size */
		start = (size = -1);
		name = _dyld_get_image_name(i);
		slide = _dyld_get_image_vmaddr_slide(i);
		h = _dyld_get_image_header(i);
		if (h != null) {
			s = getsectbynamefromheader(h,SEG_TEXT,SECT_TEXT);
			if (s != null) {
				start = s->addr;
				size = s->size;
			}
		}
		valueObj = instantiateClassindexableSize(classString(), strlen(name));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue(i * 4, topRemappableOop(), valueObj);
		nameObjData = arrayValueOf(valueObj);
		memcpy(nameObjData, name, strlen(name));
		valueObj = signed32BitIntegerFor(slide);
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 1, topRemappableOop(), valueObj);
		valueObj = (BytesPerWord == 8
			? positive64BitIntegerFor(start)
			: positive32BitIntegerFor(start));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 2, topRemappableOop(), valueObj);
		valueObj = (BytesPerWord == 8
			? positive64BitIntegerFor(size)
			: positive32BitIntegerFor(size));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 3, topRemappableOop(), valueObj);
	}
	resultObj = popRemappableOop();
	return popthenPush(1, resultObj);
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
		classArray = interpreterProxy->classArray;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		methodReturnValue = interpreterProxy->methodReturnValue;
		nilObject = interpreterProxy->nilObject;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive64BitIntegerFor = interpreterProxy->positive64BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		signed32BitIntegerFor = interpreterProxy->signed32BitIntegerFor;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
		topRemappableOop = interpreterProxy->topRemappableOop;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* VMProfileMacSupportPlugin_exports[][3] = {
	{"VMProfileMacSupportPlugin", "getModuleName", (void*)getModuleName},
	{"VMProfileMacSupportPlugin", "primitiveDLSym\000\001", (void*)primitiveDLSym},
	{"VMProfileMacSupportPlugin", "primitiveExecutableModulesAndOffsets\000\377", (void*)primitiveExecutableModulesAndOffsets},
	{"VMProfileMacSupportPlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDLSymAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
