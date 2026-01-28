#pragma once
#include "Imovel.h"
class Apartamento :
    public Imovel
{
    int numAssoalhadas;
public:
    //Override - Polimorfismo - Virtual
    std::string obtemDescricao() const override;
    void aumentarPreco() override;

    //Getter
    int getNumAssoalhadas() const { return numAssoalhadas; }

    //Construtor
    Apartamento(double areaP, int andarP, int numAssoalhadasP);
};

