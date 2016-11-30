#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:
	Animation();

	void setFrames(std::vector<sf::IntRect*> *frames);
	void setDelay(long d);
	void setFrame(int i);
	void Update(float frametime);
	int getFrame();
	sf::IntRect& getImage();
	bool hasPlayedOnce();

	~Animation();
private:
	std::vector<sf::IntRect*> *frames;
	int currentFrame;

	sf::Clock startTime;
	long delay;

	bool playedOnce;

};

