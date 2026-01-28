#include "Imovel.h"

int Imovel::id = 1;

Imovel::Imovel(double precoP, double areaP, int andarP, const std::string& tipoP) : preco(precoP), area(areaP), andar(andarP), tipo(tipoP) {
	std::ostringstream oss;
	oss << tipo << "-" << id++;
	codigo = oss.str();
}

void Imovel::setPreco(double novoPreco) {
	if (novoPreco < 0) return;
	preco = novoPreco;
}

Imovel::~Imovel(){}