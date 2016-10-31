//
//  Ball.cpp
//  Inclass_01
//
//  Created by YiqiSun on 2016/10/27.
//
//

#include "Ball.hpp"
void Ball::setInit(){

    //set initial circle radius
    mCircleRadius = 30;
    //se initial position
    mPos = ofVec2f(ofRandom(2*mCircleRadius,(ofGetWindowWidth()-2*mCircleRadius)),ofRandom(2*mCircleRadius,(ofGetWindowHeight()-2*mCircleRadius)));
//    mPos = ofVec2f(ofRandom((-ofGetWindowWidth()/2+2*mCircleRadius),(ofGetWindowWidth()/2-2*mCircleRadius)),ofRandom((-ofGetWindowHeight()/2+2*mCircleRadius),(ofGetWindowHeight()/2-2*mCircleRadius)));

    mFriction = 0.99;
    //no velocity at the beginning
    mVelocity = ofVec2f(0);
    //no force at the beginning
    mAcceleration = ofVec2f(0);
}

void Ball::update(){
    //reduce velocity according to friction
    if(mVelocity.length()>0){
        mVelocity *= ofVec2f(mFriction);
    }
    //when velocity is too small, we don't want to update our velocity
    if(mVelocity.length()< MIN_VELOCITY){
        mVelocity = ofVec2f(0);
    }
    //update position of ball according to velocity
    if(mVelocity.length()>0){
        mPos += mVelocity;
        //circle size represent the velocity
        mCircleRadius = 30 + mVelocity.length()*20;
    }
    //    if(mPos.x < 0 ){
    //        mPos.x = ofGetWindowWidth();
    //    }
    //    if(mPos.x > ofGetWindowWidth()){
    //        mPos.x = 0;
    //    }
    //    if(mPos.y < 0 ){
    //        mPos.y = ofGetWindowHeight();
    //    }
    //    if(mPos.y > ofGetWindowHeight()){
    //        mPos.y = 0;
    //    }
    if(mPos.x < mCircleRadius){
        mPos.x = mCircleRadius;
        mVelocity.x = -mVelocity.x;
    }
    if(mPos.x >ofGetWindowWidth()-mCircleRadius){
        mPos.x = ofGetWindowWidth()-mCircleRadius;
        mVelocity.x = -mVelocity.x;
    }
    if(mPos.y < mCircleRadius){
        mPos.y = mCircleRadius;
        mVelocity.y = -mVelocity.y;
    }
    if(mPos.y >ofGetWindowHeight()-mCircleRadius){
        mPos.y = ofGetWindowHeight()-mCircleRadius;
        mVelocity.y = -mVelocity.y;
    }

}
void Ball::draw(){
//    ofSetColor(165, 180, 200);
    ofSetCircleResolution(50);
    ofDrawCircle(mPos, mCircleRadius);
    //ofDrawBitmapString("Text you want to show", int x, int y, int z);
//    ofDrawBitmapString("x:"+ ofToString(mPos.x)+ "y:"+ofToString(mPos.y),mPos + ofVec2f(40,-20));
    //print stuff to console
}

void Ball::mouse(int x, int y){
    //put mouse position into a vector, local variable
    ofVec2f mousePos = ofVec2f(x,y);
    //calculate acceleration
    mAcceleration = mPos - mousePos;
    //normalize acceleration
    mAcceleration = mAcceleration.getNormalized();
    //apply acceleration (direction) to velocity
    mVelocity += 3*mAcceleration;
}