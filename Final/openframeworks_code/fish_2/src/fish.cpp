//
//  fish.cpp
//  springsPointers
//
//  Created by YiqiSun on 11/30/16.
//
//

#include "fish.hpp"

void Fish::setup(int x, int y){
    head.load("head.png");
    body1.load("body1.png");
    body2.load("body2.png");
    body3.load("body3.png");
    tail1.load("tail1.png");
    tail2.load("tail2.png");
    float time = ofGetElapsedTimef();
    acceleration = ofVec2f(10, 10);
    velocity = ofVec2f(0, 0);
    location = ofVec2f(x, y);
    target = ofVec2f(headingx, headingy);
    r2 = 2;
    maxspeed = 1;
    maxforce = 0.02;
    count = int(ofRandom(200));
    bodyLength = int(ofRandom(5, 20));
//    ofBackground(0);
    float perlin = ofNoise(x*0.05, y*0.05,time*0.5);
    
    for(int i =0; i < 3; i++){
//        
//        particles[i].setInit(ofPoint(ofRandom(ofGetWidth()),
//                                     ofRandom(ofGetHeight())));
        particles[i].setInit(ofPoint(ofGetWindowWidth()*perlin*100,
                                     ofGetWindowHeight()*perlin*100));

    }
    
    particles[0].bFix = true;
    
    //spring array
    springs[0].set(&particles[0], &particles[1]);
    springs[0].restDist = 20;
    springs[1].set(&particles[1], &particles[2]);
    springs[1].restDist = 20;
    springs[2].set(&particles[2], &particles[3]);
    springs[2].restDist = 20;
    springs[3].set(&particles[3], &particles[4]);
    springs[3].restDist = 20;
  
    
}


//--------------------------------------------------------------
void Fish::update(){
    // Update velocity
    velocity+=acceleration;
    // Limit speed
    velocity.limit(maxspeed);
    location+=velocity;
    // Reset accelerationelertion to 0 each cycle
    acceleration*=0;
    if (counter >= count) {
        counter = 0;
        
        //changing this line changes the tendency to change heading.  I highly recommend perlin noise here.
        count = int(ofRandom(200));
        
        
        headingx = int(ofRandom(ofGetWindowWidth()));
        headingy = int(ofRandom(ofGetWindowHeight()));
    }
    target.x = headingx;
    target.y = headingy;
    
    counter++;
    ofPoint p;
    p.x=location.x + (((bodyLength))-abs(ofDist(0,0,velocity.x,velocity.y)))*(sin(anum)*velocity.y);
    p.y=location.y + (((bodyLength))-abs(ofDist(0,0,velocity.x,velocity.y)))*((-1*sin(anum))*velocity.x); //+ .1*(1-sin(anum)*target.x);
    
    
    
    r = r2*(ofMap(bodyLength, 5, 20, .5, 3));

//    ofPoint p = ofPoint(_x,_y);
    particles[0].pos.set(p);
    
    for(int i =0; i< 4; i++){
        springs[i].update();
    }
    
    for(int i = 0; i < 5; i++){
        particles[i].addForce(ofPoint(0,0.1));
        particles[i].update();
//        particles[i].bounding();
    }
    
}
void Fish::applyForce(ofVec2f force) {
    // We could add mass here if we want A = F / M
    acceleration+=force;
}

// A method that calculates a steering force towards a target
void Fish::arrive() {
    ofVec2f desired = ofVec2f(target - location);  // A vector pointing from the location to the target
    float d = ofDist(0,0,desired.x,desired.y);
    if (d < 100) {
        float m = ofMap(d, 0, 100, 0, maxspeed);
//        desired.setMag(m);
        desired = desired.normalize() * m;
    } else {
//        desired.setMag(maxspeed);
        desired = desired.normalize() * maxspeed;
    }
    
    //changing the properties of this line changes the overal vigor and speed of swimming, before scale
    ofVec2f j = ofVec2f(desired.x * desired.x + desired.y * desired.y);
    float k = ofDist(0,0,j.x,j.y);
    anumcalc = .06*(k*(20/bodyLength));
    anum+=anumcalc;
    ofVec2f steer = ofVec2f(desired - velocity);
    steer.limit(maxforce);  // Limit to maximum steering force
    applyForce(steer);
}





//--------------------------------------------------------------
void Fish::draw(){
//    ofPushMatrix();
//    ofTranslate(pos);
//    float rot = atan2( vel.y, vel.x );
//    ofRotate(ofRadToDeg(rot)+ 180);
//    yu.draw(0,0, 40, 20);
//    
//    ofPopMatrix();
    
    for(int i =0; i< 4; i++){
//        springs[i].draw();
 

        
        
        

    }
    
    for(int i = 0; i < 5; i++){
        ofSetColor(color);
        particles[i].draw();
//        ofSetColor(color1);
//        particles[1].draw();
//        ofSetColor(color2);
//        particles[2].draw();
//        ofSetColor(color3);
//        particles[3].draw();
//        ofSetColor(color4);
//        particles[4].draw();
        
        
        
//        
//        ofPushMatrix();
//        ofTranslate(particles[0].pos);
//         float rot = atan2( velocity.y, velocity.x );
//        ofRotate(ofRadToDeg(rot)+ 180);
//        ofSetColor(color);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        ofDrawCircle(0, 0, 5);
//        ofSetColor(color1);
//        ofPopMatrix();
//        
        



    }
}

