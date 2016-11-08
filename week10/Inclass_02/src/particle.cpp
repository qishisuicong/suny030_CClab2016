//
//  particle.cpp
//  Inclass_02
//
//  Created by YiqiSun on 2016/11/1.
//
//

#include "particle.hpp"
//initializing constructor, and initializing the variables inside of it
Particle::Particle(ofVec2f position):mPosition(position), mSpeed(ofRandom(-2.f, 2.f),ofRandom(-2.f,2.f)),mDirection(ofVec2f(0)),mLifeSpan(255.f){};


void Particle::update(float multiplier){
    //apply acceleration to velocity
    mSpeed += mDirection;
    mPosition += mSpeed*multiplier;
    //decrease life span
    if(mLifeSpan>0){
        
        mLifeSpan = ofNoise(ofGetElapsedTimef()*200)*ofRandom(10,ofGetWidth());
        mLifeSpan -= 2.f;
        
    }
    
}

void Particle::draw(ofColor _color){
    colorH = _color;
   
    if(mLifeSpan >100){
        //make it brighter
//        ofSetColor(mLifeSpan);
         ofSetColor(colorH);
    }else if(mLifeSpan <= 100){
        ofSetColor(ofRandom(0,255));
        
        
    }
    //if particle is closer, it is smaller
    ofDrawCircle(mPosition, 3.f* ofMap(mLifeSpan,0,255.f,0,1.f));
}

void Particle::applyForce(ofVec2f force){
    //apply direction to velocity
    mDirection+=force;//mAcceleration += force
    
}
void Particle::resetForces(){
    mDirection *= 0;//mAcceleration *= 0
    
}



                                                                                                                    