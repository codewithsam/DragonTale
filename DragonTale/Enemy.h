#pragma once
#include "MapObject.h"
class Enemy: public MapObject {
public:
	Enemy(TileMap &tm);
	bool isDead();
	int getDamage();
	void hit(int damage);
	virtual void Update(float frametime);
	virtual void Draw(sf::RenderWindow *window);
	~Enemy();
protected:
	int health = 0, maxHealth = 0, damage = 0;
	bool dead = false, flinching = false;
	sf::Clock flinchTimer;
};

