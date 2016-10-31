//
//  Ball.hpp
//  Inclass_01
//
//  Created by YiqiSun on 2016/10/27.
//
//


#pragma once
#include "ofMain.h"

class Ball{
public:
    void setInit();
    void update();
    void draw();
    void mouse(int x, int y);
    //circle variables
    float mCircleRadius;//holds our circle size
    // physics variables
    ofVec2f mPos;//holds our position
    ofVec2f mVelocity;//holds our speed
    ofVec2f mAcceleration;//holds our direction
    float mFriction;
    const float MIN_VELOCITY = 0.01;
    ofColor color;

};