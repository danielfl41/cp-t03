#include "./Team.hpp"
Team::Team(string name, string comuna, string estadio, long double lat, long double lng) : coordinate(lat, lng)
{
    this->name = name;
    this->comuna = comuna;
    this->estadio = estadio;
}