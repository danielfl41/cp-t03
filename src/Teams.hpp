#ifndef TEAMS_H
#define TEAMS_H
#include "./CSVParser.hpp"
#include <unordered_map>
#include "Date.hpp"
#include "./Team.hpp"
class Teams : protected CSVParser
{

public:
    Teams(string filepath);
    unordered_map<string, Team> get();
    void parse();

private:
    unordered_map<string, Team> teams;
};
#endif