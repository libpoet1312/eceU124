#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_1_
#define _TEST_1_

int test1(char* args[]) {
  
    dequeue_t* queue = create_dequeue(student_print);
    
    FILE* fp = fopen(args[0], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[0]);
        return -1;
    }
    type_t student;
    srand(123456L);
    
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        push_front(queue, student);
        push_back(queue, student);
    }
    fclose(fp);
    
    print_dequeue(stdout, queue);
    printf("-------------------\n");
    
    destroy_dequeue(queue);
    
    return 0;
}

#endif
