#pragma once
#include "string.h"
/** A patient has attributes to keep track of
1. name
2. whether they were treated
3. the time the patient arrived
4. time began treatment in er
5. time finish in er
6. severity of their problem
7. time it has taken for them to be treated
*/

struct Patient
{
	Patient(std::string a) : name(a), beingServed(false), arrival_time(-1), emergency_start(-1), emergency_finish(-1), severity(-1), timeToFix(-1)
	{}

	std::string name;
	bool beingServed;
	int arrival_time;
	int emergency_start;
	int emergency_finish;
	int severity;
	int timeToFix;
};

