#include "Clinica.h"

Clinica::Clinica() : numAnimais(0) {
	for (int i = 0; i < TAM; i++) {
		animais[i] = nullptr;
	}
}

bool Clinica::registaAnimal(Animal* a) {
	if (numAnimais == TAM) return false;
	if (a == nullptr) return false;
	for (int i = 0; i < numAnimais; i++) {
		if (animais[i]->getCodigo() == a->getCodigo()) {
			return false;
		}
	}
	animais[numAnimais] = a;
	numAnimais++;
	return true;
}

bool Clinica::removeAnimal(const std::string& codigo) {
	if (numAnimais == 0) return false;
	for (int i = 0; i < numAnimais; i++) {
		if (animais[i]->getCodigo() == codigo) {
			animais[i] = animais[numAnimais - 1];
			numAnimais--;
			return true;
		}
	}
	return false;
}

const Animal* Clinica::leitura(const std::string& codigo)const {
	for (int i = 0; i < numAnimais; i++) {
		if (animais[i]->getCodigo() == codigo) {
			return animais[i];
		}
	}
	return nullptr;
}

std::string Clinica::descricaoAnimal(const std::string& codigo) const {
	const Animal* animal = leitura(codigo);
	std::ostringstream oss;
	oss << animal->getDescricao() << std::endl;
	return oss.str();
}

std::string Clinica::listaCompleta() const {
	std::ostringstream oss;
	for (int i = 0; i < numAnimais; i++) {
		oss << animais[i]->getDescricao() << std::endl;
	}
	return oss.str();
}

void Clinica::alimentar() {
	for (int i = 0; i < numAnimais; i++) {
		animais[i]->comer();
	}
}

void Clinica::exercitar() {
	for (int i = 0; i < numAnimais; i++) {
		animais[i]->exercitar();
	}
}
