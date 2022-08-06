################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/GPIO_Toggel_LEDs_Using_Push_Button.c \
../APP/UART_Test_1_Debugging_Using_Polling.c 

OBJS += \
./APP/GPIO_Toggel_LEDs_Using_Push_Button.o \
./APP/UART_Test_1_Debugging_Using_Polling.o 

C_DEPS += \
./APP/GPIO_Toggel_LEDs_Using_Push_Button.d \
./APP/UART_Test_1_Debugging_Using_Polling.d 


# Each subdirectory must supply rules for building sources it contributes
APP/GPIO_Toggel_LEDs_Using_Push_Button.o: ../APP/GPIO_Toggel_LEDs_Using_Push_Button.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/APP/inc" -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/GPIO_Toggel_LEDs_Using_Push_Button.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
APP/UART_Test_1_Debugging_Using_Polling.o: ../APP/UART_Test_1_Debugging_Using_Polling.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/APP/inc" -I"C:/Users/MAHMOUD ABDALHADY/Desktop/KhloudMohamed/Embedded_Diploma/Programming/Last_Update/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/UART_Test_1_Debugging_Using_Polling.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

