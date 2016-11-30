#pragma once
#include "Enemy.h"

class Slugger: public Enemy {
public:
	Slugger(TileMap& tm);
	void getNextPosition();
	void Update(float frametime);
	void Draw(sf::RenderWindow *window);
	~Slugger();
private:
	std::vector<sf::IntRect*> sprites;
	sf::Sprite *s;
	sf::Texture *t;
	sf::IntRect *rect;
	Animation animation;
};

