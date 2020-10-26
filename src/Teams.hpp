#ifndef TEAMS_H
#define TEAMS_H
#include "./CSVParser.hpp"
#include <unordered_map>
#include "Date.hpp"
#include "./Team.hpp"
/**
 * Representa un CSVParser de tipo Teams extiende el parser para leer específicamente csv formateados como Teams
 * @extends CSVParser
 */
class Teams : protected CSVParser
{

public:
    /**
* @constructor
* @param filepath ruta del archivo.
*/
    Teams(string filepath);
    /*
    * 
    * @returns Lista de equipo
    * */
    unordered_map<string, Team> get();
    void parse();

private:
    unordered_map<string, Team> teams;
};
#endif