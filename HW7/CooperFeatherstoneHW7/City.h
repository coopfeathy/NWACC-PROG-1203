//
// Created by Featherstone, Cooper P. (Student) on 2019-11-15.
//

#ifndef COOPERFEATHERSTONEHW7_CITY_H
#define COOPERFEATHERSTONEHW7_CITY_H


#include <string>

using namespace std;

class City {
private:
    string city;
    string country;
    double lat;
    double lng;
public:
    City();
    City(string city, string country, double lat, double lng);
    const string &getCity() const;
    const string &getCountry() const;
    bool matches(string cityName);
    double dist(City& c);
};


#endif //COOPERFEATHERSTONEHW7_CITY_H
