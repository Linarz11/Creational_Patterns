#include <iostream>
#include <ctime>
using namespace std;

class Human
{
	unsigned int hp;
	unsigned int damage;
	unsigned int armor;
public:
	Human(unsigned int hp, unsigned int damage, unsigned int armor)
	{
		this-> hp = hp;
		this ->damage = damage;
		this ->armor = armor;
	}
	virtual ~Human()
	{
		cout << "No human - No problem" << endl;
	}
	virtual void info()const
	{
	cout << "\n----------------\n";
		cout << typeid(*this).name() << endl;
		cout << "HP:\t" << hp << endl;
		cout << "Armor:\t" << armor << endl;
		cout << "Damage:\t" << damage << endl;

	}
};

class Traveller :public Human
{
public:
	Traveller(unsigned int hp, unsigned int damage, unsigned int armor) :Human(hp, damage, armor)
	{}
	~Traveller() {}
};

class PolliceOfficer :public Human
{
	std::string weapon;
public:
	PolliceOfficer(unsigned int hp, unsigned int damage, unsigned int armor, const std::string& weapon) :Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~PolliceOfficer() {}
	void info()const
	{
		Human::info();
		cout << "Weapons:" << weapon << endl;
	}
};

class Bandit :public Human
{
	std::string weapon;
public:
	Bandit(unsigned int hp, unsigned int damage, unsigned int armor, const std::string& weapon = "") :
		Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~Bandit()
	{

	}
	void info()const
	{
		Human::info();
		cout << "Weapons:" << weapon << endl;
	}

};

enum HumanType
{
	Traveller,
	PolliceOfficer,
	Bandit
};

std::string weapons[] =
{
	"None",
	"Beretta",
	"SPAS-12",
	"Ingram",
	"M4A1",
	"Knife"
};


Human* humanFactory(HumanType human_type)
{
	switch (human_type)
	{
	case Traveller:			return new class Traveller(100, rand() % 10 + 10, 0);
	case PolliceOfficer:	return new class PolliceOfficer (100, rand()%10 + 20, 100, "Beretta");
	case Bandit:			
		return new class Bandit(rand() % 50 + 50, rand()%10+30, rand()%20+80, weapons[rand()%(sizeof(weapons)/sizeof(std::string))]);
	}
}

//#define FACTORY_CHECK_1

void main()
{
	setlocale(LC_ALL, "");

	srand(time(NULL));
#ifdef FACTORY_CHECK_1
	Human* t = humanFactory(Traveller);
	t->info();

	Human* p = humanFactory(PolliceOfficer);
	p->info();

	Human* b = humanFactory(Bandit);
	b->info();
#endif // FACTORY_CHECK_1




	//cout << sizeof(HumanType) << endl;
	const int n = 10;
	Human* human[n]{};
	for (int i = 0; i < n; i++)
	{
		human[i] = humanFactory(HumanType(rand() % 3 ));
		human[i]->info();
	}
	for (int i = 0; i < n; i++)
	{
		delete human[i];
	}


}