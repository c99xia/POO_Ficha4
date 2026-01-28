#include "Escritorio.h"
Escritorio::Escritorio(double areaP, int andarP) :
	Imovel(10 * areaP,
		areaP > 0 ? areaP : throw std::invalid_argument("Area Invalida"),
		andarP >= 0 ? andarP : throw std::invalid_argument("Andar Invalido"),
		"Escritorio"), numAssoalhadas(2) {

}

std::string Escritorio::obtemDescricao() const {
	std::ostringstream oss;
	oss << "Area: " << getArea() << std::endl
		<< "Tipo: " << getTipo() << std::endl
		<< "Codigo: " << getCodigo() << std::endl
		<< "Andar: " << getAndar() << std::endl
		<< "Preco: " << getPreco() << std::endl
		<< "Numero de Assoalhadas: " << getNumAssoalhadas() << std::endl;
	return oss.str();
}

void Escritorio::aumentarPreco() {
	double precoAtual = getPreco();
	double novoPreco = precoAtual * (1.02);
	setPreco(novoPreco);
}
