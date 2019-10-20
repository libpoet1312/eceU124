#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_1_
#define _TEST_1_

int test1(char* args[]) {
  
    dlist_t* list = create_dlist(student_cmp, student_print);
    
    FILE* fp = fopen(args[0], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[0]);
        return -1;
    }
    type_t student;
    srand(123456L);
    
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        if(list->size==0) {
            insert(list, 0, student);
            print(stdout, list);
            printf("-------------------\n");
        }
        else {
            int pos = rand() % list->size;
            printf("Insert at pos: %d\n", pos);
            insert(list, pos, student);
            print(stdout, list);
            printf("-------------------\n");
        }
    }
    fclose(fp);
    
    print(stdout, list);
    printf("-------------------\n");
    
    destroy_dlist(list);
    
    return 0;
}

#endif
