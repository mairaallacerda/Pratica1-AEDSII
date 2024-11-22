#include <iostream>
#include "Node.h"
#include "Tree.h"
#include "Dictionary.h"

int main() {
    // Carregar o dicionário
    Node* dicionario = carregarDicionario();

    std::string prefixo;
    while (true) {
        std::cout << "\nDigite um prefixo (ou 'sair' para encerrar): ";
        std::cin >> prefixo;

        if (prefixo == "sair") {
            break;
        }

        // Obter sugestões
        std::vector<std::string> sugestoes = autocompletar(dicionario, prefixo);

        // Exibir sugestões
        if (sugestoes.empty()) {
            std::cout << "Nenhuma sugestao encontrada para o prefixo \"" << prefixo << "\".\n";
        } else {
            std::cout << "Sugestoes:\n";
            for (const auto& palavra : sugestoes) {
                std::cout << "- " << palavra << "\n";
            }
        }
    }

    std::cout << "Encerrando o programa.\n";
    return 0;
}
