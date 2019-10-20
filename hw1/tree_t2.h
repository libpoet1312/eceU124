#include "type_t.h"
#include "tree.h"

#ifndef _BTREE_2_H_ 
#define _BTREE_2_H_

void tree_t2(char *filename1, char* filename2, char* base_path) {
  FILE *fp1 = fopen(filename1, "r");
  if(!fp1) {
    fprintf(stderr, "Unable to open file \"%s\"\n", filename1);
    return;
  }
  type_t student;
  tree_t* tree = create_tree(student_cmp, student_print);
  
  while(fscanf(fp1, "%d %s\n", &student.aem, student.name) != EOF) {
    add(tree, student);
  }
  
  int i=0;
  char dot_base_filename[64], dot_filename[64];
  
  if(strcmp(base_path, "autolab")!=0) {
    sprintf(dot_base_filename, "%s_erase_%d", base_path, i);
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
      printf("\n");
  }
  
  FILE *fp2 = fopen(filename2, "r");
  if(!fp2) {
    fprintf(stderr, "Unable to open file \"%s\"\n", filename1);
    return;
  }
  
  while(fscanf(fp2, "%d %s\n", &student.aem, student.name) != EOF) {
    if(contains(tree, student)) {
        printf("Student with aem: %d FOUND\n", student.aem);
    }
    else {
        printf("Student with aem: %d NOT FOUND\n", student.aem);
    }
  }
}

#endif
