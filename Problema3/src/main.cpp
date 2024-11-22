#include <iostream>
#include <vector>
#include <chrono> // Para medir tempo de execução
#include "Node.h"
#include "Tree.h"
#include "Dictionary.h"

int main() {
    // Solicitar o tamanho do dicionário
    int tamanho;
    std::cout << "Escolha o tamanho do dicionario:\n";
    std::cout << "1. 100 palavras\n";
    std::cout << "2. 1000 palavras\n";
    std::cout << "3. 100000 palavras\n";
    std::cout << "Digite sua escolha (1, 2 ou 3): ";
    int escolha;
    std::cin >> escolha;

    if (escolha == 1) {
        tamanho = 100;
    } else if (escolha == 2) {
        tamanho = 1000;
    } else if (escolha == 3) {
        tamanho = 100000;
    } else {
        std::cout << "Escolha invalida. Encerrando o programa.\n";
        return 1;
    }

    // Carregar o dicionário
    std::cout << "Carregando dicionario com " << tamanho << " palavras...\n";
    auto inicioCarregamento = std::chrono::high_resolution_clock::now();
    Node* dicionario = carregarDicionario(tamanho);
    auto fimCarregamento = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracaoCarregamento = fimCarregamento - inicioCarregamento;
    std::cout << "Dicionario carregado em " << duracaoCarregamento.count() << " segundos.\n";

    // Loop para busca de prefixos
    while (true) {
        std::string prefixo;
        std::cout << "\nDigite o prefixo para buscar (ou 'sair' para encerrar): ";
        std::cin >> prefixo;

        if (prefixo == "sair") {
            break;
        }

        // Medir tempo da busca
        auto inicioBusca = std::chrono::high_resolution_clock::now();
        std::vector<std::string> sugestoes = autocompletar(dicionario, prefixo);
        auto fimBusca = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracaoBusca = fimBusca - inicioBusca;

        // Exibir resultados
        if (sugestoes.empty()) {
            std::cout << "Nenhuma sugestao encontrada para o prefixo \"" << prefixo << "\".\n";
        } else {
            std::cout << "Sugestoes encontradas:\n";
            for (const auto& palavra : sugestoes) {
                std::cout << "- " << palavra << "\n";
            }
        }
        std::cout << "Tempo de busca: " << duracaoBusca.count() << " segundos.\n";
    }

    std::cout << "Encerrando o programa\n";
    return 0;
}
