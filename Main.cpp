#include <iostream>
#include <cassert>
#include "Time.h"

using namespace std;

void toObj(const string& path, Time& obj)
{
	fstream fs;
	try
	{
		fs.open(path, fstream::in); //чтение
		string str = "";
		while (!fs.eof()) //проверяем, закончился ли файл
		{
			getline(fs, str);
			if (str != "")
			{
				int index_sep1 = str.find(':');
				int index_sep2 = str.find(':', index_sep1 + 1);
				obj.SetH(stoi(str.substr(0, index_sep1)));
				obj.SetM(stoi(str.substr(index_sep1+1, index_sep2)));
				obj.SetS(stoi(str.substr(index_sep2+1, '\n')));

			}
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	fs.close();
}

int main()
{
	setlocale(LC_ALL, "rus");


	Time Test1(65, 25, 15);
	//assert перевод в секунды
	assert(abs(Test1.toSeconds() - 235515) < 0.001);
	assert(abs(Test1.toHours() - 65.42083) < 0.001);
	assert(Test1.toString() == "65:25:15");
	assert()


	





	//записаь объекта в файл

	//Time c(23, 15, 48);
	//c.PrintTime();
	//cout << endl;
	//Time d;
	//Time e(15, 15, 15);
	string path = "TimeData.txt";

	//c.toFile(path);
	//d.toFile(path);
	//e.toFile(path);



	// (1) работа с динамическим массивом;
	cout << endl << "Работа с динамическим массивом!" << endl;
	const int SIZE1 = 15;
	Time* arr1 = new Time[SIZE1];
	Time::TimeArr(arr1, SIZE1);
	Time::TimeArrPrint(arr1, SIZE1);
	delete[] arr1;

	// (2) чтение из файла и запись в объект;
	cout << endl << "Чтение из файла и запись в объект!" << endl;
	Time A1;
	toObj(path, A1);
	A1.PrintTime();


	// (3)Работа со статическим массивом!
	cout << endl << "Работа со статическим массивом!" << endl;
	Time a3;
	Time b3(1, 1, 1);
	Time c3(25, 25, 25);
	//const int SIZE3 = 3;

	Time arr3[] = { a3,b3,c3 };
	for ( int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
	{
		arr3[i].PrintTime();
	}



	//(4) Динамический объект
	cout << endl << "Работа с динамическим объектом!" << endl;

	Time* a4 = new Time();
	a4->PrintTime();
	delete a4;


	//(5) Статический массив из указателей
	cout << endl << "Работа cо статическим массивом из указателей на объект!" << endl;
	
	const int a5 = 3;
	Time* arr5[a5];
	arr5[0] = new Time(); // arr5 хранит адреса объектов;
	arr5[1]->GetH();
	(*arr5[0]).GetS(); // разименовывание;





	return 0;



}