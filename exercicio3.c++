#include <iostream>
using namespace std;

// estrutura do n da arvore
struct Node {
    int data;
    Node* left;
    Node* right;
};

// novo n
Node* newNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

// Função de busca na árvore binária de busca
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    // Valores que estou buscando
    int valores[] = {60, 25, 40};
    
    for (int i = 0; i < 3; i++) {
        int valor = valores[i];
        if (search(root, valor))
            cout << "Valor " << valor << " encontrado na árvore." << endl;
        else
            cout << "Valor " << valor << " NÃO encontrado na árvore." << endl;
    }

    return 0;
}
