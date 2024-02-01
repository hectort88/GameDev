#include <SFML/Graphics.hpp>

int main()
{
	sf::Vector2f viewSize(1024, 768);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	sf::RenderWindow window(vm, "Hello SFML!!!", sf::Style::Default);

	// Square
	sf::RectangleShape rectangle(sf::Vector2f(500.0f, 300.0f));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(viewSize.x / 2, viewSize.y / 2);
	rectangle.setOrigin(sf::Vector2f(rectangle.getSize().x / 2, rectangle.getSize().y / 2));

	// Circle
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(viewSize.x / 2, viewSize.y / 2);
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));

	// Triangle
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(-100, 0));
	triangle.setPoint(1, sf::Vector2f(0, -100));
	triangle.setPoint(2, sf::Vector2f(100, 0));
	triangle.setFillColor(sf::Color::Cyan);
	triangle.setPosition(viewSize.x / 2, viewSize.y / 2);

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(rectangle);
		window.draw(circle);
		window.draw(triangle);
		window.display();
	}
	return 0;
}