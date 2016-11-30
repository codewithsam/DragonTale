#include "Animation.h"
#include<iostream>


Animation::Animation() {
	playedOnce = false;
}

void Animation::setFrames(std::vector<sf::IntRect*> *frames) {
	this->frames = frames;
	//std::cout << frames->size() << std::endl;
	currentFrame = 0;
	playedOnce = false;
}

void Animation::setDelay(long d) { delay = d; }
void Animation::setFrame(int i) { currentFrame = i; }

void Animation::Update(float frametime) {
	if (delay == -1) return;
	long elapsed = startTime.getElapsedTime().asMilliseconds();
	if (elapsed > delay) {
		currentFrame++;
		//std::cout << currentFrame << " ";
		startTime.restart();
	}
	if (currentFrame == frames->size()) {
		//std::cout << "Gliding finished";
		currentFrame = 0;
		playedOnce = true;
	}
}

int Animation::getFrame() { return currentFrame; }
sf::IntRect& Animation::getImage() { return *frames->at(currentFrame); }
bool Animation::hasPlayedOnce() { return playedOnce; }


Animation::~Animation() {
}
