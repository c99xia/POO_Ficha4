#pragma once
#include "Animal.h"
class Gato :
	public Animal
{
public:
	//Construtor
	Gato(const std::string& nomeP, const std::string& dataNascimentoP, double pesoP);

	//Virtual - Override - Polimorfismo
	std::string comer() override;
	std::string exercitar() override;
	std::string getDescricao() const override;
};

