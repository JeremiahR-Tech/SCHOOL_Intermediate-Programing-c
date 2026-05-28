#include "Motorcycle.hpp"
#include <iostream>

class User
{
	public:
	int number_;
	
	User(): number_{0} {};
};

using namespace std;

int main()
{
	User u{};

	cout << u.number_ << endl;

	return 0;
}
