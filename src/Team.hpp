#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "Coordinate.hpp"
using namespace std;
class Team
{
private:
    string name;
    string comuna;
    string estadio;
    Coordinate coordinate;

public:
    Team(string name, string comuna, string estadio, double lat, double lng);
    string getName()
    {
        return this->name;
    }
    string getComuna()
    {
        return this->comuna;
    }
    string getEstadio()
    {
        return this->estadio;
    }
    Coordinate getCoordinate()
    {
        return this->coordinate;
    }
};
#endif