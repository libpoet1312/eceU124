#include "type_t.h"
#include "dequeue.h"

dequeue_t* create_dequeue(printer_t printer) {

  dequeue_t* queue = (dequeue_t*)malloc(sizeof(dequeue_t));
  if (!queue)
    exit(-1);

  dlist_t* list = (dlist_t*) malloc(sizeof(dlist_t));
  if (!list)
    exit(-1);

  queue->list = list;

  queue->list->head = NULL;
  queue->list->tail = NULL;

  queue->list->size = 0;

  return queue;

}

void clear_dequeue(dequeue_t* queue) {
  dnode_t* curr = queue->list->head;
  dnode_t* tmp_node;

  while (curr!=NULL) {
    tmp_node = curr;
    curr = curr->next;
    free(curr);
  }
}

void destroy_dequeue(dequeue_t* queue) {

  clear_dequeue(queue); //remove all data
  if (queue->list!=NULL) {
    free(queue->list);
    free(queue);
  }
}

int dequeue_size(dequeue_t* queue) {
  return queue->list->size;
}

void push_front(dequeue_t* queue, type_t data) {
  dnode_t* new_node;

  new_node = (dnode_t*)malloc(sizeof(dnode_t));
  if (!new_node) {
    exit(-1);
  }
  new_node->data = data;

  if (queue->list->head == NULL) {
    // adeia lista
    queue->list->head = new_node;
    new_node->next = new_node->prev = NULL;

    queue->list->tail = new_node;
  }else{
    new_node->next = queue->list->head;
    new_node->prev = NULL;
    queue->list->head->prev = new_node;
    queue->list->head = new_node;
  }

  queue->list->size++;

}

void push_back(dequeue_t* queue, type_t data) {
  dnode_t* new_node;

  new_node = (dnode_t*)malloc(sizeof(dnode_t));
  if (!new_node) {
    exit(-1);
  }
  new_node->data = data;

  if (queue->list->head == NULL) {
    // adeia lista
    queue->list->head = new_node;
    queue->list->tail = new_node;

    new_node->next = new_node->prev = NULL;
  }else{
    new_node->next = NULL;
    new_node->prev = queue->list->tail;
    queue->list->tail->next = new_node;
    queue->list->tail = new_node;
  }

  queue->list->size++;

}

type_t pop_front(dequeue_t* queue) {
  type_t data;
  dnode_t* tmp_node;

  tmp_node = queue->list->head;
  if (tmp_node==NULL) {
    return (type_t){0};
  }
  data = tmp_node->data;

  if (queue->list->head == queue->list->tail) {
    //ONE element in the list
    queue->list->head = queue->list->tail = NULL;
    free(tmp_node);
    return data;
  }

  queue->list->head = queue->list->head->next;
  queue->list->size--;
  tmp_node->next = tmp_node->prev = NULL;
  free(tmp_node);
  return data;

}

type_t pop_back(dequeue_t* queue) {
  type_t data;
  dnode_t* tmp_node;

  tmp_node = queue->list->tail;
  if (tmp_node==NULL) {
    return (type_t){0};
  }
  data = tmp_node->data;

  if (queue->list->head == queue->list->tail) {
    //ONE element in the list
    queue->list->head = queue->list->tail = NULL;
    free(tmp_node);
    return data;
  }else{
    queue->list->tail = queue->list->tail->prev;
    queue->list->size--;
    queue->list->tail->next = NULL;

    tmp_node->next = tmp_node->prev = NULL;

    free(tmp_node);
    return data;
  }
}

type_t top_front(dequeue_t* queue) {
  if (queue->list->head!=NULL){
    return queue->list->head->data;
  }else{
    return (type_t){0};
  }
}

type_t top_back(dequeue_t* queue) {
  if (queue->list->tail!=NULL){
    return queue->list->tail->data;
  }else{
    return (type_t){0};
  }
}

void print_dequeue(FILE* fp, dequeue_t* queue) {
  queue->list->printer = student_print; // MY CODE
  for(dnode_t* curr=queue->list->head; curr!=NULL; curr=curr->next) {
    queue->list->printer(fp, curr->data, false);
    putchar('\n');
  }
}
