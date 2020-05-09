/* Automatically generated by
	VMPluginCodeGenerator * VMMaker.oscog-nice.2753 uuid: fa9a30c2-0c15-4231-b578-3596878b2627
   from
	Float64ArrayPlugin * VMMaker.oscog-nice.2753 uuid: fa9a30c2-0c15-4231-b578-3596878b2627
 */
static char __buildInfo[] = "Float64ArrayPlugin * VMMaker.oscog-nice.2753 uuid: fa9a30c2-0c15-4231-b578-3596878b2627 " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
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
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadReceiver 2


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveAddFloat64Array(void);
EXPORT(sqInt) primitiveAddScalar(void);
EXPORT(sqInt) primitiveAt(void);
EXPORT(sqInt) primitiveAtPut(void);
EXPORT(sqInt) primitiveDivFloat64Array(void);
EXPORT(sqInt) primitiveDivScalar(void);
EXPORT(sqInt) primitiveDotProduct(void);
EXPORT(sqInt) primitiveEqual(void);
EXPORT(sqInt) primitiveFromFloatArray(void);
EXPORT(sqInt) primitiveHashArray(void);
EXPORT(sqInt) primitiveLength(void);
EXPORT(sqInt) primitiveMulFloat64Array(void);
EXPORT(sqInt) primitiveMulScalar(void);
EXPORT(sqInt) primitiveNormalize(void);
EXPORT(sqInt) primitiveSubFloat64Array(void);
EXPORT(sqInt) primitiveSubScalar(void);
EXPORT(sqInt) primitiveSum(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static double (*floatValueOf)(sqInt oop);
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isLong64s)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodReturnFloat)(double aFloat);
static sqInt (*methodReturnInteger)(sqInt integer);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushBool)(sqInt trueOrFalse);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stSizeOf)(sqInt oop);
static double (*stackFloatValue)(sqInt offset);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern double floatValueOf(sqInt oop);
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
extern sqInt isLong64s(sqInt oop);
#else
# define isLong64s(oop) 0
#endif
extern sqInt isWords(sqInt oop);
extern sqInt methodReturnFloat(double aFloat);
extern sqInt methodReturnInteger(sqInt integer);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushBool(sqInt trueOrFalse);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stSizeOf(sqInt oop);
extern double stackFloatValue(sqInt offset);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "Float64ArrayPlugin * VMMaker.oscog-nice.2753 " INT_EXT;



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


/*	Primitive. Add the receiver and the argument, both Float64Arrays and store
	the result into the receiver.
 */

	/* Float64ArrayPlugin>>#primitiveAddFloat64Array */
EXPORT(sqInt)
primitiveAddFloat64Array(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) + (argPtr[i]));
	}
	pop(1);
	return 0;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a
	Float64Array 
 */

	/* Float64ArrayPlugin>>#primitiveAddScalar */
EXPORT(sqInt)
primitiveAddScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) + value);
	}
	pop(1);
	return 0;
}

	/* Float64ArrayPlugin>>#primitiveAt */
EXPORT(sqInt)
primitiveAt(void)
{
    double *doublePtr;
    sqInt index;
    sqInt rcvr;

	index = stackIntegerValue(0);
	rcvr = stackValue(1);
	if (!((!(failed()))
		 && ((isLong64s(rcvr))
		 && ((index > 0)
		 && (index <= (slotSizeOf(rcvr))))))) {
		return primitiveFail();
	}
	doublePtr = ((double *) (firstIndexableField(rcvr)));
	methodReturnFloat(doublePtr[index - 1]);
	return 0;
}

	/* Float64ArrayPlugin>>#primitiveAtPut */
EXPORT(sqInt)
primitiveAtPut(void)
{
    double *doublePtr;
    double floatValue;
    sqInt index;
    sqInt rcvr;
    sqInt value;

	value = stackValue(0);
	floatValue = (isIntegerObject(value)
		? ((double) (integerValueOf(value)) )
		: floatValueOf(value));
	index = stackIntegerValue(1);
	rcvr = stackValue(2);
	if (!((!(failed()))
		 && ((isLong64s(rcvr))
		 && ((index > 0)
		 && (index <= (slotSizeOf(rcvr))))))) {
		return primitiveFail();
	}
	doublePtr = ((double *) (firstIndexableField(rcvr)));
	doublePtr[index - 1] = floatValue;
	popthenPush(3, value);
	return 0;
}


/*	Primitive. Divide each element in the receiver by the corresponding
	element in the argument, both Float64Arrays, and store the result into the
	receiver. 
 */

	/* Float64ArrayPlugin>>#primitiveDivFloat64Array */
