#pragma once
#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Constants.h"
#include "Animation.h"
class MapObject {
public:
	
	MapObject(TileMap& tm): tileMap(tm) {
		tileSize = tm.getTileSize();
	}

	bool intersects(MapObject o) {
		sf::RectangleShape r1 = *getRectangle();
		sf::RectangleShape r2 = *o.getRectangle();
		return r1.getGlobalBounds().intersects(o.getRectangle()->getGlobalBounds());
	}

	sf::RectangleShape* getRectangle() {
		rect = new sf::RectangleShape();
		rect->setPosition(sf::Vector2f((int)x - cWidth, (int)y - cHeight));
		rect->setSize(sf::Vector2f(cWidth, cHeight));
		return rect;
	}


	void calculateCorners(double x, double y) {
		int lefTile = (int)(x - cWidth / 2) / tileSize;
		int rightTile = (int)(x + cWidth / 2 - 1) / tileSize;
		int topTile = (int)(y - cHeight / 2) / tileSize;
		int bottomTile = (int)(y + cHeight / 2 - 1) / tileSize;

		int tl = tileMap.getType(topTile, lefTile);
		int tr = tileMap.getType(topTile, rightTile);
		int bl = tileMap.getType(bottomTile, lefTile);
		int br = tileMap.getType(bottomTile, rightTile);

		topLeft = tl == Tile::BLOCKED;
		topRight = tr == Tile::BLOCKED;
		bottomLeft = bl == Tile::BLOCKED;
		bottomRight = br == Tile::BLOCKED;
	}

	void checkTileMapCollision() {
		currCol = (int)x / tileSize;
		currRow = (int)y / tileSize;

		xDest = x + dx;
		yDest = y + dy;

		xTemp = x;
		yTemp = y;

		calculateCorners(x, yDest);

		if (dy < 0) {
			if (topLeft || topRight) {
				dy = 0;
				yTemp = currRow * tileSize + cHeight / 2;
			}
			else {
				yTemp += dy;
			}
		}
		if (dy > 0) {
			if (bottomLeft || bottomRight) {
				dy = 0;
				falling = false;
				yTemp = (currRow + 1) * tileSize - cHeight / 2;
			}
			else {
				yTemp += dy;
			}
		}

		calculateCorners(xDest, y);

		if (dx < 0) {
			if (topLeft || bottomLeft) {
				dx = 0;
				xTemp = currCol * tileSize + cWidth / 2;
			}
			else {
				xTemp += dx;
			}
		}
		if (dx > 0) {
			if (topRight || bottomRight) {
				dx = 0;
				xTemp = (currCol + 1) * tileSize - cWidth / 2;
			}
			else {
				xTemp += dx;
			}
		}
		if (!falling) {
			calculateCorners(x, yDest + 1);
			if (!bottomLeft && !bottomRight) {
				falling = true;
			}
		}
	}

	int getX() { return (int)x; }
	int getY() { return (int)y; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getcWidth() { return cWidth; }
	int getcHeight() { return cHeight; }

	void setPosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void setVector(double dx, double dy) {
		this->dx = dx;
		this->dy = dy;
	}

	void setMapPosition() {
		xMap = tileMap.getX();
		yMap = tileMap.getY();
	}

	void setLeft(bool b) { left = b; }
	void setRight(bool b) { right = b; }
	void setUp(bool b) { up = b; }
	void setDown(bool b) { down = b; }
	void setJumping(bool b) { jumping = b; }

	bool notOnScreen() {
		return x + xMap + width < 0 || x + xMap - width >(WINWIDTH*WINSCALE) || y + yMap + height < 0 || y + yMap - height >(WINHEIGHT*WINSCALE);
	}

	~MapObject() {}

	//tile Declarations
	TileMap& tileMap;
	int tileSize = 0;
	double xMap = 0, yMap = 0;
	//position and vectors
	double x = 0, y = 0, dx = 0, dy = 0;
	//dimensions
	int width = 0, height = 0;
	//collision box
	int cWidth = 0, cHeight = 0;
	//collision
	int currCol = 0, currRow = 0;
	double xDest = 0, yDest = 0, xTemp = 0, yTemp = 0;
	bool topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
	//animation
	Animation animation;
	int currentAction = 0, previousAction = 0;
	bool facingRight = false, facingLeft = false;
	//movememnt
	bool left = false, right = false, up = false, down = false, jumping = false, falling = false;
	//movement attributes
	double moveSpeed = 0, maxSpeed = 0, stopSpeed = 0, fallSpeed = 0, maxFallSpeed = 0, jumpStart = 0, stopJumpSpeed = 0;

	sf::RectangleShape *rect;
};

