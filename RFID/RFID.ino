#include <SPI.h>
#include <MFRC522.h> 
#define RESET   9      
#define SS      10       

struct RFIDtag{
  byte uid[4];
  char *Name;
};

struct RFIDtag tags[]{
  {{169,181,236,151},"Card"},
  {{138,120,131,37},"Circle"}
};

byte taglengh = sizeof(tags);
MFRC522 mfrc522(SS, RESET); 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();  
  Serial.println("RFID ready !!!");
  Serial.println("");
}


void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()){
      byte *id = mfrc522.uid.uidByte;  
      byte idSize = mfrc522.uid.size;
      bool tag = false;
      for (byte i = 0; i < taglengh; i++) {
          if(memcmp(tags[i].uid, id , idSize) == 0){
            Serial.println("1");
            tag = true;
            break;
          }
     }
     if(!tag){
      Serial.println("0");     

   }
  }
  mfrc522.PICC_HaltA();
    
  } 
}
