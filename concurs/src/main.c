#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  !!
  Use malloc for memory allocation on the heap memory.
  Standard memory allocation occurs on the stack.

  Considerations:
  When implementing a segmented sieve with the following rules:
    - long long ints are used instead of char type
    - even numbers are not remembered
  => Max size = sqrt(10 ** 18) / 64 bits = aprox. 15625000 bits
  => around 1.9 MB on heap memory
  
  For storing the prime numbers found in the initial sieve:
    - make use of a Queue structure
    
  Sieving between a low and high bound:
    - [low..high]
    - (high - low) / 64 numbers in the array
    - index = the current number
    - bit position = segment[(index - low) / 64] & ((index - low) % 64);
*/

typedef   signed          char  int8_t;
typedef   signed     short int int16_t;
typedef   signed           int int32_t;
typedef   signed long long int int64_t;

typedef unsigned          char  uint8_t;
typedef unsigned     short int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned long long int uint64_t;

#define DEBUG

struct node {
  long long data;
  struct node* next;
};

struct queue {
  struct node* first;
  struct node* last;
  uint32_t     size; 
};

typedef struct node  Node;
typedef struct queue Queue;

/* Queue model */
uint8_t enqueue(Queue* queue, int64_t value) {
  Node* node = (Node*)malloc(sizeof(Node*));
  
  if (node == NULL)
    return 0;

  node->data = value;
  if (queue->last)
    queue->last->next = node;
    
  queue->last = node;
  if (queue->first == NULL)
    queue->first = queue->last;
    
  queue->size++;
  return 1;
}

uint8_t dequeue(Queue* queue) {
  Node* node = queue->first;
  
  if (queue->size == 0)
    return 0;

  queue->first = queue->first->next;
  queue->size--;
  free(node);
  
  return 1;
}

Node* queue_peek(Queue* queue) {
  return queue->first;
}

uint32_t queue_size(Queue* queue) {
  return queue->size;
}

void init_queue(Queue* queue) {
  queue->first = queue->last = NULL;
  queue->size  = 0;
}

/* Working with bit arrays functions */
uint8_t get_bit(uint64_t array[], uint32_t position) {
  const uint64_t mask = 1ULL << (position % 64);
  
  return array[position / 64] & mask ? 1 : 0;
}

uint8_t clear_bit(uint64_t array[], uint32_t position) {
  const uint64_t mask = ~(1ULL << (position % 64));
  
  return array[position / 64] & mask;
}

void set_bit(uint64_t array[], uint32_t position) {
  array[position / 64] |= (1ULL << (position % 64));
}

/* Solve the problem */
Queue* initial_sieve(uint64_t limit) {
  Queue* queue     = (Queue*)malloc(sizeof(Queue*));
  uint64_t size    = (uint32_t)sqrt(limit);
  uint64_t *primes = (uint64_t*)calloc(size / 64 + 1, sizeof(uint64_t));
  
  init_queue(queue);
  set_bit(primes, 0);
  set_bit(primes, 1);
  // working with reversed logic, otherwise primes should all me initialized to max uint64_t
  
  #undef DEBUG
  #ifdef DEBUG
    printf("Position 0 in array testing: %d\n", get_bit(primes, 0));
    printf("Position 1 in array testing: %d\n", get_bit(primes, 1));
    printf("Position 2 in array testing: %d\n", get_bit(primes, 2));

    printf("size: %llu\nnumber: %llu\n", size, limit);
    exit(1);
  #endif
  
  for (uint64_t number = 2; number <= size; number++) {
    if (get_bit(primes, number) == 0) {
      enqueue(queue, number);

      for (uint64_t position = number * 2; position <= size; position += number) {
        set_bit(primes, position);
      }
    }
    else
      set_bit(primes, number);
  }
  
  return queue;
}

uint32_t count_primes(uint64_t limit) {
  return ~(1 << 31);
}

/* Main */
int main(int arc, char **argv) {
  Queue* queue = (Queue*)malloc(sizeof(Queue*));

  queue = initial_sieve(1000000000000000000);
  
  printf("Queue size after the initial sieving: %u\n", queue->size);
  return 0;
}