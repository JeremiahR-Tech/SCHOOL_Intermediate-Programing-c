#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// By default these class variables are private
class Character
{
	string name  ;
	int level_;
	int ac_;
	int hp_;

	public:
		Character() : name_{"Undefined"} {}
		{
			cout << "Default constructor called." << endl
		}

		auto & name(){return name_;}
}
