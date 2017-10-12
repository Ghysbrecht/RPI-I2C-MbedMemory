#pragma once

class Mbed_Eeprom{

  private:
    char *filename;
    int addr;
    int file_i2c;


  public:
    //Filename of I2C bus file, Address of I2C slave
    Mbed_Eeprom(char *filename, int addr);

    //Write 4 bytes to the memory address
    void push(int addr, char *buffer);

    //Set the internal pointer to addr
    void pull(int addr);

    //Read the 4 bytes at the current pointer location
    void readBytes(char *buffer, int length);

    //Clear the memory
    void clear();

    //Print the memory to slave UART console
    void print();

  private:
    void initBus(char *filename, int addr);
    void busWrite(char *buffer, int length);
    void busRead(char *buffer, int length);
};
