#pragma once
#include "Rotator.h"

class Triangle :
    public Rotator
{
public:
    Triangle(int frameWidth, int frameHeight, int x, int y);
    void draw(Graphics^ graphics);
    void interactReaction() override;
};

