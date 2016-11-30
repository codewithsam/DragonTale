#include "Background.h"
#include "Constants.h"


Background::Background(std::string s, double ms) {
	t = new sf::Texture();
	if (!t->loadFromFile(s)) std::cout << "Could not load background image" << std::endl;
	moveScale = ms;
	sp = new sf::Sprite();
	sp->setTexture(*t);
	sp1 = new sf::Sprite();
	sp1->setTexture(*t);
	sp->setScale(WINSCALE, WINSCALE);
	sp1->setScale(WINSCALE, WINSCALE);
}

void Background::setPosition(double x, double y) {
	this->x = fmod(( x * moveScale),(WINWIDTH*WINSCALE));
	//this->y = fmod(( y * moveScale),(WINHEIGHT*WINSCALE));
	this->y = 0;
}

void Background::setVector(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Background::Update() {
	x += dx;
	y += dy;
	setPosition(x, y);
}

void Background::Draw(sf::RenderWindow *window) {
	
	sp->setPosition(x, y);
	window->draw(*sp);
	if (x <= -((WINWIDTH*WINSCALE) - 10)) {
		sp->setPosition(x + (WINWIDTH*WINSCALE), y);
	}
	if (x > 0) {
		sp->setPosition(x - (WINWIDTH*WINSCALE), y);
	}
	if (x < 0) {
		sp1->setPosition(x + (WINWIDTH*WINSCALE), y);
		window->draw(*sp1);
	}
	if (x > 0) {
		sp1->setPosition(x + (WINWIDTH*WINSCALE), y);
		window->draw(*sp1);
	}
	
}

Background::~Background() {
}
