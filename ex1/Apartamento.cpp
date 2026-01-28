#include "Apartamento.h"
Apartamento::Apartamento(double areaP, int andarP, int numAssoalhadasP) : 
	Imovel(10 * areaP, 
		areaP >0 ? areaP : throw std::invalid_argument("Area Invalida"), 
		andarP>=0 ? andarP : throw std::invalid_argument("Andar Invalido"), 
		"Apartamento"), numAssoalhadas(numAssoalhadasP>0 ? numAssoalhadasP : throw std::invalid_argument("Numero de Assoalhadas invalido")) {

}

std::string Apartamento::obtemDescricao() const {
	std::ostringstream oss;
	oss << "Area: " << getArea() << std::endl
		<< "Tipo: " << getTipo() << std::endl
		<< "Codigo: " << getCodigo() << std::endl
		<< "Andar: " << getAndar() << std::endl
		<< "Preco: " << getPreco() << std::endl
		<< "Numero de Assoalhadas: " << getNumAssoalhadas() << std::endl;
	return oss.str();
}

void Apartamento::aumentarPreco() {
	double precoAtual = getPreco();
	int numAssoalhada = getNumAssoalhadas();
	double novoPreco = precoAtual * (1 + numAssoalhada / 100.0);
	setPreco(novoPreco);
}
