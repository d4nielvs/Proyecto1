#include "ClaseGrupal.h"
#include <iostream>

using namespace std;

ClaseGrupal::ClaseGrupal(string cod, string espec, string hora, string sal, int cupoMX, Instructor* inst):
						 codigo(cod), especialidad(espec), horario(hora), salon(sal), cupoMax(cupoMX),
						 instructor(inst), capacidadClientes(cupoMX) {

	clientesMat = new Cliente * [capacidadClientes];

	for (int i = 0; i < capacidadClientes; i++) {
		clientesMat[i] = nullptr;
	}
}

ClaseGrupal::~ClaseGrupal() {
	delete[] clientesMat;
}

bool ClaseGrupal::matricularCliente(Cliente* cliente) {
	if (!cupo()) {
		cout << "\n CUIDADO!!! No hay cupo disponible en la Clase Grupal." << endl;
		return false;
	}

	for (int i = 0; i < capacidadClientes; i++) {
		if (clientesMat[i] == nullptr) {
			clientesMat[i] = cliente;
			cantClientes++;
			return true;
		}
	}

	return false;

}

bool ClaseGrupal::desmatricularCliente(string cedula) {
	for (int i = 0; i < capacidadClientes; i++) {
		if (clientesMat[i] != nullptr && clientesMat[i]->getCedula() == cedula) {
			clientesMat[i] = nullptr;
			cantClientes--;
			return true;
		}
	}
	return false;
}

Cliente* ClaseGrupal::buscarClienteMatriculado(string cedula) const {
	for (int i = 0; i < capacidadClientes; i++) {
		if (clientesMat[i] != nullptr && clientesMat[i]->getCedula() == cedula) {
			return clientesMat[i];
		}
	}
	return nullptr;
}

bool ClaseGrupal::cupo() const {
	return cantClientes < cupoMax;
}

int ClaseGrupal::cuposDisponibles() const {
	return cupoMax - cantClientes;
}

string ClaseGrupal::getCodigo()		  const { return codigo; }
string ClaseGrupal::getEspecialidad() const { return especialidad; }
string ClaseGrupal::getHorario()	  const { return horario; }
string ClaseGrupal::getSalon()		  const { return salon; }
int ClaseGrupal::getCupoMax()		  const { return cupoMax; }
int ClaseGrupal::getCantClientes()	  const { return cantClientes; }

Instructor* ClaseGrupal::getInstructor() const { return instructor; }

Cliente** ClaseGrupal::getClientesMatriculados() const { return clientesMat; }

// Resumen
void ClaseGrupal::mostrarInfo() const {
    cout << "\n" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Instructor: ";
    if (instructor != nullptr) {
        cout << instructor->getNombre() << endl;
    }
    else {
        cout << "No asignado" << endl;
    }
    cout << "Horario: " << horario << endl;
    cout << "Salon: " << salon << endl;
    cout << "Matriculados: " << cantClientes << "/" << cupoMax << endl;
}

void ClaseGrupal::listarClientesMatriculados() const {
    cout << "\n----- CLIENTES MATRICULADOS EN CLASE GRUPAL" << especialidad << " (" << codigo << ") -----" << endl;
    bool hayClientes = false;

    for (int i = 0; i < capacidadClientes; i++) {
        if (clientesMat[i] != nullptr) {
            cout << i + 1 << ". " << clientesMat[i]->getNombre();
            cout << " (" << clientesMat[i]->getCedula() << ")" << endl;
            hayClientes = true;
        }
    }

    if (!hayClientes) {
        cout << "No hay clientes matriculados en esta clase." << endl;
    }
}

void ClaseGrupal::mostrarInfoCompleta() const {
    cout << "\n----- INFORMACIÓN COMPLETA DE CLASE GRUPAL -----" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Cupo máximo: " << cupoMax << endl;
    cout << "Horario: " << horario << endl;
    cout << "Salón: " << salon << endl;
    cout << "Matriculados: " << cantClientes << endl;
    cout << "Cupos disponibles: " << cuposDisponibles() << endl;
    

    if (instructor != nullptr) {
        cout << "---------------------------------------------" << endl;
        cout << "Instructor: " << instructor->getNombre() << endl;
        cout << "Especialidades del instructor: " << endl;
        instructor->getEspecialidadesString();
    }
    else {
        cout << "Instructor: No asignado" << endl;
    }

    cout << "---------------------------------------------" << endl;
    cout << "Clientes: " << endl;
    listarClientesMatriculados();
}