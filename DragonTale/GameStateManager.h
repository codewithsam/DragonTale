#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "Level1State.h"


class GameStateManager {
public:
	static const int MENUSTATE = 0;
	static const int LEVEL1STATE = 1;

	GameStateManager();
	
	void SetState(int state);
	void Update(sf::RenderWindow* window, float frametime);
	void Draw(sf::RenderWindow* window);
	void Init();
	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);
	
	~GameStateManager();
private:
	std::vector<GameState*> States;
	int currentState;
};

