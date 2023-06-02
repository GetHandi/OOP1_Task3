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

	///������� �� ������ �� �����;
	/// H - �������� ����;
	/// M - �������� �����;
	/// S - �������� ������;
	void fromSeconds(int S);

public:
	
	/// ����������� �� ���������
	Time();


	/// ����������� �������� �������� ������� �������;
	/// H - �������� ����;
	/// M - �������� �����;
	/// S - �������� ������;
	Time(int H, int M, int S);

	
	/// ������ ��� ����� �������;
	/// H - �������� �����;
	/// M - �������� �����;
	/// S - �������� ������;
	void SetTime(int H, int M, int S);
	

	/// ������ ��� �����
	/// H - �������� ����
	void SetH(int H);


	/// ������ ��� �����;
	/// M - �������� �����;
	void SetM(int M);


	/// ������ ��� ������;
	/// S - �������� ������;
	void SetS(int S);


	/// ������ ��� �����;
	/// H - �������� �����;
	int GetH() const;


	/// ������ ��� �����;
	/// M - �������� �����;
	int GetM() const;


	/// ������ ��� ������;
	/// S - �������� ������;
	int GetS() const;


	/// ����� ������ ������� � �������;
	void PrintTime();


	/// ����� �������� �������;
	/// H - �������� �����;
	/// M - �������� �����;
	/// S - �������� ������;
	void SumTime(int H, int M, int S);


	/// ����� ��������� �������;
	/// H - �������� �����;
	/// M - �������� �����;
	/// S - �������� ������;
	void DiffTime(int H, int M, int S);


	/// ����� ���������� �����;
	/// H - �������� �����;
	void AddH(int H);


	/// ����� ���������� �����;
	/// M - �������� �����;
	void AddM(int M);


	/// ����� ���������� ������;
	/// S - �������� ������;
	void AddS(int S);


	/// ����� �������� � ����;
	double toHours();


	/// ����� �������� � ������;
	double toMinutes();


	/// ����� �������� � �������;
	int toSeconds();
	

	/// ����� �������������� � ������;
	string toString();


	/// ����� ������ � ����;
	/// path - ������������ ���������� �����;
	void toFile(const string& path);


	/// ����� ������ �� �����;
	/// path - ������������ ���������� �����;
	static void fromFile(const string& path);


	/// ����� ��� ��������� ������� �������� ������;
	/// arr - ������ �� ������, SIZE - ������ �������;
	static void TimeArr(Time * arr, int SIZE);


	/// ����� ������ ������� �������� ������ � �������;
	/// arr - ������ �� ������, SIZE - ������ �������;
	static void TimeArrPrint(Time* arr, int SIZE);

};
	

