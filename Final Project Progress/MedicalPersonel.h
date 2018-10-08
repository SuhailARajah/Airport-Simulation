#include <vector>
#include <queue>
#include "Patient.h"
#pragma once
#include "WaitingRoom.h"
#include "Information.h"
class MedicalPersonel {
protected:
	std::queue <Patient *> currentServing;
public:
	//both Doctors and Nurses must have these functions
	virtual Information * servePatient(int clock, WaitingRoom * waiting) = 0;
	virtual void takeNewPatient(int clock, WaitingRoom * waiting) = 0;
};