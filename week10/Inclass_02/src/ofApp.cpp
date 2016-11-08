#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    mGravity = ofVec2f(0.f,0.02f);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i<mSystems.size(); i++){
        mSystems[i].update(mGravity);
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<mSystems.size(); i++){
        mSystems[i].draw(colorp);
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
    colorp = ofColor(ofRandom(100,240),ofRandom(100,240),ofRandom(100,240));
    ParticleSystem system(ofVec2f(x,y));
    mSystems.push_back(system);
    
    

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
