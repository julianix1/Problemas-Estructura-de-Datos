#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Hora {
public:
	Hora(int segundos, int minutos, int horas) :_segundos(segundos + (minutos + (horas * 60)) * 60) {

		if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59)
			throw std::invalid_argument(" Hora invalida ");
	}

	Hora operator +(const Hora& h1) const
	{
		try
		{
			return Hora(h1._segundos + _segundos);
		}
		catch (const std::invalid_argument&)
		{
			throw std::overflow_error("hoy no");
		}
	}

	bool operator ==(const Hora& f1) const {
		return f1._segundos == _segundos;
	}

	bool operator <(Hora f1) const {
		return _segundos < f1._segundos;
	};

	int getSegundos() const { return _segundos % 60; }
	int getMinutos()  const { return (_segundos / 60) % 60; }
	int getHoras()    const { return (_segundos / 60) / 60; }

private:
	int _segundos;

	Hora(int segundos) :_segundos(segundos) {
		if (this->getHoras() > 23) throw std::invalid_argument(" Hora invalida ");
	}
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