#pragma once

#include <iostream>
#include "Instructor.h"
#include "Cliente.h"

class ClaseGrupal {

private:

	string codigo;
	string especialidad; //CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba
	string horario;
	string salon;
	int cupoMax;
	int cantClientes;
	
	Instructor* instructor;

	Cliente** clientesMat;
	int capacidadClientes;

public:

	ClaseGrupal(string cod, string espec, string hora, string sal, int cupoMX, Instructor* inst);
	~ClaseGrupal();

	bool matricularCliente(Cliente* cliente);
	bool desmatricularCliente(string cedula);
	Cliente* buscarClienteMatriculado(string cedula) const;

	bool cupo() const;
	int cuposDisponibles() const;

	void mostrarInfo() const;
	void listarClientesMatriculados() const;
	void mostrarInfoCompleta() const;

	string getCodigo()		 const;
	string getEspecialidad() const;
	string getHorario()		 const;
	string getSalon()		 const;
	int getCupoMax()		 const;
	int getCantClientes()	 const;

	Instructor* getInstructor() const;

	Cliente** getClientesMatriculados() const;
};