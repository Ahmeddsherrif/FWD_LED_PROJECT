################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/Drivers/GPIO.obj: D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/Drivers/GPIO.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Code Composer/FWD_LED_PROJECT" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM" --include_path="D:/EmbeddedSystems/COTS/" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/Drivers/GPIO.d_raw" --obj_directory="src/Drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/Drivers/interrupts.obj: D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/Drivers/interrupts.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Code Composer/FWD_LED_PROJECT" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM" --include_path="D:/EmbeddedSystems/COTS/" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/Drivers/interrupts.d_raw" --obj_directory="src/Drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/Drivers/systimer.obj: D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/Drivers/systimer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Code Composer/FWD_LED_PROJECT" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM" --include_path="D:/EmbeddedSystems/COTS/" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/Drivers/systimer.d_raw" --obj_directory="src/Drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


