################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/GPIO_Toggel_LEDs_Using_Push_Button.c 

OBJS += \
./APP/GPIO_Toggel_LEDs_Using_Push_Button.o 

C_DEPS += \
./APP/GPIO_Toggel_LEDs_Using_Push_Button.d 


# Each subdirectory must supply rules for building sources it contributes
APP/GPIO_Toggel_LEDs_Using_Push_Button.o: ../APP/GPIO_Toggel_LEDs_Using_Push_Button.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/APP/inc" -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/GPIO_Toggel_LEDs_Using_Push_Button.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

