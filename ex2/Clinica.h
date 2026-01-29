#pragma once
#include "Animal.h"
class Clinica
{
	const static int TAM = 200;

	//Guarda o endereço de cada Animal - Array de Ponteiros para o tipo Animal
	//Se fosse um array de objetos do tipo Animal - fazia Object Slicing
	Animal* animais[TAM];

	//Número de Animais - para efeitos de tracking, em vez de percorrer até TAM, percorremos apenas até ao numAnimais
	int numAnimais;

public:
	//Construtor Sem Parâmetros - Porque a Clinica apenas Regista os Animais, não cria Animais
	Clinica();

	//Parâmetro Animal* a pois ele recebe um endereço do Animal, para colocar no Array de Ponteiros do tipo Animal, basicamente tem que ser do mesmo tipo
	bool registaAnimal(Animal* a);
	bool removeAnimal(const std::string& codigo);

	//Como Animal *animais[TAM] é um array de ponteiros (Animal*), a função retorna o que está no array: <- animais[i] é do tipo Animal* então retornamos Animal*
	const Animal* leitura(const std::string& codigo) const;
	std::string descricaoAnimal(const std::string& codigo)const;
	std::string listaCompleta() const;
	void alimentar();
	void exercitar();
};

