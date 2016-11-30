#include "Slugger.h"
#include <iostream>


Slugger::Slugger(TileMap& tm): Enemy(tm) {
	moveSpeed = 0.3;
	maxSpeed = 0.3;
	fallSpeed = 0.2;
	maxFallSpeed = 10.0;
	width = 30;
	height = 30;
	cWidth = 40;
	cHeight = 40;

	health = maxHealth = 2;
	damage = 1;

	s = new sf::Sprite();
	t = new sf::Texture();
	rect = new sf::IntRect();

	if (!t->loadFromFile("Resources/Sprites/Enemies/slugger.png")) { std::cout << "Slugger gif not found" << std::endl; }
	s->setTexture(*t);
	for (int i = 0; i < 3; i++) {
		sprites.push_back(new sf::IntRect(i*width, 0, width, height));
	}

	animation.setFrames(&sprites);
	animation.setDelay(300);

	right = true;
	facingRight = true;

}

void Slugger::getNextPosition() {
	//movement
	if (left) {
		dx -= moveSpeed;
		if (dx < -moveSpeed) {
			dx = -maxSpeed;
		}
	}
	else if (right) {
		dx += moveSpeed;
		if (dx > maxSpeed) {
			dx = maxSpeed;
		}
	}
	//falling

	if (falling) {
		dy += fallSpeed;
	}
}




void Slugger::Update(float frametime) {
	getNextPosition();
	checkTileMapCollision();
	setPosition(xTemp, yTemp);

	//check flinching
	if (flinching) {
		long elapsed = flinchTimer.getElapsedTime().asMilliseconds();
		if (elapsed > 400) {
			flinching = false;
		}
	}
	//if it hits a wall, go other direction
	if (right && dx == 0) {
		right = false;
		left = true;
		facingRight = false;
	}
	else if (left && dx == false) {
		right = true;
		left = false;
		facingRight = true;
	}
	animation.Update(frametime);
}

void Slugger::Draw(sf::RenderWindow * window) {
	if (notOnScreen()) return;
	setMapPosition();


	if (facingRight) {

		*rect = animation.getImage();
		s->setTextureRect(*rect);
		s->setPosition((int)x + xMap - width / 2, (int)y + yMap - height-5);
		s->setScale(2,2);
		window->draw(*s);
	}
	else {
		*rect = animation.getImage();
		s->setTextureRect(*rect);
		s->setPosition((int)(x + xMap - width / 2 + width), (int)(y + yMap - height-5));
		s->setScale(-2,2);
		window->draw(*s);
	}

}

Slugger::~Slugger() {
}
