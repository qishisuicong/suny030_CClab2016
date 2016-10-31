#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(255);
    
    for (int i = 0; i<20;i++){
        Ball tempball;
        tempball.setInit();
        balls.push_back(tempball);
        balls[i].color = ofColor(ofRandom(190,240),ofRandom(190,240),ofRandom(190,240),ofRandom(220,250));
    }
  
//    cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));


    

}

//--------------------------------------------------------------
void ofApp::update(){
        for (int i = 0; i<20;i++){
        balls[i].update();

    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){


    for (int i = 0; i<20;i++){
        ofSetColor( balls[i].color );
        balls[i].draw();

        string colour = "Color: " + ofToString(balls[i].color);
        ofDrawBitmapString(colour, balls[i].mPos + ofVec2f(40,-20));
        if(i > 0){
        ofDrawLine(balls[i].mPos,balls[i-1].mPos);
        }
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


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
    for (int i = 0; i<20;i++){
        balls[i].mouse(x,y);
        balls[i].color = ofColor(ofRandom(190,240),ofRandom(190,240),ofRandom(190,240),ofRandom(220,250));
    }
    
    

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
