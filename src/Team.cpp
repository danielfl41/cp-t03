#include "./Team.hpp"
Team::Team(string name, string comuna, string estadio, double lat, double lng) : coordinate(lat, lng)
{
    this->name = name;
    this->comuna = comuna;
    this->estadio = estadio;
}