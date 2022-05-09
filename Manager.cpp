#include "Manager.h"
#include "math.h"
#include <iostream>


Manager* manager; // ������ ������������ ������ 

using namespace System::Drawing;

Manager::Manager(int frameWidth, int frameHeight) {
	frameHeight_ = frameHeight;
	frameWidth_ = frameWidth;
	for(int i = 0; i < MAX_OBJECTS; i++) 
    popObjects_[i] = nullptr;
	
	

}

Manager::~Manager() {


	for (int i = 0; i < MAX_OBJECTS; i++) delete popObjects_[i];
}


void Manager::add(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (!popObjects_[i]) {
		popObjects_[i] = popObject;
		break;
	}
}



void Manager::drawFrame(Graphics^ graphics) {
	
	//������ ��� - ������ ������������� � ��������� �����,
	Pen framePen(Color::Black, 3);
	graphics->FillRectangle(% SolidBrush(Color::White), 0, 0, frameWidth_, frameHeight_);
	graphics->DrawRectangle(% framePen, 0, 0, frameWidth_, frameHeight_);
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i]) {
		popObjects_[i]->draw(graphics);
	}

}

PopObject* Manager::search(int x, int y) {
	int i;
	
	for (i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;



		float Xcentr = popObjects_[i]->getX();
		float Ycentr = popObjects_[i]->getY();

		float dist = sqrt(pow(x - Xcentr, 2) + pow(y - Ycentr, 2));

		if (dist < popObjects_[i]->getSize() + popObjects_[i]->getSize()) {
			return popObjects_[i];
		}
		
	}
	return nullptr;
	
}




bool Manager::objCollision(PopObject* firstBall, PopObject* secondBall) {
	
	
	/* ������� ��������� ����� ��������� ��� ������� �������� 
	���������� get ��� �� �������� ���������� ������� ������� � ������� 
	pow - ��� ���������� � ������� ����� ���������� math.h
	� ����� ���������� �������� bool ����� �������� �������� �������� 
	��� ����� ������ � ������������
	*/
	
	float firstX = firstBall->getX();
	float firstY = firstBall->getY();
	float secondX = secondBall->getX();
	float secondY = secondBall->getY();


	float dist = sqrt(pow(secondX - firstX, 2) + pow(secondY - firstY, 2));
	
	return (dist < firstBall->getSize() + secondBall->getSize());
	
}

void Manager::move() {
	for ( int i = 0; i < MAX_OBJECTS; i++) {
		if(!popObjects_[i])continue; // ������������� ������� �������� � ��������� � ������ 
		for ( int j = 0; j < MAX_OBJECTS; j++){
			if(!popObjects_[j] || popObjects_[i] == popObjects_[j])continue;

			bool coolision = objCollision(popObjects_[i], popObjects_[j]);
			if (coolision) {
			popObjects_[i]->interact(popObjects_[j]);
			popObjects_[j]->move();
			popObjects_[i]->move();
			}
		}
		popObjects_[i]->move();
	}
	
	//���������� ������  � ������� ������������ �� ������ !
	// ������� ������ ��� ������� �����
}


bool Manager::remove(PopObject* popObject) {

	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i] == popObject) {
		popObjects_[i] = nullptr;
		delete popObject;
	
		break;
	}
	return nullptr;
}


void Manager::decreaseSpeed(PopObject* popObject) { 

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;

		float dx = popObjects_[i]->getdX();
		float dy = popObjects_[i]->getdY();

		if (dx < 15) {
			dx = dx * 2;
		} 
		if (dy < 15) {
			dy = dy * 2;
		}
		popObjects_[i]->setSpeed(dx, dy);
	}
	

}


void Manager::increaseSpeed(PopObject* popObject) {

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;

		float dx = popObjects_[i]->getdX();
		float dy = popObjects_[i]->getdY();
		if (abs(dx) > 1) { // ����� ����� � ������ ����� ��� ��������� �������� ������ ��� �������� �� ������ ����������� !!!
			dx = dx * 0.5; // �������� �� ��������� < 1
		}
		if (abs(dy) > 1) {
			dy = dy * 0.5;
		}
		popObjects_[i]->setSpeed(dx, dy);
	}


}