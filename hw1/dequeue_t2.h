#include "type_t.h"
#include "dlist.h"

#ifndef _TEST_2_
#define _TEST_2_

int test2(char* args[]) {

    dequeue_t* queue = create_dequeue(student_print);

    FILE* fp = fopen(args[0], "r");
    if(!fp) {
        printf("Unable to open file: %s for reading!\n", args[0]);
        return -1;
    }
    type_t student;
    srand(123456L);

    int count = 0;
    while(fscanf(fp, "%d %s\n", &student.aem, student.name) != EOF) {
        push_front(queue, student);
        push_back(queue, student);
        count++;
    }
    //printf("count = %d\n", count);
    fclose(fp);

    print_dequeue(stdout, queue);
    printf("-------------------\n");

    while(count >= 0) {
      printf("%d\n", count);

      student_print(stdout, top_front(queue), false);
      printf("\n");
      student_print(stdout, pop_front(queue), false);
      printf("\n");
      student_print(stdout, top_back(queue), false);
      printf("\n");
      student_print(stdout, pop_back(queue), false);
      printf("\n");

      count--;
    }

    destroy_dequeue(queue);

    return 0;
}

#endif
