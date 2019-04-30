################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/entity.c \
/home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/food.c \
/home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/score.c \
/home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/world.c 

OBJS += \
./src/sources/entity.o \
./src/sources/food.o \
./src/sources/score.o \
./src/sources/world.o 

C_DEPS += \
./src/sources/entity.d \
./src/sources/food.d \
./src/sources/score.d \
./src/sources/world.d 


# Each subdirectory must supply rules for building sources it contributes
src/sources/entity.o: /home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/entity.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../project_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sources/food.o: /home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/food.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../project_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sources/score.o: /home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/score.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../project_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sources/world.o: /home/jacoboffersen/Repos/EmbeddedProject/src/project/src/sources/world.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../project_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


