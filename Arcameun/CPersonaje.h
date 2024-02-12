#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
	using namespace std;


class CPersonaje
{
public:
	string sNombre;
	float fVida;
	int iAtaque;
	int iDinero;

	CPersonaje();

	void guardar(const std::string& strFileName);

	void cargar(const std::string& strFileName);

	int hit();
};