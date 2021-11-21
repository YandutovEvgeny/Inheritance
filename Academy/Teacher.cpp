#include"Teacher.h"
const string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
const string& Teacher::get_evil()const
{
	return evil;
}
void Teacher::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}
void Teacher::set_evil(const string& evil)
{
	this->evil = evil;
}
//          Constructors:
Teacher::Teacher
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, unsigned int experience, const string& evil
) :Human(last_name, first_name, age)
{
	set_speciality(speciality);
	set_experience(experience);
	set_evil(evil);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}
//              Methods:
void Teacher::print()const
{
	Human::print();
	cout << "�������������: " << speciality <<
		", ���� ������: " << experience << "���" <<
		", ������������� ���������: " << evil << endl;
}