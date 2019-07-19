# arduino-tv-remote
project (libraray and arduino project) for controll my tv, tv box, led strip etc.
#!!! Write your SSID and password !!!
#Description
this project is for my smart-home prject include program for recieve signal from remote. This program is from web page https://www.instructables.com/id/How-to-control-your-TV-with-an-Arduino/.

Include program for nodeMCU. This program allow nodeMCU connect to the internet and controll devices trought IR diode.

In library arduino-remote is all signals for controll devices.

Also in project is php script who tranfrom raw data to functions and create class for arduino library.

#How to using program for recieve signal 
program upload to arduino and connect IR Reciever on pin 2 and you can start measuring. In serial monitor windows you get data after pressing button on remote.

After measuring raw data you can get to txt file remote-signal.txt and run script index.php.
Script generate two file result-arduino-code.txt and result-arduino-code-header.txt first file contain function of all defined button in file remote-signal.txt. In file result-arduino-code-header.txt you get class define for lirbrary.

#structure of file remote-signal.txt
On first line you must name of class
after class declaration is line with start text with function name separate with ","
start,nameOfFunction
after this start line is raw data from measuring
and of function create with line with stop tag
after stop tag you can declare another function with start line



