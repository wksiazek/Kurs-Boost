// Boost-cz.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using boost::optional;

/*char getLastChar(deque<char> data)
{
if (!data.empty)
return data.back();
else
//i co tutaj ? return \0 przeciez to tez znak
}*/

optional<char> getLastChar(deque<char> data)
{
	if (!data.empty())
		return optional<char>(data.back());
	else
		return optional<char>();
}

int main()
{
	deque<char> data;
	optional<char> op;

	op = getLastChar(data);
	if (!op)
		cout << "Brak danych" << endl;
	else
		cout << op.get() << endl;

	//jezeli nie jest zainicjowany wypisz a
	cout << op.get_value_or('a') << endl;

	char *p = op.get_ptr();//zwroci pusty wskaŸnik

	op.reset();//op wraca do stanu niezaincjalizowanego

	system("pause");
	return 0;
}

