#include "Gato.h"

Gato::Gato(const std::string& nomeP, const std::string& dataNascimentoP, double pesoP) : Animal(nomeP, dataNascimentoP, "Gato", pesoP) {}

std::string Gato::comer() {
	std::ostringstream oss;
	oss << "o que, este pate reles novamente?" << std::endl;
	return oss.str();
}

std::string Gato::getDescricao() const {
	std::ostringstream oss;
	oss << "Nome: " << getNome() << std::endl
		<< "Data Nascimento: " << getDataNascimento() << std::endl
		<< "Codigo: " << getCodigo() << std::endl
		<< "Especie: " << getEspecie() << std::endl
		<< "Peso: " << getPeso() << std::endl;
	return oss.str();
}

std::string Gato::exercitar() {
	std::ostringstream oss;
	double pesoAtual = getPeso();
	double novoPeso = pesoAtual * 0.9;

	// Só emagrece se não ficar abaixo de 2.5kg
	if (novoPeso >= 2.5) {
		setPeso(novoPeso);
	}
	// Se ficar abaixo, fica em 2.5kg 
	else {
		setPeso(2.5);
	}
	oss << "Derrubei N jarras e arranhei M pessoas" << std::endl;
	return oss.str();
}