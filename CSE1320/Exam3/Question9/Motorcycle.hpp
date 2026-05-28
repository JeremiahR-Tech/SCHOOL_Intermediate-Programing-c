#include "Vehicle.hpp"

using namespace std;

class Motorcycle : public Vehicle
{
	bool race_ready_;
	string type_;

        public:
                Motorcycle(): type_{"Commerical"}, race_ready_{false} {}

                // Setters & Getters
                auto & setrace_ready_() { return Motorcycle::race_ready_; }
                const auto & getrace_ready_() const { return Motorcycle::race_ready_; }

                auto & settype_() { return type_; }
                const auto & gettype_() const { return type_; }
};

