#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	time_t timer;		//time_t - long long int
	time(&timer);
	cout << timer << endl;
	tm* current_time = localtime(&timer);
	//cout << *current_time << endl;
	cout << asctime(current_time) << endl;
	current_time->
}