#include "Rutina.h"
#include <iostream>

using namespace std;

Rutina::Rutina(Cliente* cli, Instructor* inst, string fec) :
			   cliente(cli), instructor(inst), fecha(fec) {

    capacidadEjPe = 5;
    ejerciciosPecho = new Ejercicio * [capacidadEjPe];
    numEjerciciosPecho = 0;

    capacidadEjTri = 5;
    ejerciciosTriceps = new Ejercicio * [capacidadEjTri];
    numEjerciciosTriceps = 0;

    capacidadEjBi = 5;
    ejerciciosBiceps = new Ejercicio * [capacidadEjBi];
    numEjerciciosBiceps = 0;

    capacidadEjPi = 5;
    ejerciciosPiernas = new Ejercicio * [capacidadEjPi];
    numEjerciciosPiernas = 0;

    capacidadEjEs = 5;
    ejerciciosEspalda = new Ejercicio * [capacidadEjEs];
    numEjerciciosEspalda = 0;
}

Rutina::~Rutina() {
    delete[] ejerciciosPecho;
    delete[] ejerciciosTriceps;
    delete[] ejerciciosBiceps;
    delete[] ejerciciosPiernas;
    delete[] ejerciciosEspalda;
}

// Gestion Ejercicios de Pecho
bool Rutina::agregarEjercicioPecho(Ejercicio* ejercicio) {
    if (numEjerciciosPecho >= capacidadEjPe) {
        // Redimensionar array
        capacidadEjPe *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjPe];
        for (int i = 0; i < numEjerciciosPecho; i++) {
            nuevo[i] = ejerciciosPecho[i];
        }
        delete[] ejerciciosPecho;
        ejerciciosPecho = nuevo;
    }

    ejerciciosPecho[numEjerciciosPecho] = ejercicio;
    numEjerciciosPecho++;
    return true;
}

bool Rutina::eliminarEjercicioPecho(string nombreEjercicio) {
    for (int i = 0; i < numEjerciciosPecho; i++) {
        if (ejerciciosPecho[i]->getNombre() == nombreEjercicio) {
            for (int j = i; j < numEjerciciosPecho - 1; j++) {
                ejerciciosPecho[j] = ejerciciosPecho[j + 1];
            }
            numEjerciciosPecho--;
            return true;
        }
    }
    return false;
}

Ejercicio** Rutina::obtenerEjerciciosPecho() const {
    return ejerciciosPecho;
}

int Rutina::getNumEjerciciosPecho() const { return numEjerciciosPecho; }

// Gestion Ejercicios de Triceps
bool Rutina::agregarEjercicioTriceps(Ejercicio* ejercicio) {
    if (numEjerciciosTriceps >= capacidadEjTri) {
        // Redimensionar array
        capacidadEjTri *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjTri];
        for (int i = 0; i < numEjerciciosTriceps; i++) {
            nuevo[i] = ejerciciosTriceps[i];
        }
        delete[] ejerciciosTriceps;
        ejerciciosTriceps = nuevo;
    }

    ejerciciosTriceps[numEjerciciosTriceps] = ejercicio;
    numEjerciciosTriceps++;
    return true;
}

bool Rutina::eliminarEjercicioTriceps(string nombreEjercicio) {
    for (int i = 0; i < numEjerciciosTriceps; i++) {
        if (ejerciciosTriceps[i]->getNombre() == nombreEjercicio) {
            for (int j = i; j < numEjerciciosTriceps - 1; j++) {
                ejerciciosTriceps[j] = ejerciciosTriceps[j + 1];
            }
            numEjerciciosTriceps--;
            return true;
        }
    }
    return false;
}

Ejercicio** Rutina::obtenerEjerciciosTriceps() const {
    return ejerciciosTriceps;
}

int Rutina::getNumEjerciciosTriceps() const { return numEjerciciosTriceps; }

