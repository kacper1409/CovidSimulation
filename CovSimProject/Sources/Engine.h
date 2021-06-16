//---------------------------------------------------------------------------

#ifndef EngineH
#define EngineH

#include <list>
#include <vector>
#include "Parameters.h"
#include "Person.h"

using namespace std;

class Engine
{

private:
    int stepNo;
    int notInfected;
    int infected;
	int recovered;

	std::list<int>* xListArr;

public:
	vector<Person> people;

	list<int> notInfectedList;
	list<int> infectedList;
	list<int> recoveredList;

    int getStepNo() { return stepNo; }
    void setStepNo(int stepNo) { this->stepNo = stepNo; }

    int getNotInfected() { return notInfected; }
    void setNotInfected(int notInfected) { this->notInfected = notInfected; }

    int getInfected() { return infected; }
    void setInfected(int infected) { this->infected = infected; }

    int getRecovered() { return recovered; }
    void setRecovered(int recovered) { this->recovered = recovered; }

    Engine();
	void init();
    void step();

    void motion();
    void infect();
    void recover();
};

#endif
