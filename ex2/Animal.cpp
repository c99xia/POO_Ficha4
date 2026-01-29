#include "Animal.h"

int Animal::id = 1000;
Animal::Animal(const std::string& nomeP, const std::string& dataNascimentoP, const std::string& especieP, double pesoP) :
	nome(nomeP), dataNascimento(dataNascimentoP), especie(especieP), peso(pesoP>0 ? pesoP : throw std::invalid_argument("Peso negativo?")) {
	std::ostringstream oss;
	oss << especie << "-" << id++;
	codigo = oss.str();
}

void Animal::setPeso(double novoPeso) {
	if (novoPeso <= 0) {
		return;
	}
	peso = novoPeso;
}

Animal::~Animal(){}