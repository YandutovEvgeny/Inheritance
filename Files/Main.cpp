#include<iostream>
#include<fstream>
using namespace std;

#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "Hello World" << endl;
	ofstream fout("File.txt", std::ios_base::app/*append*/);   //Создаём и открываем поток
	fout << "Hello World" << endl;
	fout.close();
	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	const int SIZE = 256;
	char buffer[SIZE]{};

	ifstream fin("File.txt");
	if (fin.is_open())
	{
		while (!fin.eof())  //Пока НЕ end of file
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
	}
	else
	{
		cerr << "File not found" << endl;
	}
	fin.close();
#endif // READ_FROM_FILE

}