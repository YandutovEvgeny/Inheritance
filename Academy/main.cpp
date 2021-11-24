#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

#define tab "\t"

class Human
{
protected:
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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//             Methods:
	virtual ostream& print(ostream& os)const
	{
		return os //<< last_name << " " << first_name << " " << age << "лет.";
			<< setiosflags(ios::left) << last_name << cout.width(10) << first_name << age;
			
	}

	virtual void to_file()
	{
		ofstream fout("File.txt", std::ios_base::app);
		fout << last_name << " " << first_name << " " << age << "лет.\n";
		fout.close();
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}

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
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os << tab;
		return os //<< "Специальность: " << speciality << tab << ", группа: " << group << tab <<", успеваемость: " << rating << "%";
			<< setiosflags(ios::left) << speciality << cout.width(25) << group << rating;
	}

	void to_file()
	{
		Human::to_file();
		ofstream fout("File.txt", std::ios_base::app);
		fout << ", cпециальность: " << speciality << ", группа: " << group << ", успеваемость: " << rating << "%\n";
		fout.close();
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
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os << tab;
		//return os /*<< "Специальность: "*/ << speciality << tab /*<<
		//	", опыт работы: "*/ << experience << tab/*<< "лет" <<
		//	", эмоциональное состояние: "*/ << evil;
		return os << setiosflags(ios::left) << speciality << cout.width(25) << experience << evil;
	}

	void to_file()
	{
		Human::to_file();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специальность: " << speciality <<
			", опыт работы: " << experience << "лет" <<
			", эмоциональное состояние: " << evil << endl;
		fout.close();
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
	ostream& print(ostream& os)const
	{
		Student::print(os);
		os << tab;
		return os /*<< "Тема дипломной работы: "*/ << diploma_thesis_subject << tab /*<<
			", оценка: "*/ << valuation;
	}

	void to_file()
	{
		Student::to_file();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Тема дипломной работы: " << diploma_thesis_subject << ", оценка: " << valuation << endl;
		fout.close();
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
		"Develop software for inc.", 12),
		new Teacher("Eistein", "Albert", 143, "Astronomy", 120, "good")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n------------------------------\n";
		//group[i]->print();
		//cout.width(i);
		cout << *group[i] << endl;
	}
	cout << "\n------------------------------\n";

	ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");

	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++) 
	{
		delete[] group[i];
	}

	/*ofstream fout("File.txt", std::ios_base::app);
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->to_file();
		//fout.write((char*)&group, (sizeof(group) / sizeof(Human*)));
		//fout << group[i];
	}
	system("notepad File.txt");

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}*/
}