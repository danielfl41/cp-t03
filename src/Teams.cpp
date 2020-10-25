#include "Teams.hpp"
#include <sstream>
#include "Utils.hpp"
#include <string>
using namespace std;

Teams::Teams(string filepath) : CSVParser(filepath)
{
}
unordered_map<string, Team> Teams::get()
{
    return this->teams;
}
void Teams::parse()
{
    try
    {
        ifstream file = this->read();
        string line;
        vector<string> row;
        int index = 0;
        getline(file, line);
        while (getline(file, line))
        {
            row = Utils::split(line, ';');
            string id = to_string(index);
            string name = Utils::removeCommas(row[0]);
            string comuna = Utils::removeCommas(row[1]);
            string estadio = Utils::removeCommas(row[2]);
            string latString = Utils::removeCommas(row[3]);
            string lngString = Utils::removeCommas(row[4]);
            long double lat = stold(latString);
            long double lng = stold(lngString);

            pair<string, Team>
                team(id, Team(name, comuna, estadio, lat, lng));
            this->teams.insert(team);
            index++;
            row.clear();
        }
    }
    catch (const string &e)
    {
        throw e;
    }
}