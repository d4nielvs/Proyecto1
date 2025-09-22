#include "Sucursal.h"

Sucursal::Sucursal(string cod, string prov, string can, string tel) : codigo(cod), provincia(prov), canton(can), 
telefono(tel), capacidadInstructores(10), capacidadClientes(50),numInstructores(0), numClientes(0) {

    instructores = new Instructor * [capacidadInstructores];
    clientes = new Cliente * [capacidadClientes];
}

Sucursal::~Sucursal() {
    delete[] instructores;
    delete[] clientes;
}

void Sucursal::agregarInstructor(Instructor* instructor) {
    if (numInstructores < capacidadInstructores) {
        instructores[numInstructores++] = instructor;
        cout << "Instructor agregado con éxito" << endl;
    }
    else {
        cout << "No se pueden agregar mas instructores a esta sucursal." << endl;
    }
}

void Sucursal::agregarCliente(Cliente* cliente) {
    if (numClientes < capacidadClientes) {
        clientes[numClientes++] = cliente;
        cout << "Cliente agregado con exito" << endl;
    }
    else {
        cout << "No se pueden agregar mas clientes a esta sucursal." << endl;
    }
}

void Sucursal::mostrarInfo() const {
    cout << "\n-----SUCURSAL " << codigo << " -----" << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Canton: " << canton << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Instructores: " << numInstructores << endl;
    cout << "Clientes: " << numClientes << endl;
}

void Sucursal::listarInstructores() const {
    cout << "\n----- Instructores de la sucursal " << codigo << " -----" << endl;
    for (int i = 0; i < numInstructores; i++) {
        cout << i + 1 << ". ";
        instructores[i]->mostrarInfo();
    }
}

void Sucursal::listarClientes() const {
    cout << "\n----- Clientes de la sucursal " << codigo << " -----" << endl;
    for (int i = 0; i < numClientes; i++) {
        cout << i + 1 << ". ";
        clientes[i]->mostrarInfo();
    }
}

string Sucursal::getCodigo() const { return codigo; }
int Sucursal::getNumInstructores() const { return numInstructores; }

Instructor* Sucursal::getInstructor(int index) const {
    if (index >= 0 && index < numInstructores) {
        return instructores[index];
    }
    return nullptr;
}