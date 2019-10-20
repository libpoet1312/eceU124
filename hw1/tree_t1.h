#include "type_t.h"
#include "tree.h"

#ifndef _BTREE_1_H_ 
#define _BTREE_1_H_

void tree_t1(char *filename, char* base_path) {
  FILE *fp = fopen(filename, "r");
  if(!fp) {
    fprintf(stderr, "Unable to open file \"%s\"\n", filename);
    return;
  }
  type_t student;
  
  tree_t *tree = create_tree(student_cmp, student_print);
  
  int i=0;
  char dot_base_filename[64], dot_filename[64];
  while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
    add(tree, student);
    if(strcmp(base_path, "autolab")!=0) {
        sprintf(dot_base_filename, "%s_insert_%d", base_path, ++i);
        sprintf(dot_filename, "%s.dot", dot_base_filename);
        FILE* fp = fopen(dot_filename, "w");
        if(!fp) {
          fprintf(stderr, "Unable to write to file \"%s\"\n", dot_filename);
          return;
        }
        dot_print(fp, tree);
        fclose(fp);
        dot_exec("dot", dot_base_filename);
    }
    else {
        print(stdout, tree);
        putchar('\n');
    }
  }
  
  destroy_tree(tree);
}
#endif
