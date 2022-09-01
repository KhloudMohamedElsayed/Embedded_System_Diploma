/*
 * Platform_Types.h
 *
 * Created: 8/31/2022 12:24:21 AM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char uint8_t;

typedef unsigned char* ptr_uint8_t;
typedef char* ptr_sint8_t;

typedef void(*PTR_VoidFunVoid_t)(void);
#define NULL_PTR		((void*)(0)

typedef unsigned char E_STATUS_t;
#define E_OK			(E_STATUS_t)(0)
#define E_NOK			(E_STATUS_t)(1)



#endif /* PLATFORM_TYPES_H_ */