//---------------------------------------------------------------------------

#pragma hdrstop

#include "Parameters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Parameters::population = 5000;
int Parameters::width = 400;
int Parameters::height = 300;
int Parameters::boxLen = 5;
int Parameters::stepLen = 15;
int Parameters::initInfectedPeople = 5;
int Parameters::infectionDuration = 1 * 7 * 24 * 60 / stepLen;
int Parameters::infectionCoefficient = 100;
int Parameters::riskOfInfection = 25;
