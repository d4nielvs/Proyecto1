#include "Instructor.h"
#include <iostream>

using namespace std;

Instructor::Instructor(string ced, string nom, string tel, string cor, string fechaNac): 
                       numCedula(ced), nombreCompleto(nom), telefono(tel), correo(cor),  
                       fechaNacimiento(fechaNac), numEspecialidades(0), capacidadEspecialidades(5) {

    especialidades = new string[capacidadEspecialidades];
}

Instructor::~Instructor() {
    delete[] especialidades;
}

void Instructor::agregarEspecialidad(string especialidad) {
    // cambiar tamaño si es necesario
    if (numEspecialidades >= capacidadEspecialidades) {
        capacidadEspecialidades *= 2;
        string* newArray = new string[capacidadEspecialidades];

        for (int i = 0; i < numEspecialidades; i++) {
            newArray[i] = especialidades[i];

        }

        delete[] especialidades;
        especialidades = newArray;
    }

    especialidades[numEspecialidades++] = especialidad;
}

void Instructor::mostrarInfo() const {
    cout << "\n-----INFORMACION DEL INSTRUCTOR-----" << endl;
    cout << "Numero de cedula: " << numCedula << endl;
    cout << "Nombre completo: " << nombreCompleto << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo electronico: " << correo << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Especialidades: " << getEspecialidadesString() << endl;
}

string Instructor::getCedula()          const { return numCedula; }
string Instructor::getNombre()          const { return nombreCompleto; }
string Instructor::getTelefono()        const { return telefono; }
string Instructor::getCorreo()          const { return correo; }
string Instructor::getFechaNacimiento() const { return fechaNacimiento; }

string Instructor::getEspecialidadesString() const {
    if (numEspecialidades == 0) return "Ninguna";

    string resultado = "";
    for (int i = 0; i < numEspecialidades; i++) {
        resultado += especialidades[i];
        if (i < numEspecialidades - 1) resultado += ", ";
    }
    return resultado;
}

bool Instructor::tieneEspecialidad(string especialidad) const {
    for (int i = 0; i < numEspecialidades; i++) {
        if (especialidades[i] == especialidad) return true;
    }
    return false;
}

