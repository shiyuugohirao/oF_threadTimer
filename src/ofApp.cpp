#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener(timer.eFin, this, &ofApp::action);
    timer.setTimer(ofGetElapsedTimeMillis(), 3000);
    timer.start();
}

//--------------------------------------------------------------
void ofApp::update(){

    //--- too heavy process ---//
    int i=0;
    while(i<100000){
        ofGetElapsedTimeMillis();
        i++;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("fps : " + to_string(ofGetFrameRate()), 10, 10);
    ofDrawBitmapString(timer.isRunning()?"Running":"Stopping", 10, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    timer.stop();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    timer.start();
}
