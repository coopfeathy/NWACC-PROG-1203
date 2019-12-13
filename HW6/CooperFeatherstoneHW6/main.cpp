#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


struct person {
    //declaring variables
    std::string number;
    std::string gender;
    std::string title;
    std::string givenName;
    std::string middleInitial;
    std::string surname;
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zip;
    std::string email;
    std::string birth;

    std::string toString() {
        return number + ", " + givenName + " " + middleInitial + ". " + surname + ", " + birth;
    }
};


int main() {
    std::ifstream infile("./FakeNames.csv");
    std::ofstream outfile;
    outfile.open ("summary.txt");

    if (infile.is_open()) {
        std::vector<person> people;
        std::string line;
        std::unordered_map<std::string, int> names;
        std::unordered_map<std::string, int> cities;
        std::unordered_map<std::string, int> ages;

        // getting the  first line
        getline(infile, line);

        while (getline(infile, line)) {
            std::istringstream ss(line);
            // getting the people
            person p;
            getline(ss, p.number, ',');
            getline(ss, p.gender, ',');
            getline(ss, p.title, ',');
            getline(ss, p.givenName, ',');
            getline(ss, p.middleInitial, ',');
            getline(ss, p.surname, ',');
            getline(ss, p.streetAddress, ',');
            getline(ss, p.city, ',');
            p.city.erase(std::remove( p.city.begin(), p.city.end(), '\"' ), p.city.end());
            getline(ss, p.state, ',');
            getline(ss, p.zip, ',');
            getline(ss, p.email, ',');
            getline(ss, p.birth, ',');

            names[p.givenName]++;
            cities[p.city]++;

            people.push_back(p);
        }

        //the output on the summary file
        outfile << "Collection contains " << people.size() << " records." << std::endl;
        outfile << "First person: " << people[0].toString() << std::endl;
        outfile << "Last person: " << people[people.size() - 1].toString() << std::endl;
        outfile << std::endl;
        outfile << "Collection contains " << names.size() << " unique First names." << std::endl;

        std::vector<std::pair<std::string, int>> items;

        for(auto [key, value]: names)
            items.push_back(std::make_pair(key, value));

        std::sort(items.begin(), items.end(),
                  [](auto a, auto b)
                  { return a.second > b.second;});

        for(int i = 0; i < 100; i+=4) {
            outfile << std::setw(15) << items[i].first << ": " << std::setw(3) << items[i].second;
            outfile << std::setw(15) << items[i+1].first << ": " << std::setw(3) << items[i+1].second;
            outfile << std::setw(15) << items[i+2].first << ": " << std::setw(3) << items[i+2].second;
            outfile << std::setw(15) << items[i+3].first << ": " << std::setw(3) << items[i+3].second << std::endl;
        }

        outfile << std::endl;

        outfile << "Collection contains " << cities.size() << " unique City names." << std::endl;

        items = std::vector<std::pair<std::string, int>>();

        for(auto [key, value]: cities)
            items.push_back(std::make_pair(key, value));

        std::sort(items.begin(), items.end(),
                  [](auto a, auto b)
                  { return a.second > b.second;});

        for(int i = 0; i < 100; i+=3) {
            outfile << std::setw(20) << items[i].first << ": " << std::setw(3) << items[i].second;
            outfile << std::setw(20) << items[i+1].first << ": " << std::setw(3) << items[i+1].second;
            outfile << std::setw(20) << items[i+2].first << ": " << std::setw(3) << items[i+2].second << std::endl;
        }

        infile.close();
    }

    return 0;
}
