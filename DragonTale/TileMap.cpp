#include "TileMap.h"
#include "GameStateManager.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <sstream>

TileMap::TileMap(int tileSize) {
	this->tileSize = tileSize;
	numRowsToDraw = (WINHEIGHT*WINSCALE) / tileSize + 2;
	numColsToDraw = (WINWIDTH*WINSCALE) / tileSize + 2;
	tween = 1;
}

void TileMap::LoadTiles(std::string s) {
	if (!tileTexture.loadFromFile(s)) {}
	tileset.setTexture(tileTexture);
	numTilesAcross = tileset.getGlobalBounds().width / tileSize;
	for (int col = 0; col < numTilesAcross; col++) {
		if (col == 6 || col == 7 || col==8) {
			sp = new sf::Sprite();
			sp->setTexture(tileTexture);
			sp->setTextureRect(sf::IntRect(col*tileSize, 0, tileSize, tileSize));
			tiles[0][col] = new Tile(sp, Tile::BLOCKED);
			sp = new sf::Sprite();
			sp->setTexture(tileTexture);
			sp->setTextureRect(sf::IntRect(col*tileSize, tileSize, tileSize, tileSize));
			tiles[1][col] = new Tile(sp, Tile::BLOCKED);
			continue;
		}

		sp = new sf::Sprite();
		sp->setTexture(tileTexture);
		sp->setTextureRect(sf::IntRect(col*tileSize, 0, tileSize, tileSize));
		tiles[0][col] = new Tile(sp, Tile::NORMAL);

		sp = new sf::Sprite();
		sp->setTexture(tileTexture);
		sp->setTextureRect(sf::IntRect(col*tileSize, tileSize, tileSize, tileSize));
		tiles[1][col] = new Tile(sp, Tile::BLOCKED);
	}
}
void TileMap::LoadMap(std::string s) {
	std::ifstream stream;
	stream.open(s);
	std::getline(stream, vassel);
	numCols = std::atoi(vassel.c_str());
	std::getline(stream, vassel);
	numRows = std::atoi(vassel.c_str());
	width = numCols * tileSize;
	height = numRows * tileSize;

	xmin = (WINWIDTH*WINSCALE) - width;
	xmax = 0;
	ymin = (WINHEIGHT*WINSCALE) - height;
	ymax = 0;



	for (int row = 0; row < numRows; row++) {
		std::getline(stream, vassel);
		std::istringstream iss(vassel);
		int val;
		for (int col = 0; col < numCols; col++) {
			iss >> val;
			map[row][col] = val;
		}
	}
}

int TileMap::getTileSize() { return tileSize; }
int TileMap::getX() { return (int)x; }
int TileMap::getY() { return (int)y; }
int TileMap::getWidth() { return width; }
int TileMap::getHeight() { return height; }

int TileMap::getType(int row, int col) {
	int rc = map[row][col];
	int r = rc / numTilesAcross;
	int c = rc % numTilesAcross;
	return tiles[r][c]->getType();
}

void TileMap::setPosition(double x, double y) {
	this->x += (x - this->x) * tween;
	this->y += (y - this->y) * tween;
	fixBounds();

	colOffset = (int)-this->x / tileSize;
	rowOffset = (int)-this->y / tileSize;
}

void TileMap::fixBounds() {
	if ((int)x < xmin) x = xmin;
	if ((int)y < ymin) y = ymin;
	if ((int)x > xmax) x = xmax;
	if ((int)y > ymax) y = ymax;
}

void TileMap::Draw(sf::RenderWindow * window) {
	for (int row = rowOffset; row < rowOffset + numRowsToDraw; row++) {
		if (row >= numRows) break;
		for (int col = colOffset; col < colOffset + numColsToDraw; col++) {
			if (col >= numCols) break;
			if (map[row][col] == 0) continue;

			int rc = map[row][col];
			rc--;
			int r = rc / numTilesAcross;
			int c = rc % numTilesAcross;
			drawsp =  tiles[r][c]->getImage();
			drawsp->setPosition(x + col*tileSize, y + row * tileSize);
			window->draw(*drawsp);
			
		}
	}
}

TileMap::~TileMap() {
}
