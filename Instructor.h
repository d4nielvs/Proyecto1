#pragma once

#include <iostream>
#include <string>

using namespace std;

class Instructor{

private:
    string numCedula;
    string nombreCompleto;
    string telefono;
    string correo;
    string fechaNacimiento;
    string* especialidades;  // Arreglo dinámico  especialidades
    int numEspecialidades;
    int capacidadEspecialidades;

public:
    Instructor(string ced, string nom, string tel, string cor, string fechaNac);
    ~Instructor();

    void agregarEspecialidad(string especialidad);
    void mostrarInfo() const;
      
    string getCedula() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    string getFechaNacimiento() const;
    string getEspecialidadesString() const;
    bool tieneEspecialidad(string especialidad) const;


};




