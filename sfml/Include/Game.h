#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include"Shape.h"
#include"Point.h"
#include"AssetManager.h"

class Game {
public:
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game();
	void run();
private:
	void gameModeOne();
	void processEvents();
	void update();
	void render();
	void message();   


	AssetManager manager;
	sf::Font font;
	sf::Text text;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Sprite arrow,background1,frame,tiles,background2;
	sf::Texture blockFont;
	Shape shape;

	int gameMode;
	int gamePoints;
	float timer , delay;
	int Status; //1表示正常游戏，0表示暂停游戏，-1表示游戏失败
};



#endif // !GAME_H
