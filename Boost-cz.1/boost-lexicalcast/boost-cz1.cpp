// boost-lexicalcast.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <boost/lexical_cast.hpp>
#include<string>
#include<iostream>
#include<vector>
using std::cout;
using std::cerr;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using std::string;
using std::for_each;
using std::endl;
using std::to_string;

template<typename T>
string To_string(const T &argument)
{
	try
	{
		return lexical_cast<string>(argument);
	}
	catch (bad_lexical_cast &e)
	{
		cerr << "Nastapil blad konwersji" <<e.what()<< endl;
		return "";
	}
}

int main()
{
	int s = 23;
	string str = lexical_cast<string>(s);//lexical_cast do konwertowania róznych typów danych do stringa
	cout << str << endl;

	string str2 = "123";
	int b = lexical_cast<int>(str2);
	cout << b<<endl;

	string str3 = "123.5";
	try
	{
		int c = lexical_cast<int>(str3);//bad_lexical_cast
	}
	catch (bad_lexical_cast &e)
	{
		cerr << "Blad konwersji: " << e.what() << endl;
	}
	
	int d = lexical_cast<int>("1234yuasdasdsads",4); //uwaga pierwszy parametr to char* a nie string
	cout << d << endl;

	//ale mozna
	string str4 = "1111asdasds";
	const char* chr = str4.c_str();
	int e = lexical_cast<int>(chr, 4); //uwaga pierwszy parametr to char* a nie string
	cout << e << endl;

	//albo po prostu
	string str5 = "1111asdasds";
	int f = lexical_cast<int>(str5.c_str(), 4); //uwaga pierwszy parametr to char* a nie string
	cout << f << endl;

	//skorzystanie z funkcji-szablonu
	string str6 = To_string(5);
	cout << str6 << endl;

	//skorzystanie z to_string z C++11
	string str7 = to_string(77.5);
	cout << str7 << endl;
	system("pause");
    return 0;
}

