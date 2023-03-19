# Iot-security-using-RFID-card
project uses Arduino UNO Microcontroller and Its IDE .

## Projects-Requirements

> Arduino IDE [download-link](https://www.arduino.cc/en/software)<br>
> Arduino UNO Micro. [Purchase](https://www.indiamart.com/proddetail/arduino-uno-r3-20489886862.html)<br>

## Libraries

> SPI.h<br>
   This library allows you to communicate with SPI devices, with the Arduino as the controller device. <br>
   This library is bundled with every Arduino platform, so you do not need to install the library separately.<br>
   [download-link](https://electronoobs.com/eng_arduino_sd.php)<br>
   
> MRFC522.h<br>
   Read and write different types of Radio-Frequency IDentification (RFID) cards on your <br>
   Arduino using a RC522 based reader connected via the Serial Peripheral Interface (SPI) interface.<br>
   [download-link](https://www.arduinolibraries.info/libraries/mfrc522)<br>
   
## Presentation<br>
  ![persenation](https://github.com/yashdargan/Iot-security-using-RFID-card/blob/main/iot%20security.pdf)

## Code
```
#include <SPI.h>// This library allows you to communicate with SPI devices
#include<MFRC522.h>//Read and write different types of Radio-Frequency IDentification (RFID)

#define ss_pin 10
#define rst_pin 9
const int buzzer=8; 
MFRC522 mfrc522(ss_pin,rst_pin); 
String allowedonly="5173708B";

int readsuccess;
byte readcard[4];
char str[32]="";
String struid; 
void setup() {

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 8 as an output


  Serial.println("....Welcome to RFID World...\n ONLY For Identification Card \n");
  delay(2500);
  Serial.println("Please Use Tag FOR ENTRY\n");
  
}

void loop() {
  // put your main code here, to run rep
  readsuccess=getid();
  if(readsuccess)
  { tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);  
    noTone(buzzer);  
    Serial.println((String)"This Is Identification number is "+struid);
      if(struid==allowedonly)
         allowing(struid);
      else
      Serial.println("Sorry! You are not allowed");
          
  
  }
}
int getid(){  
  if(!mfrc522.PICC_IsNewCardPresent()){
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return 0;
  }
 
  
  Serial.println("The scaning of Card complete");
  
  for(int i=0;i<4;i++){
    readcard[i]=mfrc522.uid.uidByte[i]; //storing the UID of the tag in readcard
    array_to_string(readcard, 4, str);
    struid = str;
  
  }
  mfrc522.PICC_HaltA();
  return 1;
}

String allowing(String str)
{ 
  Serial.println("allowed!! Welcome master");
}
// --------------------------------------------------------------------
void array_to_string(byte array[], unsigned int len, char buffer[])
{
    for (unsigned int i = 0; i < len; i++)
    {
        byte nib1 = (array[i] >> 4) & 0x0F;
        byte nib2 = (array[i] >> 0) & 0x0F;
        buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
        buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
    }
    buffer[len*2] = '\0';
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About

```
