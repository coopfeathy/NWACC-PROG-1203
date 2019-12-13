#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "City.h"

using namespace std;

int main() {
    ifstream infile("worldcities.csv");
    vector<City> cities;
    string line;

    getline(infile, line);

    while (getline(infile, line)) {
        istringstream ss(line);
        string city, country, temp;
        double lat, lng;

        // get cities
        getline(ss, city, ',');
        getline(ss, country, ',');
        // get rid of the first space
        country = country.substr(1);
        getline(ss, temp, ',');
        lat = stod(temp);
        getline(ss, temp, ',');
        lng = stod(temp);

        City c = City(city, country, lat, lng);

        cities.emplace_back(c);
    }

    //set the width for the first row
    cout << setw(3) << "index" << setw(16) << "City" << ", " << setw(18) << "Country" << endl;

    //set the width for the rest of the rows
    for (int i = 0; i < cities.size(); i++) {
        City city = cities[i];
        cout << setw(3) << i << setw(18) << city.getCity() << ", " << setw(18) << city.getCountry() << endl;
    }

    City city;

    while(true){
        do {
            //Prompting the user to choose a city
            cout << endl;
            cout << "Chose a city by entering index number or name(enter Quit to stop): ";

            string choice;

            // getting the users input
            getline(cin, choice);

            // catchign the quit
            if(choice == "Quit" || choice =="quit"){
                return 0;
            }
            try {
                int i = stoi(choice);

                city = cities[i];
            } catch (invalid_argument &e) {
                for (auto& c : cities) {
                    if (c.matches(choice)) {
                        city = c;
                    }
                }
            }
        } while(city.getCity().empty());

        // printing the output
        cout << endl;
        cout << "Closest cities to " << city.getCity() << ", " << city.getCountry() << endl;

        sort(cities.begin(), cities.end(),
             [&city](auto a, auto b)
             { return a.dist(city) < b.dist(city);});

        for (int i = 1; i <= 5; i++) {
            City cit = cities[i];
            cout << setw(3) << i << setw(18) << cit.getCity() << ", " << setw(18) << cit.getCountry()
                 << " " << fixed << showpoint << setprecision(2) << setw(8) << cit.dist(city) << " mi" << endl;
        }

    }
}