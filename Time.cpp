#include "Time.h"


void Time::fromSeconds(int Seconds)
{
	this->H = abs(Seconds) / 3600;
	this->M = (abs(Seconds) - 3600 * H) / 60;
	this->S = (abs(Seconds) - 3600 * H - 60 * M);

	if (Seconds < 0) { this->H *=(-1); this->M *= (-1); this->S *= (-1); }
}


Time::Time()
{
	H = M = S = 0;
}


Time::Time(int H, int M, int S)
{
	SetH(H);
	SetM(M);
	SetS(S);
}


void Time::SetH(int H)
{
	this->H = H;
}


void Time::SetM(int M)
{
	this->M = M;
}


void Time::SetS(int S)
{
	this->S = S;
}


int Time::GetH() const
{
	return H;
}


int Time::GetM() const
{
	return M;
}


int Time::GetS() const
{
	return S;
}


void Time::PrintTime() const
{
	H < 0 || M < 0 || S < 0 ? cout << "Time: -" : cout << "Time: ";
	abs(H) < 10 ? cout << "0" << abs(H) : cout << abs(H);
	cout << ":";
	abs(M) < 10 ? cout << "0" << abs(M) : cout << abs(M);
	cout << ":";
	abs(S) < 10 ? cout << "0" << abs(S) : cout << abs(S);
	cout << endl;
}


void Time::SumTime(int H, int M, int S)
{
	this->H += H;
	this->M += M;
	this->S += S;
	fromSeconds(toSeconds());
}


void Time::DiffTime(int H, int M, int S)
{
	this->H -= H;
	this->M -= M;
	this->S -= S;
	fromSeconds(toSeconds());
}


void Time::AddH(int H)
{
	this->H += H;
	fromSeconds(toSeconds());
}


void Time::AddM(int M)
{
	this->M += M;
	fromSeconds(toSeconds());
}


void Time::AddS(int S)
{
	this->S += S;
	fromSeconds(toSeconds());
}


double Time::toHours()
{
	double Hours;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Hours = (-1.0) * (abs(double(this->H)) + abs(double(this->M)/60) + abs(double(this->S)/3600));
	}
	else {
		return Hours = this->H + (double)this->M / 60.0 + (double)this->S / 3600.0;
	}
}


double Time::toMinutes()
{
	double Minutes;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Minutes = (-1) * (abs(double(this->H) * 60) + abs(double(this->M)) + abs(double(this->S) / 60));
	}
	else {
		return Minutes = double(this->H)*60 + double(this->M) + double(this->S) / 60;
	}
}


int Time::toSeconds()
{
	int Seconds;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Seconds = (-1) * (abs(this->H) * 3600 + abs(this->M) * 60 + abs(this->S));
	}
	else {
		return Seconds = this->H * 3600 + this->M * 60 + this->S;
	}
}


string Time::toString()
{
	return to_string(this->H) + ":" + to_string(this->M) + ":" + to_string(this->S);
}


void Time::toFile(const string & path )
{
	fstream fs;
	//fs.exceptions(fstream::badbit | fstream::failbit);
	try
	{
		fs.open(path, fstream::out | fstream::app); // запись, добавление через битовое или
		fs << this->H << ":" << this->M << ":" << this->S << endl;
	}
	//catch (const ifstream::failure & ex)
	catch (const std::exception & ex)
	{
		cout << ex.what() << endl;
		//cout << ex.code() << endl;
	}
	fs.close();
}


void Time::fromFile(const string& path)
{
	fstream fs;
	try
	{
		fs.open(path, fstream::in); //чтение
		string str = "";
		while (!fs.eof()) //проверяем, закончился ли файл
		{
			getline(fs, str);
			cout << str << endl;
			if (str != "")
			{
				int index_sep1 = str.find(':');
				int index_sep2 = str.find(':', index_sep1+1);
				this->H = stoi(str.substr(0, index_sep1));
				this->M = stoi(str.substr(index_sep1, index_sep2));
				this->S = stoi(str.substr(index_sep2, '\n'));

			}
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	fs.close();
}


void Time::TimeArr(Time* arr, int SIZE)
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = Time(rand() % 24, rand() % 60, rand() % 60);
	}
		
}


void Time::TimeArrPrint(Time* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i].PrintTime();
	}
}


