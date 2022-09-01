/*
 * Util.h
 *
 * Created: 9/1/2022 5:16:32 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef UTIL_H_
#define UTIL_H_

#define	GET_BIT(reg,bit)				(((reg)>>(bit))&1)
#define SET_BIT(reg,bit)				(reg|=(1<<bit))
#define CLR_BIT(reg,bit)				(reg&=~(1<<bit))
#define TOGGLE_BIT(reg,bit)			    (reg^=(1<<bit))



#endif /* UTIL_H_ */