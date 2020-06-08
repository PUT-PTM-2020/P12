################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Robo_v7.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Robo_v7.list \

OBJCOPY_BIN += \
Robo_v7.bin \


# All Target
all: Robo_v7.elf secondary-outputs

# Tool invocations
Robo_v7.elf: $(OBJS) $(USER_OBJS) C:\Users\lewy\STM32CubeIDE\robo_v7_camera\Robo_v7\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "Robo_v7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\lewy\STM32CubeIDE\robo_v7_camera\Robo_v7\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Robo_v7.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Robo_v7.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Robo_v7.list"
	@echo 'Finished building: $@'
	@echo ' '

Robo_v7.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Robo_v7.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
