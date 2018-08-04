#pragma once

#include "ofMain.h"



class threadTimer : public ofThread {
private:
    ofThreadChannel<int> timeChannel;
    int startTime;
    int finTime;
    bool bRunning;

protected:
    void threadedFunction() {
        while (isThreadRunning()) {
            int t;
            if (timeChannel.tryReceive(t)) {
                startTime  = t;
                bRunning = true;
            }
            if (bRunning) {
                if (ofGetElapsedTimeMillis() - startTime > finTime) {
                    bRunning = false;
                    bool isFin = true;
                    ofNotifyEvent(eFin, isFin);
                    cout<<"[threadTimer] passed "<<finTime<<" millis !!"<<endl;
                }
            }
        }
    }
public:
    ofEvent<bool> eFin;
    threadTimer():startTime(0),finTime(0),bRunning(false) {}
    virtual~threadTimer() {
        timeChannel.close();
        waitForThread(true);
    }

    void setTimer(int start, int fin) {
        timeChannel.send(start);
        finTime = fin;
    }
    void start(bool reset=true){
        if(reset){ setTimer(ofGetElapsedTimeMillis(),finTime); }
        bRunning = true;
        if(!isThreadRunning()){
            startThread();
            cout<<"start"<<endl;
        }
    }
    void stop() {
        bRunning = false;
        if(isThreadRunning()) {
            stopThread();
            cout<<"stop"<<endl;
        }
    }
    bool isRunning(){ return bRunning; }
};



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

    threadTimer timer;

    void action(bool &b){
        if(b){
            cout<<"--- ACTION!! ---"<<endl;
            timer.setTimer(ofGetElapsedTimeMillis(), 3000);
        }
    }
};
