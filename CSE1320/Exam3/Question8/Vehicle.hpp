#include <string>

using namespace std;

class Vehicle {
    string make_;
    string model_;
    int num_wheels_;
    int horsepower_;

    public:
        Vehicle(string make, string model, int num_wheels, int horsepower) :
            make_{make}, model_{model}, num_wheels_{num_wheels}, horsepower_{horsepower} {}

	bool operator<(const Vehicle& v1)
	{
		return (horsepower_ < v1.horsepower_);
	}
};
