#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Animal
{
	std::string nome, dataNascimento, codigo, especie;
	double peso;
	static int id;

public:
	//Construtor
	Animal(const std::string& nomeP, const std::string& dataNascimentoP, const std::string& especieP, double pesoP);

	//Getters
	std::string getNome() const { return nome; }
	std::string getDataNascimento() const { return dataNascimento; }
	std::string getCodigo() const { return codigo; }
	std::string getEspecie() const { return especie; }
	double getPeso() const { return peso; }
	
	//Setter
	void setPeso(double novoPeso);

	//Destrutor
	virtual~Animal();

	//Virtual - Polimorfismo 
	virtual std::string comer();
	virtual std::string exercitar();
	virtual std::string getDescricao() const;

};

