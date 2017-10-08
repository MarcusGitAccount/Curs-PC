// $< represents the first target in the dependency list
// $@ represents the target

int is_prime(int nbr) {
  if (nbr == 2)
    return 1;
  if (nbr < 2)
    return 0;
  
  for (unsigned int d = 2; d * d <= nbr; d++)
    if (nbr % d == 0)
      return 0;
  
  return 1;
}

int sum_of_digits(int nbr) { 
  if (nbr <= 0)
    return 0;
    
  return nbr % 10 + sum_of_digits(nbr / 10);
}