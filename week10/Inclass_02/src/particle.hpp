//
//  particle.hpp
//  Inclass_02
//
//  Created by YiqiSun on 2016/11/1.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    //create constructor, constructors initialize classes, they can take arguments, but they do not have return type, because theyr eturn classes themselves
    Particle(ofVec2f position);
    void setup();
    void update(float multiplier);
    void draw(ofColor _color);
    void applyForce(ofVec2f force);
    void resetForces();
    ofVec2f mPosition, mSpeed, mDirection;
    float mLifeSpan;
    ofColor colorH;
    
};