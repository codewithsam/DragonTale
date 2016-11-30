#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStateManager.h"
#include "Constants.h"

int main(int argc, char** argv) {
	GameStateManager gsm;
	sf::RenderWindow window(sf::VideoMode(WINWIDTH * WINSCALE, WINHEIGHT * WINSCALE), "Dragon Tale");
	sf::Clock clock;
	window.setFramerateLimit(90);
	gsm.Init();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				gsm.KeyPressed(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased) {
				gsm.KeyReleased(event.key.code);
			}
		}
		float frametime = clock.getElapsedTime().asMilliseconds();
		window.clear(sf::Color(255,255,255));
		gsm.Update(&window, frametime);
		gsm.Draw(&window);
		window.display();
		clock.restart();

	}

	return 0;
}
