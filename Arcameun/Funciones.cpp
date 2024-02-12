#include "Funciones.h"

int minar(CPersonaje& Player, CInventario& miInventario) {
	srand(time(0)); // Para generar números aleatorios


	CRoca piedra;
	char opcion;

	while (piedra.estaViva()) {
		HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");
		SetConsoleTextAttribute(Hconsole, 15);
		cout << "MINERO " << Player.sNombre << endl;
		cout << "Estamina " << Player.fVida << endl;
		cout << "¿Deseas golpear la piedra? (s/n): ";
		cin >> opcion;

		if (opcion == 'n' || opcion == 'N') {
			break;
		}

		int golpe = Player.hit();
		piedra.recibirGolpe(golpe);
		if (golpe == 0|| Player.fVida <= 0) {
			cout << "El fallas al darle a la piedra, que feo.\n";
			Player.fVida -= 5;
			system("pause");
		}
		else {
			piedra.vida = piedra.vida - Player.iAtaque;
			cout << "le metes un buen golpe a la Piedra. Vida restante de la piedra: " << piedra.vida << "\n";
			cout << "Consigues 1 de Oro" << "\n";
			miInventario.agregarMaterial(CMaterial("Oro",100));
			Player.fVida -= 5;
			system("pause");

		}
	}

	if (piedra.estaViva()) {
		std::cout << "Has salido del combate.\n";
		system("pause");

	}
	else {
		std::cout << "La piedra ha sido destruida.\n";
		miInventario.agregarMaterial(CMaterial("Diamante", 1000));
		system("pause");

	}
	Player.fVida = 100;

	return 0;
}

int menu(CPersonaje& Player,CInventario& miInventario)
{
	//para cambiar el color del texto 
	HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);


	string strMenu[3]{ "Nuevo Juego", "Cargar Juego","Salir" };
	
	bool bSalir = false;
	//lo que revisa el while 
	int iRow = 0;
	char cOption = '?';

	while (!bSalir)
	{
		//mientras no se presione ENTER que es "13" el while sigue
		while (cOption != 13)
		{
			system("cls");
			SetConsoleTextAttribute(Hconsole, 7);
			cout << "Escoja su opcion con las teclas W y S, y luego presione ENTER." << endl;
			for (int i = 0; i < 3; i++)
			{
				if (i == iRow)
				{
					SetConsoleTextAttribute(Hconsole, 11);
					cout << "->";
				}
				else 
					SetConsoleTextAttribute(Hconsole, 7);
				cout << " ";
				cout << strMenu[i] << endl;
			}
			//funcion que recive el valor del input
			cOption = _getch();

			switch (cOption)
			{
			case 's':
			case 'S':
				iRow++;
				if (iRow > 2)
					iRow = 0;
				break;
			case 'w':
			case 'W':
				iRow--;
				if (iRow < 0)
					iRow = 2;
				break;
			}
		}
		//ya se toco enter e iRow es la opcion del menu seleccionada
		switch (iRow)
		{
		case 0:
			cout << "Hola minero, cual es tu nombre? \n";
			cin >> Player.sNombre;
			menu2(Player, miInventario);
			bSalir = true;
			break;
		case 1:
			Player.cargar("Personaje");
			miInventario.cargar("inventario");
			if (Player.sNombre != ".") 
			{
				menu2(Player, miInventario);
				bSalir = true;
			}
			else 
			{
				system("pause");
				cOption = '?';
			}
			break;
		case 2: 
			SetConsoleTextAttribute(Hconsole, 7);
			cout << "adios!" << endl;
			bSalir = true;
			break;
		default: 
			SetConsoleTextAttribute(Hconsole, 4);
			cout << "glitch";
		}
	}
	return 0;

}

int menu2(CPersonaje& Player,CInventario& miInventario)
{
	HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string strMenu[6]{ "Guardar", "Inventario","Minar recursos","tienda","fusion de objetos","Salir"};
	bool bSalir = false;
	int iRow = 0;
	char cOption = '?';

	while (!bSalir)
	{
		while (cOption != 13)
		{
			system("cls");
			SetConsoleTextAttribute(Hconsole, 15);
			cout << "HOLAA "<< Player.sNombre << endl;
			cout << "Estamina " << Player.fVida << endl;
			cout << "ATAQUE " << Player.iAtaque << endl;
			cout << "DINERO " << Player.iDinero << endl;
			SetConsoleTextAttribute(Hconsole, 7);
			cout << "Escoja su opcion con las teclas W y S, y luego presione ENTER." << endl;
			for (int i = 0; i < 6; i++)
			{
				if (i == iRow)
				{
					SetConsoleTextAttribute(Hconsole, 11);
					cout << "->";
				}
				else
					SetConsoleTextAttribute(Hconsole, 7);
				cout << " ";
				cout << strMenu[i] << endl;
			}

			cOption = _getch();

			switch (cOption)
			{
			case 's':
			case 'S':
				iRow++;
				if (iRow > 5)
					iRow = 0;
				break;
			case 'w':
			case 'W':
				iRow--;
				if (iRow < 0)
					iRow = 5;
				break;
			}
		}
		switch (iRow)
		{
		case 0:
			Player.guardar("Personaje");
			miInventario.guardar("inventario");
			//guardar(Player);
			SetConsoleTextAttribute(Hconsole, 2);
			cout << "JUEGO GUARDADO" << endl;
			SetConsoleTextAttribute(Hconsole, 7);
			system("pause");
			cOption = '?';
			break;
		case 1:
			miInventario.verInventario();
			system("pause");
			cOption = '?';
			
			break;
		case 2:
			minar(Player, miInventario);
			system("pause");
			cOption = '?';
			break;
		case 3:
			//tienda
			cout << "Bienvenido a la tienda" << endl;
			cout << "1. Vender todos los materiales" << endl;
			cout << "2. Comprar un pico (Costo: 100 de oro)" << endl;
			cout << "Selecciona una opción: ";

			int opcion;
			cin >> opcion;

			if (opcion == 1) {
				int ganancia = miInventario.venderMateriales();
				cout << "Has vendido todos los materiales por " << ganancia << " de Dinero." << endl;
				Player.iDinero += ganancia;
			}
			else if (opcion == 2) {
				if (Player.iDinero >= 100) {
					miInventario.agregarHerramienta(CHerramienta("Pico", 1, 10));
					Player.iDinero -= 100;
					cout << "Has comprado un pico." << endl;
				}
				else {
					cout << "No tienes suficiente oro para comprar un pico." << endl;
				}
			}
			system("pause");
			cOption = '?';
			break;
		case 4:
			miInventario.fusionarHerramientas();
			cout << "todos tu picos se fusionaron yeii" << endl;
			system("pause");
			cOption = '?';
			break;
		case 5:
			SetConsoleTextAttribute(Hconsole, 7);
			cout << "adios!" << endl;
			bSalir = true;
			break;

		default:
			SetConsoleTextAttribute(Hconsole, 4);
			cout << "glitch";
		}
	}
	return 0;
}
