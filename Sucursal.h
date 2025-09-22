#pragma once

#include <iostream>
#include <string>
#include "Instructor.h"
#include "Cliente.h"

using namespace std;

class Sucursal {
private:
    string codigo;
    string provincia;
    string canton;   
    string telefono;
    Instructor** instructores;
    Cliente** clientes;
    int capacidadInstructores;
    int capacidadClientes;
    int numInstructores;
    int numClientes;

public:
    Sucursal(string cod, string prov,string can, string tel);
    ~Sucursal();

    void agregarInstructor(Instructor* instructor);
    void agregarCliente(Cliente* cliente);
    void mostrarInfo() const;
    void listarInstructores() const;
    void listarClientes() const;

    
    string getCodigo() const;
    int getNumInstructores() const;
    Instructor* getInstructor(int index) const;
};


