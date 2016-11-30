#pragma once
#include "MapObject.h"
class FireBall: public MapObject {
public:
	FireBall(TileMap& tm, bool right);

	void setHit();

	bool shouldRemove();

	void Update(float frametime);

	void Draw(sf::RenderWindow * window);




	~FireBall();
private:
	bool hit = false;
	bool remove = false;
	std::vector<sf::IntRect*> sprites;
	std::vector<sf::IntRect*> hitSprites;
	sf::Texture *t;
	sf::Sprite *s;
	sf::IntRect *rect;
};

