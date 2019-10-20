
#include <stdio.h>
#include <stdlib.h>

#include "type_t.h"
#include "dlist.h"

#include "dlist_t1.h"
#include "dlist_t2.h"
#include "dlist_t3.h"
#include "dlist_t4.h"
#include "dlist_t5.h"

int main(int argc, char* argv[]) {
    
    if(argc<4) {
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
        case '3':
            test3(&argv[2]);
            break;
        case '4':
            test4(&argv[2]);
            break;
        case '5':
            test5(&argv[2]);
            break;
    }
    
    return 0;
}
