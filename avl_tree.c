#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//Alunos
// Guilherme Leite Félix
// Amadeu Mateus de Vasconcelos Neto

typedef struct Node_ {
    //struct Node_ *father;
    struct Node_ *left;
    struct Node_ *right;
    int value;
    int ht;
}Node, *PtrNode;

PtrNode insert(PtrNode, int);
PtrNode newNode(int);
PtrNode delete(PtrNode, int);
PtrNode right_rot(PtrNode);
PtrNode left_rot(PtrNode);
void inOrder(PtrNode);
int balance(PtrNode);
int height(PtrNode);

PtrNode newNode(int val){
    PtrNode new_node = (PtrNode) malloc (sizeof(Node));

    if(new_node == NULL){
        printf("\nMemory can't be allocated\n");
        return NULL;
    }

    new_node->value = val;
    //new_node->father = NULL;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

int balance(PtrNode root){
    int lh, rh;

    if (root == NULL)
        return 0;

    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;

    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}

int height(PtrNode root){
    int lh, rh;

    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;

    if (lh > rh)
        return (lh);

    return (rh);
}

PtrNode right_rot(PtrNode root){
    PtrNode left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;

    root->ht = height(root);
    left_child->ht = height(left_child);

    // return the new node after rotation
    return left_child;
}

PtrNode left_rot(PtrNode root){
    PtrNode right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    root->ht = height(root);
    right_child->ht = height(right_child);

    return right_child;
}

PtrNode insert(PtrNode root, int val){
    if (root == NULL){
        PtrNode new_node = newNode(val);

        if(new_node == NULL){
            return NULL;
        }
        root = new_node;
    }
    else if (val > root->value){
        root->right = insert(root->right, val);

        if (balance(root) == -2)
        {
            if (val > root->right->value)
            {
                root = left_rot(root);
            }
            else
            {
                root->right = right_rot(root->right);
                root = left_rot(root);
            }
        }
    }
    else{
        root->left = insert(root->left, val);

        if (balance(root) == 2)
        {
            if (val < root->left->value)
            {
                root = right_rot(root);
            }
            else
            {
                root->left = left_rot(root->left);
                root = right_rot(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}

PtrNode delete(PtrNode root, int val){
    PtrNode temp = NULL;

    if (root == NULL)
    {
        return NULL;
    }

    if (val > root->value){
        root->right = delete(root->right, val);
        if (balance(root) == 2)
        {
            if (balance(root->left) >= 0)
            {
                root = right_rot(root);
            }
            else
            {
                root->left = left_rot(root->left);
                root = right_rot(root);
            }
        }
    }
    else if (val < root->value){
        root->left = delete(root->left, val);

        if (balance(root) == -2)
        {
            if (balance(root->right) <= 0)
            {
                root = left_rot(root);
            }
            else
            {
                root->right = right_rot(root->right);
                root = left_rot(root);
            }
        }
    }
    else {
        if (root->right != NULL) {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->value = temp->value;
            root->right = delete(root->right, temp->value);
            if (balance(root) == 2)
            {
                if (balance(root->left) >= 0)
                {
                    root = right_rot(root);
                }
                else
                {
                    root->left = left_rot(root->left);
                    root = right_rot(root);
                }
            }
        }
        else {
            return (root->left);
        }
    }
    root->ht = height(root);
    return(root);
}

void inOrder(PtrNode root){
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d", root->value);
    inOrder(root->right);
}


int main(void){
    int user_choice, value;
    char user_continue = 'y';
    //Node_ initialization;
    PtrNode root = NULL;
    PtrNode result = NULL;

    while (user_continue == 'y' || user_choice == 4){
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. In Order");
        printf("\n4. EXIT");

        printf("\n\nEscolha uma opção: ");
        scanf("%d", &user_choice);

        switch(user_choice){
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("\nDigite um valor: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                printf("\nFinalizado.\n");
                return 1;
        }
    }
}
