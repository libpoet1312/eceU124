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
  tree_t* tree;

  tree = (tree_t*)malloc(sizeof(tree_t));
  if (!tree)
    exit(-1);

  tree->root = NULL;
  tree->cmp = cmp;
  tree->printer = printer;
  tree->size = 0;

  return tree;
}

void deleteTree(node_t* node) {
  //incursive deletion
  if (node->left) {
    deleteTree(node->left);
    free(node->left);
  }
  if (node->right) {
    deleteTree(node->right);
    free(node->right);
  }
}

void clear_tree(tree_t* tree) {
  node_t* node = tree->root;

  deleteTree(node);
}

void destroy_tree(tree_t* tree) {
  clear_tree(tree);
  free(tree);
}

int size(tree_t* tree) {
  return tree->size;

}

node_t* get_sibling(node_t* node) {

  node_t* parent = node->parent;

  if(node == parent->left)
    if(parent->right)
      return parent->right;

  if(node == parent->left)
    if(parent->right)
      return parent->right;

  return NULL;
}

bool is_left_child(node_t* node) {
  node_t* parent = node->parent;

  if(!parent)
    return false; //root

  if(node == parent->left)
    return true;

  return false;
}

bool is_right_child(node_t* node) {
  node_t* parent = node->parent;

  if(!parent)
    return false; //root

  if(node == parent->right)
    return true;

  return false;
}

void swap(node_t* n1, node_t* n2) {
  node_t* tmp;

  tmp = (node_t*)malloc(sizeof(node_t));
  tmp->data = n1->data;
  n1->data = n2->data;
  n2->data = tmp->data;
  free(tmp);
}

type_t find(tree_t* tree, type_t data) {
  //find data and return it
  node_t* curr = tree->root;

  //search the tree for data
  while ( curr != NULL ) {
    if ( tree->cmp(data, curr->data) < 0 ){ // data < curr->data
      curr = curr->left;
    }else if ( tree->cmp(data, curr->data) > 0 ) {  // data > curr->data
      curr = curr->right;
    }else{
      //curr->data = data;
      return curr->data; //ean yparxei
    }
  }
  return (type_t){0};
}

bool contains(tree_t* tree, type_t data) {
  node_t* curr = tree->root;
  //node_t* parent=curr;

  while ( curr != NULL ) {
    //parent = curr;
    if ( tree->cmp(data, curr->data) < 0 ){ // data < curr->data
      curr = curr->left;
    }else if ( tree->cmp(data, curr->data) > 0 ) {  // data > curr->data
      curr = curr->right;
    }else{
      return true; //ean yparxei
    }
  }
  return false;
}


node_t* find_node(tree_t* tree, type_t data) {
  // Gyrnaei ton komvo pou tha ginei i enthesi
  node_t* curr = tree->root;
  node_t* parent=curr;

  while ( curr != NULL ) {
    parent = curr;
    if ( tree->cmp(data, curr->data) < 0 ){ // data < curr->data
      curr = curr->left;
    }else if ( tree->cmp(data, curr->data) > 0 ) {  // data > curr->data
      curr = curr->right;
    }else{
      return curr; //ean yparxei
    }
  }
  if(!curr){
    return parent;
  }
  return curr;
}


bool add(tree_t* tree, type_t data) {
  node_t* found;
  found = find_node(tree, data);

  if (found!=NULL && (tree->cmp(data, found->data)==0)) {
    return false; // node exists
  }

  node_t* node = (node_t*)malloc(sizeof(node_t));
  if(!node)
    failure("malloc failure", __FILE__, __LINE__);

  node->left = node->right = NULL;
  node->parent = found;
  node->data = data;

  if(found) {
    if(tree->cmp(data, found->data) < 0){
      found->left = node;
    }else{
      found->right = node;
    }
  }else{
    tree->root = node;
  }
  tree->size++;
  return true;
}

bool update(tree_t* tree, type_t data, type_t new_data) {
  node_t* curr = tree->root;

  //search the tree for data
  while ( curr != NULL ) {
    if ( tree->cmp(data, curr->data) < 0 ){ // data < curr->data
      curr = curr->left;
    }else if ( tree->cmp(data, curr->data) > 0 ) {  // data > curr->data
      curr = curr->right;
    }else{
      curr->data = new_data;
      return true; //ean yparxei
    }
  }

  return false;

}

node_t* rmv_node(tree_t *tree, node_t* node) {
  if(node->left!=NULL && node->right != NULL) {
    // exei 2 paidia
    // periptwsi 3
    node_t* curr = node->right;
    while(curr->left != NULL)
      curr = curr->left;
    swap(node, curr);
    node = curr;
  }
  // eite exei aristero eite dexi paidi, eite katholou paidia
  if(node->left != NULL) // exei aristero paidi
    node->left->parent = node->parent;
  else if(node->right != NULL) // exei dexi paidi
    node->right->parent = node->parent;

  if(tree->root == node) //einai riza tou dentrou
    tree->root = (node->left != NULL ? node->left : node->right);
  else if(is_left_child(node))
    node->parent->left = (node->left != NULL ? node->left : node->right);
  else
    node->parent->right = (node->left != NULL ? node->left : node->right);

  tree->size--;
  free(node);
  return(node);


}

bool rmv(tree_t* tree, type_t data) {
  node_t* node;
  //node_t* parent;
  node_t* deleted;
  type_t d;

  d = find(tree, data);
  if( tree->cmp(d,data)!= 0 )
    return false;

  node = find_node(tree,data);
  if(!node)
    return false; //den vrethike

  //printf("delete: %d\n", node->data.aem);
  //parent = node->parent;

  deleted = rmv_node(tree, node);

  if(deleted)
    return false;

  return true;




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
