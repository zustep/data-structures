#include "bintree.h"
#include <stdio.h>

int main()
{
        TREE_INSERT_INIT(int);
        tree *root = NULL;
        root = int_tree_insert(root, 1);
        root = int_tree_insert(root, 2);
        root = int_tree_insert(root, 3);

        preorder_traversal(root);
        printf("\n");

        return 0;
}

void preorder_traversal(tree *root)
{
        if (root != NULL) {
                preorder_traversal(root->right);
                printf("%d ", *(int*)root->data);
                preorder_traversal(root->left);
        }
}