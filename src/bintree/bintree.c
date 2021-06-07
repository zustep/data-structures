#include "bintree.h"
#include <stdio.h>

int main()
{
        TREE_INSERT_INIT(int);
        tree *root = NULL;
        root = int_tree_insert(root, 1);
        root = int_tree_insert(root, 2);
        root = int_tree_insert(root, 3);

        int_preorder_traversal(root);
        printf("\n");

        printf("size = %d\n", tree_size(root));

        delete_tree(root);

        return 0;
}

void int_preorder_traversal(tree *root)
{
        if (root != NULL) {
                int_preorder_traversal(root->right);
                printf("%d ", *(int*)root->data);
                int_preorder_traversal(root->left);
        }
}

unsigned int tree_size(tree *root)
{
        if (root == NULL)
                return 0;
        return tree_size(root->left) + tree_size(root->right) + 1;
}

void delete_tree(tree *root)
{
        if (root != NULL)
        {
                delete_tree(root->right);
                delete_tree(root->left);
                free(root->data);
                free(root);
        }
}

tree *min_element(tree *root)
{
        if (root == NULL || root->left == NULL)
                return 0;
        return min_element(root->left);
}

tree *max_element(tree *root)
{
        if (root == NULL || root->right == NULL)
                return 0;
        return max_element(root->right);
}