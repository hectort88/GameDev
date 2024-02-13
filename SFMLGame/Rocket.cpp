#include "Rocket.hpp"

Rocket::Rocket()
{
}

Rocket::~Rocket()
{
}

void Rocket::init(std::string textureName, sf::Vector2f position, float _speed)
{
	m_position = position;
	m_speed = _speed;

	// Load Texture
	m_texture.loadFromFile(textureName.c_str());

	//create sprite
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2 );
}

void Rocket::update(float dt)
{
	m_sprite.move(m_speed * dt, 0);
}

sf::Sprite Rocket::getSprite()
{
	return m_sprite;
}
