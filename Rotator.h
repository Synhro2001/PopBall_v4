
#pragma once
#include "Mover.h"



class Rotator :
    public Mover
{
protected:
    float alpha_;
    float dAlpha_;
public:
    Rotator::Rotator(int frameWidth, int frameHeight, int x, int y);
    void move();
    
};

