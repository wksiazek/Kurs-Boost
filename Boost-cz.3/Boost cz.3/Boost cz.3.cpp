// Boost cz.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using boost::any;
using boost::any_cast;
using boost::bad_any_cast;

int main()
{
	any x, y, z, f;
	x = 10;
	y = 12.5;
	z = string("text");

	//cout << x << endl;// nie skompiluje sie, brak przeci¹¿enia dla any
	cout << any_cast<int>(x) << endl; //kopia x, podobne do get, tyle ze get zwraca referencje


	//zle rzutowanie
	try
	{
		cout << any_cast<int>(z) << endl;
	}
	catch (bad_any_cast &e)
	{
		cerr << "Nieudana konwersja: " << e.what() << endl;
	}

	//cos jeszcze
	vector<any>vect;
	vect.push_back(9.5);
	vect.push_back(5);

	for (auto a : vect)
	{
		if (a.type() == typeid(int))
			cout << any_cast<int>(a) << endl;

		if (a.type() == typeid(double))
			cout << any_cast<double>(a) << endl;;
	}

	/*auto a = 7;
	a = "ble";*/

	any example = 5;
	example = "text";

	system("pause");
	return 0;
}


