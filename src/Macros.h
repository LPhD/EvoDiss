#ifndef MACROS_H_
#define MACROS_H_

#define MAKRO(y) MAKRO2(y##1)
#define MAKRO2(y) MAKRO3(y##2)
#define MAKRO3(y) y##3


// Macros to support option testing (from Marlin)
#define _CAT(a, ...) a ## __VA_ARGS__
#define SWITCH_ENABLED_false 0
#define SWITCH_ENABLED_true  1
#define SWITCH_ENABLED_0     0
#define SWITCH_ENABLED_1     1
#define SWITCH_ENABLED_      1
#define ENABLED(b) _CAT(SWITCH_ENABLED_, b)
#define DISABLED(b) (!_CAT(SWITCH_ENABLED_, b))

void testMacros();

#endif /* MACROS_H_ */
