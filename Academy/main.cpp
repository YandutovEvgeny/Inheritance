#include<fstream>
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

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

	Graduate i("Savchenko", "Oleg", 30, "C++ developer", "WW_01", 93, "Develop software for inc.", 12);
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

	/*for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n------------------------------\n";
		group[i]->print();
	}
	cout << "\n------------------------------\n";

	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++) 
	{
		delete[] group[i];
	}*/


	fstream fout("File.txt", std::ios_base::app);
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//fout.write((char*)&group, (sizeof(group) / sizeof(Human*)));
		fout << group[i];
	}
	fout.close();
	system("notepad File.txt");

	const int SIZE = 256;
	char buffer[SIZE]{};
	ifstream fin("File.txt");
	if (fin.is_open())
	{

		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
	}
	else
	{
		cerr << "File not found" << endl;
	}
	fin.close();
}