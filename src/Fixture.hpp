#ifndef FIXTURE_H
#define FIXTURE_H
#include "Teams.hpp"
/**
 * Representa y calcula el fixture
 */
class Fixture
{
private:
    int daysIndicator = 0;
    string filepath;
    Teams *teams;
    Date lastDate;
    struct footballMatch
    {
        time_t date;
        string localId;
        string visitId;
        long double distance;
    };
    unordered_map<string, footballMatch> fixture;
    /**
*  Añade un partido al fixture
* @param string id de local.
* @param string id de visita.
* @param long double distancia (en metros).
*/
    void addToFixture(string localId, string visitId, long double distance);

public:
    /**
* @constructor
* @param filepath ruta del archivo.
* @param *productsCSV Referencia a un objeto de tipo Teams que contenga la información de los equipos
*/
    Fixture(string filepath, Teams *teams);
    /**
* Calcula el fixture
*/
    void calc();
    /**
* Añade los duelos de segunda ronda y los guarda en un archivo
*/
    void write();
};
#endif