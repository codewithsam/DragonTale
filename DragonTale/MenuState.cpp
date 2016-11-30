#include "MenuState.h"
#include <iostream>
#include "Constants.h"

MenuState::MenuState(GameStateManager& gsm):gsm(gsm), background("Resources/Backgrounds/menubg.gif",1){
	background.setVector(-1, 0);
}

void MenuState::Update(sf::RenderWindow * window, float frametime) {
	background.Update();
}

void MenuState::Draw(sf::RenderWindow * window) {
	background.Draw(window);
	window->draw(MenuHeader);
	for (int i = 0; i < Options.size(); i++) {
		if (i == currentChoice) {
			Options.at(i)->setColor(sf::Color::Black);
		}
		else {
			Options.at(i)->setColor(sf::Color::Red);
		}
		window->draw(*Options.at(i));
	}
}

void MenuState::Init() {
	bgSprite.setTexture(bg);
	bgSprite.setPosition(bgx, bgy);
	bgSprite.setScale(WINWIDTH*WINSCALE / bgSprite.getGlobalBounds().width, WINHEIGHT*WINSCALE / bgSprite.getGlobalBounds().height);
	if (!font.loadFromFile("Resources/GOTHIC.TTF")) {
		std::cout << "unable to load from file" << std::endl;
	}
	MenuHeader.setFont(font);
	MenuHeader.setString("Dragon Tale"); 
	MenuHeader.setPosition(WINWIDTH*WINSCALE /2-MenuHeader.getGlobalBounds().width/2, 80);
	MenuHeader.setColor(sf::Color(128, 0, 0));
	int offset = 50;
	for (sf::Text *t : Options) {
		t->setPosition(WINWIDTH*WINSCALE / 2 - t->getGlobalBounds().width / 2, 100+offset);
		t->setColor(sf::Color(40,40,40));
		offset+=50;
	}

}

void MenuState::KeyPressed(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Up) {
		currentChoice--;
		if (currentChoice < 0) {
			currentChoice = Options.size() - 1;
		}
	}
	if (key == sf::Keyboard::Down) {
		currentChoice++;
		if (currentChoice > Options.size() - 1) {
			currentChoice = 0;
		}
	}
	if (key == sf::Keyboard::Return) {
		selected();
	}
}

void MenuState::KeyReleased(sf::Keyboard::Key key) {
}

void MenuState::selected() {
	if (currentChoice == 0) {
		gsm.SetState(GameStateManager::LEVEL1STATE);
	}
	if (currentChoice == 1) {
		//Help
	}
	if (currentChoice == 2) {
		//Quit
	}
}


MenuState::~MenuState() {
}
