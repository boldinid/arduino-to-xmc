/*
 * Main.c
 *
 */

#define ARDUINO
#define ARDUINO_MAIN
#include "Arduino.h"

#include <XMC1100.h>		//SFR declarations of the selected device
#include <DAVE3.h>

// #include Arduino HEADER FILES.
#include "pins_arduino.h"
#include "wiring_digital.h"
#include "wiring_time.h"
#include "wiring_clock.h"

#include <stdio.h>

/**
 * @brief This function will transmit the input data to PC Hyperterminal
 *
 * @param[in]: p start address of character buffer
 * @return void
 * */
void uart_printf(const char *p)
{
	while(*p){
		while( 0 != ((UART001_Handle0.UartRegs->TRBSR) & (USIC_CH_TRBSR_TFULL_Msk)));
		UART001_WriteData(UART001_Handle0,*p);
		p++;
	}

}

int main(void)
{

	/*
	  *  Wiring Initialization
	  */
	wiring_digital_init();
	wiring_analog_init();

	/*
	  *  Periferals Initialization
	  */
	DAVE_Init();

	// Arduino's main() function just calls setup() and loop()....
	setup();
	while (1) {
		loop();
		//yield();
	}
}

//****************************************************************************
// 							       ARDUINO SKETCH
//****************************************************************************

/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 7 has a pushbutton attached to it. Give it a name:
int pushButton = 7;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 19200 bits per second:
//  Serial.begin(19200);  --> already done by DAvE

	// make the pushbutton's pin an input:
	pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
	// read the input pin:
	int buttonState = digitalRead(pushButton);
	// print out the state of the button:
	if (buttonState)
		uart_printf("ON\r\n");
	else
		uart_printf("OFF\r\n");

	delay(1000);        // delay in between reads for stability
}

//****************************************************************************
// 							       END OF FILE
//****************************************************************************
