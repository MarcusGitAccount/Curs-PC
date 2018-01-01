#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <math.h>
# include <time.h>

# define  KRED  "\x1B[31m"
# define  KGRN  "\x1B[32m"
# define  KYEL  "\x1B[33m"
# define  KBLU  "\x1B[34m"
# define  KMAG  "\x1B[35m"
# define  KCYN  "\x1B[36m"
# define  KWHT  "\x1B[37m"
# define KRESET "\033[0m"

typedef struct node {
  uint32_t     data;
  struct node* next;
} Node_t;

typedef struct queue {
  Node_t* head;
  Node_t* last;
} Queue_t;

Queue_t* initqueue() {
  Queue_t* queue = malloc(sizeof(Queue_t));

  queue->head = queue->last = NULL;
  return queue;
}

bool is_empty(Queue_t* queue);
bool dequeue (Queue_t* queue) {
  Node_t* temp = queue->head;

  if (is_empty(queue))
    return false;

  queue->head = queue->head->next;
  free(temp);
  return true;
}

bool enqueue(Queue_t* queue, uint32_t new_data) {
  Node_t* new_node = malloc(sizeof(Node_t));

  if (new_node == NULL)
    return false;

  new_node->data = new_data;

  if (queue->last)
    queue->last->next = new_node;
  if (queue->head == NULL)
    queue->head = new_node;
  queue->last = new_node;

  return true;
}

bool is_empty(Queue_t* queue) {
  if (!queue->head)
    return true;
  return false;
}

Node_t* peek(Queue_t* queue) {
  return queue->head;
}

uint64_t queue_size(Queue_t* queue) {
  Node_t*  copy = queue->head;
  uint64_t size = 0;
  
  while (copy) {
    size++;
    copy = copy->next;
  }

  free(copy);
  return size; 
}

void print_and_destroy(Queue_t* queue, void (*print)(uint32_t)) {
  while (!is_empty(queue)) {
    print(queue->head->data);
    dequeue(queue);
  }

  printf("\n");
}

void set_bit(uint32_t* primes, uint32_t position) {
  const uint32_t mask = 1U << (position % 32);

  primes[position / 32] |= mask;
}

bool get_bit(uint32_t* primes, uint32_t position) {
  const uint32_t mask = 1U << (position % 32);

  return (primes[position / 32] & mask) != 0 ? true : false;
}

#endif