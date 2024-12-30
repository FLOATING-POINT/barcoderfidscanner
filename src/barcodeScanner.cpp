#include "barcodeScanner.h"

//--------------------------------------------------------------
void barcodeScanner::setup(int barcodeLength){

	inputCount = 0;
	inputLength = barcodeLength;

	last_inputs.resize(inputLength);
	for (int i = 0; i < inputLength; i++) {
		last_inputs[i] = 0;
	}

	invalid_read	= false;
	bLastReadValid	= false;
	validCharCount	= 0;

}

//--------------------------------------------------------------
void barcodeScanner::update(){

}

//--------------------------------------------------------------
void barcodeScanner::draw(){

	ofSetBackgroundColor(0);
	
	ofSetColor(255);
	string output_first;
	for (int i = 0; i < last_inputs.size(); i++) {
		output_first += ofToString(last_inputs[i]);
		if (i % 4 == 3) { output_first += "-"; }
	}

	ofDrawBitmapString(output_first, 20, 20);

	
	ofPopMatrix();

}

//--------------------------------------------------------------
void barcodeScanner::codeReceived(int key){

	int code = -1;	

	switch (key) {

	case 48:
		code = 0;
		break;
	case 49:
		code = 1;
		break;
	case 50:
		code = 2;
		break;
	case 51:
		code = 3;
		break;
	case 52:
		code = 4;
		break;
	case 53:
		code = 5;
		break;
	case 54:
		code = 6;
		break;
	case 55:
		code = 7;
		break;
	case 56:
		code = 8;
	case 57:
		code = 9;
		break;
	}

	if (ofInRange(code,0,9)) {
		
		last_inputs[validCharCount] = code;

		validCharCount++;
		invalid_read = false;

		if (validCharCount == inputLength) { // reuse the current one;

			validCharCount	= 0;

		}
	}
	else if(key != 13){
		invalid_read = true;
		validCharCount--;
		if (validCharCount < 0) validCharCount = 0;
	}
	inputCount++;
	if (inputCount > (inputLength+1)) invalid_read = true;

	if (key == 13) { // carriage return which denotes end of sequence
		
		bLastReadValid		= !invalid_read;
		validCharCount		= 0;
		inputCount			= 0;
		invalid_read		= false;
		hasBarcodeReceived	= true;

		ofNotifyEvent(barcodeReceived, hasBarcodeReceived);
			
	}
}
//--------------------------------------------------------------

string barcodeScanner::getLastBarcode() {

	string output;
	for (int i = 0; i < last_inputs.size(); i++) {
		output += ofToString(last_inputs[i]);
	}

	return output;
}

bool barcodeScanner::isValidRead()
{
	return bLastReadValid;
}
