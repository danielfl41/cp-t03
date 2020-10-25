#ifndef FIXTURE_H
#define FIXTURE_H
#include "Teams.hpp"

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
    void addToFixture(string localId, string visitId, long double distance, bool second);

public:
    Fixture(string filepath, Teams *teams);
    void calc();
    void write();
};
#endif