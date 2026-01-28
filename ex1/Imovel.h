#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

class Imovel
{
	std::string tipo, codigo;
	static int id;
	int andar;
	double preco, area;

public:
	//Getters
	std::string getTipo() const { return tipo; }
	std::string getCodigo() const { return codigo; }
	int getAndar() const { return andar; }
	double getPreco() const { return preco; }
	double getArea() const { return area; }

	//Setter
	void setPreco(double novoPreco);

	//Construtor
	Imovel(double precoP, double areaP, int andarP, const std::string& tipoP);

	//Destrutor
	virtual~Imovel();

	//Virtuais/Polimorfismo
	virtual std::string obtemDescricao() const;
	virtual void aumentarPreco();
};



