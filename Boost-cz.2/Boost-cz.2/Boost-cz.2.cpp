// Boost-cz.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using boost::variant;
using boost::get;
using boost::bad_get;
using boost::static_visitor;
using boost::apply_visitor;

union example
{
	int a;
	double b;
};

/*union exampleWithString
{
int a;
string b;
};*/

template<typename T>
void print(T &variant)
{
	if (int *elem = get<int>(&variant))
	{
		cout << "To jest int" << endl;
	}
	else if (double *elem = get<double>(&variant))
	{
		cout << "To jest double" << endl;
	}
	else if (string *elem = get<string>(&variant))
	{
		cout << "To jest string" << endl;
	}
}

class printVisitor :public static_visitor<void>
{
public:
	void operator()(int i)const
	{
		cout << "To jest int" << endl;
	}
	void operator()(double i)const
	{
		cout << "To jest double" << endl;
	}
	void operator()(string i)const
	{
		cout << "To jest string" << endl;
	}
};

int main()
{
	example ex1;
	ex1.a = 5;
	ex1.b = 7.7;//nadpisujemy a

				//exampleWithString ex2;//problem

	variant<int, string> variant1, variant2;
	variant1 = 5;
	variant2 = "aaa";

	cout << variant1 << " " << variant2 << endl;

	variant<int, string> variant3("text"), variant4(12);
	variant3 = 5;
	variant4 = 7;

	cout << variant3 << " " << variant4 << endl;

	//variant3 = variant3 * 3;// niemozliwe, ze wzglêdu na brak przeci¹¿enia * dla typu Variant
	variant3 = get<int>(variant3) * 3;
	cout << variant3 << " " << variant4 << endl;

	//sprobujemy zla konwersje
	try
	{
		string temp = get<string>(variant3);
		cout << temp << endl;
	}
	catch (bad_get &e)
	{
		cerr << "Nie udalo sie poprawnie skonwertowac: " << e.what() << endl;
	}

	//jeszcze cos fajnego
	vector<variant<int, string>> vect;
	vect.push_back("aaa");
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back("bbb");

	for (auto a : vect)
	{
		cout << a << endl;
	}

	//sprobojmy napisac funkcje, ktora poinformuje nas o typie jaki przechowuje Variant
	variant<int, string, double>variant5('q');
	print(variant5);

	//z wykorzystaniem wizytatora- argumenty przez wartosc
	printVisitor printV;
	apply_visitor(printV, variant5);

	system("pause");
	return 0;
}


