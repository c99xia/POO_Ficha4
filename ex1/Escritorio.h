#pragma once
#include "Imovel.h"
class Escritorio :
    public Imovel
{
    int numAssoalhadas;
public:
    //Override - Polimorfismo - Virtual
    std::string obtemDescricao() const override;
    void aumentarPreco() override;

    //Getter
    int getNumAssoalhadas() const { return numAssoalhadas; }

    //Construtor
    Escritorio(double areaP, int andarP); 

    /*
     * CONSTRUTOR - Por que APENAS 2 parâmetros (área e andar)?
     * =========================================================
     *
     * RAZÃO: numAssoalhadas é SEMPRE 2 (fixo/hardcoded)
     *
     * O enunciado especifica: "tem sempre tipologia 2"
     * Isto significa que numAssoalhadas NÃO é uma característica variável do Escritório,
     * mas sim uma CONSTANTE da classe.
     *
     * POR QUE NÃO TER numAssoalhadasP COMO PARÂMETRO?
     * ------------------------------------------------
     * Se tivéssemos 3 parâmetros: Escritorio(double areaP, int andarP, int numAssoalhadasP)
     *
     * PROBLEMA 1 - Valor seria IGNORADO:
     *   Escritorio esc(60, 3, 5);  // Programador passa 5 assoalhadas
     *   // Na inicialização: numAssoalhadas(2)  ← IGNORA o 5, usa sempre 2!
     *   // Resultado: esc.getNumAssoalhadas() == 2 (não 5!)
     *   // CONFUSO! O programador passou 5 mas o objeto tem 2.
     * 
     * PROBLEMA 2 - Interface ENGANADORA:
     *   - Ter o parâmetro sugere que é configurável (mas não é!)
     *   - Violaria o princípio do "menor espanto" (principle of least surprise)
     *   - O construtor estaria a "mentir" sobre o que aceita
     * 
     * PROBLEMA 3 - Validação IMPOSSÍVEL:
     *   if (numAssoalhadasP != 2) {  erro? warning? }
     *   // Como reagir se o programador passar valor diferente de 2?
     *   // Lançar exceção? (agressivo)
     *   // Ignorar silenciosamente? (confuso)
     *
     * SOLUÇÃO CORRETA - SEM o parâmetro:
     * -----------------------------------
     * ✅ Assinatura clara: Escritorio(double areaP, int andarP)
     * ✅ Impossível passar valor errado (não existe o parâmetro!)

     * ✅ Self-documenting: a ausência do parâmetro indica que é fixo
     * ✅ Menos código, menos bugs
     *
     * COMPARAÇÃO COM OUTRAS CLASSES:
     * -------------------------------
     * Apartamento(area, andar, numAssoalhadas) ← variável (1, 2, 3, 4...)
     * Escritorio(area, andar)                  ← fixo (sempre 2)
     * Loja(area)                               ← sem andar (sempre 0)
     *
     * Cada classe expõe apenas os parâmetros que VARIAM entre instâncias.
     * O que é fixo fica hardcoded no construtor (como 'andar' na Loja).
     *
     * EXEMPLO DE USO:
     * ---------------
     * Escritorio esc1(60, 3);     // Área=60m², Andar=3, Assoalhadas=2 (automático)
     * cout << esc1.getNumAssoalhadas();  // Output: 2
     *
     * @param areaP: Área do escritório em m² (deve ser > 0)
     * @param andarP: Andar onde se situa o escritório (>= 0)
     */
   
};

