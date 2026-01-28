#include "Loja.h"

Loja::Loja(double areaP) : Imovel(15 * areaP, areaP>0 ? areaP : throw std::invalid_argument("Area Invalida"), 0, "Loja") {

}

std::string Loja::obtemDescricao() const {
	std::ostringstream oss;
	oss << "Area: " << getArea() << std::endl
		<< "Tipo: " << getTipo() << std::endl
		<< "Codigo: " << getCodigo() << std::endl
		<< "Andar: " << getAndar() << std::endl
		<< "Preco: " << getPreco() << std::endl;
	return oss.str();
}

void Loja::aumentarPreco() {
	double precoAtual = getPreco();
	double novoPreco = precoAtual * (1.01);
	setPreco(novoPreco);
}