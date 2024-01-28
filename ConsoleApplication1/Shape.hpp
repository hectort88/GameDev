#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
private:
	int m_width, m_length;
public:
	Shape(int length, int width) : m_length(length), m_width(width) 
	{}
	~Shape();
	int area() const;
	void print();
};

#endif // SHAPE_H
