#pragma once

#include <iostream>
#include <string>
#include "Sucursal.h"
#include "Ejercicio.h"
#include "Mediciones.h"
#include "Rutina.h"
#include "Instructor.h"  
#include "Cliente.h"

using namespace std;

class Gimnasio {

private:

    Sucursal** sucursales;
    int capacidadSucursales;
    int numSucursales;

    Medicion** historialMediciones;
    int capacidadMediciones;
    int numMediciones;

    Ejercicio** bateriaEjercicios;
    int capacidadEjercicios;
    int numEjercicios;

    Rutina** rutinaActual;
    int capacidadRutinas;
    int numRutinas;

    ClaseGrupal** clasesGrupales;
    int capacidadClasesG;
    int numClasesG;

public:

    Gimnasio();

    ~Gimnasio();

    void cargarDatosIniciales();
    void mostrarMenuPrincipal() const;

    // Gestionar Sucursales
    void agregarSucursal();
    void listarSucursales() const;
    Sucursal* seleccionarSucursal();
    void gestionarSucursal();
    void menuGestionSucursal(Sucursal* sucursal);
    void agregarInstructor(Sucursal* sucursal);
    void agregarCliente(Sucursal* sucursal);
    void listarInstructoresSucursal(Sucursal* sucursal) const;
    void listarClientesSucursal(Sucursal* sucursal) const;

    // Gestionar Mediciones
    void agregarMedicionesCliente();
    void historialCliente();
    void menuMediciones();

    //Bateria de Ejercicios
    void agregarBateriaEjercicios();
    void mostrarBateriaEjercicios() const; 
    void menuBateriaEjercicios();
    
    // Gestionar Rutinas
    void agregarRutinaCliente();
    void mostrarRutinaCliente();
    void listarRutinasActivas() const;
    void menuRutinas();

    // Gestinar Clases Grupales
    void agregarClaseGrupal();
    void matricularCliente();
    void listarClasesGrupales() const;
    void menuClasesGrupales(Sucursal* sucursal);

    void ejecutar();
};


