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
		cout << last_name << " " << first_name << " " << age << "лет." << endl;
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
};

void main()
{
	setlocale(LC_ALL, "");
}