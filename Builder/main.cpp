#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

class Computer
{
	string type;
	string CPU;
	string GPU;
	string RAM;
	string Disk;
	bool on;
public:
	
	Computer()
	{
		on = false;
	}
	void setType(const std::string& type)
	{
		this->type = type;
	}
	void setCPU(const string& CPU)
	{
		this->CPU = CPU;
	}
	void setGPU(const string& GPU)
	{
		this->GPU = GPU;
	}
	void setRAM(const string& RAM)
	{
		this->RAM = RAM;
	}
	void setDisk(const string& Disk)
	{
		this->Disk = Disk;
	}
	void power_button()
		{
		on = on ? false:true;
		}
	void info()const
	{
		cout << "\n------------------------------------\n";
		cout << type << endl;
		if (on)
		{
			cout << "System properties:\n ";
			cout << "CPU: " << CPU << endl;
			cout << "RAM: " << RAM << endl;
			cout << "Disk: " << Disk << endl;
			cout << "GPU: " << GPU << endl;
		}
		else
		{
			cout << "Computer is off" << endl;
		}
		cout << "\n------------------------------------\n";
	}
	
	
};
	//Abstract builder
class ComputerBuilder
{
protected:
	Computer* computer;
public: ComputerBuilder()
{
	this->computer = new Computer;
}
	  virtual ~ComputerBuilder()
	  {
		  delete this->computer;
	  }
	  Computer* getComputer() const
	  {
		  return this->computer;
	  }
	  virtual void setType() = 0;
	  virtual void setCPU() = 0;
	  virtual void setGPU() = 0;
	  virtual void setRAM() = 0;
	  virtual void setDisk() = 0;
};

class CheepComputerBuilder :public ComputerBuilder
{
public: 
	~CheepComputerBuilder(){}
	void setType()
	{
		computer->setType("Cheep Computer");
	}
	void setCPU()
	{
		computer->setCPU("Celeron");
	}
	void setGPU()
	{
		computer->setGPU("Intel HD Graphics");
	}
	void setRAM()
	{
		computer->setRAM("4GB");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 360GB");
	}
};

class OfficeComputerBuilder : public ComputerBuilder
{
public:
	~OfficeComputerBuilder() {}
	void setType()
	{
		computer->setType("Office Computer");
	}
	void setCPU()
	{
		computer->setCPU("Core i3-2125");
	}
	void setGPU()
	{
		computer->setGPU("Intel HD Graphics 3000");
	}
	void setRAM()
	{
		computer->setRAM("8 GB");
	}
	void setDisk()
	{
		computer->setDisk("Kingston SSD 128 GB");
	}

};

class GameComputerBuilder : public ComputerBuilder
{
public:
	~GameComputerBuilder() {}
	void setType()
	{
		computer->setType("Game Computer");
	}
	void setCPU()
	{
		computer->setCPU("Core i9-9900K");
	}
	void setGPU()
	{
		computer->setGPU("GeForce 3090-Ti");
	}
	void setRAM()
	{
		computer->setRAM("64 GB");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980-Pro");
	}

};


class ServerBuilder :public ComputerBuilder
{
public:
	void setType()
	{
		computer->setType("Server");
	}
	void setCPU()
	{
		computer->setCPU("Intel Xeon E3");
	}
	void setGPU()
	{
		computer->setGPU("Maxtor");
	}
	void setRAM()
	{
		computer->setRAM("128 GB ECC");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980_Evo 2TB");
	}

};

class Sysadmin
{
	ComputerBuilder* comp_builder;
public:
	void assemblyComputer(ComputerBuilder* comp_builder)
	{
		this->comp_builder = comp_builder;
		comp_builder->setType();
		comp_builder->setCPU();
		comp_builder->setGPU();
		comp_builder->setRAM();
		comp_builder->setDisk();
	}
	void turnOnTheComputer()
	{
		comp_builder->getComputer()->power_button();
		comp_builder->getComputer()->info();
	}
};



void main()
{
	setlocale(LC_ALL, "Russian");
	//Computer computer;
	//computer.info();
	Sysadmin nice_guy;
	CheepComputerBuilder computer_for_bookkeeper;
	nice_guy.assemblyComputer(&computer_for_bookkeeper);
	nice_guy.turnOnTheComputer();
	cout << endl;
	//computer_for_bookkeeper.getComputer()->power_button();
	//computer_for_bookkeeper.getComputer()->info();

	OfficeComputerBuilder computer_for_director;
	nice_guy.assemblyComputer(&computer_for_director);
	computer_for_director.getComputer()->power_button();
	computer_for_director.getComputer()->info();

	GameComputerBuilder computer_for_sysadmin;
	nice_guy.assemblyComputer(&computer_for_sysadmin);
	nice_guy.turnOnTheComputer();




}