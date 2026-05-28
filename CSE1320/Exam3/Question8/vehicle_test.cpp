#include "Vehicle.hpp"

#include <iostream>

using namespace std;

int main() {
    Vehicle v1{"Ford", "Ranger", 4, 150};
    Vehicle v2{"Ferrari", "F430", 4, 500};

    if (v1 < v2) {
        cout << "v2 has more horsepower." << endl;
    } else {
        cout << "v1 has more horsepower." << endl;
    }

    return 0;
}
