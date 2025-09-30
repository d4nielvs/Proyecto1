#include "Mediciones.h"
#include <iostream>
#include <cmath>

using namespace std;

Medicion::Medicion(Cliente* cli, Instructor* inst, string fec, double pe, double alt, double porGra, 
				   double porMus, double porGraVic, double cint, double cad, double pec, double mus, int edMeta):
				   cliente(cli), instructor(inst), fecha(fec), peso(pe), altura(alt), porcentajeGrasa(porGra), 
				   porcentajeMusculo(porMus), porcentajeGrasaViceral(porGraVic), cintura(cint), 
				   cadera(cad), pecho(pec), muslo(mus), edadMetabolismo(edMeta){ }

Medicion::~Medicion() {}
				   
double Medicion::calcularIMC() const {
	return peso / (altura * altura);
}

string Medicion::claseIMC() const {
	double imc = calcularIMC();

	if (imc < 16.00) return "Delgadez Severa";
	else if (imc >= 16.01 && imc <= 16.99) return "Delgadez Moderada";
	else if (imc >= 17.00 && imc <= 18.49) return "Delgadez Leve";
	else if (imc >= 18.50 && imc <= 24.99) return "Normal";
	else if (imc >= 25.00 && imc <= 29.99) return "Pre-obesidad";
	else if (imc >= 30.00 && imc <= 34.99) return "Obesidad leve";
	else if (imc >= 35.00 && imc <= 39.99) return "Obesidad media";
	else return "Obesidad mórbida";
}

bool Medicion::esAltoRiesgo() const {
	double imc = calcularIMC();
	return (imc >= 30.00);
}

double Medicion::calcularProteinaNecesaria() const {
	double proteinaBase = peso * 0.8;

	if (cliente != nullptr) {
		string sexo = cliente->getSexo();
		if (sexo == "Masculino" || sexo == "M") {
			return peso * 2.0;
		}else if (sexo == "Femenino" || sexo == "F") {
			return peso * 1.7;
		}
	}
	
	return proteinaBase;
}

int Medicion::calcularAgua() const {
	return peso / 7;
}

// Resumen
void Medicion::mostrarInfo() const {

	if (cliente != nullptr) {
		cout << "Cliente: " << cliente->getNombre() << endl;
	}
	if (instructor != nullptr) {
		cout << "Instructor: " << instructor->getNombre() << endl;
	}

	cout << "Fecha: " << fecha << endl;
	cout << "Peso: " << peso << " kg" << endl;
	cout << "Altura: " << altura << " m" << endl;
	cout << "IMC: " << calcularIMC() << " --- " << claseIMC() << endl;
}

void Medicion::reporte() const {

	cout << "\n-----REPORTE DE MEDICIONES DEL CLIENTE-----" << endl;
	
	cout << "Fecha: " << fecha << endl;

	if (cliente != nullptr) {
		cout << "Cliente: " << cliente->getNombre() << endl;
		cout << "Numero de cedula: " << cliente->getCedula() << endl;
	}
	if (instructor != nullptr) {
		cout << "Instructor: " << instructor->getNombre() << endl;
	}

	cout << "\n--- MEDICIONES ---" << endl;
	cout << "Peso: " << peso << " kg" << endl;
	cout << "Altura: " << altura << " m" << endl;
	cout << "Porcentaje de grasa: " << porcentajeGrasa << "%" << endl;
	cout << "Porcentaje de músculo: " << porcentajeMusculo << "%" << endl;
	cout << "Edad metabólica: " << edadMetabolismo << " años" << endl;
	cout << "Grasa visceral: " << porcentajeGrasaViceral << "%" << endl;

	cout << "\n--- MEDIDAS CORPORALES ---" << endl;
	cout << "Cintura: " << cintura << " cm" << endl;
	cout << "Cadera: " << cadera << " cm" << endl;
	cout << "Pecho: " << pecho << " cm" << endl;
	cout << "Muslo: " << muslo << " cm" << endl;
	
	cout << "\n--- Calculos ---" << endl;
	cout << "IMC: " << calcularIMC() << endl;
	cout << "Clasificación: " << claseIMC() << endl;
	cout << "Riesgo: " << (esAltoRiesgo() ? "ALTO RIESGO" : "Normal") << endl;

	cout << "\n--- Recomendaciones ---" << endl;
	cout << "Vasos de agua (250ml) al día: " << calcularAgua() << endl;
	cout << "Proteínas requeridas: " << calcularProteinaNecesaria() << " g/día" << endl;

	if (esAltoRiesgo()) {
		cout << "\n*** CUIDADO!!! Paciente de alto riesgo según Ministerio de Salud ***" << endl;
	}
	cout << "------------------------------------------------------------------------------------" << endl;
}