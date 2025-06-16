#include <iostream>
using namespace std;

struct No {
    float dado;
    No *prox;
};

struct Fila {
    No *ini;
    No *fim;
};

Fila *init() {
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmpty(Fila *f) {
    return (f->ini == NULL);
}

int count(Fila *f) {
    int qtde = 0;
    No *no;
    no = f->ini;
    while (no != NULL) {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void print(Fila *f) {
    No *no;
    no = f->ini;
    cout << "---------------------" << endl;
    cout << "Elementos na fila: " << count(f) << endl;
    cout << "---------------------" << endl;
    while (no != NULL) {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "---------------------" << endl;
}

void enqueue(Fila *f, float v) {
    No *no = new No;
    no->dado = v;
    no->prox = NULL;
    if (isEmpty(f)) {
        f->ini = no;
    } else {
        f->fim->prox = no;
    }
    f->fim = no;
}

float dequeue(Fila *f) {
    float ret;
    if (isEmpty(f)) {
        ret = -1;
    } else {
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;
        if (f->ini == NULL) {
            f->fim = NULL;
        }
        free(no);
    }
    return ret;
}

void freeFila(Fila *f) {
    No *no;
    no = f->ini;
    while (no != NULL) {
        No *aux = no->prox;
        free(no);
        no = aux;
    }
    free(f);
}

int main(int argc, char** argv) {
    Fila *senhasGeradas = init();
    Fila *senhasAtendidas = init();
    int contadorSenhas = 0;
    int opcao;

    do {
        cout << "========== MENU ==========" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Gerar senha" << endl;
        cout << "2 - Realizar atendimento" << endl;
        cout << "Senhas aguardando: " << count(senhasGeradas) << endl;
        cout << "==========================" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                contadorSenhas++;
                enqueue(senhasGeradas, contadorSenhas);
                cout << "Senha " << contadorSenhas << " gerada com sucesso." << endl;
                break;

            case 2:
                if (!isEmpty(senhasGeradas)) {
                    float senha = dequeue(senhasGeradas);
                    enqueue(senhasAtendidas, senha);
                    cout << "Atendendo senha: " << senha << endl;
                } else {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                }
                break;

            case 0:
                if (!isEmpty(senhasGeradas)) {
                    cout << "Ainda ha senhas aguardando atendimento. Nao e possivel sair." << endl;
                    opcao = -1;
                } else {
                    cout << "Sistema encerrado. Total de senhas atendidas: " << count(senhasAtendidas) << endl;
                }
                break;

            default:
                cout << "Opcao invalida." << endl;
                break;
        }

        cout << endl;

    } while (opcao != 0);

    freeFila(senhasGeradas);
    freeFila(senhasAtendidas);

    return 0;
}
