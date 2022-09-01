/*
 * Platform_Types.h
 *
 * Created: 9/1/2022 5:17:34 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char               uint8;
typedef unsigned short              uint16;
typedef unsigned int                uint32;
typedef unsigned long long int      uint64;


typedef signed char                 sint8;
typedef signed short                sint16;
typedef signed int                  sint32;
typedef signed long long int        sint64;


typedef volatile unsigned char              vuint8_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile unsigned long long int     vuint64_t;


typedef volatile signed char                vsint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile signed long long int       vsint64_t;


typedef float       float32_t;
typedef double      float64_t;

typedef enum
{
	false,
	ture,
}bool;


#define NULL ((void *)0)




#endif /* PLATFORM_TYPES_H_ */