#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE createBST(NODE root, int key) {
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
        return temp;
    cur = root;
    prev = NULL;
    while (cur != NULL) {
        prev = cur;
        if (key < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (key < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    NODE root = NULL;
    int item, ch;
    for (;;) {
        printf("\n1. Insert");
        printf("\n2. Preorder");
        printf("\n3. Inorder");
        printf("\n4. Postorder");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter item to be inserted: ");
                scanf("%d", &item);
                root = createBST(root, item);
                break;
            case 2:
                printf("\nPreorder traversal is:\n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nInorder traversal is:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder traversal is:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
