#include <iostream>
#include "Shape.hpp"

Shape::~Shape()
{
	std::cout << "Shape with width: " << m_width << " and length: " << m_length << " destroyed" << std::endl;
}

int Shape::area() const
{
	return m_width * m_length;
}

void Shape::print()
{
	std::cout << "Shape width: " << m_width << " and length: " << m_length << ", has area: " << area() << std::endl;
}