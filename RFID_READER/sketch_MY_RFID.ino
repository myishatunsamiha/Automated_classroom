/*
 * Electro Maniac
 */

#include <MFRC522.h> // for the RFID
#include <SPI.h> // for the RFID and SD card module
#include <RTClib.h> // for the RTC

// define pins for RFID
#define CS_RFID 10
#define RST_RFID 9




// Instance of the class for RFID
MFRC522 rfid(CS_RFID, RST_RFID); 

// Variable to hold the tag's UID
String uidString;

// Instance of the class for RTC
RTC_DS1307 rtc;

// Define check in time
const int checkInHour = 11;
const int checkInMinute = 5;

//Variable to hold user check in
int userCheckInHour;
int userCheckInMinute;

// Pins for LEDs and buzzer
const int redLED = 6;
const int greenLED = 7;
const int buzzer = 5;

void setup() {
  
  // Set LEDs and buzzer as outputs
  pinMode(redLED, OUTPUT);  
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Init Serial port
  Serial.begin(9600);
  while(!Serial); // for Leonardo/Micro/Zero
  
  // Init SPI bus
  SPI.begin(); 
  // Init MFRC522 
  rfid.PCD_Init(); 


  // Setup for the RTC  
  if(!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }
  else {
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  if(!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
}

void loop() {
  //look for new cards
  if(rfid.PICC_IsNewCardPresent()) {
     Serial.println();
     Serial.println();
    readRFID();
    logCard();
   // verifyCheckIn();
  }
  delay(10);
}

void readRFID() {
  rfid.PICC_ReadCardSerial();
  Serial.print("Tag UID: ");
  uidString = String(rfid.uid.uidByte[0]) + " " + String(rfid.uid.uidByte[1]) + " " + 
    String(rfid.uid.uidByte[2]) + " " + String(rfid.uid.uidByte[3]);
  Serial.println(uidString);

  if(uidString == "209 133 235 137" || uidString == "234 169 82 211"){
    Serial.println("Authorized access");
     verifyCheckIn();
  }else{
    Serial.println(" Access denied");
    delay(3000);  
  }
  // Sound the buzzer when a card is read
  tone(buzzer, 2000); 
  delay(100);        
  noTone(buzzer);
  
  delay(100);
}

void logCard() {

    

    DateTime now = rtc.now();

    // Print time on Serial monitor
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.println(now.minute(), DEC);


    // Save check in time;
    userCheckInHour = now.hour();
    userCheckInMinute = now.minute();
    Serial.print("userCheckInHour: ");
    Serial.println(userCheckInHour);
    Serial.print("userCheckInMinute: ");
    Serial.println(userCheckInMinute);

}

void verifyCheckIn(){
  if((userCheckInHour < checkInHour)||((userCheckInHour==checkInHour) && (userCheckInMinute <= checkInMinute))){
    digitalWrite(greenLED, HIGH);
    delay(2000);
    digitalWrite(greenLED,LOW);
    Serial.println("You're welcome!");
  }
  else{
    digitalWrite(redLED, HIGH);
    delay(2000);
    digitalWrite(redLED,LOW);
    Serial.println("You are late...");
  }
}
