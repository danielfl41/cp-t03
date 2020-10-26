#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "Coordinate.hpp"
using namespace std;
/**
 * Representa a un equipo
 */
class Team
{
private:
    string name;
    string comuna;
    string estadio;
    Coordinate coordinate;

public:
    /**
* @constructor
* @param string Nombrde del equipo
* @param string Comuna donde se encuentra el estadio
* @param string Nombre del estadio
* @param long double Coordenada - latitud
* @param long double Coordenada - longitud
*/
    Team(string name, string comuna, string estadio, long double lat, long double lng);
    /*
    * @returns Nombre del equipo
    */
    string getName()
    {
        return this->name;
    }
    /*
    * @returns Nombre de la comuna
    */
    string getComuna()
    {
        return this->comuna;
    }
    /*
    * @returns Nombre del estadio
    */
    string getEstadio()
    {
        return this->estadio;
    }
    /*
    * @returns Coordenadas
    */
    Coordinate getCoordinate()
    {
        return this->coordinate;
    }
};
#endif