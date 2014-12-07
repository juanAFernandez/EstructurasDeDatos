#ifndef _PALABRA
#define _PALABRA

#include <utility>
#include <set>
#include <string>
using namespace std;

class Palabra{

  private:

    pair < string, set < string > > palabra;

  public:

    void setPalabraOrigen(string palabraOrigen);

    string getPalabraOrigen();

    void setPalabraDestino(set <string> palabrasDestino);

    set <string> getPalabrasDestino();

    void cargarPalabras(string lineaTemporal);

};
#endif
