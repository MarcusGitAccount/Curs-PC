#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

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

#define  SIZE 32 
#define DEBUG

#define  KRED "\x1B[31m"
#define  KGRN "\x1B[32m"
#define  KYEL "\x1B[33m"
#define  KBLU "\x1B[34m"
#define  KMAG "\x1B[35m"
#define  KCYN "\x1B[36m"
#define  KWHT "\x1B[37m"
#define RESET "\033[0m"

struct node {
  uint64_t     data;
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

uint64_t dequeue(Queue* queue) {
  Node*         node = queue->first;
  uint64_t save_data = node->data;

  if (queue->size == 0)
    return 0;

  queue->first = queue->first->next;
  queue->size--;
  free(node);
  
  return save_data;
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
uint8_t count_set_bits(uint64_t nbr) {
  uint8_t count = 0;

  while (nbr) {
    count++;
    nbr &= (nbr - 1);
  }

  return count;
}

uint8_t get_bit(uint32_t array[], uint32_t position) {
  const uint64_t mask = 1U << (position % SIZE);
  
  return array[position / SIZE] & mask ? 1 : 0;
}

void clear_bit(uint32_t array[], uint32_t position) {
  const uint64_t mask = ~(1U << (position % SIZE));
  
  array[position / SIZE] &= mask;
}

void set_bit(uint32_t array[], uint32_t position) {
  array[position / SIZE] |= (1U << (position % SIZE));
}

/* Solve the problem */
Queue* initial_sieve(uint64_t limit) {
  Queue* 	 queue   = (Queue*)malloc(sizeof(Queue*));
  uint64_t _sqrt   = (uint64_t)sqrt(limit);
  uint32_t *primes = (uint32_t*)calloc(_sqrt / SIZE + 1, sizeof(uint32_t));
  
  init_queue(queue);
  set_bit(primes, 0);
  // working with reversed logic, otherwise primes should all me initialized to max uiint64_t
  
  #undef DEBUG
  #ifdef DEBUG
    printf("Position 0 in array testing: %d\n", get_bit(primes, 0));
    printf("Position 1 in array testing: %d\n", get_bit(primes, 1));
    printf("Position 2 in array testing: %d\n", get_bit(primes, 2));
    printf("size: %llu\nnumber: %llu\n", size, limit);
  #endif
  
	enqueue(queue, 2);
  for (uint64_t number = 3; number <= _sqrt; number += 2) {
    if (get_bit(primes, number / 2) == 0) {
      enqueue(queue, number);

			#ifdef DEBUG
				printf("Number: %llu %llu\n", number, number / 2);
      #endif

			for (uint64_t position = number * number; position <= _sqrt; position += (number * 2)) {
				#ifdef DEBUG
					printf("Current position: %llu %llu\n", position, position / 2);
        #endif
				
				set_bit(primes, position / 2);
      }
    }
    else
      set_bit(primes, number / 2);
  }
  
  return queue;
}

uint64_t count_primes(uint64_t limit) {
  uint64_t start, end, delta;
  uint64_t non_primes_counter;
  uint32_t *current_sieve;
  Queue* queue = (Queue*)malloc(sizeof(Queue*));

  uint64_t sum = 0;

  queue = initial_sieve(limit);
  start = delta = (uint64_t)sqrt(limit) + 1;
  end   = 2 * start;
  non_primes_counter = 0;
  current_sieve = (uint32_t*)malloc((delta / SIZE + 1) * sizeof(uint32_t));

  printf("Queue size after the initial sieving: %s%u%s\n", KYEL, queue->size, RESET);
  while (start < limit) {
    Node*    prime = queue->first->next; // pass 2 since only odd maps are represented in the sieve
    uint64_t count = 0;

    //printf("Limits: %llu -> %llu\n", start, end);
    for (uint64_t index = 0; index < delta / SIZE + 1; index++)
      current_sieve[index] = 0;

    while (prime != NULL) {
      uint64_t first_composite = start / prime->data * prime->data;

      // calculate the first multiple of the given prime in the interval
      if (first_composite < start)
        first_composite += prime->data;
      if ((first_composite & 1) == 0)
        first_composite += prime->data;

      // set all the composites of the current prime in the given interval
      for (uint64_t number = first_composite; number <= end; number += (prime->data) * 2) {
        const uint64_t position = (number - start) / 2;
        
        if (get_bit(current_sieve, position) == 0) {
          // printf("Position debug: %llu %llu %d\n", number, position, get_bit(current_sieve, position));
          set_bit(current_sieve, position);
          count++;
        }
      }

      prime = prime->next;
    }

    for (uint64_t index = 0; index < delta / SIZE + 1; index++)
      sum += count_set_bits(current_sieve[index]);
    non_primes_counter += count;
    start += delta;
    end   += delta;

    //printf("%sCount, total and delta: %llu %llu %llu\n%s", KRED, count, non_primes_counter, delta , RESET);
    if (end > limit)
      end = limit;
  }
 
  printf("%sTotal composites: %llu%s\n", KCYN, non_primes_counter, RESET);
  printf("%sTotal set:        %llu%s\n", KCYN, sum, RESET);
  return queue->size + (limit  - delta + 1) / 2 - non_primes_counter;
}

/* Main */
int main(int argc, char **argv) {
	clock_t begin, end;
	double  time;

	if (argc < 2) {
		printf("Invalid number of parameters\n");
		printf("Program will exit now.\n");
		return 0;
	}

	begin = clock();
  printf("%sNumber of primes found up to %s%s: %s%llu.\n%s", KWHT, KCYN, argv[1], KYEL, count_primes(atoll(argv[1])), RESET);
  end		= clock();
	time	= (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%sTotal time elapsed since the starting of the program: %s%lf seconds.\n%s", KWHT, KYEL, time, RESET);
  
	#ifdef DEBUG
		while (queue->size)
			printf("%llu ", dequeue(queue));
		printf("\n");
	#endif

	return 0;
}
