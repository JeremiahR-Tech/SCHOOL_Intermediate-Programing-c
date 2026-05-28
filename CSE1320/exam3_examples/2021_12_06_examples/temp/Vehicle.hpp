#pragma once

#include <unordered_map>
#include <iostream>

using namespace std;

class Vehicle {
    int year_;
    string make_;
    string model_;
    string color_;
    string license_plate_;

	public:
		Vehicle() {}
		Vehicle(int year, string make, string model, string color, string license_plate) : year_{year}, make_{make}, model_{model}, color_{color}, license_plate_{license_plate} {}

        auto & make() { return make_; }
        auto & make() const { return make_; }

        void setLicensePlate(string lic) {
            // Add validation rules.
            license_plate_ = lic;
        }

        string getLicensePlate() {
            return license_plate_;
        }

		friend ostream& operator<<(ostream& os, const Vehicle& v) {
			return os << v.year_ << " "
				<< v.make_ << " "
				<< v.model_ << " ("
				<< v.color_ << ") LIC#"
				<< v.license_plate_;
		}

		static void loadVehicles(unordered_map<string, Vehicle>&, string);
};
