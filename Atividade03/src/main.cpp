#include <iostream>
#include <vector>
#include "Node.h"
#include "Tree.h"

void atualizarAltura(Node* &raiz, const std::string& operacao, int valor) {
    if (operacao == "inserir") {
        raiz = inserir(raiz, valor);
    } else if (operacao == "remover") {
        raiz = remover(raiz, valor);
    }
    std::cout << "Altura da arvore após " << operacao << " " << valor << ": " << alturaArvore(raiz) << std::endl;
}

int main() {
    Node* raiz = nullptr;

    // Inserções iniciais
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 98);
    raiz = inserir(raiz, 44);

    // Visualização após operações
    atualizarAltura(raiz, "inserir", 8);
    atualizarAltura(raiz, "remover", 44);
    atualizarAltura(raiz, "remover", 25);

    // Encontrar o caminho mais longo
    std::vector<int> caminho, melhorCaminho;
    encontrarCaminhoMaisLongo(raiz, caminho, melhorCaminho);
    std::cout << "Caminho mais longo: ";
    for (int val : melhorCaminho) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
