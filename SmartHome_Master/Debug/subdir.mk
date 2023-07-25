################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Keypad.c \
../LCD.c \
../SPI.c \
../eeprom.c \
../i2c.c \
../main.c 

OBJS += \
./Keypad.o \
./LCD.o \
./SPI.o \
./eeprom.o \
./i2c.o \
./main.o 

C_DEPS += \
./Keypad.d \
./LCD.d \
./SPI.d \
./eeprom.d \
./i2c.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


