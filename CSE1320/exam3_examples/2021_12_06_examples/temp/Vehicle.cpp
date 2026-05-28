#include "Vehicle.hpp"
#include "utils.hpp"

#include <fstream>

void Vehicle::loadVehicles(unordered_map<string, Vehicle>& vmap, string filename) {
	ifstream file{filename};

	for (string line; getline(file, line);) {
		vector<string> tokens = tokenizeCSVLine(line);

		try {
			auto result = vmap.at(tokens[4]);
			cout << result << " already exists." << endl;
		} catch (out_of_range& e) {
			vmap.emplace(tokens[4], Vehicle{stoi(tokens[0]), tokens[1], tokens[2], tokens[3], tokens[4]});
		}
	}
}
