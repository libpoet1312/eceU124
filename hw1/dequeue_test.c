#include <stdio.h>
#include <stdlib.h>

#include "type_t.h"
#include "dequeue.h"

#include "dequeue_t1.h"
#include "dequeue_t2.h"
//#include "dequeue_t3.h"
//#include "dequeue_t4.h"

int main(int argc, char* argv[]) {
    
    if(argc<3) {
        printf("Insufficient arguements!\n");
        return -1;
    }
    
    switch(argv[1][1]) {
        case '1':
            test1(&argv[2]);
            break;
        case '2':
            test2(&argv[2]);
            break;
    }
    
    return 0;
}
