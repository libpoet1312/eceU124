#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_5_
#define _TEST_5_

#include <assert.h>

int test5(char* args[]) {
  
    dlist_t* list1 = create_dlist(student_cmp, student_print);
    
    dlist_t* list2 = create_dlist(student_cmp, student_print);
    
    FILE* fp = fopen(args[0], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[0]);
        return -1;
    }
    type_t student;

    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        insert(list1, 0, student);
    }
    fclose(fp);
    
    catenate(list2, list1);
    print(stdout, list1);
    printf("-------------------\n");
    print(stdout, list2);
    printf("-------------------\n");
    
    catenate(list1, list2);
    print(stdout, list1);
    printf("-------------------\n");
    print(stdout, list2);
    printf("-------------------\n");
    
    fp = fopen(args[1], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[1]);
        return -1;
    }
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        insert(list2, 0, student);
    }
    fclose(fp);
    
    catenate(list1, list2);
    print(stdout, list1);
    printf("-------------------\n");
    print(stdout, list2);
    printf("-------------------\n");
    
    swap(list1->head, list1->tail);
    print(stdout, list1);
    printf("-------------------\n");
    
    destroy_dlist(list1);
    destroy_dlist(list2);
    
    return 0;
}

#endif
