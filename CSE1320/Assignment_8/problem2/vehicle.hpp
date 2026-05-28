#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Vehicle {

	protected:
		int year_;
		string make_;
		string model_;
		string color_;
		string license_;

	public:
	
	// Needed for constructors
	vector<string> tokenizeCSVLine(string line)
	{
		vector<string> tokens;
		stringstream lineStream(line);
		string temp;

		while(getline(lineStream,temp,','))
		{
			tokens.push_back(temp);
		}

		return tokens;
	}
	
	/* 
	Constructors
	*/
		Vehicle(): year_{2021},make_{"None"},model_{"None"},color_{"None"},license_{"None"} {}
		Vehicle(string make,string model): make_{make},model_{model} {}
		Vehicle(string csvline)
		{
			vector<string> tokens = tokenizeCSVLine(csvline);

			year_ = stoi(tokens[0]);
			make_ = tokens[1];
			model_ = tokens[2];
			color_ = tokens[3];
			license_ = tokens[4];
		}
		~Vehicle() {}

		
		/*
		Getters/Setters
		*/
		auto & year() {return year_;}
		const auto & year() const {return year_;}
		
		auto & make() {return make_;}
		const auto & make() const {return make_;}
		
		auto & model() {return model_;}
		const auto model() const {return model_;}
		
		auto & color() {return color_;}
		const auto color() const{return color_;}
		
		auto & license() {return license_;}
		const auto & license() const {return license_;}
                
		/*
		Overload Functions
		*/
		friend ostream& operator<<(ostream& os, Vehicle const & v)
		{
			return os << v.year() << " " << v.make() <<
			" " << v.model() << " " << v.color() <<
			" " << v.license() << endl;
		}

		friend bool operator== (const Vehicle& c1, const Vehicle& c2)
		{
			return ((c1.year_ == c2.year_) && (c1.make_ == c2.make_) && (c1.model_ == c2.model_) && (c1.color_ == c2.color_) && (c1.license_ == c2.license_));
		}

		/* 
		Functions
		*/

		string toCSV()
		{
			string csvline;
			string year = to_string(year_);
			return csvline = year + "," + make_ + "," + model_ + "," + color_ + "," + license_
;
		}

		Vehicle addVehicle();
		vector<Vehicle> loadVehicles();
		void printVehicles(vector<Vehicle>);
		void printVehiclesCSV(vector<Vehicle>);

};
