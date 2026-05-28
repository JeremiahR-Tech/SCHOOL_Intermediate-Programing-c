#include <iostream>
#include <fstream>
#include <sstream>
#include "vehicle.hpp"

Vehicle Vehicle::addVehicle()
{
	Vehicle input;

	cout << "Year?  ";
	cin >> input.year_;
	
	cout << "Make? ";
	cin >> input.make_;

	cout << "Model? ";
	cin >> input.model_;

	cout << "Color? ";
	cin >> input.color_;

	cout << "License? ";
	cin >> input.license_;

	return input;
}

vector<Vehicle> Vehicle::loadVehicles()
{
	// Getting input of filename
	string filename;
	cout << "Filename? ";
	cin >> filename;

	// Opening file and vector
	ifstream file(filename);
	vector<Vehicle> vehicles;

	int i = 0;

	for(string line; getline(file,line);)
	{
		// Skipping the first line of a file
		if(i == 0)
		{
			i++;
			continue;
		}

		// New temp monster for each line of csv
		Vehicle temp = Vehicle(line);
		vehicles.push_back(temp);
	}
	
	file.close();

	return vehicles;
}

void Vehicle::printVehicles(vector<Vehicle> vehicles)
{
	for(Vehicle v: vehicles)
	{
		cout << v << endl;
	}
}

void Vehicle::printVehiclesCSV(vector<Vehicle> vehicles)
{
	for(Vehicle v: vehicles)
	{
		string csvline;
		csvline = v.toCSV();
		cout << csvline << endl;
	}
}
