#pragma once
#include "Rotator.h"
class Rectan :
    public Rotator
{
public:
    Rectan(int frameWidth, int frameHeight, int x, int y);
    void draw(Graphics^ graphics);
    void interactReaction() override;

};

