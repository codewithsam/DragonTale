#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"
class TileMap {
public:
	TileMap(int tileSize);
	void LoadTiles(std::string s);
	void LoadMap(std::string s);
	int getTileSize();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getType(int row, int col);
	void setPosition(double x, double y);
	void Draw(sf::RenderWindow* window);

	~TileMap();
private:
	void fixBounds();
	//position
	double x = 0, y = 0;
	//bounds
	int xmin = 0, xmax = 0 ,ymin = 0 ,ymax = 0;
	double tween;
	//Map
	int map[10000][10000];
	int tileSize, numRows, numCols,width, height;
	std::string vassel;
	//tileset
	sf::Texture tileTexture;
	sf::Sprite tileset;
	int numTilesAcross;
	Tile* tiles[10000][10000];
	//drawing
	int rowOffset=0, colOffset = 0, numRowsToDraw = 0, numColsToDraw = 0;
	sf::Sprite *sp;
	sf::Sprite *drawsp;
};


