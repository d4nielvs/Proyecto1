#include "Sucursal.h"
#include <iostream>

using namespace std;

Sucursal::Sucursal(string cod, string prov, string cant, string tel, string cor): 
                   codigo(cod), provincia(prov), canton(cant),telefono(tel), correo(cor), 
                   capacidadInstructores(10), numInstructores(0), capacidadClientes(30),
                   numClientes(0), capacidadClasesG(8), numClasesG(0) {

    instructores = new Instructor * [capacidadInstructores];

    clientes = new Cliente * [capacidadClientes];

    clasesGrupales = new ClaseGrupal * [capacidadClasesG];
}

Sucursal::~Sucursal() {
    delete[] instructores;
    delete[] clientes;
    delete[] clasesGrupales;
}

void Sucursal::mostrarInfo() const {
    cout << "\n----- SUCURSAL " << codigo << " -----" << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Canton: " << canton << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Instructores: " << numInstructores << endl;
    cout << "Clientes: " << numClientes << endl;
}

string Sucursal::getCodigo()    const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton()    const { return canton; }
string Sucursal::getTelefono()  const { return telefono; }
string Sucursal::getCorreo()    const { return correo; }

int Sucursal::getNumInstructores() const { return numInstructores; }
int Sucursal::getNumClientes()     const { return numClientes; }
int Sucursal::getNumClasesG()      const { return numClasesG; }

// Instructores
void Sucursal::agregarInstructor(Instructor* instructor) {
    if (numInstructores >= capacidadInstructores) {
        capacidadInstructores *= 2;
        Instructor** nuevo = new Instructor*[capacidadInstructores];
        for (int i = 0; i < numInstructores; i++) {
            nuevo[i] = instructores[i];
        }
        delete[] instructores;
        instructores = nuevo;
    }
    instructores[numInstructores] = instructor;
        numInstructores++;
}

bool Sucursal::eliminarInstructor(string cedula) {
    for (int i = 0; i < numInstructores; i++) {
        if (instructores[i]->getCedula() == cedula) {
            for (int j = i; j < numInstructores - 1; j++) {
                instructores[j] = instructores[j + 1];
            }
            numInstructores--;
            return true;
        }
    }
    return false;
}

Instructor* Sucursal::buscarInstructor(string cedula) const {
    for (int i = 0; i < numInstructores; i++) {
        if (instructores[i]->getCedula() == cedula) {
            return instructores[i];
        }
    }
    return nullptr;
}

Instructor** Sucursal::obtenerInstructores() const {
    return instructores;
}

void Sucursal::listarInstructores() const {
    cout << "\n----- INSTRUCTORES DE LA SUCURSAL -----" << endl;
    for (int i = 0; i < numInstructores; i++) {
        cout << i + 1 << ". ";
        instructores[i]->mostrarInfo();
        cout << "---------------------------------------------" << endl;
    }
}

// Clientes
void Sucursal::agregarCliente(Cliente* cliente) {
    if (numClientes >= capacidadClientes) {
        capacidadClientes *= 2;
        Cliente** nuevo = new Cliente * [capacidadClientes];
        for (int i = 0; i < numClientes; i++) {
            nuevo[i] = clientes[i];
        }
        delete[] clientes;
        clientes = nuevo;
    }
    clientes[numClientes] = cliente;
    numClientes++;
}

bool Sucursal::eliminarCliente(string cedula) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->getCedula() == cedula) {
            for (int j = i; j < numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            numClientes--;
            return true;
        }
    }
    return false;
}

Cliente* Sucursal::buscarCliente(string cedula) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->getCedula() == cedula) {
            return clientes[i];
        }
    }
    return nullptr;
}

Cliente** Sucursal::obtenerClientes() const {
    return clientes;
}

void Sucursal::listarClientes() const {
    cout << "\n----- CLIENTES DE SUCURSAL " << codigo << " -----" << endl;
    for (int i = 0; i < numClientes; i++) {
        cout << i + 1 << ". ";
        clientes[i]->mostrarInfo();
        cout << "----------------------------------------------" << endl;
    }
}

// Clases Grupales
void Sucursal::agregarClaseGrupal(ClaseGrupal* claseG) {
    if (numClasesG >= capacidadClasesG) {
        cout << "n----- CUIDADO!!!No se pueden agregar más clases -----" << endl;
        return;
    }

    clasesGrupales[numClasesG] = claseG;
    numClasesG++;
    cout << "Clase grupal agregada exitosamente!" << endl;
}

bool Sucursal::eliminarClaseGrupal(string codigoClaseG) {
    for (int i = 0; i < numClasesG; i++) {
        if (clasesGrupales[i]->getCodigo() == codigoClaseG) {
            for (int j = i; j < numClasesG - 1; j++) {
                clasesGrupales[j] = clasesGrupales[j + 1];
            }
            numClasesG--;
            return true;
        }
    }
    return false;
}

ClaseGrupal* Sucursal::buscarClaseGrupal(string codigoClaseG) const{
    for (int i = 0; i < numClasesG; i++) {
        if (clasesGrupales[i]->getCodigo() == codigoClaseG) {
            return clasesGrupales[i];
        }
    }
    return nullptr;
}

ClaseGrupal** Sucursal::obtenerClaseGrupal() const {
    return clasesGrupales;
}

void Sucursal::listarClasesGrupales() const {
    cout << "\n----- CLASES GRUPALES DE LA SUCURSAL " << codigo << " -----" << endl;
    for (int i = 0; i < numClasesG; i++) {
        cout << i + 1 << ". ";
        clasesGrupales[i]->mostrarInfo();
        cout << "----------------------------------------------" << endl;
    }
}

// Resumen
void Sucursal::mostrarInfo() const {
    cout << "\n----- INFORMACIÓN DE SUCURSAL -----" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Cantón: " << canton << endl;
    cout << "Correo: " << correo << endl;
    cout << "Teléfono: " << telefono << endl;
}

void Sucursal::mostrarDatos() const {
    cout << "\n----- DATOS DE SUCURSAL -----" << endl;
    cout << "Sucursal " << codigo << ", " << canton << ", " << provincia << endl;
    cout << "Instructores: " << numInstructores << endl;
    cout << "Clientes: " << numClientes << endl;
    cout << "Clases grupales: " << numClasesG << "/8" << endl;
}