
#include <iostream>
#include "Teams.hpp"
#include "Fixture.hpp"

using namespace std;
int main()
{
    cout << "START" << endl;
    // Instancia las clases, especificando la ruta de los archivos segú el tipo
    Teams teams("equipos.csv");
    Fixture fixture("fixture.csv", &teams);
    try
    {
        teams.parse();
        fixture.calc();
        fixture.write();
    }
    catch (const string &msg)
    {
        cout << "ERROR:" << endl
             << msg << endl;
    }
}
