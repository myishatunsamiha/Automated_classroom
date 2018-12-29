
Procedure of including library of Rfid-RC522 and RTC(1307)

(libraries.zip) unzip or extract this zip folder
rename your folder
Move the folder to your Arduino IDE installation libraries folder
Reopen your Arduino IDE


or, 
You can go to Tools in the Arduino IDE (Tools->Manage Library->search for your desired library(here MFRC522)-> if the library is built in arduino IDE, just press install)
Again, go to Tools in the Arduino IDE (Tools->Manage Library->search for your desired library(here RTClib)-> if the library is built in arduino IDE, just press install)

Procedure of Testing if the total system works


Download (sketch_MY_RFID.ino) and copy the code
go to File->New file(remove whatever is written here)-> paste the code here-> save the code in sketchBook
go to Tools->select the port(if not selected)-> Get Board info->press ok
verify the code(it may fail to compile for once or twice, but if all the connections are okay it will surely compile successfully) and upload
go to the serial monitor, place your card or key infront of the rfid reader and check if your access is authorized or not
