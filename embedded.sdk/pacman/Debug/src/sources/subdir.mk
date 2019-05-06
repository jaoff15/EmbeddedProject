################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sources/entity.c \
../src/sources/food.c \
../src/sources/game.c \
../src/sources/io_devices.c \
../src/sources/led_matrix.c \
../src/sources/movement.c \
../src/sources/pacman.c \
../src/sources/score.c \
../src/sources/world.c 

OBJS += \
./src/sources/entity.o \
./src/sources/food.o \
./src/sources/game.o \
./src/sources/io_devices.o \
./src/sources/led_matrix.o \
./src/sources/movement.o \
./src/sources/pacman.o \
./src/sources/score.o \
./src/sources/world.o 

C_DEPS += \
./src/sources/entity.d \
./src/sources/food.d \
./src/sources/game.d \
./src/sources/io_devices.d \
./src/sources/led_matrix.d \
./src/sources/movement.d \
./src/sources/pacman.d \
./src/sources/score.d \
./src/sources/world.d 


# Each subdirectory must supply rules for building sources it contributes
src/sources/%.o: ../src/sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../pacman_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


