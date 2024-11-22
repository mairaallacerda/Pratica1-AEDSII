#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>
#include <string>

// Insere uma palavra na árvore
Node* inserir(Node* raiz, const std::string& palavra) {
    if (raiz == nullptr) {
        return new Node(palavra);
    }
    if (palavra < raiz->word) {
        raiz->left = inserir(raiz->left, palavra);
    } else if (palavra > raiz->word) {
        raiz->right = inserir(raiz->right, palavra);
    }
    return raiz;
}

// Coleta palavras com um prefixo específico
void coletarSugestoes(Node* raiz, const std::string& prefixo, std::vector<std::string>& sugestoes) {
    if (raiz == nullptr) {
        return;
    }
    if (raiz->word.compare(0, prefixo.size(), prefixo) == 0) {
        sugestoes.push_back(raiz->word);
    }
    coletarSugestoes(raiz->left, prefixo, sugestoes);
    coletarSugestoes(raiz->right, prefixo, sugestoes);
}

// Busca por sugestões
std::vector<std::string> autocompletar(Node* raiz, const std::string& prefixo) {
    std::vector<std::string> sugestoes;
    coletarSugestoes(raiz, prefixo, sugestoes);
    return sugestoes;
}

#endif // TREE_H
