#include <stdio.h>
#include <string.h>

#include "type_t.h"
#include "tree.h"
#include "common.h"

#include "tree_t1.h"
#include "tree_t2.h"
#include "tree_t3.h"
#include "tree_t4.h"

int main(int argc, char* argv[]) {
  
  char base_path[128];
  if(argc<5) {
    printf("Insufficient number of arguments!\n");
    return 0;
  }
  
  if(strcmp(argv[4], "autolab")==0)
    strcpy(base_path, "autolab");
  else if(strcmp(argv[4], "dot")==0)
    strcpy(base_path, "dot/btree");
  
  switch(argv[1][1]) {
    case '1':
      tree_t1(argv[2], base_path);
      break;
    case '2':
      tree_t2(argv[2], argv[3], base_path);
      break;
    case '3':
      tree_t3(argv[2], argv[2], base_path);
      break;
    case '4':
      tree_t4(argv[2], argv[2], base_path);
      break;
  }
  
  return 0;
}
