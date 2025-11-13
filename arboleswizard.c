#include <stdio.h>
#include <stdlib.h>

/* Estructura del nodo del árbol */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

/* Crear un nuevo nodo */
struct Node* create_node(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insertar una clave en el árbol*/
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return create_node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

/* Recorridos del árbol */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* Liberar memoria */
void free_tree(struct Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/* Programa principal */
int main(void) {
    struct Node* root = NULL;
    int value;

    printf("=== Árbol binario de búsqueda ===\n");
    printf("Ingrese números para construir el árbol.\n");
    printf("Ingrese -1 para finalizar.\n\n");

    while (1) {
        printf("Ingrese un número: ");
        if (scanf("%d", &value) != 1) {
            printf("Entrada no válida. Saliendo.\n");
            break;
        }
        if (value == -1) break;
        root = insert(root, value);
    }

    printf("\nRecorridos del árbol:\n");

    printf("Inorder (orden ascendente): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
