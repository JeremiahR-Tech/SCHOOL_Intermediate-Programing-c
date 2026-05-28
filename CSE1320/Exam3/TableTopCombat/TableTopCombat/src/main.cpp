#include "Monster.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<Monster> loadMonsters(string filename) {
    ifstream file(filename);
    vector<Monster> monsters;

    int i = 0;

    for (string line; getline(file, line); ) {
        // Skip the first line of the file.
        if (i == 0) {
            i++;
            continue;
        }
        // Monster initializes an object from CSV.
        Monster temp = Monster();
        temp.loadFromCSV(line);
        monsters.push_back(temp);
    }

    file.close();

    return monsters;
}

int main()
{
	string filename;

	cout << "Enter the monster filename: ";
	cin >> filename;

	vector<Monster> monsters = loadMonsters(filename);

	sort(monsters.begin(),monsters.end());

	for(auto m: monsters)
	{
		cout << m << endl;
	}

	return 0;

}