EXPORT(sqInt)
primitiveDivFloat64Array(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));

	/* Check if any of the argument's values is zero */
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		if ((argPtr[i]) == 0.0) {

			/* i.e. check for both 0.0 and -0.0 */
			return primitiveFail();
		}
	}
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) / (argPtr[i]));
	}
	pop(1);
	return 0;
}


/*	Primitive. Divide each element in the receiver by the argument, a scalar,
	and store the result into the receiver, a Float64Array
 */

	/* Float64ArrayPlugin>>#primitiveDivScalar */
EXPORT(sqInt)
primitiveDivScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) / value);
	}
	pop(1);
	return 0;
}


/*	Primitive. Compute the dot product of the receiver and the argument, both
	Float64Arrays. The dot product is defined as the sum of the products of
	the individual elements.
 */

	/* Float64ArrayPlugin>>#primitiveDotProduct */
EXPORT(sqInt)
primitiveDotProduct(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double result;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	result = 0.0;
	for (i = 0; i < length; i += 1) {
		result += (rcvrPtr[i]) * (argPtr[i]);
	}
	methodReturnFloat(result);
	return 0;
}

	/* Float64ArrayPlugin>>#primitiveEqual */
EXPORT(sqInt)
primitiveEqual(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && (isLong64s(rcvr)))) {
		return primitiveFail();
	}
	pop(2);
	if (!(((length = stSizeOf(arg))) == (stSizeOf(rcvr)))) {
		return pushBool(0);
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		if (!((rcvrPtr[i]) == (argPtr[i]))) {
			return pushBool(0);
		}
	}
	return pushBool(1);
}


/*	Primitive. Set each element of the receiver, a Float64Array with that of
	the argument, a FloatArray and return the receiver.
	Fail if both have different size
 */

	/* Float64ArrayPlugin>>#primitiveFromFloatArray */
EXPORT(sqInt)
primitiveFromFloatArray(void)
{
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isWords(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = (((double) (argPtr[i])));
	}
	pop(1);
	return 0;
}

	/* Float64ArrayPlugin>>#primitiveHashArray */
EXPORT(sqInt)
primitiveHashArray(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    unsigned int *rcvrPtr;
    unsigned int result;

	rcvr = stackValue(0);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((unsigned int *) (firstIndexableField(rcvr)));
	result = 0;
	for (i = 0; i < (length * 2); i += 1) {
		result += rcvrPtr[i];
	}
	methodReturnInteger(result & 0x1FFFFFFF);
	return 0;
}


/*	Primitive. Compute the length of the argument (sqrt of sum of component
	squares). 
 */

	/* Float64ArrayPlugin>>#primitiveLength */
EXPORT(sqInt)
primitiveLength(void)
{
    sqInt i;
    double len;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	rcvr = stackValue(0);
	if (!(isLong64s(rcvr))) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	len = 0.0;
	for (i = 0; i < length; i += 1) {
		len += (rcvrPtr[i]) * (rcvrPtr[i]);
	}
	if (!(len > 0.0)) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	methodReturnFloat(sqrt(len));
	return 0;
}


/*	Primitive. Multiply the receiver and the argument, both Float64Arrays and
	store the result into the receiver.
 */

	/* Float64ArrayPlugin>>#primitiveMulFloat64Array */
EXPORT(sqInt)
primitiveMulFloat64Array(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) * (argPtr[i]));
	}
	pop(1);
	return 0;
}


/*	Primitive. Multiply elements in the receiver, a Float64Array, by argument,
	a scalar value, and store the result into the receiver.
 */

	/* Float64ArrayPlugin>>#primitiveMulScalar */
EXPORT(sqInt)
primitiveMulScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) * value);
	}
	pop(1);
	return 0;
}


/*	Primitive. Normalize the argument (A Float64Array) in place. */

	/* Float64ArrayPlugin>>#primitiveNormalize */
EXPORT(sqInt)
primitiveNormalize(void)
{
    sqInt i;
    double len;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	rcvr = stackValue(0);
	if (!(isLong64s(rcvr))) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	len = 0.0;
	for (i = 0; i < length; i += 1) {
		len += (rcvrPtr[i]) * (rcvrPtr[i]);
	}
	if (!(len > 0.0)) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	len = sqrt(len);
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) / len);
	}
	return 0;
}


/*	Primitive. Subtract each element in the argument from each element in the
	receiver, both Float64Arrays and store the result into the receiver.
 */

	/* Float64ArrayPlugin>>#primitiveSubFloat64Array */
