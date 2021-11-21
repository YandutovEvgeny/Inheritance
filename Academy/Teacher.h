#pragma once
#include"Human.h"
class Teacher :public Human
{
	string speciality;         //—пециальность
	unsigned int experience;   //ќпыт работы
	string evil;               //Ёмоцианальное состо€ние
public:
	const string& get_speciality()const;
	unsigned int get_experience()const;
	const string& get_evil()const;
	void set_speciality(const string& speciality);
	void set_experience(unsigned int experience);
	void set_evil(const string& evil);
	//          Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience, const string& evil
	);
	~Teacher();
	//              Methods:
	void print()const;
};