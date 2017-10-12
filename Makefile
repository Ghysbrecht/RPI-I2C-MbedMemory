# The C++ compiler
PREFIX=/home/thomas/rpi-tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
CC=$(PREFIX)g++

# The compiler flags
CFLAGS=-Wall -c

#
EXECUTABLE=hello

all: $(EXECUTABLE)

$(EXECUTABLE): main.o Mbed_Eeprom.o
	$(CC)  main.o Mbed_Eeprom.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Mbed_Eeprom.o: lib/Mbed_Eeprom.cpp
	$(CC) $(CFLAGS) lib/Mbed_Eeprom.cpp


clean:
	rm -f *.o $(EXECUTABLE)
