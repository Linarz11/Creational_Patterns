#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Singleton
{
	static Singleton* instance ;
	string last_name;
	string first_name;
	tm birth_date;
protected:
	Singleton()
	{
		cout << "Constructor:\t" << this << endl;
	}
	~Singleton()
	{
		cout << "Destructor:\t" << this << endl;
	}
public:
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(size_t year, size_t month, size_t day)
	{
		this->birth_date.tm_year = year-1900;
		this -> birth_date.tm_mon = month-1;
		this -> birth_date.tm_mday = day;

	}
	
	static Singleton* getInstance()
	{
		if (instance == nullptr)instance = new Singleton;		// Ленивая инициализация (Lazy initialisation) - объект не создается до тех пор, 
																// пока он не понадобится
		return instance;
	}
	void print() const
	{
		time_t timer;
		time(&timer);
		tm* current_time = localtime(&timer);
		cout << "Текущее время:\t"<< asctime(current_time);
		size_t age = current_time->tm_year - birth_date.tm_year;
		if (current_time->tm_mon < birth_date.tm_mon) age--;
		if (current_time->tm_mon == birth_date.tm_mon &&
			current_time->tm_mday < birth_date.tm_mday)age--;
		//cout << last_name << " " << first_name<< " " << age << " лет \n";
		printf("Director: %s  %s  %u лет ", last_name.c_str(), first_name.c_str(), age);
	}


};

Singleton* Singleton::instance = nullptr;

//#define SINGLETON_1

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef SINGLETON_1
	//Singleton obj;
	Singleton::getInstance();	// метод getINstance является статическим  и может быть вызван только для класса, а не для объекта
	Singleton::getInstance()->set_last_name("Tupenko");
	Singleton::getInstance()->set_first_name("Vasiliy");
	Singleton::getInstance()->set_birth_date(2001, 5, 15);
	Singleton::getInstance()->print();
#endif // SINGLETON_1

	Singleton* director = Singleton::getInstance();		// Создаем объект
	director->set_last_name("Pupenko");
	director->set_first_name("Baziliy");
	director->set_birth_date(1991, 7, 24);
	director->print();


	
}

