#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;        //Фамилия
	string first_name;       //Имя
	unsigned int age;        //Возраст
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

	//            Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//             Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << "лет.\n";
	}
};

class Student:public Human
{
	string speciality;      //Специальность
	string group;           //Группа
	double rating;          //Успеваемость
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	
	//            Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	):Human(last_name, first_name, age) //Делегируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//        Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", группа: " << group << ", успеваемость: " << rating << "%" << endl;
	}
};

class Teacher:public Human
{
	string speciality;         //Специальность
	unsigned int experience;   //Опыт работы
	string evil;               //Эмоцианальное состояние
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	const string& get_evil()const
	{
		return evil;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_evil(const string& evil)
	{
		this->evil = evil;
	}
	//          Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience, const string& evil
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		set_evil(evil);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//              Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality <<
			", опыт работы: " << experience << "лет" <<
			", эмоциональное состояние: " << evil << endl;
	}
};

class Graduate:public Student
{
	string diploma_thesis_subject;
	unsigned int valuation;
public:
	const string& get_diploma_thesis_subject()const
	{
		return diploma_thesis_subject;
	}
	unsigned int get_valuation()const
	{
		return valuation;
	}
	void set_diploma_thesis_subject(const string& diploma_thesis_subject)
	{
		this->diploma_thesis_subject = diploma_thesis_subject;
	}
	void set_valuation(unsigned int valuation)
	{
		this->valuation = valuation;
	}
	//           Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& get_diploma_thesis_subject, unsigned int get_valuation
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_thesis_subject(get_diploma_thesis_subject);
		set_valuation(get_valuation);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//             Methods:
	void print()const
	{
		Student::print();
		cout << "Тема дипломной работы: " << diploma_thesis_subject <<
			", оценка: " << valuation << endl;
	}
};

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human t("Montana", "Antonio", 35);
	t.print();

	Student f("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93);
	f.print();

	Teacher s("Сащеко", "Роман", 33, "C++ basic and OOP teacher", 10, "good");
	s.print();

	Graduate i("Savchenko", "Oleg", 30, "C++ developer", "WW_01", 93, "Разработка ПО для коммерческих компаний", 12);
	i.print();
#endif // INHERITANCE

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),  //upcast
		new Student("Vercetti", "Tomas", 30, "Cryminal", "Vice", 90),    //upcast
		new Teacher("Сащеко", "Роман", 33, "C++ basic and OOP teacher", 10, "good"),  //upcast
		new Student("Diaz", "Ricardo", 55, "Weapon distribution", "Vice", 80),
		new Graduate("Savchenko", "Oleg", 30, "C++ developer", "WW_01", 93,
		"Разработка ПО для коммерческих компаний", 12),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120, "good")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n------------------------------\n";
		group[i]->print();
	}
	cout << "\n------------------------------\n";
}