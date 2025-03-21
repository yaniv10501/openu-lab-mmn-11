#include<stdio.h>

int count_zero_bits(int x);

int main(void) {
  int user_input, zero_bits;

  printf("Welcome to the all-mighty unsigned int zero-bits counter!\n");
  printf("Please provide input (positive integers only):\n");

  scanf("%d", &user_input);

  zero_bits = count_zero_bits(user_input);

  printf("There are %d zero bits for input: '%d'\n", zero_bits, user_input);

  return zero_bits;
}

int count_zero_bits(int x) {
  unsigned int inverted = ~x;  /* Invert all bits */
  int zero_bits = 0;
  
  while (inverted > 0) {
      inverted &= (inverted - 1); /* Clear the rightmost set bit */
      zero_bits++; /* Increment counter */
  }
  
  return zero_bits;
}
