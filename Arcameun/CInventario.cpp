#include "CInventario.h"
void CInventario::guardar(const std::string& strFileName) {
    std::ofstream archivo(strFileName);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para guardar la partida.\n";
        return;
    }

    // Guardar la cantidad de herramientas
    archivo << herramientas.size() << '\n';

    // Guardar cada herramienta individualmente
    for (const auto& herramienta : herramientas) {
        archivo << herramienta.sNombre << '\n';
        archivo << herramienta.iLvL << '\n';
        archivo << herramienta.iAtaque << '\n';
    }

    archivo << materiales.size() << '\n';


    for (const auto& materiales : materiales) {
        archivo << materiales.sNombre << '\n';
        archivo << materiales.iValor << '\n';
    }

    archivo.close();
}

void CInventario::cargar(const std::string& strFileName) {
    std::ifstream archivo(strFileName);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para cargar la partida.\n";
        return;
    }

    size_t tamano;
    archivo >> tamano;
    archivo.ignore(); // Ignora el salto de línea después de leer el tamaño

    herramientas.clear(); // Limpiar el vector actual
    for (size_t i = 0; i < tamano; ++i) {
        std::string sNombre;
        int iLvL;
        int iAtaque;

        getline(archivo, sNombre);
        archivo >> iLvL;
        archivo >> iAtaque;
        archivo.ignore(); // Ignora el salto de línea después de leer durabilidad

        herramientas.emplace_back(sNombre, iLvL,iAtaque);
    }

    size_t tamanoM;
    archivo >> tamanoM;
    archivo.ignore(); 

    materiales.clear(); 
    for (size_t i = 0; i < tamanoM; ++i) {
        std::string sNombre;
        int iValor;

        getline(archivo, sNombre);
        archivo >> iValor;
        archivo.ignore(); 

        materiales.emplace_back(sNombre, iValor);
    }

    archivo.close();
}
