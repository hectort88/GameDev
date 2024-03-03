#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Rocket.hpp"

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
std::vector<Enemy*> enemies;
std::vector<Rocket*> rockets;
float currentTime;
float prevTime = 0.0f;

static void spawnEnemy()
{
	int randLoc = rand() % 3;
	sf::Vector2f enemyPos;
	float speed;
	switch (randLoc)
	{
	case 0:
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
		speed = -400;
		break;
	case 1:
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60f);
		speed = -550;
		break;
	case 2:
		enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40f);
		speed = -650;
		break;
	default:
		std::cerr << "Incorrect Value" << std::endl;
		return;
	}

	Enemy* enemy = new Enemy();
	enemy->init("Assets/graphics/enemy.png", enemyPos, speed);
	enemies.push_back(enemy);
}

static void shoot()
{
	Rocket* rocket = new Rocket();
	auto position = hero.getSprite().getPosition();
	position.y += 16;
	position.x += 40;
	rocket->init("Assets/graphics/rocket.png", position, 600.0f);
	rockets.push_back(rocket);
}

static bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
	auto shape1 = sprite1.getGlobalBounds();
	auto shape2 = sprite2.getGlobalBounds();

	return shape1.intersects(shape2);
}

static void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);	
	window.draw(hero.getSprite());

	for (Enemy *enemy: enemies) {
		window.draw(enemy->getSprite());
	}

	for (Rocket *rocket : rockets)
	{
		window.draw(rocket->getSprite());
	}
}

static void init()
{
	skySprite.setTexture(skyTexture);
	bgTexture.loadFromFile("Assets/graphics/bg.jpg");
	bgSprite.setTexture(bgTexture);
	hero.init("Assets/graphics/hero3.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
	srand((int)time(0));
}

static void update(float dt)
{
	hero.update(dt);
	currentTime += dt;
	if (currentTime > prevTime + 1.125f) {
		spawnEnemy();
		prevTime = currentTime;
	}

	// Check Collision
	for (size_t idx_rocket = 0; idx_rocket < rockets.size(); idx_rocket++)
	{
		for (size_t idx_enemy = 0; idx_enemy < enemies.size(); idx_enemy++)
		{
			Rocket* rocket = rockets[idx_rocket];
			Enemy* enemy = enemies[idx_enemy];

			if (checkCollision(rocket->getSprite(), enemy->getSprite()))
			{
				std::cout << "Rocket " << idx_rocket << " killed enemy " << idx_enemy << "\n";
				rockets.erase(rockets.begin() + idx_rocket);
				enemies.erase(enemies.begin() + idx_enemy);

				delete(rocket);
				delete(enemy);
			}
		}
	}

	// Update Enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		Enemy* enemy = enemies[i];
		enemy->update(dt);
		if (enemy->getSprite().getPosition().x < 0)
		{
			enemies.erase(enemies.begin() + i);
			delete(enemy);
		}
	}

	// Update Rockets
	for (int i = 0; i < rockets.size(); i++)
	{
		Rocket* rocket = rockets[i];
		rocket->update(dt);
		if (rocket->getSprite().getPosition().x > viewSize.x)
		{
			rockets.erase(rockets.begin() + i);
			delete(rocket);
		}
	}
	
}

static void updateInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				hero.jump(750.0f);
			}
			if (event.key.code == sf::Keyboard::Space) {
				shoot();
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