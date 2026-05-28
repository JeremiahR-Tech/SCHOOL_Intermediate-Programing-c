#include "Vehicle.hpp"

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    string filename{argv[1]};

    unordered_map<string, Vehicle> vmap;

    Vehicle::loadVehicles(vmap, filename);

    Vehicle v;
    v.make() = "Chevrolet";

    for (auto& v : vmap) {
        cout << v.second << endl;
    }
}
