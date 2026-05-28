#include "Motorcycle.hpp"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void motorcycle_check(Vehicle &v) {
    try {
        auto result = dynamic_cast<Motorcycle&> (v);
        cout << "Is a motorcycle" << endl;
    } catch (bad_cast& e) {
        cout << "Not a motorcycle" << endl;
    }
}

int main() {
    Vehicle v1 {"Ford", "Pinto", 4, 95};
    Motorcycle m1;

    motorcycle_check(v1);
    motorcycle_check(m1);

    return 0;
}
