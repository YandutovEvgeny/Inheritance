#include<iostream>
#include<stdlib.h>
using std::cin;
using std::cout;
using std::endl;

enum Color
{
	console_gray = 0x88,  //0x88 - шестнадцатеричный код цвета
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white = 0xFF
};
//enum - перечисление. Перечисление - набор именованных констант типа int.

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

class Rectangle :public Shape   //Прямоугольник
{
	double left_side;           //Левая сторона
	double upper_side;          //Верхняя сторона
public:
	double get_left_side()const
	{
		return left_side;
	}
	double get_upper_side()const
	{
		return upper_side;
	}
	void set_left_side(double left_side)
	{
		if (left_side <= 0)left_side = 1;
		this->left_side = left_side;
	}
	void set_upper_side(double upper_side)
	{
		if (upper_side <= 0)upper_side = 2;
		this->upper_side = upper_side;
	}
	Rectangle(double upper_side, double left_side, Color color) :Shape(color)
	{
		set_upper_side(upper_side);
		set_left_side(left_side);
		cout << "RecConstructor: " << this << endl;
	}
	~Rectangle()
	{
		cout << "RecDestructor: " << this << endl;
	}

	double get_area()const
	{
		return left_side * upper_side;
	}
	double get_perimeter()const
	{
		return (left_side * 2) + (upper_side * 2);
	}
	void draw()const
	{
		for (int i = 0; i < left_side; i++)
		{
			for (int j = 0; j < upper_side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Triangle :public Shape   //Треугольник
{
	double height;           //Высота
	double side;             //Сторона
public:
	double get_height()const
	{
		return height;
	}
	double get_side()const
	{
		return side;
	}
	void set_height(double height)
	{
		if (height <= 0)height = 2;
		this->height = height;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 2;
		this->side = side;
	}
	Triangle(double side, double height, Color color) :Shape(color)
	{
		set_side(side);
		set_height(height);
		cout << "TriConstructor: " << this << endl;
	}
	~Triangle()
	{
		cout << "TriDestructor: " << this << endl;
	}

	double get_area()const
	{
		return 0.5 * (side * height);
	}
	double get_perimeter()const
	{
		return side * 3;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)                  //|    *
		{                                               //|   * *
			for (int j = i; j < side; j++)              //|  * * *
			{                                           //| * * * *
				cout << " ";                            //|* * * * *
			}
			for (int j = 0; j <= i; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Circle :public Shape             //Круг
{
	double radius;                     //Радиус
	double number_pi;                  //Число Пи
public:
	double get_radius()const
	{
		return radius;
	}
	double get_number_pi()const
	{
		return number_pi;
	}
	void set_radius(double radius)
	{
		if (radius <= 0)radius = 1;
		this->radius = radius;
	}
	void set_number_pi(double number_pi)
	{
		this->number_pi = number_pi;
	}
	Circle(double radius, double number_pi, Color color) :Shape(color)
	{
		set_radius(radius);
		set_number_pi(number_pi);
		cout << "CircConstructor: " << this << endl;
	}
	~Circle()
	{
		cout << "CircDestructor: " << this << endl;
	}

	double get_area()const
	{
		return number_pi * pow(radius, 2);
	}
	double get_perimeter()const
	{
		return 2 * radius * number_pi;
	}
	void draw()const
	{
		cout << "O" << endl;
	}
};


//#define SQUARE
//#define RECTANGLE
//#define TRIANGLE
//#define CIRCLE

void main()
{
	setlocale(LC_ALL, "");
#ifdef SQUARE
	//Shape shape;
	Square square(5, Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
#endif // SQUARE
#ifdef RECTANGLE
	Rectangle rectangle(7, 5, Color::console_gray);
	cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	cout << "Периметр прямоугольника: " << rectangle.get_perimeter() << endl;
	rectangle.draw();
#endif // RECTANGLE
#ifdef TRIANGLE
	Triangle triangle(5, 5, Color::console_green);
	cout << "Площадь треугольника: " << triangle.get_area() << endl;
	cout << "Периметр треугольниа: " << triangle.get_perimeter() << endl;
	triangle.draw();
#endif // TRIANGLE
#ifdef CIRCLE
	Circle circle(5, 22 / 7, Color::console_white);
	cout << "Площадь круга: " << circle.get_area() << endl;
	cout << "Периметр круга: " << circle.get_perimeter() << endl;
	circle.draw();
#endif // CIRCLE
	Shape* Shapes[] =
	{
		new Square(5, Color::console_red),
		new Rectangle(7, 5, Color::console_gray),
		new Triangle(5, 5, Color::console_green),
		new Circle(5, 22 / 7, Color::console_white)
	};
	srand(time(NULL));
	for (int i = 0; i < sizeof(Shapes) / sizeof(Shapes[0]); i++)
	{
		Shapes[i] = rand() % 4   //  ?????????????????????????
	}


}