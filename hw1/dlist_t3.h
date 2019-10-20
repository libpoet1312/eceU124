
#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_3_
#define _TEST_3

#include <assert.h>

int test3(char* args[]) {
  
    dlist_t* list = create_dlist(student_cmp, student_print);
    
    FILE* fp = fopen(args[0], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[0]);
        return -1;
    }
    type_t student;
    srand(123456L);
    
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        insert(list, 0, student);
    }
    fclose(fp);
    
    print(stdout, list);
    printf("-------------------\n");
    
    fp = fopen(args[1], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[1]);
        return -1;
    }
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        int index = index_of(list, student);
        type_t st = get_index(list, index);
        
        if(student_cmp(st,student)!=0)
            printf("Assertion error at %s:%d\n", __FILE__, __LINE__);
    }
    fclose(fp);
    
    destroy_dlist(list);
    
    return 0;
}

#endif
