#pragma once

#include <iostream>
#include <string>
#include "Sucursal.h"
#include "Instructor.h"  
#include "Cliente.h"

using namespace std;

class Gimnasio {
private:
    Sucursal** sucursales;
    int capacidadSucursales;
    int numSucursales;

    void cargarDatosIniciales();
    void mostrarMenuPrincipal() const;
    void listarSucursales() const;
    void gestionarSucursal();
    void menuGestionSucursal(Sucursal* sucursal);
    void agregarInstructor(Sucursal* sucursal);
    void agregarCliente(Sucursal* sucursal);
   

public:
    Gimnasio();
    ~Gimnasio();

    void agregarSucursal();
    void ejecutar();
};

