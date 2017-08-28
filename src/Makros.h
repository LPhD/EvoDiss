#ifndef MAKROS_H_
#define MAKROS_H_

void testMakros();

#define MAKRO(y) MAKRO2(y##1)
#define MAKRO2(y) MAKRO3(y##2)
#define MAKRO3(y) y##3

#define BUBBLE2 BUBBLE

#endif /* MAKROS_H_ */
