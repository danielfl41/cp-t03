
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
        // Se realiza un parse sobre el contenido del archivo de equipos
        teams.parse();
        // Se calcula el fixture
        fixture.calc();
        // Se calcula la segunda ronda y se guarda el contenido en un csv
        fixture.write();
        cout << "END" << endl;
    }
    catch (const string &msg)
    {
        cout << "ERROR:" << endl
             << msg << endl;
    }
}
