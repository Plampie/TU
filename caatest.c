#include <stdio.h>
#include <stdlib.h>

// Структура на възел от двоично дърво
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Създаване на нов възел
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Грешка при заделяне на памет.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Рекурсивна функция за намиране на дълбочината на дървото
int treeDepth(Node *root) {
    if (root == NULL)
        return 0;

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Примерно двоично дърво
Node* buildExampleTree() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    return root;
}

// Освобождаване на паметта
void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = buildExampleTree();
    int depth = treeDepth(root);

    printf("Дълбочината на двоичното дърво е: %d\n", depth);

    freeTree(root);
    return 0;
}
