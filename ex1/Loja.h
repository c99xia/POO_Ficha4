#pragma once
#include "Imovel.h"
class Loja :
    public Imovel
{
public:
    //Override - Polimorfismo - Virtual
    std::string obtemDescricao() const override;
    void aumentarPreco() override;

    //Construtor
    Loja(double areaP);
};

