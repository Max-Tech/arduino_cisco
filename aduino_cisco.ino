#include <SoftwareSerial.h>

int temp_data=0;
int ch_temp_data;
SoftwareSerial softSerial(10, 11); 

void setup()
{
 softSerial.begin(9600);

 Serial.begin(9600);
 Serial.println("Hello to Max Cisco Terminal v1");

     softSerial.print("\r");
     softSerial.print("\n");
}


void loop() 
{
  if (softSerial.available())
    {
     int data = softSerial.read();
     Serial.print(char(data));
     
      char comm[] = "Switch>";
  
      for (int i=0;i<sizeof(comm); i++) {  
        if ( i-1 < 0 ) {ch_temp_data = 0;}else{ch_temp_data = comm[i-1]-0;}
        if (temp_data == ch_temp_data and data == comm[i]-0) {temp_data = comm[i]-0;}
        if (temp_data == ch_temp_data and data == comm[sizeof(comm)-2]-0) {
      Serial.print("*yes*");
        }
      }  
    }
  if (Serial.available())
    {
       char data = Serial.read();
       softSerial.print(data);    
    }
}

