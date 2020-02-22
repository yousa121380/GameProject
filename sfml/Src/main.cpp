#include"Game.h"
int main()
{
	Game game;
	game.run();
	return 0;
}
//#include"AssetManager.h"
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(482, 180), "Bad Squares!");  //创建窗口代码
//	AssetManager manager;
//
//	sf::Vector2i spriteSize(28, 21);
//	sf::Vector2i spriteSize1(18, 32);
//	sf::Texture t,t1;
//	t.loadFromFile("arrow_sheet.png");
//	sf::Sprite sprite(AssetManager::GetTexture("arrow_sheet.png"));
//	t1.loadFromFile("Block Font.png");
//	sf::Sprite sprite1(t1);
//	int frameNum = 20; //Animation consists of 8 frames
//	float animationDuration = 1; // 1 seconds
//
//	sf::Time deltaTime;
//	sf::Time elapsedTime;
//	sf::Clock clock;
//
//	while (window.isOpen())
//	{
//		// Returns the elapsed time and restarts the clock
//		deltaTime = clock.restart();
//
//		//Handle input
//
//		//Accumulate time with each time
//		elapsedTime += deltaTime;
//		float timeAsSeconds = elapsedTime.asSeconds();
//		int fontx = 1, fonty = 2;
//		sprite1.setTextureRect(sf::IntRect(fontx *spriteSize1.x,fonty*spriteSize1.y, spriteSize1.x, spriteSize1.y));
//		sprite1.setPosition(50, 50);
//		//Get the current animation frame
//		int animFramex = (static_cast<int>((timeAsSeconds / animationDuration)*frameNum) % frameNum) % 4;
//		int animFramey = (static_cast<int>((timeAsSeconds / animationDuration)*frameNum) % frameNum) / 4;
//
//
//		// Set the texture rectangle, depending on the frame
//		sprite.setTextureRect(sf::IntRect(animFramex *spriteSize.x, animFramey *spriteSize.y, spriteSize.x, spriteSize.y));
//		sprite.setScale(0.8f,0.8f);
//		// Render frame
//		window.clear();
//		window.draw(sprite);
//		window.draw(sprite1);
//		sprite1.setTextureRect(sf::IntRect((fontx+1) *spriteSize1.x, fonty*spriteSize1.y, spriteSize1.x, spriteSize1.y));
//		sprite1.setPosition(50 + spriteSize1.x, 50);
//		window.draw(sprite1);
//		window.display();
//	}
//	system("pause");
//	return 0;
//}