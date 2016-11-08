//
//  particleSystem.cpp
//  Inclass_02
//
//  Created by YiqiSun on 2016/11/1.
//
//

#include "particleSystem.hpp"

ParticleSystem::ParticleSystem(ofVec2f position):mPosition(position),mEmitRate(10), mIsAddingParticles(true){}

void ParticleSystem::update(ofVec2f force){
    if(mIsAddingParticles){
        //push new particles into our vector
        for (int i = 0; i< mEmitRate; i++){
            Particle particle(mPosition);
            mParticleList.push_back(particle);
        }
    }
    for (int i = 0; i< mParticleList.size(); i++){
        //calculate the difference between center and particle position
        
        ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x),abs(mParticleList[i].mPosition.y-mPosition.y));
      
        mParticleList[i].resetForces();
        //force is passed through ofapp.cpp
        mParticleList[i].applyForce(force);
        //Apply random Spped/Velocity to the particle
        mParticleList[i].update(ofMap(diff.length(),0,200,4,1));
        if(diff.length()>=ofRandom(200,400)){
            //stop adding particles if diff is higher than certain number
            mIsAddingParticles = false;
            //erase particle if it gets too far from center
            if(mParticleList.size()>0){
                mParticleList.erase(mParticleList.begin()+i);
            }
        }
        
    }
    
}
void ParticleSystem::draw(ofColor color){
    colorS = color;
    for(int i = 0; i<mParticleList.size(); i++){
        mParticleList[i].draw(colorS);
    }
}
