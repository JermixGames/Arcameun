#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "CPersonaje.h"
#include "CInventario.h"
#include "CRoca.h"
#include <ctime>
#include <cstdlib>
using namespace std;

	int menu(CPersonaje& Player,CInventario& miInventario);
	int menu2(CPersonaje& Player,CInventario& miinventario);
	int minar(CPersonaje& Player,CInventario& miInventario);