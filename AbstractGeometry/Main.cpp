#include<iostream>
#include<string>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;

namespace Geometry
{
	enum Color
	{
		console_gray = 0x88,  //0x88 - шестнадцатеричный код цвета
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		red        = 0x000000FF,
		green      = 0x0000FF00,
		dark_green = 0x0000AA00,
		blue       = 0x00FF0000,
		yellow     = 0x0000FFFF  //1-00: альфа-канал, 2-00: blue, 3-FF: green, 4-FF: red
		//

		/*console_gray,  //0x88 - шестнадцатеричный код цвета
		console_blue,
		console_green,
		console_red,
		console_white*/
	};
	//enum - перечисление. Перечисление - набор именованных констант типа int.

	const char* console_color[] =
	{
		"08",
		"19",
		"2A",
		"4C",
		"7F"
	};

	class Shape
	{
	protected:
		Color color;
		unsigned int width; //Ширина линии
		//Начальные координаты для рисования фигуры
		unsigned int start_x;
		unsigned int start_y;
	public:
		unsigned int get_width()const
		{
			return width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		void set_width(unsigned int width)
		{
			if (width > 20)width = 20;
			this->width = width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 1000)start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 700)start_y = 700;
			this->start_y = start_y;
		}
		Shape
		(
			Color color, unsigned int width = 5, unsigned int start_x = 100, 
			unsigned int start_y = 100
		) :color(color)
		{
			set_width(width);
			set_start_x(start_x);
			set_start_y(start_y);
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
		Square(double side, Color color, unsigned int width = 5, unsigned int start_x = 100,
			unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
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
			//std::string command = std::string("color ") + console_color[color];
			//cout << command << endl;
			//system(command.c_str());
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|BACKGROUND_RED);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
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
		Rectangle(double upper_side, double left_side, Color color, unsigned int width = 5, unsigned int start_x = 100,
			unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
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
			//1) Получаем окно консоли:
			HWND hwnd = GetConsoleWindow();
			//HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2) Создаём контекст устройства, полученного окна:
			HDC hdc = GetDC(hwnd);
			//3)Создаём карандаш:
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселей
			//4)Прежде чем рисовать, нужно выбрать чем и на чём рисовать:
			SelectObject(hdc, hPen);
			//5)Чтобы фигура была закрашена орпеделённым цветом, нужно создать и применить кисть:
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + upper_side, start_y + left_side);
			DeleteObject(hBrush);
			//?)Удаляем карандаш:
			DeleteObject(hPen);
			//?) Все контексты устройств нужно удалять, чтобы освободить занимаемые ими ресурсы:
			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < left_side; i++)
			{
				for (int j = 0; j < upper_side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
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
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		Circle(double radius, Color color, unsigned int width = 5, unsigned int start_x = 100,
			unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_radius(radius);
			cout << "CircConstructor: " << this << endl;
		}
		~Circle()
		{
			cout << "CircDestructor: " << this << endl;
		}

		double get_area()const
		{
			return (22/7)  * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * radius * (22/7);
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			SelectObject(hdc, hPen);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);
			for (int i = 0; i < 25; cout << endl, i++); Sleep(200);
				
			::Ellipse(hdc, 0,150,radius*50,150 + radius*50);
			
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
			//cout << "O" << endl;
		}
	};
}


//#define SQUARE
#define RECTANGLE
//#define TRIANGLE
#define CIRCLE

void main()
{
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
	system("pause");*/
	setlocale(LC_ALL, "");
#ifdef SQUARE
	//Shape shape
	Geometry::Square square(5, Geometry::Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
#endif // SQUARE
#ifdef RECTANGLE
	Geometry::Rectangle rectangle(200, 100, Geometry::Color::yellow, 5, 200, 100);
	cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	cout << "Периметр прямоугольника: " << rectangle.get_perimeter() << endl;
	rectangle.draw();
#endif // RECTANGLE
#ifdef TRIANGLE
	Geometry::Triangle triangle(5, 5, Geometry::Color::console_green);
	cout << "Площадь треугольника: " << triangle.get_area() << endl;
	cout << "Периметр треугольниа: " << triangle.get_perimeter() << endl;
	triangle.draw();
#endif // TRIANGLE
#ifdef CIRCLE
	Geometry::Circle circle(5, Geometry::Color::red);
	cout << "Площадь круга: " << circle.get_area() << endl;
	cout << "Периметр круга: " << circle.get_perimeter() << endl;
	circle.draw();

#endif // CIRCLE
}