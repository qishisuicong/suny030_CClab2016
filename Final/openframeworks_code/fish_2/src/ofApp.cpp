#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofBackground(165,222,228);
    titleCount=170;
    zScale=40;
    noiseXRange=6;
    noiseYRange=6;
    noiseOffset=1;
    cam.setPosition(ofPoint(ofGetWidth(), ofGetHeight(), 700));

    
    
    
    
    for( int i=0; i<fishes; i++){
        myfish[i].setup(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
        
        myfish[i].color = ofColor(ofRandom(0,180),ofRandom(0,230),ofRandom(165,240),80);
        myfish[i].color1 = ofColor(ofRandom(0,250),ofRandom(0,250),ofRandom(165,250),90);
        myfish[i].color2 = ofColor(ofRandom(0,250),ofRandom(0,250),ofRandom(165,250),90);
        myfish[i].color3 = ofColor(ofRandom(0,250),ofRandom(0,250),ofRandom(165,250),90);
        myfish[i].color4 = ofColor(ofRandom(0,250),ofRandom(0,250),ofRandom(165,250),90);
        myfish[i].color5 = ofColor(ofRandom(165,200));
        
    }
  
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    mesh.setMode( OF_PRIMITIVE_LINES );
    mesh2.clear();
    mesh2.setMode( OF_PRIMITIVE_LINES );
    
    float tileSizeY = (float)ofGetHeight()/(titleCount+200);
    float noiseStepY = (float)noiseYRange/titleCount;
    float time=ofGetElapsedTimef();
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {
        
        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = ofNoise(noiseX+noiseOffset, noiseY,time);
            float y1 = 2*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time);
            
            ofFill();
            ofSetColor(255,20);
            mesh.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,0));
            mesh.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,0));
            
        }
        
    }
    
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {
        
        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = 1.5*ofNoise(noiseX+noiseOffset, noiseY,time+0.05);
            float y1 = 1.5*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time+0.05);
            
            ofFill();
            ofSetColor(51,166,184,15);
            mesh2.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,-20));
            mesh2.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,-20));
            
        }
        
    }
    
    noiseOffset+=0.005;
    float area = 200;


    
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(165,222,228);
//     ofBackground(255);
    

    
    cam.begin();
    
    
    mesh.draw();
    ofPushMatrix();
    ofRotateZ(90);
    //    ofRotate(PI/3);
    mesh2.draw();
    ofPopMatrix();
    cam.end();
    for( int i=0; i<fishes; i++){
        
//        fishes[i].draw();
        myfish[i].arrive();
        myfish[i].update();
        myfish[i].draw();
        
    }
    
//    for(int i =0; i< 4; i++){
//        springs[i].draw();
//    }
//    
//    for(int i = 0; i < 5; i++){
//        
//        particles[i].draw();
//    }

    
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
