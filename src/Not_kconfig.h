/*
 * Not_kconfig.h
 *
 *  Created on: 24.08.2017
 *      Author: gerling
 */

#ifndef NOT_KCONFIG_H_
#define NOT_KCONFIG_H_


#define MAKRO(y) MAKRO2(y##1)
#define MAKRO2(y) MAKRO3(y##2)
#define MAKRO3(y) y##3

#define SELECT BUBBLE

#endif /* NOT_KCONFIG_H_ */
