#include "Imobiliaria.h"

Imobiliaria::Imobiliaria() : quantidade(0) {
	for (int i = 0; i < TAM; i++) {
		imoveis[i] = nullptr;
	}
}

bool Imobiliaria::adicionarImovel(Imovel* a) {
	if (quantidade >= TAM || a == nullptr) {
		return false;
	}
	for (int i = 0; i < quantidade; i++) {
		if (a->getCodigo() == imoveis[i]->getCodigo()) {
			return false;
		}
	}
	imoveis[quantidade] = a;
	quantidade++;
	return true;
}

std::string Imobiliaria::listarPorAndar(int andar) const {
	std::ostringstream oss;
	for (int i = 0; i < quantidade; i++) {
		if (imoveis[i]->getAndar() == andar) {
			oss << imoveis[i]->obtemDescricao() << std::endl;
		}
	}
	return oss.str();
}

const Imovel* Imobiliaria::leitura(const std::string& codigo) const {
	for (int i = 0; i < quantidade; i++) {
		if (imoveis[i]->getCodigo() == codigo) {
			return imoveis[i];
		}
	}
	return nullptr;
}

std::string Imobiliaria::obterDescricao(const std::string& codigo) const {
	const Imovel* imovel = leitura(codigo);

	// Verificar se existe
	if (imovel != nullptr) {
		return imovel->obtemDescricao();
	}

	return "Imovel nao encontrado"; 
}

bool Imobiliaria::removerImovel(const std::string& codigo) {
	for (int i = 0; i < quantidade; i++) {
		if (imoveis[i]->getCodigo() == codigo) {
			imoveis[i] = imoveis[quantidade - 1];
			quantidade--;
			return true;
		}
	}
	return false;
}

void Imobiliaria::aumentarPrecos() {
	for (int i = 0; i < quantidade; i++) {
		imoveis[i]->aumentarPreco();
	}
}

std::string Imobiliaria::listarTodos() const {
	std::ostringstream oss;
	for (int i = 0; i < quantidade; i++) {
		oss << imoveis[i]->obtemDescricao() << std::endl;
	}
	return oss.str();
}