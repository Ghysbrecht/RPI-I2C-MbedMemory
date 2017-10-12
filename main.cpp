#include <iostream>
#include <cstdio>
#include "lib/Mbed_Eeprom.h"
#include <unistd.h>

int main(void){
  std::cout << "Starting I2C program" << std::endl;


  Mbed_Eeprom eeprom((char*)"/dev/i2c-1", 0x12);

  //Wait a second before doing things
  sleep(3);

  //Printing the memory to serial of Mbed
  std::cout << "Printing out data...:" << std::endl;
  eeprom.print();

  //Wait a second before doing things
  sleep(3);

  //Pushing 4 bytes to the first memory address
  std::cout << "Writing to memory...:" << std::endl;
  char buffer[4] = { 'd', 'o', 'g', 'o' };
  eeprom.push(0, buffer);

  //Wait a second before doing things
  sleep(3);

  //Setting the address pointer
  std::cout << "Setting pointer to 0..." << std::endl;
  eeprom.pull(0);

  //Wait a second before doing things
  sleep(3);

  //Reading from that address
  std::cout << "Reading data from memory..." << std::endl;
  char buffer2[5];
  eeprom.readBytes(buffer2, sizeof(buffer2));

  //Wait a second before doing things
  sleep(3);

  //Printing out data
  std::cout << "Data received:" << std::endl;
  unsigned int i;
  for(i=0; i < sizeof(buffer2); i++) std::cout << (buffer2[i]) << std::endl;

  //Wait a second before doing things
  sleep(3);

  //Print the memory again
  std::cout << "Printing out data..." << std::endl;
  eeprom.print();

  //Wait a second before doing things
  sleep(3);

  //Clear the memory
  std::cout << "Clearing..." << std::endl;
  eeprom.clear();

  std::cout << "End of program" << std::endl;

  return 0;
}