EXPORT(sqInt)
primitiveSubFloat64Array(void)
{
    sqInt arg;
    double *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;

	arg = stackValue(0);
	rcvr = stackValue(1);
	if (!((isLong64s(arg))
		 && ((isLong64s(rcvr))
		 && (((length = stSizeOf(arg))) == (stSizeOf(rcvr)))))) {
		return primitiveFail();
	}
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	argPtr = ((double *) (firstIndexableField(arg)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) - (argPtr[i]));
	}
	pop(1);
	return 0;
}


/*	Primitive. Subtract the argument, a scalar value from each element in the
	receiver, a Float64Array */

	/* Float64ArrayPlugin>>#primitiveSubScalar */
EXPORT(sqInt)
primitiveSubScalar(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double value;

	value = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	rcvr = stackValue(1);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	for (i = 0; i < length; i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) - value);
	}
	pop(1);
	return 0;
}


/*	Primitive. Answer the sum of each float in the receiver, a Float64Array. */

	/* Float64ArrayPlugin>>#primitiveSum */
EXPORT(sqInt)
primitiveSum(void)
{
    sqInt i;
    sqInt length;
    sqInt rcvr;
    double *rcvrPtr;
    double sum;

	rcvr = stackValue(0);
	if (!(isLong64s(rcvr))) {
		return primitiveFail();
	}
	length = stSizeOf(rcvr);
	rcvrPtr = ((double *) (firstIndexableField(rcvr)));
	sum = 0.0;
	for (i = 0; i < length; i += 1) {
		sum += rcvrPtr[i];
	}
	methodReturnFloat(sum);
	return 0;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		floatValueOf = interpreterProxy->floatValueOf;
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
		isLong64s = interpreterProxy->isLong64s;
#else
#if !defined(isLong64s)
		isLong64s = 0;
#endif
#endif
		isWords = interpreterProxy->isWords;
		methodReturnFloat = interpreterProxy->methodReturnFloat;
		methodReturnInteger = interpreterProxy->methodReturnInteger;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushBool = interpreterProxy->pushBool;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stSizeOf = interpreterProxy->stSizeOf;
		stackFloatValue = interpreterProxy->stackFloatValue;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "Float64ArrayPlugin";
void* Float64ArrayPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveAddFloat64Array\000\000", (void*)primitiveAddFloat64Array},
	{(void*)_m, "primitiveAddScalar\000\000", (void*)primitiveAddScalar},
	{(void*)_m, "primitiveAt\000\000", (void*)primitiveAt},
	{(void*)_m, "primitiveAtPut\000\000", (void*)primitiveAtPut},
	{(void*)_m, "primitiveDivFloat64Array\000\000", (void*)primitiveDivFloat64Array},
	{(void*)_m, "primitiveDivScalar\000\000", (void*)primitiveDivScalar},
	{(void*)_m, "primitiveDotProduct\000\000", (void*)primitiveDotProduct},
	{(void*)_m, "primitiveEqual\000\000", (void*)primitiveEqual},
	{(void*)_m, "primitiveFromFloatArray\000\000", (void*)primitiveFromFloatArray},
	{(void*)_m, "primitiveHashArray\000\000", (void*)primitiveHashArray},
	{(void*)_m, "primitiveLength\000\000", (void*)primitiveLength},
	{(void*)_m, "primitiveMulFloat64Array\000\000", (void*)primitiveMulFloat64Array},
	{(void*)_m, "primitiveMulScalar\000\000", (void*)primitiveMulScalar},
	{(void*)_m, "primitiveNormalize\000\000", (void*)primitiveNormalize},
	{(void*)_m, "primitiveSubFloat64Array\000\000", (void*)primitiveSubFloat64Array},
	{(void*)_m, "primitiveSubScalar\000\000", (void*)primitiveSubScalar},
	{(void*)_m, "primitiveSum\000\000", (void*)primitiveSum},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveAddFloat64ArrayAccessorDepth = 0;
signed char primitiveAddScalarAccessorDepth = 0;
signed char primitiveAtAccessorDepth = 0;
signed char primitiveAtPutAccessorDepth = 0;
signed char primitiveDivFloat64ArrayAccessorDepth = 0;
signed char primitiveDivScalarAccessorDepth = 0;
signed char primitiveDotProductAccessorDepth = 0;
signed char primitiveEqualAccessorDepth = 0;
signed char primitiveFromFloatArrayAccessorDepth = 0;
signed char primitiveHashArrayAccessorDepth = 0;
signed char primitiveLengthAccessorDepth = 0;
signed char primitiveMulFloat64ArrayAccessorDepth = 0;
signed char primitiveMulScalarAccessorDepth = 0;
signed char primitiveNormalizeAccessorDepth = 0;
signed char primitiveSubFloat64ArrayAccessorDepth = 0;
signed char primitiveSubScalarAccessorDepth = 0;
signed char primitiveSumAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
