#include "type_t.h"
#include "tree.h"

#ifndef _BTREE_3_H_ 
#define _BTREE_3_H_

void update_and_verify(tree_t* tree, type_t student) {
  strcpy(student.name, "Peter Pan");
  // We only use the key of type_t from the second argument 
  // of update.
  fprintf(stdout, "Student with AEM ");
  student_print(stdout, student, true);
  if(update(tree, student, student)) {
    fprintf(stdout, " was updated!\n");
  }
  else {
    fprintf(stdout, " was NOT updated!\n");
  }
  
  fprintf(stdout, "Updated value: ");
  type_t found_student = find(tree, student);
  student_print(stdout, found_student, false);
  printf("\n");
}

void tree_t3(char *filename1, char* filename2, char* base_path) {
  FILE *fp1 = fopen(filename1, "r");
  if(!fp1) {
    fprintf(stderr, "Unable to open file \"%s\"\n", filename1);
    return;
  }
  type_t student, student_copy;
  tree_t* tree = create_tree(student_cmp, student_print);
  
  int i=0;
  while(fscanf(fp1, "%d %s\n", &student.aem, student.name) != EOF) {
    add(tree, student);
    i++;
    if(i==7)  //random selection
      student_copy = student;
  }
  
  strcpy(student_copy.name, "Peter Pan");
  update_and_verify(tree, student_copy);
  student_copy.aem = 123456;
  update_and_verify(tree, student_copy);
  
   
}

#endif
