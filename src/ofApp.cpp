#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1920, 1080);
    
    ofSetBackgroundAuto(false);
//    ofHideCursor();
    
    index = 0;
    for(int i = 0; i < IMAGE_NUM; i++) {
        image[i].load(ofToString(i) + ".png");
    }
    is_show_information = true;
    
    // osc setup
    osc_sender.setup(HOST, PORT);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::image_update(int num){
    index = num;
    
    // osc send
    ofxOscMessage m;
    m.setAddress("/photon");
    m.addIntArg(index);
    osc_sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    image[index].draw(ofGetWidth()*0.5 - ofGetHeight()*0.5, 0, ofGetHeight(), ofGetHeight());

    if(is_show_information) {
        ofDrawBitmapStringHighlight("press ' ' : toggle information", 20, 20);
        ofDrawBitmapStringHighlight("press 'i' : increase image index", 20, 40);
        ofDrawBitmapStringHighlight("press 'd' : decrease image index", 20, 60);
        ofDrawBitmapStringHighlight("press 'r' : randomize image index", 20, 80);
        ofDrawBitmapStringHighlight("press 'f' : toggle full screen", 20, 100);
    }
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()) , ofGetMouseX(), ofGetMouseY());
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'r':
            image_update(int(ofRandom(IMAGE_NUM)));
            break;
        case 'i':
            index++;
            if(index >= IMAGE_NUM) {
                index = 0;
            }
            image_update(index);
            break;
        case 'd':
            index--;
            if(index < 0) {
                index = IMAGE_NUM-1;
            }
            image_update(index);
            break;
        case ' ':
            is_show_information = !is_show_information;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
