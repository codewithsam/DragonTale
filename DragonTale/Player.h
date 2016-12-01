#pragma once
#include "MapObject.h"
#include "FireBall.h"
#include "Enemy.h"
class Player: public MapObject {
public:
	Player(TileMap& tm);

	int getHealth();
	int getMaxHealth();
	int getFire();
	int getMaxFire();
	void setFiring();
	void setScratching();
	void setGliding(bool b);
	void checkAttack(std::vector<Enemy*>&enemies);
	void getNextPosition();
	void hit(int damage);
	void Update(float frametime);
	void Draw(sf::RenderWindow *window);

	~Player();
private:
	//player declarations
	int health = 0, maxHealth = 0, fire = 0, maxFire = 0;
	bool dead = false, flinching = false;
	long flinchtimer = 0;
	//fireball
	bool firing = false;
	int fireCost = 0;
	int fireBallDamage = 0;
	long fr = 0;
	std::vector<FireBall*> fireballs;

	//scratch
	bool scratching = false;
	int scratchDamage = 0;
	int scratchRange = 0;

	//gliding
	bool gliding = false;

	sf::Texture *t;
	sf::Sprite *s;
	sf::Clock clock;

	FireBall *fb;

	//animations
	std::vector<sf::IntRect*> *bi;
	std::vector<std::vector<sf::IntRect*>*> sprites;
	sf::IntRect *rect;
	const int numFrames[7] = { 2,8,1,2,4,2,5 };

	//animation actions
	static const int IDLE = 0;
	static const int WALKING = 1;
	static const int JUMPING = 2;
	static const int FALLING = 3;
	static const int GLIDING = 4;
	static const int FIREBALL = 5;
	static const int SCRATCHING = 6;

};

