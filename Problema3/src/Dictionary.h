#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Node.h"
#include "Tree.h"
#include <vector>
#include <string>

// Carrega palavras no dicionário
Node* carregarDicionario() {
    Node* raiz = nullptr;
    std::vector<std::string> palavras = {
        "abacaxi", "abelha", "academia", "amarelo", "amigo", "amora", "andar",
        "animal", "anjo", "arara", "armário", "artigo", "azul", "banana",
        "barco", "bicho", "biblioteca", "bicicleta", "branco", "cachorro",
        "caderno", "café", "caminhar", "carro", "casa", "cavalo", "cereja",
        "chapéu", "chave", "chuva", "cinza", "colher", "computador", "coração",
        "dedo", "dente", "dinheiro", "doce", "elefante", "envelope", "escada",
        "escola", "esmalte", "espelho", "estrela", "fada", "familia", "festa",
        "flauta", "flor", "fogo", "gato", "girafa", "goiaba", "grande", "graviola",
        "janela", "jardim", "joaninha", "leão", "limão", "linda", "livro", 
        "luz", "maçã", "melancia", "mesa", "montanha", "morango", "mundo",
        "neve", "nuvem", "ocelote", "olho", "orelha", "pato", "peixe", "piano",
        "pirulito", "porta", "quadro", "queijo", "raposa", "rede", "relógio",
        "rio", "rosto", "sabonete", "sacola", "sapo", "sol", "tigre", "uva",
        "ventilador", "vermelho", "verde", "violão"
    };

    for (const auto& palavra : palavras) {
        raiz = inserir(raiz, palavra);
    }

    return raiz;
}

#endif // DICTIONARY_H
