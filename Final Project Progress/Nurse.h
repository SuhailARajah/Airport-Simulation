#pragma once
#include "MedicalPersonel.h"
#include "WaitingRoom.h"
#include "Information.h"

extern Random my_random; //enables us to access the global variable in Simulator.h

class Nurse : public MedicalPersonel {
public:
	Nurse() {};
	Information * servePatient(int clock, WaitingRoom * waiting) {
		if (!currentServing.empty())//currentServing is a protected data field from base class
		{
			Patient * pat = currentServing.front();
			if ((clock - pat->emergency_start) > pat->timeToFix)//checks to see if patient has been fully served
			{
				waiting->decServed();//Decrements overall total being served
				pat->emergency_finish = clock;
				pat->beingServed = false;
				int time;
				time = clock - pat->arrival_time;
				currentServing.pop();//currentServing is now empty
				return new Information(pat->name, time, pat->severity);//Info of patient
			}
		}
		return new Information;//Default constructor with total_time of 0
	}

	void takeNewPatient(int clock, WaitingRoom * waiting) {
		if (currentServing.empty()) {
			if (!waiting->minorEmpty()) {
				Patient * pat = waiting->minorTop();//minorTop() also pops the top element
				pat->emergency_start = clock;
				pat->timeToFix = rand() % 10 + 1;
				currentServing.push(pat);
			}
		}
	}
};