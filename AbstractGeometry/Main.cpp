#include<iostream>
using std::cin;
using std::cout;
using std::endl;

enum Color
{
	console_gray = 0x88,  //0x88 - ����������������� ��� �����
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white = 0xFF
};
//enum - ������������. ������������ - ����� ����������� �������� ���� int.

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color)
	{
		cout << "ShConstructor: " << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShDestructor: " << this << endl;
	}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
		cout << "SqConstructor: " << this << endl;
	}
	~Square()
	{
		cout << "SqDestructor: " << this << endl;
	}

	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape;
	Square square(5, Color::console_red);
	cout << "������� ��������: " << square.get_area() << endl;
	cout << "�������� ��������: " << square.get_perimeter() << endl;
	square.draw();
}