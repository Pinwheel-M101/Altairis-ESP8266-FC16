#include <LedControlSPIESP8266.h>

#ifndef _FC16_h
#define _FC16_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class FC16 {

private:

	int _maxDevices;
	int _maxColumns;
	LedControl _lc;
	char* _text;
	int _textSize = 0;
	int _textColumns = 0;
	int _curCharIndex = 0;
	int _curCharBit = 0;
	bool _isScrolling = false;
	int _updateCount = 0;
   bool _addressingDisplaysBackward;

	byte reverseBits(byte b);

	void shutdown(bool status);

public:
   /**
     addressingDisplaysBackward = true  => address 0 is last 8x8 display matrix block (one of the type matrix display module)
     addressingDisplaysBackward = false => address 0 is first 8x8 display matrix block (second of the type matrix display module)
   */
	FC16(int csPin, int numDevices = 1, bool addressingDisplaysBackward = true);

	void begin();

	void end();

	int getColumnCount();

	int getTextColumns();

	void setColumn(int col, byte value);

	void setLed(int row, int col, bool state);

	void clearDisplay();

	void setIntensity(int intensity);

	void setText(char* text);

	void setBitmap(byte* bitmap);

	void setClock(byte part1, byte part2, byte part3, int offset = 0, bool showDots = true);

	bool update();

};

#endif

