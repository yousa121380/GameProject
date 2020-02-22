#include "Game.h"
#include <vector>
Game::Game():window(sf::VideoMode(320, 480), "The Game!"), timer(0.0f), delay(0.5f), 
	gamePoints(0),Status(true), gameMode(0), 
	arrow(AssetManager::GetTexture("./Resources/Images/arrow_sheet.png")), 
	frame(AssetManager::GetTexture("./Resources/Images/frame.png")),
	background1(AssetManager::GetTexture("./Resources/Images/background.png")),
	background2(AssetManager::GetTexture("./Resources/Images/Menu.png")),
	tiles(AssetManager::GetTexture("./Resources/Images/tiles.png")),
	blockFont(AssetManager::GetTexture("./Resources/Images/Block Font.png"))

{
	tiles.setTextureRect(sf::IntRect(0, 0, 18, 18));
	font.loadFromFile("./Resources/Fonts/Sansation.ttf");
}

void Game::run()  //运行函数的菜单，在这里选择游戏模式
{
	int gameModestatus = 0;
	sf::Vector2i startFontSize(18, 32);
	std::vector<sf::Sprite> alphabet;  //设置二十六个字母
	for(int i = 0; i< 26; ++i)
	{
		alphabet.push_back(sf::Sprite(blockFont));
		alphabet.back().setTextureRect(sf::IntRect((i + 1) * 18 , 2 * 32, 18, 32));
	}
	//开始菜单屏幕上的文字
	float startData[][3] = {0, 0, 13, 0, 1, 4, 0, 2, 22, 0, 3.3, 6, 0, 4.3, 0, 0, 5.3, 12, 0, 6.3, 4, 
						1, 0, 6, 1, 1, 0, 1, 2, 12, 1, 3, 4, 1, 4.3, 12, 1, 5.3, 14, 1, 6.3, 3, 1, 7.3, 4,
						2, 1, 14, 2, 2, 15, 2, 3, 19, 2, 4, 8, 2, 5, 14, 2, 6, 13,
						3, 2, 4, 3, 3, 23, 3, 4, 8, 3, 5, 19};
	int frameNum = 20; 
	float animationDuration = 1; 

	sf::Time deltaTime;
	sf::Time elapsedTime;
	sf::Clock clock;

	while (window.isOpen()&&!(gameMode))
	{
		sf::Event e;
		deltaTime = clock.restart();

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) window.close();
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Up) gameModestatus=(gameModestatus-1)<0?3:(gameModestatus - 1);
				else if (e.key.code == sf::Keyboard::Down) gameModestatus = (gameModestatus + 1) % 4;
				else if (e.key.code == sf::Keyboard::Enter) gameMode = gameModestatus+1;
			}
		}
		elapsedTime += deltaTime;
		float timeAsSeconds = elapsedTime.asSeconds();
		window.clear(sf::Color::White);
		window.draw(background2);
		for(int i = 0; i < 25; ++i)
		{ 
			alphabet.at(startData[i][2]).setPosition(85 + 22 * startData[i][1], 205 + 35 * startData[i][0]);
			window.draw(alphabet.at(startData[i][2]));
		}
		//sf::Text startText;
		//startText.setFont(font);
		//startText.setString(sf::String(" start game\ngame mode\n    option\n      exit"));
		//startText.setCharacterSize(20);
		//startText.setFillColor(sf::Color::Black);
		//startText.setStyle(sf::Text::Bold);
		//startText.setPosition(110, 200);
		//window.draw(startText);
		int animFramex = (static_cast<int>((timeAsSeconds / animationDuration)*frameNum) % frameNum) % 4;
		int animFramey = (static_cast<int>((timeAsSeconds / animationDuration)*frameNum) % frameNum) / 4;

		arrow.setTextureRect(sf::IntRect(animFramex *28, animFramey *21, 28, 21));
		arrow.setScale(0.8f,0.8f);

		arrow.setPosition(40, 213 + 35 * gameModestatus);
		window.draw(arrow);
		window.display();
	}
	switch (gameMode)
	{
		case 1:gameModeOne();
		default:
			break;
	}
}

void Game::gameModeOne()
{
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		processEvents();   
		update();         
		gamePoints += shape.checkLine();
		message();
		render();
		delay = 0.5f;
	}
}

void Game::processEvents()
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed) window.close();

		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Up)
			{
				shape.rotateit();
			}
			else if (e.key.code == sf::Keyboard::Left) shape.moveit(1,-1);
			else if (e.key.code == sf::Keyboard::Right) shape.moveit(1,1);
			else if (e.key.code == sf::Keyboard::Down) delay = 0.05f;
			else if (e.key.code == sf::Keyboard::Space)
			{
				if (Status) Status = false;
				else Status = true;
			}
		}
	}
}

void Game::update()
{
	if ((timer > delay)&&(Status))
	{
		shape.moveit(2, 1);
		shape.newShape();
		timer = 0;
	}
}

void Game::render()
{
	window.clear(sf::Color::White);
	window.draw(background1);

	for (int i = 0; i < shape.M; i++)
		for (int j = 0; j < shape.N; j++)
		{
			if (shape.field[i][j] == 0) continue;
			tiles.setTextureRect(sf::IntRect(shape.field[i][j] * 18, 0, 18, 18));
			tiles.setPosition((float)j * 18, (float)i * 18);
			tiles.move(28, 31); //offset
			window.draw(tiles);
		}
	for (int i = 0; i < 4; i++)
	{
		tiles.setTextureRect(sf::IntRect(shape.colorNum * 18, 0, 18, 18));
		tiles.setPosition((float)shape.a[i].x * 18, (float)shape.a[i].y * 18);
		tiles.move(28, 31); //offset
		window.draw(tiles);
	}
	window.draw(frame);
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(70, 355));
	rectangle.setFillColor(sf::Color(255, 255, 255, 120));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(2);
	rectangle.setPosition(240, 35);
	window.draw(rectangle);

	text.setFont(font);
	text.setString(sf::String("Points:") + sf::String(std::to_string(gamePoints))
		+ sf::String("\nMode:hard") + sf::String("\nRecord:0"));
	text.setCharacterSize(10);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(250, 50);
	window.draw(text);
	if (!Status)
	{
		sf::RectangleShape timeOutBG;
		timeOutBG.setSize(sf::Vector2f(320, 480));
		timeOutBG.setFillColor(sf::Color(255, 255, 255, 120));
		timeOutBG.setPosition(0, 0);

		sf::Text timeOutText;
		timeOutText.setFont(font);
		timeOutText.setString(sf::String("GAME PAUSED"));
		timeOutText.setCharacterSize(30);
		timeOutText.setFillColor(sf::Color::Black);
		timeOutText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		timeOutText.setPosition(55, 160);
		
		window.draw(timeOutBG);
		window.draw(timeOutText);
	}
	window.display();
}

void Game::message()
{
}
