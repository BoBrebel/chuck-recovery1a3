#include "Serial.h"

FILE *arduinoIN;

int SerialOpen()
{
    arduinoIN = fopen("/dev/ttyACM0","r");
    return arduinoIN!=NULL ;
}

int SerialRead(char buffer[])
{
    int i=0,len;
    if(arduinoIN)
    {
        len=fgetc(arduinoIN);
        while(i<len)
        {
            while((buffer[i]=fgetc(arduinoIN))!=EOF)
            {
                i++;
            }
        }
    }
    return i;
}
void SerialClose()
{
    fclose(arduinoIN);
    fclose(arduinoOUT);
    arduinoIN=NULL;
    arduinoOUT=NULL;
}