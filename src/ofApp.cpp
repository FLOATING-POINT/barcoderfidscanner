#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	bcScanner.setup(16);
	ofAddListener(bcScanner.barcodeReceived, this, &ofApp::barcodeEvent);
	//ofAddListener(bcScanner.invalidBarcodeReceived, this, &ofApp::invalidBarcodeEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
	bcScanner.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	bcScanner.draw();

}
void ofApp::barcodeEvent(bool& e) {

	cout << "Barcode received " << bcScanner.getLastBarcode() << endl;
	cout << "Is valid Barcode? " << bcScanner.isValidRead() << endl;

}
void ofApp::invalidBarcodeEvent(bool& e) {

	

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	bcScanner.codeReceived(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	cout << "msg " << msg.message << endl;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}