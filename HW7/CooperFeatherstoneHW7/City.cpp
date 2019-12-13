//
// Created by Featherstone, Cooper P. (Student) on 2019-11-15.
//

#include "City.h"
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

City::City() {
    lat = 0;
    lng = 0;
}

City::City(string cty, string cntry, double lt, double lg) {
    city = cty;
    country = cntry;
    lat = lt;
    lng = lg;
}

bool City::matches(string cityName) {
    string cit = city;
    transform(cit.begin(), cit.end(), cit.begin(), ::tolower);
    transform(cityName.begin(), cityName.end(), cityName.begin(), ::tolower);

    return cit == cityName;
}

double City::dist(City &cit) {
    double dlng = cit.lng - lng;
    double dlat = cit.lat - lat;
    double a = pow(sin(dlat/2 * M_PI/180), 2) + cos(lat * M_PI/180) * cos(cit.lat * M_PI/180) * pow(sin(dlng/2 * M_PI/180), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return c * 3963;
}

const string &City::getCity() const {
    return city;
}

const string &City::getCountry() const {
    return country;
}

