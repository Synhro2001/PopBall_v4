#include "Mover.h";
#include <math.h>;
#include <iostream>

Mover::Mover() {

}

Mover::Mover(int frameWidth, int frameHeight, int x, int y) {
    frameHeight_ = frameHeight;
    frameWidth_ = frameWidth;
    x_ = x;
    y_ = y;
    size_ = 15;
    color_ = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb(); //   Transparent red color.

    dX_ = (rand() % 10) - 10;
    dY_ = (rand() % 10) - 10;

}




void Mover::interact(PopObject* popObject) {

    float dx2, dy2, x2, y2; //данные второго обьекта 
    x2 = popObject->getX();
    y2 = popObject->getY();
    dx2 = popObject->getdX();
    dy2 = popObject->getdY();


    //sides of the triangle
    float Dx = x_ - x2; // 
    float Dy = y_ - y2;
    float h = sqrt(Dx * Dx + Dy * Dy);  // hypotenuse

    if (h == 0) h = 0.01; // what was not was division by 0

    float sinV = Dx / h;
    float cosV = Dy / h;


    float vectorN = dx2 * sinV + dy2 * cosV;
    float vectorT = -dx2 * cosV + dy2 * sinV;




    float vectorSecondN = dX_ * sinV + dY_ * cosV;
    float vectorSecondT = -dX_ * cosV + dY_ * sinV;

    vectorSecondN = vectorN;

    dX_ = vectorSecondN * sinV - vectorSecondT * cosV;
    dY_ = vectorSecondN * cosV + vectorSecondT * sinV;
    dx2 = vectorN * sinV - vectorT * cosV;
    dy2 = vectorN * cosV + vectorT * sinV;

    interactReaction();
    popObject->interactReaction();
}

void Mover::setPos(int x, int y) {

    if (x <= size_) x = size_ + 1;
    if (x > frameWidth_ - size_) x = frameWidth_ - size_ - 1;

    if (y <= size_) y = size_ + 1;
    if (y > frameHeight_ - size_) y = frameHeight_ - size_ - 1;


    x_ = x;
    y_ = y;

}

float Mover::getX() {
    return x_;
}

float Mover::getY() {
    return y_;
}

float Mover::getdX() {
    return dX_;
}

float Mover::getdY() {
    return dY_;
}


int Mover::getSize() {
    return size_;
}

void Mover::setSpeed(float dX, float dY) {
    if (dX > 10) dX = 10;
    if (dX < -10) dX = -10;
    if (dY > 10) dY = 10;
    if (dY < -10) dY = -10;

    dX_ = dX;
    dY_ = dY;


}

void Mover::move() {

    if ((x_ <= size_) || (x_ > frameWidth_ - size_))
    {
        dX_ = -dX_;
    }
    if ((y_ <= size_) || (y_ > frameHeight_ - size_))
    {
        dY_ = -dY_;
    }

    x_ += dX_;
    y_ += dY_;
}


