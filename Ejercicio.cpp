#include "Ejercicio.h"
#include <iostream>

using namespace std;

Ejercicio::Ejercicio(string nom, string des, string are, string maqui, int ser, int rep) :
					 nombre(nom), descripcion(des), area(are), maquinas(maqui),
					 serie(ser), repeticiones(rep) { }

Ejercicio::~Ejercicio() {}

bool Ejercicio::areaValida(string area) const {
	string areaValida[] = { "Pecho", "Triceps", "Biceps", "Piernas", "Espalda" };
    
    for (int i = 0; i < 5; i++) {
        if (area == areaValida[i]) {
            return true;
        }
    }
    return false;
}

string Ejercicio::getNombre()      const { return nombre; }
string Ejercicio::getDescripcion() const { return descripcion; }
string Ejercicio::getArea()        const { return area; }
string Ejercicio::getMaquinas()    const { return maquinas; }
int Ejercicio::getSeries()         const { return serie; }
int Ejercicio::getRepeticiones()   const { return repeticiones; }

// Resumen
void Ejercicio::mostrarInfoBasica() const {
    cout << "Nombre: " << nombre;
    cout << "Area: " << area << endl;;
    cout << "Series: " << serie << " x " << repeticiones;
    cout << "Maquinas: " << maquinas << endl;
}

void Ejercicio::mostrarInfoCompleta() const {
    cout << "\n----- INFORMACIÓN DEL EJERCICIO " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "Area: " << area << endl;
    cout << "Series y repeticiones: " << serie << " x " << repeticiones << endl;
    cout << "Maquinas: " << maquinas << endl;
}

void Ejercicio::resumen() const {
    cout << nombre << " (" << area << ") - " << serie << "x" << repeticiones << endl;
}