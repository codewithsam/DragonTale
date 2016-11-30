#include "Tile.h"
#include <iostream>


Tile::Tile(sf::Sprite *sp, int type) {
	//std::cout << "Tile Address: " << sp << std::endl;
	this->image = sp;
	this->type = type;
}

sf::Sprite* Tile::getImage() {
	return image;
}

int Tile::getType() {
	return type;
}


Tile::~Tile() {
}
