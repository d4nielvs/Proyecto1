#include "Cliente.h"

Cliente::Cliente(string ced, string nom, string tel, string cor,
    string fechaNac, string sex, string fechaInsc, Instructor* instr): numCedula(ced), nombreCompleto(nom), telefono(tel), correo(cor), 
    fechaNacimiento(fechaNac), sexo(sex), fechaInscripcion(fechaInsc), instructorAsignado(instr) { }

void Cliente::asignarInstructor(Instructor* instr) {
    instructorAsignado = instr;
}

void Cliente::mostrarInfo() const {
    cout << "\n-----INFORMACION DEL CLIENTE-----" << endl;
    cout << "numero de cedula: " << numCedula << endl;
    cout << "Nombre completo: " << nombreCompleto << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo electronico: " << correo << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Fecha de inscripcion: " << fechaInscripcion << endl;
    if (instructorAsignado) {
        cout << "El instructor asignado es: " << instructorAsignado->getNombre() << endl;
        
    }
    else {
        cout << "Instructor asignado: Ninguno" << endl;
    }
}

string Cliente::getCedula() const { return numCedula; }
string Cliente::getNombre() const { return nombreCompleto; }
string Cliente::getTelefono() const { return telefono; }
string Cliente::getCorreo() const { return correo; }
string Cliente::getFechaNacimiento() const { return fechaNacimiento; }
string Cliente::getSexo() const { return sexo; }
string Cliente::getFechaInscripcion() const { return fechaInscripcion; }
Instructor* Cliente::getInstructor() const { return instructorAsignado; }