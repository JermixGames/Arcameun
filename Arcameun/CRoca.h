#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class CRoca
{
public:
    int vida = 10000;
    void recibirGolpe(int golpe) {
        vida -= golpe;
    }
    bool estaViva() {
        return vida > 0;
    }

};

