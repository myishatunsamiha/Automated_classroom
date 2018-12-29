Procedure of enrollment

(Adafruit-Fingerprint-Sensor-Library-master.zip) unzip or extract this zip folder
rename your folder
Move the folder to your Arduino IDE installation libraries folder
Reopen your Arduino IDE


or, 
You can go to Tools in the Arduino IDE (Tools->Manage Library->search for your desired library(here Adafruit-Fingerprint-Sensor-Library)-> if the library is built in arduino IDE, just press install)
Then go to (File > Examples > Adafruit Fingerprint Sensor Library > Enroll)
go to Tools->select the port(if not selected)-> Get Board info->press ok
verify the code(it may fail to compile for once or twice, but if all the connections are okay it will surely compile successfully) and upload
go to serial monitor which is on the right corner of the screen, click there and see the output in the serial monitor
give your fingerprint with ID#(1-127, for example 1#, 2#)->send->place the finger untill the scanner scan and store your fingerprint successfully


Procedure of Testing if this scanner works

Download (sketch_Check_MY_fingerprint.ino) and copy the code
go to File->New file(remove whatever is written here)-> paste the code here-> save the code in sketchBook
go to Tools->select the port(if not selected)-> Get Board info->press ok
verify the code(it may fail to compile for once or twice, but if all the connections are okay it will surely compile successfully) and upload
go to the serial monitor, place your finger and check if your access is authorized or not
