#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "TileMap.h"
#include "Background.h"
#include "Player.h"


class Level1State: public GameState {
public:
	class GameStateManager& gsm;
	Level1State(class GameStateManager& gsm);
	void Update(sf::RenderWindow* window, float frametime);
	void Draw(sf::RenderWindow* window);
	void Init();
	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);
	~Level1State();
private:
	TileMap tileMap;
	Background background;
	Player *player;
};

