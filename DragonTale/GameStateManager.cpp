#include "GameStateManager.h"

#include <iostream>

GameStateManager::GameStateManager() {
	this->currentState = MENUSTATE;
	this->States.push_back(new MenuState(*this));
	this->States.push_back(new Level1State(*this));
}

void GameStateManager::SetState(int state) {
	this->currentState = state;
}

void GameStateManager::Update(sf::RenderWindow * window, float frametime) {
	this->States.at(this->currentState)->Update(window, frametime);
}

void GameStateManager::Draw(sf::RenderWindow * window) {
	this->States.at(this->currentState)->Draw(window);
}

void GameStateManager::Init() {
	this->States.at(this->currentState)->Init();
}

void GameStateManager::KeyPressed(sf::Keyboard::Key key) {
	this->States.at(this->currentState)->KeyPressed(key);
}

void GameStateManager::KeyReleased(sf::Keyboard::Key key) {
	this->States.at(this->currentState)->KeyReleased(key);
}



GameStateManager::~GameStateManager() {
}
