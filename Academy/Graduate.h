#pragma once
#include"Student.h"
class Graduate :public Student
{
	string diploma_thesis_subject;
	unsigned int valuation;
public:
	const string& get_diploma_thesis_subject()const;
	unsigned int get_valuation()const;
	void set_diploma_thesis_subject(const string& diploma_thesis_subject);
	void set_valuation(unsigned int valuation);
	//           Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& get_diploma_thesis_subject, unsigned int get_valuation
	);
	~Graduate();
	//             Methods:
	void print()const;
};