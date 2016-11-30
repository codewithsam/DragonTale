#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Background {
public:
	Background(std::string s, double ms);
	void setPosition(double x, double y);
	void setVector(double dx, double dy);
	void Update();
	void Draw(sf::RenderWindow * window);
	~Background();
private:
	double x = 0, y = 0, dx = 0, dy = 0, moveScale = 0;
	sf::Sprite *sp;
	sf::Sprite *sp1;
	sf::Texture *t;
	int count = 0;
};

