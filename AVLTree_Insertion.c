//Github Username: Omkar-Khairnar
//Aim: Insertion in AVL Tree in C
//Date: 05-10-2022

#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
    int balance_factor;
};

typedef struct node node;

int height(node * root){
    if (root == NULL){
        return 0;
    }else{
        int left = height(root->left);
        int right = height(root->right);
        if (left > right){
            return left + 1;
        }else{
            return right + 1;
        }
    }
}

int balance_factor(node * root){
    return height(root->left) - height(root->right);
}

void inorder(node * root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


node * LL_rotation(node * root){
    printf("performed LL rotation\n");
    node * temp = root->left->right;
    node * newroot = root->left;
    newroot->right = root;
    root->left = temp;
    return newroot;
}

node * RR_rotation(node * root){
    printf("performed RR rotation\n");
    node * temp = root->right->left;
    node * newroot = root->right;
    newroot->left = root;
    root->right = temp;
    return newroot;
}

node * LR_rotation(node * root){
    printf("performed LR rotation\n");
    node * newroot = root->left->right;
    node * right = newroot->right;
    node * left = newroot->left;
    newroot->right = root;
    newroot->left = root->left;
    root->left = right;
    newroot->left->right = left;
    return newroot;
}

node * RL_rotation(node * root){
    printf("performed RL rotation\n");
    node * newroot = root->right->left;
    node * right = newroot->right;
    node * left = newroot->left;
    newroot->left = root;
    newroot->right = root->right;
    root->right = left;
    newroot->right->left = right;
    return newroot;
}

node * insert(node * root, int x){
    if (root != NULL){
        int decider;
        if (x > root->data){
            root->right = insert(root->right, x);
            decider = 1;
        }else{
            root->left = insert(root->left, x);
            decider = 2;
        }

        int bfactor = balance_factor(root);
        // printf("%d ", bfactor);

        int rotation = 0;

        if (bfactor >= 2 || bfactor <= -2){
            if (decider == 2){
                int temp = balance_factor(root->left);
                if (temp == 1){
                    rotation = 1;
                }else if(temp == -1){
                    rotation = 2;
                }
            }else{
                int temp = balance_factor(root->right);
                if (temp == -1){
                    rotation = 3;
                }else if(temp == 1){
                    rotation = 4;
                }
            }
        }

        // printf("%d\n", rotation);

        switch (rotation){
            case 1:
                root = LL_rotation(root);
                break;
            case 2:
                root = LR_rotation(root);
                break;
            case 3:
                root = RR_rotation(root);
                break;
            case 4:
                root = RL_rotation(root);
                break;
            default:
                break;
        }

        return root;


    }else{
        node * n = (node *)malloc(sizeof(node));
        n->left = NULL;
        n->right = NULL;
        n->data = x;
        return n;
    }
}

int main(){
    node * root = NULL;
   int n;
   printf("Enter Total Number of Elements to be Insert\n");
   scanf("%d",&n);
   int list[n];

   for (int i = 0; i < n; i++) {
       scanf("%d",&list[i]); 
   }
   printf("Inserting Elements in AVL Tree\n");
    for (int i = 0; i < n; i++){
        printf("inserting %d\n", list[i]);
        root = insert(root, list[i]);
    }
    printf("\nInorder :");
    inorder(root);
    printf("\n");

    return 0;
}