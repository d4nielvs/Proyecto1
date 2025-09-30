#pragma once

#include <iostream>

class Ejercicio {

private:

	string nombre;
	string descripcion;
	string area;
	string maquinas;
	int serie;
	int repeticiones;

public:

	Ejercicio(string nom, string des, string are, string maqui, int ser, int rep);

	~Ejercicio();

	bool areaValida(string area) const;

	void mostrarInfoBasica()   const;
	void mostrarInfoCompleta() const;
	void resumen()			   const;

	string getNombre()		const;
	string getDescripcion() const;
	string getArea()		const;
	string getMaquinas()	const;
	int getSeries()			const;
	int getRepeticiones()	const;
};