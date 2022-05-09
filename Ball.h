#pragma once
#include "PopObject.h";
#include "Mover.h";


class Ball : public Mover
{
	
	public:

		void draw(Graphics^ graphics) ;
		Ball(int frameWidth, int frameHeight, int x, int y);
		void interactReaction() override;
};


// Исправил ошибку связаную с циклическим включением С2504 'PopObject': base class undefined
