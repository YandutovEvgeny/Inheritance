#include<iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//                 Constructor:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:" << this << endl;
	}
	
	//                  Mathods:
	void Print()const
	{
		cout << last_name << " " << first_name << " " << age << "лет" << endl;
	}

};

class Employee:public Human
{
	string post;
public:
	const string& get_post()const
	{
		return post;
	}
	void set_post(const string& post)
	{
		this->post = post;
	}

	//              Constructor:
	Employee(const string& last_name, const string& first_name,
		unsigned int age, const string& post) :Human(last_name, first_name, age)
	{
		set_post(post);
		cout << "EConstructor:" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:" << this << endl;
	}

	//               Methods:
	void Print()const
	{
		Human::Print();
		cout << " должность: " << post << endl;
	}
};

class Hourly_worker:public Employee   // Работник с почасовой оплатой
{
	double completed_job;   //Время выполненой работы
	double cash_per_hour;   //Сумма денег в час
public:
	const double get_completed_job()const
	{
		return completed_job;
	}
	const double get_cash_per_hour()const
	{
		return cash_per_hour;
	}

	void set_completed_job(const double completed_job)
	{
		this->completed_job = completed_job;
	}
	void set_cash_per_hour(const double cash_per_hour)
	{
		this->cash_per_hour = cash_per_hour;
	}

	//            Constructor:
	Hourly_worker(const string& last_name, const string& first_name,
		unsigned int age, const string& post, double completed_job,
		double cash_per_hour) :Employee(last_name, first_name, age, post)
	{
		set_completed_job(completed_job);
		set_cash_per_hour(cash_per_hour);
		cout << "HwConstructor: " << this << endl;
	}
	~Hourly_worker()
	{
		cout << "HwDestructor: " << this << endl;
	}

	//            Methods:
	void Print()const
	{
	    Employee::Print();
		cout << " время выполненной работы: " << completed_job << "часов" << " денег в час: " << cash_per_hour << "$" << endl;
	}
};

class Salaried_worker :public Employee   //Сотрудник с фиксированным окладом
{
	double salary;    //Размер оклада
public:
	const double get_salary()const
	{
		return salary;
	}
	void set_salary(const double salary)
	{
		this->salary = salary;
	}

	//               Constructor:
	Salaried_worker(const string& last_name, const string& first_name,
		unsigned int age, const string& post, double salary) :Employee(last_name, first_name, age, post)
	{
		set_salary(salary);
		cout << "SwConstructor: " << this << endl;
	}
	~Salaried_worker()
	{
		cout << "SwDectructor: " << this << endl;
	}

	//                Methods:
	void Print()const
	{
		cout << " оклад: " << salary << "$" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	const Human* group[] =
	{
		new Salaried_worker("Zubenko", "Michael", 45, "operator", 35678.35),
		new Hourly_worker("Pinkman", "Jessie", 22, "producer", 169, 25),
		new Hourly_worker("White", "Walter", 50, "culinary", 150, 45),
		new Salaried_worker("Diaz", "Ricardo", 55, "distributor", 50000)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
	}
}