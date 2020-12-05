################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Final_D2.axf

# Tool invocations
Final_D2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\sasha\Documents\MCUXpressoIDE_11.1.1_3241\workspace\Practica_Filtro_FIR.zip_expanded\lpc_chip_43xx\Debug" -Xlinker -Map="Final_D2.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "Final_D2_Debug.ld" -o "Final_D2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Final_D2.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Final_D2.axf"; # arm-none-eabi-objcopy -v -O binary "Final_D2.axf" "Final_D2.bin" ; # checksum -p LPC4337 -d "Final_D2.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
