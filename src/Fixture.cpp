#include "Fixture.hpp"
#include <vector>
#include <algorithm> // std::sort

Fixture::Fixture(string filepath, Teams *teams)
{
    this->filepath = filepath;
    this->teams = teams;
}
void Fixture::addToFixture(string localId, string visitId, long double distance, bool second = false)
{
    string id = localId + "VS" + visitId;
    string altId = visitId + "VS" + localId;
    if (second)
    {
        id += "s";
        altId += "s";
    }
    if (this->fixture.find(id) != this->fixture.end() || this->fixture.find(altId) != this->fixture.end())
        return;
    Date matchDate;
    matchDate.addDays(this->daysIndicator);
    if (!this->lastDate.isSeted())
        this->lastDate.setDate(matchDate.getDate());
    if (this->lastDate.isLowerThan(matchDate.getDate()))
    {
        this->lastDate.setDate(matchDate.getDate());
    }
    this->daysIndicator++;
    this->fixture[id] = {matchDate.getDate(), localId, visitId, distance};
}
void Fixture::calc()
{
    try
    {
        const auto teams = this->teams->get();
        this->daysIndicator = 0;
        this->lastDate.clear();
        struct teamDistance
        {
            string id;
            long double distance;
        };
        for (auto local : teams)
        {
            string localId = local.first;
            auto localTeam = local.second;
            vector<teamDistance> oTeams;
            for (auto visit : teams)
            {
                string visitId = visit.first;
                if (visitId == localId)
                    continue;
                auto visitTeam = visit.second;
                auto distance = localTeam.getCoordinate().distance(visitTeam.getCoordinate());
                oTeams.push_back({visitId,
                                  distance});
            }
            sort(
                oTeams.begin(), oTeams.end(), [](teamDistance a, teamDistance b) {
                    return a.distance < b.distance;
                });
            ;
            for (auto it = oTeams.begin(); it != oTeams.end(); ++it)
            {
                auto teamDistance = *it;
                auto visitTeam = teams.at(teamDistance.id);
                this->addToFixture(localId, teamDistance.id, teamDistance.distance);
            }
        }
    }
    catch (const string &msg)
    {
        throw msg;
    }
    return;
}
void Fixture::write()
{
    try
    {
        ofstream outfile;
        outfile.open(this->filepath);
        outfile << "\"Fecha\";\"Local\";\"Visita\";\"Distancia (m)\"" << endl;
        for (auto _match : this->fixture)
        {
            auto teams = this->teams->get();
            auto match = _match.second;
            auto distance = match.distance;
            auto local = teams.at(match.localId);
            auto visit = teams.at(match.visitId);
            char *date = ctime(&match.date);
            string strDistance = to_string(distance);
            std::string strDate(date);
            string line = "\"" + strDate + "\";\"" + local.getName() + "\";\"" + visit.getName() + "\";\"" + strDistance + "\"";
            outfile << line << endl;
        };
        int indicator = 1;
        for (auto _match : this->fixture)
        {
            auto teams = this->teams->get();
            auto match = _match.second;
            auto distance = match.distance;
            auto local = teams.at(match.visitId);
            auto visit = teams.at(match.localId);
            cout << "indicator: " << indicator << endl;
            Date fDate;
            fDate.setDate(this->lastDate.getDate());
            fDate.addDays(indicator);
            auto lDate = fDate.getDate();
            char *date = ctime(&lDate);
            cout << "date: " << date << endl;
            string strDistance = to_string(distance);
            std::string strDate(date);
            string line = "\"" + strDate + "\";\"" + local.getName() + "\";\"" + visit.getName() + "\";\"" + strDistance + "\"";
            indicator++;
            outfile << line << endl;
        }
        outfile.close();
        return;
    }
    catch (const string &e)
    {
        throw e;
    }
}
