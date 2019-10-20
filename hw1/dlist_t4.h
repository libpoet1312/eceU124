#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_4_
#define _TEST_4_

#include <assert.h>

int test4(char* args[]) {
  
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
        }
        else {
            int pos = rand() % list->size;
            insert(list, pos, student);
            print(stdout, list);
            printf("-------------------\n");
        }
    }
    fclose(fp);
    
    print(stdout, list);
    printf("-------------------\n");
    
    fp = fopen(args[1], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[1]);
        return -1;
    }
    int i=0, init_list_size = size(list);
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        if(i++<init_list_size/2) {
            rmv(list, student);
        } else {
            int index = index_of(list, student);
            type_t st = get_index(list, index);
            rmv_index(list, index);
            if(student_cmp(st, student)!=0)
                printf("Assertion error at %s:%d\n", __FILE__, __LINE__);
        }
        print(stdout, list);
        printf("-------------------\n");
    }
    fclose(fp);
    
    destroy_dlist(list);
    
    return 0;
}

#endif
