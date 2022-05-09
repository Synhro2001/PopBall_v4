#include "Star.h"
#define _USE_MATH_DEFINES
#include <iostream>;
#include <cmath>


using namespace System::Drawing;

Star::Star(int frameWidth, int frameHeight, int x, int y)
    : Rotator(frameWidth, frameHeight, x, y) { 
	size_ = 20;
};

void Star::draw(Graphics^ AGraphics)
{
	int n = 5;
	SolidBrush brush(Color::FromArgb(color_)); // izveidot otu
	array<Point>^ points = gcnew array<Point>(14); // izveidot CLI masīvu ar 3 elementiem Point tipa
	for (int i = 0; i < 14; i++) {
		if (i % 2) {
			points[i] = Point( // un ierakstīt tas uz masīva
				x_ + size_ * cos(alpha_ + 2 * M_PI / 14 * i),
				y_ + size_ * sin(alpha_ + 2 * M_PI / 14 * i)
			);
		}
		else {
			points[i] = Point(
				x_ + size_ / 2 * cos(alpha_ + 2 * M_PI / 14 * i),
				y_ + size_ / 2 * sin(alpha_ + 2 * M_PI / 14 * i)
			);
		}
	}
	AGraphics->FillPolygon(% brush, points); // uzzīmēt aizpildīto figūru

	
}

void Star::interactReaction() {
	dAlpha_ = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.05;
}