#ifndef _BTREE_H_ 
#define _BTREE_H_

#include <stdbool.h>

typedef int (*comparator_t)(type_t v1, type_t v2);
typedef void (*printer_t)(FILE*fp, type_t data, bool only_key);

typedef struct bt_node {
  struct bt_node* parent;
  struct bt_node* left;
  struct bt_node* right;
  type_t data;
} node_t;

typedef struct btree {
  node_t* root;
  int size;
  
  comparator_t cmp;
  printer_t printer;
} tree_t;

node_t* get_sibling(node_t* node);
bool is_left_child(node_t* node);
bool is_right_child(node_t* node);
void swap(node_t* n1, node_t* n2);

tree_t* create_tree(comparator_t cmp, printer_t printer);
void clear_tree(tree_t* tree);
void destroy_tree(tree_t* tree);
int size(tree_t* tree);

type_t find(tree_t* tree, type_t data);
bool contains(tree_t* tree, type_t data);
bool add(tree_t* tree, type_t data);
bool update(tree_t* tree, type_t data, type_t new_data);
bool rmv(tree_t* tree, type_t data);

/* prints all tree datas using pre-order traversal
 * and utilizing printer function pointer
 */
void dot_print(FILE* fp, tree_t* tree);

void print(FILE* fp, tree_t* tree);


#endif
