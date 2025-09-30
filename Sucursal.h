#pragma once

#include <iostream>
#include "Instructor.h"
#include "Cliente.h"
#include "ClaseGrupal.h"

using namespace std;

class Sucursal {

private:

    string codigo;
    string provincia;
    string canton;   
    string telefono;
    string correo;

    Instructor** instructores;
    int capacidadInstructores;
    int numInstructores;

    Cliente** clientes;
    int capacidadClientes;
    int numClientes;

    ClaseGrupal** clasesGrupales;
    int capacidadClasesG;
    int numClasesG;

public:

    Sucursal(string cod, string prov, string cant, string tel, string cor);
    ~Sucursal();

    string getCodigo()    const;
    string getProvincia() const;
    string getCanton()    const;
    string getTelefono()  const;
    string getCorreo()    const;

    int getNumInstructores() const;
    int getNumClientes()     const;
    int getNumClasesG()      const;

    // Instructores
    void agregarInstructor(Instructor* instructor);
    bool eliminarInstructor(string cedula);
    Instructor* buscarInstructor(string cedula) const;
    Instructor** obtenerInstructores()          const;
    void listarInstructores()                   const;

    // Clientes
    void agregarCliente(Cliente* cliente);
    bool eliminarCliente(string cedula);
    Cliente* buscarCliente(string cedula);
    Cliente** obtenerClientes() const;
    void listarClientes()       const;

    // Clases grupales
    void agregarClaseGrupal(ClaseGrupal* claseG);
    bool eliminarClaseGrupal(string codigoClaseG);
    ClaseGrupal* buscarClaseGrupal(string codigoClaseG) const;
    ClaseGrupal** obtenerClaseGrupal()                  const;
    void listarClasesGrupales()                         const;
    
    void mostrarInfo()  const;
    void mostrarDatos() const;
};
