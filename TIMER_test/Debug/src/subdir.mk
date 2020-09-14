################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/dac.c \
../src/distance_sensor.c \
../src/gpio_set.c \
../src/interruptions.c \
../src/leds_setup.c \
../src/main.c \
../src/scu_set.c \
../src/sysinit.c \
../src/tec_setup.c \
../src/timers.c \
../src/uart_18xx_43xx.c \
../src/vibrator.c \
../src/zones.c 

OBJS += \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/dac.o \
./src/distance_sensor.o \
./src/gpio_set.o \
./src/interruptions.o \
./src/leds_setup.o \
./src/main.o \
./src/scu_set.o \
./src/sysinit.o \
./src/tec_setup.o \
./src/timers.o \
./src/uart_18xx_43xx.o \
./src/vibrator.o \
./src/zones.o 

C_DEPS += \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/dac.d \
./src/distance_sensor.d \
./src/gpio_set.d \
./src/interruptions.d \
./src/leds_setup.d \
./src/main.d \
./src/scu_set.d \
./src/sysinit.d \
./src/tec_setup.d \
./src/timers.d \
./src/uart_18xx_43xx.d \
./src/vibrator.d \
./src/zones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -D__REDLIB__ -I"C:\Users\sasha\Documents\MCUXpressoIDE_11.1.1_3241\workspace\TIMER_test\inc" -I"C:\Users\sasha\Documents\MCUXpressoIDE_11.1.1_3241\workspace\Practica_Filtro_FIR.zip_expanded\lpc_chip_43xx\inc" -I"C:\Users\sasha\Documents\MCUXpressoIDE_11.1.1_3241\workspace\Practica_Filtro_FIR.zip_expanded\lpc_chip_43xx\inc\usbd" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


