#pragma once

#include "Cliente.h"
#include "Instructor.h"
#include <iostream>

class Medicion {

private:
	
	Cliente* cliente;
	
	Instructor* instructor;
	string fecha;
	double peso;	//en kilogramos
	double altura;  //en metros
	double porcentajeGrasa;
	double porcentajeMusculo;
	double porcentajeGrasaViceral;
	double cintura; //en centimetros
	double cadera;  //en centimetros
	double pecho;   //en centimetros
	double muslo;   //en centimetros
	int edadMetabolismo;

public:

	Medicion(Cliente* cli, Instructor* inst, string fec, double pe, double alt, double porGra, double porMus,
			 double porGraVic, double cint, double cad, double pec, double mus, int edMeta);

	~Medicion();

	// Métodos
	double calcularIMC()			   const;
	string claseIMC()				   const;
	bool esAltoRiesgo()				   const;
	double calcularProteinaNecesaria() const;
	int calcularAgua()				   const;

	Cliente* getCliente() const { return cliente; }
	Instructor* getInstructor() const { return instructor; }
	
	void mostrarInfo() const;
	void reporte() const;
};
