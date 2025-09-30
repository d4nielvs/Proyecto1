#pragma once

#include <iostream>
#include <string>
#include "Instructor.h"
#include "Sucursal.h"

using namespace std;

class Cliente {

private:

    string numCedula;
    string nombreCompleto;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;
    Instructor* instructorAsignado;
    Sucursal* codigo;

public:
  
    Cliente(string ced, string nom, string tel, string cor, string fechaNac, string sex, string fechaInsc, Instructor* instr = nullptr, Sucursal* codSuc = nullptr);
    
    ~Cliente();

    // Métodos 
    void asignarInstructor(Instructor* instr);
    void mostrarInfo() const;

    string getCedula()           const;
    string getNombre()           const;
    string getTelefono()         const;
    string getCorreo()           const;
    string getFechaNacimiento()  const;
    string getSexo()             const;
    string getFechaInscripcion() const;
    Instructor* getInstructor()  const;
    Sucursal* getCodigo()        const;
};
