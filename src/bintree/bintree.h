#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

typedef struct node
{
        void *data;
        struct node *left;
        struct node *right;
}tree, node;

tree *min_element();
tree *max_element();
unsigned int tree_size(tree*);
void delete_tree(tree*);
void int_preorder_traversal(tree*);

#define TREE_INSERT_INIT(TYPE)                                          \
        tree* TYPE ##_tree_insert(tree *root, TYPE value)               \
        {                                                               \
                node *new_node = malloc(sizeof(node));                  \
                new_node->left = new_node->right = NULL;                \
                new_node->data = malloc(sizeof(TYPE));                  \
                *(TYPE*)new_node->data = value;                         \
                                                                        \
                if (root == NULL) {                                     \
                        root = new_node;                                \
                        return root;                                    \
                }                                                       \
                                                                        \
                node *prev_ptr = NULL, *temp_ptr = root;                \
                while (temp_ptr != NULL) {                              \
                        prev_ptr = temp_ptr;                            \
                        if (*(TYPE*)temp_ptr->data > value)             \
                                temp_ptr = temp_ptr->right;             \
                        else                                            \
                                temp_ptr = temp_ptr->left;              \
                }                                                       \
                                                                        \
                if (*(TYPE*)prev_ptr->data > value)                     \
                        prev_ptr->right = new_node;                     \
                else                                                    \
                        prev_ptr->left = new_node;                      \
                                                                        \
                return root;                                            \
        }                                                               \                                                                                            

#endif