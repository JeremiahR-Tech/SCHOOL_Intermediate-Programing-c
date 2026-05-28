#pragma once

#include <string> 
using namespace std;

class Ship 
{
	string name_;
	int id_;

	public:
		Ship(string name,int id) : name_{},id_{}

		const string & name() const {return name_;}
}
