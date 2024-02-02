#include <SFML/Graphics.hpp>

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML!!!", sf::Style::Default);

sf::Sprite skySprite;
sf::Texture skyTexture;
sf::Sprite bgSprite;
sf::Texture bgTexture;
sf::Texture heroTexture;
sf::Sprite heroSprite;

void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(heroSprite);
}

void init()
{
	skyTexture.loadFromFile("Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
	bgTexture.loadFromFile("Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);
	heroTexture.loadFromFile("Assets/graphics/hero.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
	heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);
}

int main()
{
	init();
	sf::Event event;
	
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}