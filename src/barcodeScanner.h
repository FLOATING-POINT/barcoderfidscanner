#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class barcodeScanner : public ofBaseApp{
	public:
		void setup(int barcodeLength);
		void update();
		void draw();
		
		void codeReceived(int key);
		string getLastBarcode();	
		bool isValidRead();

		string lastBarcode;

		vector<int > last_inputs;

		int inputCount;
		bool invalid_read;
		bool bLastReadValid;

		string allinputs;
		int inputLength;
		int validCharCount;

		bool hasBarcodeReceived;
		ofEvent<bool> barcodeReceived;
		ofEvent<bool> invalidBarcodeReceived;
};
