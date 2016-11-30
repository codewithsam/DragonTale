#include "Enemy.h"



Enemy::Enemy(TileMap &tm): MapObject(tm) {

}

bool Enemy::isDead() {
	return false;
}

int Enemy::getDamage() {
	return 0;
}

void Enemy::hit(int damage) {
	if (dead || flinching) return;
	health -= damage;
	if (health < 0) health = 0;
	if (health == 0) dead = true;
	flinching = true;
	flinchTimer.restart();
	
}

void Enemy::Update(float frametime) {
}

void Enemy::Draw(sf::RenderWindow * window) {
}


Enemy::~Enemy() {
}
