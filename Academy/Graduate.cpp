#include"Graduate.h"
const string& Graduate::get_diploma_thesis_subject()const
{
	return diploma_thesis_subject;
}
unsigned int Graduate::get_valuation()const
{
	return valuation;
}
void Graduate::set_diploma_thesis_subject(const string& diploma_thesis_subject)
{
	this->diploma_thesis_subject = diploma_thesis_subject;
}
void Graduate::set_valuation(unsigned int valuation)
{
	this->valuation = valuation;
}
//           Constructors:
Graduate::Graduate
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
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
//             Methods:
void Graduate::print()const
{
	Student::print();
	cout << "Тема дипломной работы: " << diploma_thesis_subject <<
		", оценка: " << valuation << endl;
}