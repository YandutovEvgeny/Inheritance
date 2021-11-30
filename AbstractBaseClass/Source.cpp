#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move()const = 0;   //Чисто виртуальный метод(pure virtual function), 
	                                //именно этот метод и делает класс абстрактным
};

class GroundVehicle :public Vehicle
{
	//Абстрактный класс
};

class WaterVehicle :public Vehicle
{
	//Абстрактный класс
};

class AirVehicle :public Vehicle
{
	int height;  //Абстрактный класс
};

class Bike :public GroundVehicle
{
public:
	//Конкретный класс, поскольку он ОПРЕДЕЛЯЕТ чисто виртуальный метод move
	void move()const
	{
		cout << "Мотоцикл едет на двух колёсах" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "quattro работает хорошо, по снегу самое то!" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()const
	{
		cout << "Лодка плывёт" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "russian");
	//Vehicle v;  //Невозможно создать экземпляр абстрактного класса
	//GroundVehicle gv; //Этот класс также является абстрактным, поскольку он не определяет метод move
	Bike HD;
	HD.move();
	Car Audi;
	Audi.move();
	Boat boat;
	boat.move();
}