#include "CPersonaje.h"

CPersonaje::CPersonaje() {

	
	sNombre = "Nada";
    fVida = 100;
    iAtaque = 100;
    iDinero = 0;
}
//funcion de guardado
void CPersonaje::guardar(const std::string& strFileName) {
    std::ofstream archivo(strFileName);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para guardar la partida.\n";
        return;
    }
    archivo << sNombre << '\n';
    archivo << fVida << '\n';
    archivo << iAtaque << '\n';
    archivo << iDinero << '\n';

}

void CPersonaje::cargar(const std::string& strFileName) {
    std::ifstream archivo(strFileName);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para cargar la partida.\n";
        return;
    }
    archivo >> sNombre;
    archivo >> fVida;
    archivo >> iAtaque;
    archivo >> iDinero;
}
int CPersonaje::hit() {
    // Genera un número aleatorio entre 0 y 1
    int golpe = rand() % 2;
    return golpe;
}
