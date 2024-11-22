#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Node.h"
#include "Tree.h"
#include <vector>
#include <string>
#include <cstdlib> // Para geração de palavras aleatórias

// Lista inicial com pelo menos 100 palavras reais
const std::vector<std::string> palavrasFixas = {
    "abacaxi", "abelha", "academia", "amarelo", "amigo", "andar", "animal", "anjo", 
    "arara", "armário", "banana", "barco", "bicho", "biblioteca", "bicicleta", 
    "branco", "cachorro", "caderno", "café", "caminhar", "carro", "casa", "cavalo", 
    "cereja", "chuva", "computador", "coração", "dedo", "dente", "dinheiro", "doce", 
    "elefante", "escola", "estrela", "família", "festa", "flor", "fogo", "girafa", 
    "gato", "goiaba", "jardim", "janela", "leão", "limão", "livro", "maçã", 
    "melancia", "mesa", "montanha", "morango", "neve", "nuvem", "ocelote", "olho", 
    "orelha", "pato", "peixe", "piano", "porta", "quadro", "queijo", "raposa", "rede", 
    "relógio", "rio", "rosto", "sol", "tigre", "uva", "ventilador", "verde", 
    "vermelho", "violão", "zebra", "zangão", "zoológico", "zero", "zumbido",
    "avó", "balão", "caminhão", "doutor", "estudo", "ferro", "grande", "homem",
    "igreja", "jornal", "lanterna", "moradia", "natureza", "ovo", "parque",
    "quarto", "remédio", "sanduíche", "tapete", "unha", "vassoura", "xícara"
};

// Gera palavras aleatórias de comprimento fixo
std::string gerarPalavraAleatoria(int tamanho) {
    std::string palavra;
    for (int i = 0; i < tamanho; ++i) {
        palavra += 'a' + rand() % 26; // Gera letras de 'a' a 'z'
    }
    return palavra;
}

// Carrega o dicionário com o tamanho especificado
Node* carregarDicionario(int tamanho) {
    Node* raiz = nullptr;

    // Primeiro, adiciona as palavras fixas
    for (const auto& palavra : palavrasFixas) {
        raiz = inserir(raiz, palavra);
    }

    // Completa o dicionário com palavras aleatórias se necessário
    for (int i = palavrasFixas.size(); i < tamanho; ++i) {
        raiz = inserir(raiz, gerarPalavraAleatoria(5)); // Palavras aleatórias de 5 letras
    }

    return raiz;
}

#endif // DICTIONARY_H
