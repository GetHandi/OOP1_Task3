#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Time
{
	int H;
	int M, S;

	///перевод из секунд во время;
	/// H - значение часа;
	/// M - значение минут;
	/// S - значение секунд;
	void fromSeconds(int S);

public:
	
	/// Конструктор по умолчанию
	Time();


	/// Конструктор задающий значения объекта мкласса;
	/// H - значение часа;
	/// M - значение минут;
	/// S - значение секунд;
	Time(int H, int M, int S);

	
	/// Сеттер для всего времени;
	/// H - значение часов;
	/// M - значение минут;
	/// S - значение секунд;
	void SetTime(int H, int M, int S);
	

	/// Сеттер для часов
	/// H - значение часа
	void SetH(int H);


	/// Сеттер для минут;
	/// M - значение минут;
	void SetM(int M);


	/// Сеттер для секунд;
	/// S - значение секунд;
	void SetS(int S);


	/// Геттер для часов;
	/// H - значение часов;
	int GetH() const;


	/// Геттер для минут;
	/// M - значение минут;
	int GetM() const;


	/// Геттер для секунд;
	/// S - значение секунд;
	int GetS() const;


	/// Метод вывода времени в консоль;
	void PrintTime();


	/// Метод сложения времени;
	/// H - значение часов;
	/// M - значение минут;
	/// S - значение секунд;
	void SumTime(int H, int M, int S);


	/// Метод вычитания времени;
	/// H - значение часов;
	/// M - значение минут;
	/// S - значение секунд;
	void DiffTime(int H, int M, int S);


	/// Метод добавления часов;
	/// H - значение часов;
	void AddH(int H);


	/// Метод добавления минут;
	/// M - значение минут;
	void AddM(int M);


	/// Метод добавления секунд;
	/// S - значение секунд;
	void AddS(int S);


	/// Метод перевода в часы;
	double toHours();


	/// Метод перевода в минуты;
	double toMinutes();


	/// Метод перевода в секунды;
	int toSeconds();
	

	/// Метод преобразования в строку;
	string toString();


	/// Метод записи в файл;
	/// path - расположение текстового файла;
	void toFile(const string& path);


	/// Метод чтения из файла;
	/// path - расположение текстового файла;
	static void fromFile(const string& path);


	/// Метод для генерации массива объектов класса;
	/// arr - ссылка на массив, SIZE - размер массива;
	static void TimeArr(Time * arr, int SIZE);


	/// Метод вывода массива объектов класса в консоль;
	/// arr - ссылка на массив, SIZE - размер массива;
	static void TimeArrPrint(Time* arr, int SIZE);

};
	

