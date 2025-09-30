#pragma once

#include "Ejercicio.h"
#include "Cliente.h"
#include "Instructor.h"
#include <iostream>

class Rutina {

private:

	Cliente* cliente;
	Instructor* instructor;

	string fecha;

    Ejercicio** ejerciciosPecho;
    int numEjerciciosPecho;
    int capacidadEjPe;

    Ejercicio** ejerciciosTriceps;
    int numEjerciciosTriceps;
    int capacidadEjTri;

    Ejercicio** ejerciciosBiceps;
    int numEjerciciosBiceps;
    int capacidadEjBi;

    Ejercicio** ejerciciosPiernas;
    int numEjerciciosPiernas;
    int capacidadEjPi;

    Ejercicio** ejerciciosEspalda;
    int numEjerciciosEspalda;
    int capacidadEjEs;

public:

    Rutina(Cliente* cli, Instructor* inst, string fec);

    ~Rutina();

    // Ejercicios Pecho
    bool agregarEjercicioPecho(Ejercicio* ejercicio);
    bool eliminarEjercicioPecho(string nombreEjercicio);
    Ejercicio** obtenerEjerciciosPecho() const;
    int getNumEjerciciosPecho() const;

    // Ejercicios Tricpes
    bool agregarEjercicioTriceps(Ejercicio* ejercicio);
    bool eliminarEjercicioTriceps(string nombreEjercicio);
    Ejercicio** obtenerEjerciciosTriceps() const;
    int getNumEjerciciosTriceps() const;

    // Ejercicios Biceps
    bool agregarEjercicioBiceps(Ejercicio* ejercicio);
    bool eliminarEjercicioBiceps(string nombreEjercicio);
    Ejercicio** obtenerEjerciciosBiceps() const;
    int getNumEjerciciosBiceps() const;
    
    // Ejercicios Pierna
    bool agregarEjercicioPiernas(Ejercicio* ejercicio);
    bool eliminarEjercicioPiernas(string nombreEjercicio);
    Ejercicio** obtenerEjerciciosPiernas() const;
    int getNumEjerciciosPiernas() const;

    // Ejercicios Espalda
    bool agregarEjercicioEspalda(Ejercicio* ejercicio);
    bool eliminarEjercicioEspalda(string nombreEjercicio);
    Ejercicio** obtenerEjerciciosEspalda() const;
    int getNumEjerciciosEspalda() const;

    void mostrarRutina() const;
    void EjerciciosPorTipo(string tipo) const;
    void ResumenRutina() const;
    void ReporteRutina() const;

    Cliente* getCliente()       const;
    Instructor* getInstructor() const;
    string getFecha()           const;
    int getTotalEjercicios()    const;
};