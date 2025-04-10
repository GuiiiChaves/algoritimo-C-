#include <iostream>
using namespace std;

struct Nodo {
    int chave;
    Nodo *esq, *dir;

    Nodo(int k) : chave(k), esq(nullptr), dir(nullptr) {}
};

class ArvoreBusca {
private:
    Nodo* raiz;

    Nodo* adicionar(Nodo* nodo, int chave) {
        if (nodo == nullptr) return new Nodo(chave);

        if (chave < nodo->chave)
            nodo->esq = adicionar(nodo->esq, chave);
        else
            nodo->dir = adicionar(nodo->dir, chave);

        return nodo;
    }

    Nodo* removerNodo(Nodo* nodo, int chave) {
        if (nodo == nullptr) return nullptr;

        if (chave < nodo->chave) {
            nodo->esq = removerNodo(nodo->esq, chave);
        } else if (chave > nodo->chave) {
            nodo->dir = removerNodo(nodo->dir, chave);
        } else {
            if (nodo->esq == nullptr) {
                Nodo* temp = nodo->dir;
                delete nodo;
                return temp;
            } else if (nodo->dir == nullptr) {
                Nodo* temp = nodo->esq;
                delete nodo;
                return temp;
            }

            Nodo* sucessor = menorValor(nodo->dir);
            nodo->chave = sucessor->chave;
            nodo->dir = removerNodo(nodo->dir, sucessor->chave);
        }

        return nodo;
    }

    Nodo* menorValor(Nodo* nodo) {
        while (nodo->esq != nullptr)
            nodo = nodo->esq;
        return nodo;
    }

    void inOrder(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrder(nodo->esq);
            cout << nodo->chave << " ";
            inOrder(nodo->dir);
        }
    }

public:
    ArvoreBusca() : raiz(nullptr) {}

    void inserirChave(int chave) {
        raiz = adicionar(raiz, chave);
    }

    void removerChave(int chave) {
        raiz = removerNodo(raiz, chave);
    }

    void mostrarInOrder() {
        inOrder(raiz);
        cout << endl;
    }
};
