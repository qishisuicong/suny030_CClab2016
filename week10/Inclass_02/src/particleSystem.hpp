//
//  particleSystem.hpp
//  Inclass_02
//
//  Created by YiqiSun on 2016/11/1.
//
//

#pragma once
#include "ofMain.h"
#include "particle.hpp"

class ParticleSystem{
public:
    ParticleSystem(ofVec2f position);
    void update(ofVec2f force);
    void draw(ofColor color);
    
    vector<Particle> mParticleList;
    ofVec2f mPosition;
    int mEmitRate;
    bool mIsAddingParticles;
    ofColor colorS;
};