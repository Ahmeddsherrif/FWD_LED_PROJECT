################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/APP/main.obj: D:/EmbeddedSystems/COTS/Application/FWD_First_Project/main.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/EmbeddedSystems/COTS/Application/FWD_First_Project/Service/inc" --include_path="D:/Code Composer/FWD_LED_PROJECT" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="D:/EmbeddedSystems/COTS/Lib" --include_path="D:/EmbeddedSystems/COTS/HAL/inc" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/TargetHeader" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/Drivers/inc" --include_path="D:/EmbeddedSystems/COTS/Lib" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/TargetHeader" --include_path="D:/EmbeddedSystems/COTS/HAL/inc" --include_path="D:/EmbeddedSystems/COTS/MCAL/ARM/ti/TM4C123GH6PM/Drivers/inc" --include_path="D:/EmbeddedSystems/COTS/Application/FWD_First_Project/Service/inc" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/APP/main.d_raw" --obj_directory="src/APP" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


