#include <iostream>
using namespace std;

#define LIMITE 10

struct Fila {
    int elementos[LIMITE];
    int inicio;
    int fim;
};

Fila* criarFila() {
    Fila *fila = new Fila;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

int estaVazia(Fila *fila) {
    return (fila->inicio == fila->fim);
}

int proximoIndice(int indice) {
    return (indice == LIMITE - 1 ? 0 : indice + 1);
}

int quantidadeElementos(Fila *fila) {
    int total = 0;
    int i = fila->inicio;
    while (i != fila->fim) {
        total++;
        i = proximoIndice(i);
    }
    return total;
}

int enfileirar(Fila *fila, int valor) {
    int temEspaco = (proximoIndice(fila->fim) != fila->inicio);
    if (temEspaco) {
        fila->elementos[fila->fim] = valor;
        fila->fim = proximoIndice(fila->fim);
    }
    return temEspaco;
}

int desenfileirar(Fila *fila) {
    if (!estaVazia(fila)) {
        int valor = fila->elementos[fila->inicio];
        fila->inicio = proximoIndice(fila->inicio);
        return valor;
    }
    return -1;
}

void liberarFila(Fila *fila) {
    free(fila);
}

void exibirMenu(Fila *fila) {
    cout << "========== MENU ==========" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Gerar senha" << endl;
    cout << "2 - Realizar atendimento" << endl;
    cout << "Senhas na fila: " << quantidadeElementos(fila) << endl;
    cout << "==========================" << endl;
    cout << "Opcao: ";
}

int main() {
    Fila* filaSenhas = criarFila();
    Fila* filaAtendidas = criarFila();
    int numeroSenha = 0;
    int escolha;

    do {
        exibirMenu(filaSenhas);
        cin >> escolha;

        switch (escolha) {
            case 1:
                numeroSenha++;
                if (enfileirar(filaSenhas, numeroSenha)) {
                    cout << "Senha " << numeroSenha << " gerada com sucesso." << endl;
                } else {
                    cout << "Fila cheia. Não é possível gerar nova senha." << endl;
                }
                break;

            case 2:
                if (!estaVazia(filaSenhas)) {
                    int senhaAtual = desenfileirar(filaSenhas);
                    enfileirar(filaAtendidas, senhaAtual);
                    cout << "Atendendo senha: " << senhaAtual << endl;
                } else {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                }
                break;

            case 0:
                if (!estaVazia(filaSenhas)) {
                    cout << "Ainda há senhas na fila. Não é possível encerrar." << endl;
                    escolha = -1;
                } else {
                    cout << "Sistema encerrado. Total de senhas atendidas: " << quantidadeElementos(filaAtendidas) << endl;
                }
                break;

            default:
                cout << "Opção inválida." << endl;
                break;
        }

        cout << endl;

    } while (escolha != 0);

    liberarFila(filaSenhas);
    liberarFila(filaAtendidas);

    return 0;
}
