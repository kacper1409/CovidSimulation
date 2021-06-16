//---------------------------------------------------------------------------

#pragma hdrstop

#include <DateUtils.hpp>
#include <random>
#include <iostream>
#include "Engine.h"

using namespace std;

Engine::Engine()
{
	xListArr = NULL;
}

void Engine::init()
{
	if (xListArr != NULL) delete[] xListArr;

	xListArr = new std::list<int>[Parameters::width];

    stepNo = 0;
    notInfected = Parameters::population - Parameters::initInfectedPeople;
    infected = Parameters::initInfectedPeople;
    recovered = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distX(0, Parameters::width - 1);
    uniform_int_distribution<> distY(0, Parameters::height - 1);

	/// dodanie ludzi do listy
    people.clear();
    for (int i = 0; i < Parameters::population; i++)
    {
        Person person(Healthy);
        people.push_back(person);
    }

    int startX, startY;
	int infectedCounter = 0;
	int personCounter = 0;

	/// wylosowanie pozycji poczatkowych ludzi i ustawienie poczatkowo zarazonych ludzi
	vector<Person>::iterator p = people.begin();
	while (p != people.end())
	{
		startX = distX(gen);
		startY = distY(gen);
		p->setPosition(Vector2d(startX, startY));

		xListArr[startX].push_back(personCounter++);

        if (infectedCounter++ < Parameters::initInfectedPeople) p->setStatus(Infected);

        p++;
    }
}

void Engine::step()
{
	stepNo++;

	notInfectedList.push_back(notInfected);
	infectedList.push_back(infected);
	recoveredList.push_back(recovered);

	TDateTime t0 = Now();

    infect();
    recover();
	motion();

	int dt = MilliSecondsBetween(Now(), t0);
}

void Engine::motion()
{
	int personCounter = 0;

	vector<Person>::iterator p = people.begin();
	while (p != people.end())
	{
		int prevX = p->getPosition().getX();

		p->setPosition(p->getPosition().add(Vector2d::getUnitMotion()));

		if (p->getPosition().getX() != prevX)
		{
			xListArr[prevX].remove(personCounter);
			xListArr[p->getPosition().getX()].push_back(personCounter);
		}

        personCounter++;
        p++;
    }
}

void Engine::infect()
{
    /// spotkanie sie dwoch lub wiecej osob, wsrod ktorych jest co najmniej jedna zarazona,
    /// oznacza zarazenie pozostalych z prawdopodobienstwem riskOfInfection

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, Parameters::infectionCoefficient);


	vector<Person>::iterator p = people.begin();
//    vector<Person>::iterator q = people.begin();

    list<Vector2d> checkedSpots;
    list<Vector2d>::iterator r = checkedSpots.begin();

    while (p != people.end())
    {
        /// sprawdzenie czy pozycja nie byla juz sprawdzana
        bool spotChecked = false;

        r = checkedSpots.begin();
        while (r != checkedSpots.end())
        {
            if (r->equals(p->getPosition())) { spotChecked = true; break; }
            r++;
        }
        if (spotChecked) { p++; continue; }

        /// utworzenie listy ludzi znajdujacych sie na pozycji aktualnie przegladanej osoby w petli glownej;
        /// jednoczesne sprawdzanie czy aktualna osoba na pozycji jest zarazona
        list<Person*> peopleAtPosition;
        bool infectedExists = false;

		std::list<int>& xList = xListArr[p->getPosition().getX()];

		for (std::list<int>::const_iterator it = xList.begin(); it != xList.end(); it++)
		{
			int iq = *it;
			Person& person = people[iq];

			if (person.getPosition().getY() == p->getPosition().getY())
			{
				peopleAtPosition.push_back(&person);
				if (person.getStatus() == Infected) infectedExists = true;
			}
		}


		/// jesli na tej pozycji nie ma zarazonych, to ja pomijamy
        if (!infectedExists) { p++; continue; }

        list<Person*>::iterator s = peopleAtPosition.begin();
        while (s != peopleAtPosition.end())
        {
            if ((*s)->getStatus() == Healthy)
            {
                int infectFactor = dist(gen);

                if (infectFactor <= Parameters::riskOfInfection)
                {
                    (*s)->setStatus(Infected);

                    infected++;
                    notInfected--;

                    (*s)->updateRecovering();
                }
            }
            s++;
        }

        checkedSpots.push_back(p->getPosition());
        p++;
    }
}

void Engine::recover()
{
    vector<Person>::iterator p = people.begin();
    while (p != people.end())
    {
        if (p->getStatus() == Recovered) { p++; continue; }

        p->updateRecovering();

        if (p->getStatus() == Recovered)
        {
            recovered++;
            infected--;
        }

        p++;
    }
}

#pragma package(smart_init)
