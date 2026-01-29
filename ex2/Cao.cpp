#include "Cao.h"

Cao::Cao(const std::string& nomeP, const std::string& dataNascimentoP, double pesoP) : Animal(nomeP, dataNascimentoP, "Cao", pesoP) {}

std::string Cao::comer() {
    std::ostringstream oss;
    double pesoAtual = getPeso();

    double novoPeso = pesoAtual * 1.05;

    // Só engorda se tiver menos de 20kg
    if (novoPeso <= 20) {
        setPeso(novoPeso);
    }

    // Se ficar acima, fica em 20kg 
    else {
        setPeso(20);
    }

    oss << "biscoitos bons. obrigado";
    return oss.str();
}

std::string Cao::getDescricao() const {
	std::ostringstream oss;
	oss << "Nome: " << getNome() << std::endl
		<< "Data Nascimento: " << getDataNascimento() << std::endl
		<< "Codigo: " << getCodigo() << std::endl
		<< "Especie: " << getEspecie() << std::endl
		<< "Peso: " << getPeso() << std::endl;
	return oss.str();
}

std::string Cao::exercitar() {
	std::ostringstream oss;
	oss << "Corri X quilometros" << std::endl;
	return oss.str();
}
