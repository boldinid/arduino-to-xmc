# arduino-to-xmc
Automatically exported from code.google.com/p/arduino-to-xmc

Documentation and Examples in https://code.google.com/p/arduino-to-xmc/

Arduino™ Wiring language is a widely used language for embedded system programming. It is very easy and immediate to create little microcontrollers applications such as to control servos, motors, inputs, outputs, displays, etc.. . This project has the aim to port the Arduino™ Wiring language to the XMC microcontrollers. I've started the project by using the Infineon XMC1100. Then I've continued by using the Infineon XMC1300 (see details...). Now I'm testing the XMC4500 and the XMC2GO as well...

Why Arduino to XMC?
I've started this porting project because I like very much the simplicity and intuitive Arduino Wiring language, but I'm not confortable with the absence of a professional debug (Arduino 'serial.print()' is good only for basic debug purposes). Merging Arduino to XMC I'll get the best of both environments:

ARM 32-bit power;
Arduino's simplicity;
Arduino's various examples;
Arduino's various libraries;
XMC professional Integrated Development Environment (IDE), Eclipse based;
XMC professional debug environment (Tasking plug-in);
XMC application based code generator (DAvE).
