#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "type_t.h"
#include "tree.h"
#include "common.h"

#ifdef _AVL_
#include "avl.h"
#elif defined _REDBLACK_
#include "red_black.h"
#endif

tree_t* create_tree(comparator_t cmp, printer_t printer) {
  
}

void clear_tree(tree_t* tree) {
  
}

void destroy_tree(tree_t* tree) {
  
}

int size(tree_t* tree) {
  
}

node_t* get_sibling(node_t* node) {
  
}

bool is_left_child(node_t* node) {
  
}

bool is_right_child(node_t* node) {
  
}

void swap(node_t* n1, node_t* n2) {
  
}

type_t find(tree_t* tree, type_t data) {

}

bool contains(tree_t* tree, type_t data) {

}

bool add(tree_t* tree, type_t data) {

}

bool update(tree_t* tree, type_t data, type_t new_data) {

}

node_t* rmv_node(tree_t *tree, node_t* node) {

}

bool rmv(tree_t* tree, type_t data) {

}

void __print_node(FILE* fp, tree_t* tree, node_t* node) {
  if(!node)
    return;
  tree->printer(fp, node->data, true);
  __print_node(fp, tree, node->left);
  __print_node(fp, tree, node->right);
}

void print(FILE* fp, tree_t* tree) {
  __print_node(fp, tree, tree->root);
}

void __dot_print_node(FILE* fp, tree_t* tree, node_t* node) {
  if(!node)
    return;
  fprintf(fp, "  "); 
  tree->printer(fp, node->data, true);
  fprintf(fp, "\n");
  
  if(node->left != NULL) {
    fprintf(fp, "  ");
    tree->printer(fp, node->data, true);
    fprintf(fp, " -- ");
    tree->printer(fp, node->left->data, true);
    fprintf(fp, "\n");
  }
  
  if(node->right != NULL) {
    fprintf(fp, "  ");
    tree->printer(fp, node->data, true);
    fprintf(fp, " -- ");
    tree->printer(fp, node->right->data, true);
    fprintf(fp, "\n");
  }
  
  __dot_print_node(fp, tree, node->left);
  __dot_print_node(fp, tree, node->right);
}

void dot_print(FILE* fp, tree_t* tree) {
  fprintf(fp, "graph G {\n");
  __dot_print_node(fp, tree, tree->root);
  fprintf(fp, "}\n");
}
