#pragma once
#include "Rotator.h"


class Star :
    public Rotator
{
public:
    Star(int frameWidth, int frameHeight, int x, int y) ;
    void draw(Graphics^ AGraphics);
    void interactReaction() override;
};