// Gestion Ejercicios de Biceps
bool Rutina::agregarEjercicioBiceps(Ejercicio* ejercicio) {
    if (numEjerciciosBiceps >= capacidadEjBi) {
        capacidadEjBi *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjBi];
        for (int i = 0; i < numEjerciciosBiceps; i++) {
            nuevo[i] = ejerciciosBiceps[i];
        }
        delete[] ejerciciosBiceps;
        ejerciciosBiceps = nuevo;
    }

    ejerciciosBiceps[numEjerciciosBiceps] = ejercicio;
    numEjerciciosBiceps++;
    return true;
}

bool Rutina::eliminarEjercicioBiceps(string nombreEjercicio) {
    for (int i = 0; i < numEjerciciosBiceps; i++) {
        if (ejerciciosBiceps[i]->getNombre() == nombreEjercicio) {
            for (int j = i; j < numEjerciciosBiceps - 1; j++) {
                ejerciciosBiceps[j] = ejerciciosBiceps[j + 1];
            }
            numEjerciciosBiceps--;
            return true;
        }
    }
    return false;
}

Ejercicio** Rutina::obtenerEjerciciosBiceps() const {
    return ejerciciosBiceps;
}

int Rutina::getNumEjerciciosBiceps() const { return numEjerciciosBiceps; }

// Gestion Ejercicios de Pierna
bool Rutina::agregarEjercicioPiernas(Ejercicio* ejercicio) {
    if (numEjerciciosPiernas >= capacidadEjPi) {
        capacidadEjPi *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjPi];
        for (int i = 0; i < numEjerciciosPiernas; i++) {
            nuevo[i] = ejerciciosPiernas[i];
        }
        delete[] ejerciciosPiernas;
        ejerciciosPiernas = nuevo;
    }

    ejerciciosPiernas[numEjerciciosPiernas] = ejercicio;
    numEjerciciosPiernas++;
    return true;
}

bool Rutina::eliminarEjercicioPiernas(string nombreEjercicio) {
    for (int i = 0; i < numEjerciciosPiernas; i++) {
        if (ejerciciosPiernas[i]->getNombre() == nombreEjercicio) {
            for (int j = i; j < numEjerciciosPiernas - 1; j++) {
                ejerciciosPiernas[j] = ejerciciosPiernas[j + 1];
            }
            numEjerciciosPiernas--;
            return true;
        }
    }
    return false;
}

Ejercicio** Rutina::obtenerEjerciciosPiernas() const {
    return ejerciciosPiernas;
}

int Rutina::getNumEjerciciosPiernas() const { return numEjerciciosPiernas; }

// Gestion Ejercicios de Espalda
bool Rutina::agregarEjercicioEspalda(Ejercicio* ejercicio) {
    if (numEjerciciosEspalda >= capacidadEjEs) {
        capacidadEjEs *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjEs];
        for (int i = 0; i < numEjerciciosEspalda; i++) {
            nuevo[i] = ejerciciosEspalda[i];
        }
        delete[] ejerciciosEspalda;
        ejerciciosEspalda = nuevo;
    }

    ejerciciosEspalda[numEjerciciosEspalda] = ejercicio;
    numEjerciciosEspalda++;
    return true;
}

bool Rutina::eliminarEjercicioEspalda(string nombreEjercicio) {
    for (int i = 0; i < numEjerciciosEspalda; i++) {
        if (ejerciciosEspalda[i]->getNombre() == nombreEjercicio) {
            for (int j = i; j < numEjerciciosEspalda - 1; j++) {
                ejerciciosEspalda[j] = ejerciciosEspalda[j + 1];
            }
            numEjerciciosEspalda--;
            return true;
        }
    }
    return false;
}

Ejercicio** Rutina::obtenerEjerciciosEspalda() const {
    return ejerciciosEspalda;
}

int Rutina::getNumEjerciciosEspalda() const { return numEjerciciosEspalda; }

Cliente* Rutina::getCliente()       const { return cliente; }
Instructor* Rutina::getInstructor() const { return instructor; }
string Rutina::getFecha()           const { return fecha; }

int Rutina::getTotalEjercicios()    const {
    return numEjerciciosPecho + numEjerciciosTriceps + numEjerciciosBiceps +
           numEjerciciosPiernas + numEjerciciosEspalda;
}

