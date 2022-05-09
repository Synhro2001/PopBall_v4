#define _USE_MATH_DEFINES

#include "Rotator.h";
#include <iostream>;
#include <cmath>


Rotator::Rotator(int frameWidth, int frameHeight, int x, int y)
    : Mover(frameWidth, frameHeight, x, y) {
    alpha_ = (float)rand() / (RAND_MAX / (2 * M_PI));
    dAlpha_ = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.05;

};

void Rotator::move() {

    Mover::move();
   
    alpha_ += dAlpha_;

}

//alpha_ = (0 + rand() % 2 * M_PI);
//dAlpha_ = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.05;