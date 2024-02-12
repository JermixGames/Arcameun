#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class CHerramienta
{
public:
	
	string sNombre;
	int iLvL;
	int iAtaque;
	
	CHerramienta(string _sNombre, int _iLvL, int _iAtaque) : sNombre(_sNombre), iLvL(_iLvL), iAtaque(_iAtaque) {}

	bool operator==(const CHerramienta& otra) const {
		return sNombre == otra.sNombre;
	}

	CHerramienta& operator+=(const CHerramienta& otra) {
		if (*this == otra) {
			this->iLvL += otra.iLvL;
		}
		return *this;
	}
	static CHerramienta fusionar(const CHerramienta& h1, const CHerramienta& h2) {
		if (h1 == h2) {
			// Crear una nueva herramienta con nivel incrementado
			return CHerramienta(h1.sNombre, h1.iLvL + h2.iLvL,h2.iAtaque + h2.iAtaque);
		}
		// Devuelve la primera herramienta si no son iguales
		return h1;
	}
};

