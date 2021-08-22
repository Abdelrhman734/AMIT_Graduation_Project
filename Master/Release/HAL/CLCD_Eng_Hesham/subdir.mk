################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/CLCD_Eng_Hesham/CLCD_program.c 

OBJS += \
./HAL/CLCD_Eng_Hesham/CLCD_program.o 

C_DEPS += \
./HAL/CLCD_Eng_Hesham/CLCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/CLCD_Eng_Hesham/%.o: ../HAL/CLCD_Eng_Hesham/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