void Rutina::mostrarRutina() const {
    cout << "\n----- RUTINA -----" << endl;
    cout << "Fecha: " << fecha << endl;

    if (cliente != nullptr) {
        cout << "Cliente: " << cliente->getNombre() << endl;
    }

    if (instructor != nullptr) {
        cout << "Instructor: " << instructor->getNombre() << endl;
    }

    cout << "\n--- PECHO ---" << endl;
    if (numEjerciciosPecho > 0) {
        for (int i = 0; i < numEjerciciosPecho; i++) {
            cout << i + 1 << ". ";
            ejerciciosPecho[i]->resumen();
        }
    }
    else {
        cout << "No hay ejercicios asignados." << endl;
    }

    cout << "\n--- TRÍCEPS ---" << endl;
    if (numEjerciciosTriceps > 0) {
        for (int i = 0; i < numEjerciciosTriceps; i++) {
            cout << i + 1 << ". ";
            ejerciciosTriceps[i]->resumen();
        }
    }
    else {
        cout << "No hay ejercicios asignados." << endl;
    }

    cout << "\n--- BÍCEPS ---" << endl;
    if (numEjerciciosBiceps > 0) {
        for (int i = 0; i < numEjerciciosBiceps; i++) {
            cout << i + 1 << ". ";
            ejerciciosBiceps[i]->resumen();
        }
    }
    else {
        cout << "No hay ejercicios asignados." << endl;
    }

    cout << "\n--- PIERNAS ---" << endl;
    if (numEjerciciosPiernas > 0) {
        for (int i = 0; i < numEjerciciosPiernas; i++) {
            cout << i + 1 << ". ";
            ejerciciosPiernas[i]->resumen();
        }
    }
    else {
        cout << "No hay ejercicios asignados." << endl;
    }

    cout << "\n--- ESPALDA ---" << endl;
    if (numEjerciciosEspalda > 0) {
        for (int i = 0; i < numEjerciciosEspalda; i++) {
            cout << i + 1 << ". ";
            ejerciciosEspalda[i]->resumen();
        }
    }
    else {
        cout << "No hay ejercicios asignados." << endl;
    }

    cout << "\nTotal de ejercicios: " << getTotalEjercicios() << endl;
}

void Rutina::EjerciciosPorTipo(string tipo) const {
    cout << "\n----- EJERCICIOS DE " << tipo << " -----" << endl;

    if (tipo == "PECHO") {
        for (int i = 0; i < numEjerciciosPecho; i++) {
            cout << i + 1 << ". ";
            ejerciciosPecho[i]->mostrarInfoBasica();
        }
    }
    else if (tipo == "TRICEPS") {
        for (int i = 0; i < numEjerciciosTriceps; i++) {
            cout << i + 1 << ". ";
            ejerciciosTriceps[i]->mostrarInfoBasica();
        }
    }
    else if (tipo == "BICEPS") {
        for (int i = 0; i < numEjerciciosBiceps; i++) {
            cout << i + 1 << ". ";
            ejerciciosBiceps[i]->mostrarInfoBasica();
        }
    }
    else if (tipo == "PIERNAS") {
        for (int i = 0; i < numEjerciciosPiernas; i++) {
            cout << i + 1 << ". ";
            ejerciciosPiernas[i]->mostrarInfoBasica();
        }
    }
    else if (tipo == "ESPALDA") {
        for (int i = 0; i < numEjerciciosEspalda; i++) {
            cout << i + 1 << ". ";
            ejerciciosEspalda[i]->mostrarInfoBasica();
        }
    }
    else {
        cout << "..." << endl;
    }
}

void Rutina::ResumenRutina() const {
    cout << "Rutina de: " << fecha << endl;
    cout << "Ejercicios: " << getTotalEjercicios() << endl;
    cout << "Pecho: " << numEjerciciosPecho << endl;
    cout << "Triceps: " << numEjerciciosTriceps << endl;
    cout << "Biceps: " << numEjerciciosBiceps << endl;
    cout << "Piernas: " << numEjerciciosPiernas << endl;
    cout << "Espalda: " << numEjerciciosEspalda << endl;
}

void Rutina::ReporteRutina() const {
    cout << "\n----- REPORTE DE RUTINA -----" << endl;
    mostrarRutina();
}









