/*
 * Utils.h
 *
 * Created: 7/25/2022 2:58:15 AM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(reg,bit)			(reg = reg |(1<<bit))
#define Clear_Bit(reg,bit)		    (reg = reg &~(1<<bit))
#define Read_Bit(reg,bit)			((reg>>bit)&1)
#define Toggel_Bit(reg,bit)         (reg = reg^(1<<bit))


#endif /* UTILS_H_ */