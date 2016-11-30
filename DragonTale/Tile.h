#pragma once
#include <SFML/Graphics.hpp>
class Tile {
public:
	static const int NORMAL = 0;
	static const int BLOCKED = 1;
	Tile(sf::Sprite *sp, int type);
	sf::Sprite* getImage();
	int getType();
	~Tile();
private:
	sf::Sprite *image;
	int type;
};

