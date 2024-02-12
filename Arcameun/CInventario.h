#pragma once
#include"CHerramienta.h"
#include"CMaterial.h"
#include <fstream>
class CInventario
{
private:
    vector<CHerramienta> herramientas;
    vector<CMaterial> materiales;

public:
    void agregarHerramienta(const CHerramienta& herramienta) {
        herramientas.push_back(herramienta);
    }

    void agregarMaterial(const CMaterial& material) {
        materiales.push_back(material);
    }

    void verInventario() const {
        cout << "Herramientas:\n";
        for (const auto& h : herramientas) {
            cout << h.sNombre << h.iLvL << "\n";
        }

        cout << "Materiales:\n";
        for (const auto& m : materiales) {
            cout << m.sNombre << "\n";
        }
    }
    int venderMateriales() {
        int ganancia = 0;
        for (auto& material : materiales) {
            ganancia += material.iValor;
        }
        materiales.clear();
        return ganancia;
    }
    void guardar(const std::string& strFileName);

    void cargar(const std::string& strFileName);

    void fusionarHerramientas() {
        for (size_t i = 0; i < herramientas.size(); ++i) {
            for (size_t j = i + 1; j < herramientas.size();) {
                if (herramientas[i].sNombre == herramientas[j].sNombre) {
                    herramientas[i] = CHerramienta::fusionar(herramientas[i], herramientas[j]);
                    herramientas.erase(herramientas.begin() + j);
                }
                else {
                    ++j;
                }
            }
        }
    }
 
};

