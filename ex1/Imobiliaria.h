#pragma once
#include "Imovel.h"
class Imobiliaria
{
	/*
	 * IMPORTANTE: Array de PONTEIROS (Imovel* imoveis[TAM]), não de objetos (Imovel imoveis[TAM])
	 *
	 * POR QUE USAR PONTEIROS?
	 * ========================
	 * 1. OBJECT SLICING (problema com array de objetos):
	 *    - Se usássemos Imovel imoveis[TAM], cada posição teria tamanho fixo sizeof(Imovel)
	 *    - Apartamento tem mais dados (numAssoalhadas) e ocupa sizeof(Apartamento) > sizeof(Imovel)
	 *    - Ao copiar um Apartamento para imoveis[i], os dados extra seriam CORTADOS/PERDIDOS
	 *    - Exemplo: numAssoalhadas desapareceria! (object slicing)
	 *
	 * 2. POLIMORFISMO NÃO FUNCIONA SEM PONTEIROS:
	 *    - Funções virtuais (obtemDescricao, aumentarPreco) só funcionam via ponteiros/referências
	 *    - Com objetos diretos, sempre chamaria Imovel::obtemDescricao(), mesmo sendo Apartamento
	 *
	 * COMO OS PONTEIROS RESOLVEM O PROBLEMA?
	 * =======================================
	 * - Todos os ponteiros têm o mesmo tamanho (8 bytes em 64-bits), independentemente do tipo
	 * - O ponteiro Imovel* pode APONTAR para qualquer objeto derivado (Apartamento, Loja)
	 * - O objeto COMPLETO (com todos os seus dados) fica na sua localização original (stack/heap)
	 * - imoveis[i] guarda apenas o ENDEREÇO do objeto → não há cópia → não há perda de dados
	 *
	 * Exemplo:
	 *   Apartamento ap(50, 2, 3);     // objeto na stack (endereço 0x1000)
	 *   imoveis[0] = &ap;             // guarda 0x1000 (8 bytes)
	 *   imoveis[0]->obtemDescricao(); // vai a 0x1000, encontra Apartamento COMPLETO
	 *                                 // chama Apartamento::obtemDescricao() (polimorfismo!)
	 */

	const static int TAM = 100;
	Imovel* imoveis[TAM];
	int quantidade;

public:
	//Métodos
	/*
	 * IMPORTANTE: Usa Imovel* a (ponteiro), NÃO Imovel a (objeto)
	 *
	 * Razão: Se usássemos (Imovel a), ao passar um Apartamento:
	 *   - Criaria uma CÓPIA apenas da parte Imovel (object slicing)
	 *   - Perderia numAssoalhadas e todos os dados específicos de Apartamento
	 *   - Não conseguiríamos guardar o objeto completo no array
	 *
	 * Com (Imovel* a):
	 *   - Recebe o ENDEREÇO do objeto real (Apartamento ou Loja)
	 *   - Objeto completo fica preservado na sua localização original
	 *   - Guardamos apenas o ponteiro (8 bytes) no array imoveis[]
	 */
	bool adicionarImovel(Imovel* a);
	std::string listarPorAndar(int andar) const;
	const Imovel* leitura(const std::string& codigo) const; //Como Imovel *imoveis[TAM] é um array de ponteiros (Imovel*), a função retorna o que está no array: <- imoveis[i] é do tipo Imovel* então retornamos Imovel*
	std::string obterDescricao(const std::string& codigo) const;
	bool removerImovel(const std::string& codigo);
	void aumentarPrecos();
	std::string listarTodos() const;

	Imobiliaria();
	/*
	 * CONSTRUTOR SEM PARÂMETROS - POR QUÊ?
	 * =====================================
	 *
	 * CONCEITO: OWNERSHIP (PROPRIEDADE DE OBJETOS)
	 *
	 * Neste exercício, a Imobiliária NÃO É DONA dos imóveis que gere.
	 * Os imóveis têm existência própria, independente da imobiliária.
	 *
	 * ANALOGIA DO MUNDO REAL:
	 * - Uma agência imobiliária ANUNCIA casas, mas não as CONSTRÓI nem POSSUI
	 * - As casas já existem (pertencem aos proprietários)
	 * - Se a agência fechar, as casas continuam a existir
	 * - A agência apenas REGISTA/LISTA casas para venda
	 *
	 * IMPLICAÇÕES NO CÓDIGO:
	 * ----------------------
	 * 1. Os objetos Apartamento/Loja são criados FORA da Imobiliaria (normalmente na main)
	 * 2. A Imobiliaria recebe PONTEIROS para esses objetos (via adicionarImovel)
	 * 3. O construtor apenas INICIALIZA a estrutura vazia (array de ponteiros)
	 * 4. NÃO cria objetos → NÃO precisa de parâmetros para os construir
	 *
	 * EXEMPLO DE USO:
	 *   Apartamento ap1(50, 2, 3);  // Criado na main (dono: main)
	 *   Loja loja1(100);            // Criado na main (dono: main)
	 *
	 *   Imobiliaria imob;           // Construtor SEM parâmetros (array vazio)
	 *   imob.adicionarImovel(&ap1); // Regista imóvel existente (guarda endereço)
	 *   imob.adicionarImovel(&loja1);
	 *
	 *   imob.removerImovel("Apartamento-1"); // Remove REGISTO (ap1 continua a existir!)
	 *   cout << ap1.getPreco();              // ap1 ainda está vivo e acessível
	 *
	 *
	 * E SE O CONSTRUTOR TIVESSE PARÂMETROS? (CENÁRIO ALTERNATIVO - NÃO É O CASO!)
	 * ===========================================================================
	 *
	 * Se a Imobiliária FOSSE DONA dos imóveis, o design seria completamente diferente:
	 *
	 * CONSTRUTOR (criaria os imóveis):
	 *   Imobiliaria(int numApartamentos, int numLojas) {
	 *       for (int i = 0; i < numApartamentos; i++) {
	 *           imoveis[quantidade++] = new Apartamento(50, i, 3); // ← usa NEW
	 *       }
	 *       for (int i = 0; i < numLojas; i++) {
	 *           imoveis[quantidade++] = new Loja(100); // ← usa NEW
	 *       }
	 *   }
	 *
	 * DESTRUTOR (destruiria os imóveis):
	 *   ~Imobiliaria() {
	 *       for (int i = 0; i < quantidade; i++) {
	 *           delete imoveis[i]; // ← OBRIGATÓRIO fazer DELETE!
	 *       }
	 *   }
	 *
	 * REMOVER (destruiria o objeto):
	 *   bool removerImovel(const string& codigo) {
	 *       // ... encontra posição i ...
	 *       delete imoveis[i];  // ← DESTRÓI o objeto
	 *       // ... remove do array ...
	 *   }
	 *
	 * PROBLEMAS DESTE CENÁRIO:
	 * - Imóveis deixam de existir se a Imobiliaria for destruída (não faz sentido!)
	 * - Não se pode aceder aos objetos diretamente (estão "presos" dentro da Imobiliaria)
	 * - Violaria o princípio do enunciado (imóveis têm existência própria)
	 *
	 *
	 * CONCLUSÃO:
	 * ==========
	 * ✅ SEM parâmetros: Imobiliaria é apenas um REGISTO/CATÁLOGO de imóveis
	 * ❌ COM parâmetros: Imobiliaria seria FÁBRICA/DONA dos imóveis (ownership)
	 *
	 * Neste exercício, a primeira abordagem é a correta!
	 */
};

