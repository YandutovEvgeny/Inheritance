#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move()const = 0;   //����� ����������� �����(pure virtual function), 
	                                //������ ���� ����� � ������ ����� �����������
};

class GroundVehicle :public Vehicle
{
	//����������� �����
};

class WaterVehicle :public Vehicle
{
	//����������� �����
};

class AirVehicle :public Vehicle
{
	int height;  //����������� �����
};

class Bike :public GroundVehicle
{
public:
	//���������� �����, ��������� �� ���������� ����� ����������� ����� move
	void move()const
	{
		cout << "�������� ���� �� ���� ������" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "quattro �������� ������, �� ����� ����� ��!" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()const
	{
		cout << "����� �����" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "russian");
	//Vehicle v;  //���������� ������� ��������� ������������ ������
	//GroundVehicle gv; //���� ����� ����� �������� �����������, ��������� �� �� ���������� ����� move
	Bike HD;
	HD.move();
	Car Audi;
	Audi.move();
	Boat boat;
	boat.move();
}