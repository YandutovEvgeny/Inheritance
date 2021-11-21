#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

#define INHERITANCE

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

	/*Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),  //upcast
		new Student("Vercetti", "Tomas", 30, "Cryminal", "Vice", 90),    //upcast
		new Teacher("Сащеко", "Роман", 33, "C++ basic and OOP teacher", 10, "good"),  //upcast
		new Student("Diaz", "Ricardo", 55, "Weapon distribution", "Vice", 80),
		new Graduate("Savchenko", "Oleg", 30, "C++ developer", "WW_01", 93,
		"Разработка ПО для коммерческих компаний", 12),
		new Teacher("Eistein", "Albert", 143, "Astronomy", 120, "good")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n------------------------------\n";
		group[i]->print();
	}
	cout << "\n------------------------------\n";

	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++) 
	{
		delete[] group[i];
	}*/
}