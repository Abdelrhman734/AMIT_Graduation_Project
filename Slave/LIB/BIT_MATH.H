/*
 * BIT_MATH.H
 *
 *  Created on: May 28, 2021
 *      Author: Aya
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BIT_NUMBER) VAR=VAR |(1<<BIT_NUMBER)
#define CLR_BIT(VAR,BIT_NUMBER) VAR=VAR &(~(1<<BIT_NUMBER))
#define TOG_BIT(VAR,BIT_NUMBER) VAR ^=(1<<BIT_NUMBER)
#define GET_BIT(VAR,BIT_NUMBER) (1&(VAR>>BIT_NUMBER))





#endif /* BIT_MATH_H_ */
