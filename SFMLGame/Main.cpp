#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.hpp"

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!", sf::Style::Default);

sf::Vector2f playerPosition;
bool playerMoving = false;
sf::Sprite skySprite;
sf::Texture skyTexture;
sf::Sprite bgSprite;
sf::Texture bgTexture;
Hero hero;

static void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);	
	window.draw(hero.getSprite());
}

static void init()
{
	skyTexture.loadFromFile("Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
	bgTexture.loadFromFile("Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);
	hero.init("Assets/graphics/hero.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
}

static void update(float dt)
{
	hero.update(dt);
}

static void updateInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				hero.jump(750.0f);
			}
		}
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			window.close();
	}
}

int main()
{
	sf::Clock clock;
	window.setFramerateLimit(60);

	init();	
	
	while (window.isOpen())
	{
		updateInput();
		sf::Time dt = clock.restart();
		update(dt.asSeconds());
		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}