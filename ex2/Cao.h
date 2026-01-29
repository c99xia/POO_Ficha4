#pragma once
#include "Animal.h"
class Cao :
    public Animal
{
public:
    //Construtor
    Cao(const std::string& nomeP, const std::string& dataNascimentoP, double pesoP);

    //Virtual - Override - Polimorfismo
    std::string comer() override;
    std::string getDescricao() const override;
    std::string exercitar() override;
};

