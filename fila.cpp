#include <iostream>
#include <queue>
#include <random>
#include <ctime>

struct Filas {
    std::queue<int> geradas;   // senhas aguardando atendimento
    std::queue<int> atendidas; // senhas já atendidas
};

int gerarSenha() {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(1, 9999);
    return dist(rng);
}


void mostrarStatus(const Filas& filas) {
    std::cout << "--------------------------------------\n";
    std::cout << filas.geradas.size() << " pessoas estao aguardando atendimento\n";
    std::cout << "--------------------------------------\n";
}

// Mostra o menu de opções
void exibirMenu() {
    std::cout << "\nEscolha uma opcao:\n\n"
              << "0. Sair\n"
              << "1. Gerar senha\n"
              << "2. Realizar atendimento\n\n";
}

int main() {
    Filas filas;
    int opcao = -1;

    while (true) {
        mostrarStatus(filas);
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 0:  
                if (filas.geradas.empty()) {
                    std::cout << "Pessoas atendidas: " << filas.atendidas.size() << '\n';
                    std::cout << "Atendimentos encerrados\n";
                    return 0;
                }
                std::cout << "Ainda existem pessoas a serem atendidas\n";
                break;

            case 1: { 
                int senha = gerarSenha();
                filas.geradas.push(senha);
                std::cout << "Senha " << senha << " gerada\n";
                break;
            }

            case 2:  
                if (filas.geradas.empty()) {
                    std::cout << "Nao ha senhas para atender\n";
                } else {
                    int senhaDaVez = filas.geradas.front();
                    filas.geradas.pop();
                    filas.atendidas.push(senhaDaVez);
                    std::cout << "Senha da vez: " << senhaDaVez << '\n';
                }
                break;

            default:
                std::cout << "!!! POR FAVOR, SELECIONE UMA OPCAO DE 0 A 2 !!!\n";
        }
    }
}
