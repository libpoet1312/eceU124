#include <stdio.h>
#include <stdlib.h>

#include "type_t.h"
#include "dlist.h"

dlist_t* create_dlist(comparator_t cmp, printer_t printer) {
  dlist_t* list = (dlist_t*) malloc(sizeof(dlist_t));
  if (!list) {
    exit(-1);
  }
  list->head = list->tail = NULL;
  list->size = 0;

  return list;
}

void clear_dlist(dlist_t* list) {

}

void destroy_dlist(dlist_t* list) {

}

int size(dlist_t* list) {
  return list->size;
}

bool insert(dlist_t* list, int index, type_t data) {
  int i;
  dnode_t* tmp_node;
  dnode_t* new_node;

  //elegxos oriwn
  if (index<0 || index>list->size) {
    return false;
  }

  if ((list->head == NULL) && (index != 0)){
        printf("%d Empty list \n", index);
        return false;
  }

  //dimioyrgia neou komvou
  new_node = (dnode_t*)malloc(sizeof(dnode_t));
  //tmp_node = (dnode_t*)malloc(sizeof(dnode_t));
  if (!new_node) {
    exit(-1);
  }
  new_node->data = data;


  if (index == 0){
    if (list->head == NULL) {
      // 1. enthesi stin arxi tis KENIS listas
      //printf(". 1 .\n");
      list->head = new_node;
      new_node->prev = NULL;
      new_node->next = NULL;
      list->size++;
      return true;
    }else{
      // 2. Enthesi stin arxi se gemati lista
      //printf(". 2 .\n");
      new_node->next = list->head;
      list->head->prev = new_node;
      list->head = new_node;
      return true;
    }
  }else{
    // 3. Enthesi se kathe alli periptwsi
    //printf("%d\n", index);
    //printf(". 3 .\n");
    i=0;
    tmp_node = list->head;
    while (i < index){
            tmp_node = tmp_node->next;
            i++;
    }
    new_node->prev = tmp_node;
    new_node->next = tmp_node->next;
    tmp_node->next->prev = new_node;
    tmp_node->next = new_node;
    list->size++;
    return true;
  }
}

int index_of(dlist_t* list, type_t data) {
  //diatrexw tin lista ews to telos
  int index=0;
  for(dnode_t* curr=list->head; curr!=NULL; curr=curr->next, index++) {
    if (list->cmp(curr->data,data) == 0) {
      return index;
    }
  }
  return -1;
}

int instances_of(dlist_t* list, type_t data) {
  int instances=0;
  for(dnode_t* curr=list->head; curr!=NULL; curr=curr->next) {
    if (list->cmp(curr->data,data) == 0) { //  SEGMETATION FAULT
      instances++;
    }
  }
  return instances;
}

type_t get_index(dlist_t* list, int index) {
  // Elegxoi
  type_t* zero_student;
  if(index<0 || index>list->size-1){
    zero_student = (type_t*)malloc(sizeof(type_t));
    zero_student->aem=0;
    return *zero_student;
  }
  if (list->head==NULL) {
    exit(-1);
  }


  dnode_t* tmp_node=list->head;
  //ftanw sto epithimito index
  for (int i = 0; i < list->size-1; i++) {
    tmp_node=tmp_node->next;
  }
  return tmp_node->data;
}

bool rmv(dlist_t* list, type_t data) {

}

type_t rmv_index(dlist_t* list, int index) {

}

void swap(dnode_t* n1, dnode_t* n2) {

}

void catenate(dlist_t* list1, dlist_t* list2) {

}

type_t* dlist2table(dlist_t* list) {
  type_t* table = (type_t*)malloc((list->size) * sizeof(type_t));
  if(!table) {
    fprintf(stderr, "Malloc failure [%s:%d]\n", __FILE__, __LINE__);
    exit(-1);
  }
  int i=0;
  while(size(list)>0) {
    table[i++] = get_index(list, 0);
    rmv_index(list,0);
  }
  return table;
}

void table2dlist(type_t table[], int table_size, dlist_t* list) {
    for(int i=0; i<table_size; i++) {
        insert(list, size(list), table[i]);
    }
    free(table);
}

void print(FILE* fp, dlist_t* list) {
    for(dnode_t* curr=list->head; curr!=NULL; curr=curr->next) {
      fprintf(fp, "%5d. %s", curr->data.aem, curr->data.name);
      //list->printer(fp, curr->data, false);
      putchar('\n');
    }
}
