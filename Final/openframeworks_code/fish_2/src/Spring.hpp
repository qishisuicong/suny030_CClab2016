

#pragma once 
#include "ofMain.h"
#include "Particle.hpp"

class Spring{

public:
    
    Spring();
    void set(Particle * _A, Particle * _B);
    void update();
    void draw();
    
    float k;
    float restDist;
    float restDist1;
    


    Particle * A;
    Particle * B;

    


};