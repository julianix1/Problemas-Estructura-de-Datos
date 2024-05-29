#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Hora {
public:
	Hora(int segundos, int minutos, int horas) :_segundos(segundos + (minutos + (horas * 60)) * 60) {

		if (horas < 0 || horas > 24 || minutos < 0 || minutos > 60 || segundos < 0 || segundos > 60)
			throw std::invalid_argument(" Hora invalida ");

	}

	bool operator ==(const Hora& f1) {
		return f1._segundos == _segundos;
	}

	bool operator <(Hora f1) {
		return _segundos < f1._segundos;
	};

	int getSegundos() const { return _segundos % 60; }
	int getMinutos()  const { return (_segundos / 60) % 60; }
	int getHoras()    const { return (_segundos / 60) / 60; }

private:
	int _segundos;
};

inline ostream& operator << (ostream& salida, const Hora& f)
{
	salida << setw(2) << setfill('0') << f.getHoras() << ":"
		<< setw(2) << setfill('0') << f.getMinutos() << ":"
		<< setw(2) << setfill('0') << f.getSegundos();

	return salida;
}

inline istream& operator >> (istream& entrada, Hora& f)
{
	int segundos, minutos, horas;
	char basura;

	entrada >> horas >> basura >> minutos >> basura >> segundos;

	f = Hora(segundos, minutos, horas);

	return entrada;
}