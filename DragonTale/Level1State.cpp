#include "Level1State.h"


Level1State::Level1State(GameStateManager & gsm): gsm(gsm), tileMap(30), background("Resources/Backgrounds/grassbg1.gif", 0.5) {
	Init();
}

void Level1State::Update(sf::RenderWindow * window, float frametime) {
	player->Update(frametime);
	tileMap.setPosition(((WINWIDTH*WINSCALE) / 2 - player->getX()) , ((WINHEIGHT*WINSCALE) / 2 - player->getY()));
	background.setPosition(tileMap.getX(), tileMap.getY());

	//attack enemies
	player->checkAttack(enemies);
	
	//update all enemies

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Update(frametime);
		if (enemies[i]->isDead()) {
			enemies.erase(enemies.begin() + i);
			i--;
		}
	}
}

void Level1State::Draw(sf::RenderWindow * window) {
	//draw background
	background.Draw(window);
	//draw tilemap
	tileMap.Draw(window);
	//draw player
	player->Draw(window);
	//draw enemies
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Draw(window);
	}
}

void Level1State::Init() {
	tileMap.LoadTiles("Resources/Tilesets/grasstileset.png");
	tileMap.LoadMap("Resources/Maps/one.map");
	tileMap.setPosition((double)0, (double)0);
	player = new Player(tileMap);
	player->setPosition(100, 400);

	s = new Slugger(tileMap);
	s->left = true;
	s->setPosition(300, 530);
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->setPosition(1110, 420);
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->left = true;
	s->setPosition(1530, 420);
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->setPosition(1890, 600);
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->setPosition(1990, 600);
	s->right = true;
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->setPosition(2260, 600);
	s->left = true;
	enemies.push_back(s);

	s = new Slugger(tileMap);
	s->setPosition(2400, 600);
	s->left = true;
	enemies.push_back(s);
}

void Level1State::KeyPressed(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Left) player->setLeft(true);
	if (key == sf::Keyboard::Right) player->setRight(true);
	if (key == sf::Keyboard::Up) player->setUp(true);
	if (key == sf::Keyboard::Down) player->setDown(true);
	if (key == sf::Keyboard::W) player->setJumping(true);
	if (key == sf::Keyboard::E) player->setGliding(true);
	if (key == sf::Keyboard::R) player->setScratching();
	if (key == sf::Keyboard::F) player->setFiring();

}

void Level1State::KeyReleased(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Left) player->setLeft(false);
	if (key == sf::Keyboard::Right) player->setRight(false);
	if (key == sf::Keyboard::Up) player->setUp(false);
	if (key == sf::Keyboard::Down) player->setDown(false);
	if (key == sf::Keyboard::W) player->setJumping(false);
	if (key == sf::Keyboard::E) player->setGliding(false);
}

Level1State::~Level1State() {
}
