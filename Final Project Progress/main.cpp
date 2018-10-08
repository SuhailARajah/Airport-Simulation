#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Patient.h"
#include <vector>
#include <fstream>
#include <string>
#include "Simulator.h"

using namespace std;

int main(){
	string filename = "C:\\Users\\srajah19\\Documents\\residents_of_273ville.txt";
	vector < Patient * >  the_town;
	
	string line;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		string name = "start";
		while (getline(myfile, line))
		{
			myfile >> name;
			the_town.push_back(new Patient(name));
		}
		myfile.close();
		Simulator hospital(the_town);
		hospital.enter_data();
		hospital.run_simulation();
		hospital.show_stats();
		hospital.post_simulation();
	}
	else
		cout << "Unable to open file" << endl;
}
