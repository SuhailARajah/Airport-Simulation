#pragma once
#include <iostream>
#include "Patient.h"
//for pointers to Patients
struct Node_Comparison{
	bool operator() (const Patient * a, const Patient * b) const{
		return (a->severity < b->severity);
	}
};
