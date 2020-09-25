###############################################################################
# Makefile for the project Line_Follower_using_Analog_IR_Sensor
###############################################################################

## General Flags
PROJECT = Line_Follower_using_Analog_IR_Sensor
MCU = atmega16
TARGET = Line_Follower_using_Analog_IR_Sensor.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=Line_Follower_using_Analog_IR_Sensor.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = Line_Follower_using_Analog_IR_Sensor.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) Line_Follower_using_Analog_IR_Sensor.hex Line_Follower_using_Analog_IR_Sensor.eep Line_Follower_using_Analog_IR_Sensor.lss size

## Compile
Line_Follower_using_Analog_IR_Sensor.o: ../Line_Follower_using_Analog_IR_Sensor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) Line_Follower_using_Analog_IR_Sensor.elf dep/* Line_Follower_using_Analog_IR_Sensor.hex Line_Follower_using_Analog_IR_Sensor.eep Line_Follower_using_Analog_IR_Sensor.lss Line_Follower_using_Analog_IR_Sensor.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

