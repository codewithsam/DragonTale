#include "FireBall.h"
#include <iostream>



FireBall::FireBall(TileMap & tm, bool right): MapObject(tm) {
	moveSpeed = 3.8;
	if (right) dx = moveSpeed;
	else dx = -moveSpeed;
	width = 30;
	height = 30;
	cWidth = 14;
	cHeight = 14;

	facingRight = true;
	
	//load sprite
	t = new sf::Texture();
	s = new sf::Sprite();
	rect = new sf::IntRect();
	if (!t->loadFromFile("Resources/Sprites/Player/fireball.png")) { std::cout << "Cannot load fireball sprites" << std::endl; }
	s->setTexture(*t);
	for (int i = 0; i < 4; i++) {
		sprites.push_back(new sf::IntRect(i*width, 0, width, height));
	}

	for (int i = 0; i < 3; i++) {
		hitSprites.push_back(new sf::IntRect(i*width, height, width, height));
	}

	animation.setFrames(&sprites);
	animation.setDelay(70);

}

void FireBall::setHit(){
	if (hit) return;
	hit = true;
	animation.setFrames(&hitSprites);
	animation.setDelay(70);
	dx = 0;
}

bool FireBall::shouldRemove() { return remove; }

void FireBall::Update(float frametime) {
	checkTileMapCollision();
	setPosition(xTemp, yTemp);
	if (dx == 0 && !hit) {
		setHit();
	}
	animation.Update(frametime);
	if (hit && animation.hasPlayedOnce()) {
		remove = true;
	}
}
void FireBall::Draw(sf::RenderWindow *window){
	setMapPosition();
	
	if (facingRight) {

		*rect = animation.getImage();
		s->setTextureRect(*rect);
		s->setPosition((int)x + xMap - width / 2, (int)y + yMap - height);
		s->setScale(1.0 , 1.0);
		window->draw(*s);
	}
	else {
		*rect = animation.getImage();
		s->setTextureRect(*rect);
		s->setPosition((int)(x + xMap - width / 2 + width), (int)(y + yMap - height));
		s->setScale(-1.0, 1.0 );
		window->draw(*s);
	}

}

FireBall::~FireBall() {
}
