#include <SFML/Graphics.hpp>

int main()
{
	sf::Vector2f viewSize(1024, 768);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	sf::RenderWindow window(vm, "Hello SFML!!!", sf::Style::Default);
	
	while (window.isOpen())
	{
		window.clear(sf::Color::Red);
		window.display();
	}
	return 0;
}