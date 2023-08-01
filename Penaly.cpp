#include<iostream>
#include <string>
#include <list>

using namespace std;

class Date
{
	size_t _day;
	size_t _month;
	size_t _year;

public:
	Date()
	{
		_day = 0;
		_month = 0;
		_year = 0;
	}
	Date(size_t day, size_t month, size_t year)
	{
		set_day(day);
		set_month(month);
		set_year(year);
	}
	void set_day(size_t day)
	{
		if (day > 0 && day <= 31)
			_day = day;
		else
			throw invalid_argument("Error date");
	}
	void set_month(size_t month)
	{
		if (month > 0 && month <= 12)
			_month = month;
		else
			throw invalid_argument("Error date");
	}
	void set_year(size_t year)
	{
		if (year > 0)
			_year = year;
		else
			throw invalid_argument("Error date");
	}

	friend ostream& operator<<(ostream& os, Date& dt);
};
ostream& operator<<(ostream& os, Date& dt)
{
	os << dt._day << "." << dt._month << "." << dt._year;
	return os;
}


class Number
{
	string _rayon;
	string _herf;
	string _reqem;


public:
	Number()
	{
		_rayon = "";
		_herf = "";
		_reqem = "";
	}
	Number(string rayon, string herf, string reqem)
	{
		set_rayon(rayon);
		set_herf(herf);
		set_reqem(reqem);
	}
	void set_rayon(string rayon)
	{
		if (rayon.size() > 0)
			_rayon = rayon;
		else
			throw invalid_argument("Invalid rayon of number of Car");

	}
	void set_herf(string herf)
	{
		if (herf.size() > 0)
			_herf = herf;
		else
			throw invalid_argument("Invalid herf of number of Car");

	}
	void set_reqem(string reqem)
	{
		if (reqem.size() > 0)
			_reqem = reqem;
		else
			throw invalid_argument("Invalid reqem of number of Car");

	}

	void show()
	{
		cout << _rayon << "-" << _herf << "-" << _reqem<<endl;
	}
};

class Penaly
{
	static int _static_id;
	int _id;
	string _text;
	Date _datetime;
	float _price;

public:
	Penaly(string text, Date datetime, float price)
	{
		_id = _static_id++;
		set_text(text);
		_datetime = datetime;
		set_price(price);
	}
	void set_text(string text)
	{
		if (text.size() > 0)
			_text = text;
		else
			throw invalid_argument("Invalid Text");
	}
	void set_price(float price)
	{
		if (price >= 0 && price <= 10000)
			_price = price;
		else
			throw invalid_argument("Invalid price");
	}

	friend ostream& operator<<(ostream& os, Penaly& pn);

};
int Penaly::_static_id = 1;
ostream& operator<<(ostream& os, Penaly& pn)
{
	os << "Penaly ID: " << pn._id << endl
		<< "Text: " << pn._text << endl
		<< "Penaly Date: " << pn._datetime << endl
		<< "Penaly Price: " << pn._price << endl;
	return os;


}


class Car
{
	static int _static_id_car;
	int _id;
	Number _number;
	string _name;
	Penaly** _penalies;
	int _penalies_count;

public:
	Car(string name, Penaly** penalies, int count,Number number)
	{
		set_name(name);
		_number = number;
		set_all_penalies(penalies, count);
	}

	void set_name(string name)
	{
		if (name.size() > 0)
			_name = name;
		else
			throw invalid_argument("Invalid name of Car");

	}
	void set_all_penalies(Penaly** penalies, int count)
	{
		if (_penalies != nullptr) {
			for (size_t i = 0; i < _penalies_count; i++)
			{
				delete _penalies[i];
			}
			delete _penalies;
		}

		Penaly** new_penalies = new Penaly * [count] {};

		for (size_t i = 0; i < count; i++)
		{
			new_penalies[i] = new Penaly(*penalies[i]);
		}

		_penalies = new_penalies;
		_penalies_count = count;

	}

	void add_penaly(Penaly* penaly)
	{

		if (penaly == nullptr) { return; }

		Penaly** new_penalies = new Penaly * [_penalies_count + 1] {};

		for (size_t i = 0; i < _penalies_count; i++)
			new_penalies[i] = new Penaly(*_penalies[i]);

		new_penalies[_penalies_count] = new Penaly(*penaly);

		for (size_t i = 0; i < _penalies_count; i++)
			delete _penalies[i];
		delete _penalies;

		_penalies = new_penalies;
		_penalies_count++;


	}
	void show()
	{
		cout << "Car Name: " << _name << endl;
		cout << "Car Number: "; _number.show();
		cout << endl;
		for (size_t i = 0; i < _penalies_count; i++)
		{
			cout << *_penalies[i] << endl;
		}
		cout << "-------------------------------" << endl;
	}
};

int Car::_static_id_car = 1;


int main()
{
	Date date1(11, 7, 2023);
	Date date2(23, 8, 2023);

	Penaly* qosa_xett = new Penaly("1.1 QOSA XETT ", date1, 20);
	Penaly* qirmizi_isiq = new Penaly("12.4 QIRMIZI ISIQ ", date2, 40);
	Penaly* yol_ayirici = new Penaly("327.2 Yolayiricini kecme qaydalarinin pozulmasi ", date2, 40);
	Penaly* suret_60 = new Penaly("12.4 SURET HEDDI 60KM/H ", date2, 40);
	Penaly* suret_90 = new Penaly("12.4 SURET HEDDI 90KM/H ", date2, 40);


	Penaly** penalies_tesla = new Penaly * [1] {suret_90};
	Penaly** penalies_merc = new Penaly * [3] {qirmizi_isiq, yol_ayirici, suret_60};
	Penaly** penalies_bmw = new Penaly * [4] { qosa_xett, yol_ayirici, suret_60, suret_90};
	Number num1("10", "BD", "200");
	Number num2("77", "BB", "310");
	Number num3("90", "EH", "507");

	Car tesla("Tesla", penalies_tesla, 1, num1);
	Car mercedes("Mercedes", penalies_merc, 3, num2);
	Car bmw("BMW", penalies_bmw, 4, num3);



	list<Car> cars;
	cars.push_back(tesla);
	cars.push_back(mercedes);
	cars.push_back(bmw);


	cars.front().show();
	//cars.back().show();
	cout << endl;
	cout << endl;
	cout << endl;

	cars.front().add_penaly(qirmizi_isiq);

	cars.front().show();

	return 0;
}
//BVC