//
//  fish.hpp
//  springsPointers
//
//  Created by YiqiSun on 11/30/16.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Spring.hpp"


class Fish{
    
public:
    void setup(int x, int y);
    void update();
    void applyForce(ofVec2f force);
    void arrive();
    void draw();
    

    
    
    Particle particles[5];
    Spring springs[4];
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f target;
    ofVec2f center1;
    ofVec2f point1;
    ofVec2f point2;
    float r;
    float r2;
    float maxforce;    // Maximum steering force
    float maxspeed;    // Maximum speed
    int headingx;
    int headingy;
    int counter;
    int count;
    float anum;
    float anumcalc;
    int bodyLength;
    ofImage head,body1,body2,body3,tail1,tail2;
    float x1,x2,y1,y2,x3,y3,ii,jj,angle1;
     ofColor color,color1,color2,color3,color4,color5;
    
};

