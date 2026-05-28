#include "utils.hpp"

#include <sstream>

vector<string> tokenizeCSVLine(string line) {
    vector<string> tokens;
    stringstream lineStream(line);
    string temp;

    while (getline(lineStream, temp, ',')) {
        tokens.push_back(temp);
    }

    return tokens;
}
