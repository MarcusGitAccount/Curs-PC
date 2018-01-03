#include "header.h"

Queue_t* init_sieve(uint64_t upperbound) {
  Queue_t* queue = initqueue();
  uint64_t limit = (uint64_t)sqrt(upperbound) + 1;
  uint32_t size  = limit / 32  / 2 + 1;
  uint32_t* primes = calloc(size, sizeof(uint32_t));

  set_bit(primes, 0);
  limit /= 2;
  for (uint32_t current = 1; current < limit; current++) {
    if (get_bit(primes, current) == 0) {
      const uint32_t nbr = current * 2 + 1;
      
      enqueue(queue, current);
      for (uint32_t position = current + nbr; position  < limit; position += nbr)
        set_bit(primes, position);
    }
    else
      set_bit(primes, current);
  }

  return queue;
}

uint64_t count_primes(uint64_t upperbound) {
  Queue_t* queue = init_sieve(upperbound);
  uint64_t start, delta, end;
  uint32_t counter = 0;
  uint32_t size;
  uint32_t* primes;

  delta = (uint64_t)sqrt(upperbound) + 1;
  delta /= 2;
  start = delta;
  end   = 2 * delta;
  size  = delta / 32 + 1;
  primes = malloc(sizeof(uint32_t) * size);

  if ((upperbound & 1) == 0)
    upperbound--;
  if (upperbound >= 2)
    counter = 1;

  upperbound /= 2;
  while (start < upperbound) {
    Node_t* current = queue->head;
    uint32_t non_primes_counter = 0;

    memset(primes, 0, size * sizeof(uint32_t));
    while (current) {
      uint32_t first_prime = 2 * current->data + 1;
      uint32_t first_composite_position = (uint32_t)ceil(((double)start - current->data) / first_prime);

      first_composite_position = first_prime * first_composite_position + current->data;
      for (uint64_t position = first_composite_position; position < end; position += first_prime) {
        const uint64_t index = position - start;

        if (get_bit(primes, index) == 0) {
          set_bit(primes, index);
          non_primes_counter++;
        }
      }

      current = current->next;
    }

    counter += (end - start - non_primes_counter);
    start += delta;
    end   += delta;
    if (end > upperbound)
      end = upperbound + 1;
  }

  return counter + queue_size(queue);
}

int main(int argc, char** argv) {
  clock_t beginning, end;
  double  duration;

  if (argc != 2) {
    printf("Invalid number of arguments.\n");
    return 1;
  }

  int64_t nbr = atoll(argv[1]);

  beginning = clock();
  printf("Number of primes up to %s%ld: %s%ld%s\n", KYEL, nbr, KCYN, count_primes(nbr), KRESET);
  end = clock();
  duration = (double)(end - beginning) / CLOCKS_PER_SEC;
  printf("%sTotal time elapsed since the starting of the program: %s%lf seconds.\n%s", KWHT, KYEL, duration, KRESET);

  return 0;
}