#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Background.h"

class MenuState: public GameState{
public:
	class GameStateManager& gsm;
	MenuState(class GameStateManager& gsm);
	void Update(sf::RenderWindow* window, float frametime);
	void Draw(sf::RenderWindow* window);
	void Init();
	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);
	void selected();
	~MenuState();
private:
	sf::Texture bg;
	sf::Sprite bgSprite;
	Background background;
	double bgx = 0, bgy = 0;
	int currentChoice = 0;
	sf::Font font;
	std::vector<sf::Text*> Options = { 
		new sf::Text("Start",font), 
		new sf::Text("Help",font), 
		new sf::Text("Credits",font),
		new sf::Text("Quit",font)
	};
	sf::Text MenuHeader;
	
};

