

#include "Particle.hpp"

Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.70; // de resistance!!!
    radius = 5;
    
    bFix = false;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}
void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
}

//void Particle::bounding(){
//    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
//        pos.x -= vel.x; // Bounced back! think of this as an undo;
//        vel.x *= -1.0;
//    }
//    
//    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
//        pos.y -= vel.y; // Bounced back! think of this as an undo;
//        vel.y *= -1.0;
//    }
//}

ofPoint Particle::getPosition(){
    return pos;
}

ofPoint Particle::getVelocity(){
    return vel;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::draw() {
    float time = ofGetElapsedTimef();
    float perlin = ofNoise(pos.x*0.05, pos.y*0.05,time*0.5);
    radius = perlin*30;
    ofDrawCircle(pos, radius);
    
//    ofDrawRectangle(pos, radius,radius);
    
//    ofPoint velNormal = vel;
//    velNormal.normalize();
//    
//    ofVec2f velPerp;
//    velPerp.x = -velNormal.y;
//    velPerp.y = velNormal.x;
    
//    ofDrawLine(pos.x, pos.y, pos.x + velNormal.x*10, pos.y + velNormal.y*10);
}