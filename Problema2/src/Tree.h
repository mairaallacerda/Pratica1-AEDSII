#ifndef TREE_H
#define TREE_H

#include "Node.h" // Inclua o arquivo Node.h para que o tipo Node seja reconhecido

#include <iostream>
#include <vector>
#include <algorithm> // Para std::max

// Calcula a altura máxima da árvore
int alturaArvore(Node* raiz) {
    if (raiz == nullptr) {
        return 0; // Árvore vazia tem altura 0
    }
    int alturaEsquerda = alturaArvore(raiz->left);
    int alturaDireita = alturaArvore(raiz->right);
    return 1 + std::max(alturaEsquerda, alturaDireita);
}

// Insere um valor na árvore
Node* inserir(Node* raiz, int valor) {
    if (raiz == nullptr) {
        return new Node(valor);
    }
    if (valor < raiz->val) {
        raiz->left = inserir(raiz->left, valor);
    } else {
        raiz->right = inserir(raiz->right, valor);
    }
    return raiz;
}

// Encontra o menor valor na subárvore
Node* encontrarMinimo(Node* raiz) {
    while (raiz->left != nullptr) {
        raiz = raiz->left;
    }
    return raiz;
}

// Remove um valor da árvore
Node* remover(Node* raiz, int valor) {
    if (raiz == nullptr) {
        return raiz;
    }
    if (valor < raiz->val) {
        raiz->left = remover(raiz->left, valor);
    } else if (valor > raiz->val) {
        raiz->right = remover(raiz->right, valor);
    } else {
        // Nó com um ou nenhum filho
        if (raiz->left == nullptr) {
            Node* temp = raiz->right;
            delete raiz;
            return temp;
        } else if (raiz->right == nullptr) {
            Node* temp = raiz->left;
            delete raiz;
            return temp;
        }
        // Nó com dois filhos
        Node* temp = encontrarMinimo(raiz->right);
        raiz->val = temp->val;
        raiz->right = remover(raiz->right, temp->val);
    }
    return raiz;
}

// Encontra o caminho mais longo
void encontrarCaminhoMaisLongo(Node* raiz, std::vector<int>& caminho, std::vector<int>& melhorCaminho) {
    if (raiz == nullptr) {
        if (caminho.size() > melhorCaminho.size()) {
            melhorCaminho = caminho;
        }
        return;
    }
    caminho.push_back(raiz->val);
    encontrarCaminhoMaisLongo(raiz->left, caminho, melhorCaminho);
    encontrarCaminhoMaisLongo(raiz->right, caminho, melhorCaminho);
    caminho.pop_back();
}

#endif // TREE_H
