#ifndef SERIAL_H_INCLUDED
#define SERIAL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <SDL.h>

FILE *arduinoIN;


int SerialOpen();
int SerialRead(char buffer[]);
void SerialClose();

#endif // SERIAL_H_INCLUDED