#include <stdio.h>

#define MAXLINE 80 /* maximum input line size */

int readline(char s[], int maxline);
int palindrome(char s[], int length);

int main(void) {
  char s[MAXLINE];
  int length;

  printf("Welcome to the all-mighty palindrome detector!\n");
  printf("Please provide input:\n");

  length = readline(s, MAXLINE);

  printf("Input is: '%s'\n", s);

  return palindrome(s, length);
}

int palindrome(char s[], int length) {
  /* Using pointers to track start and end */
  char *start = s;
  char *end = s + length - 1;

  while (start < end) {
    /* Skip spaces or tabs either from start or end */
    if (*start == ' ' || *start == '\t') {
      start++;
      continue;
    }
    if (*end == ' ' || *end == '\t') {
      end--;
      continue;
    }

    /* Check if it's not a palindrome to exit early */
    if (*start != *end) return 0;
    
    /* Move pointers closer */
    start++;
    end--;
  }

  return 1;
}

int readline(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  s[i] = '\0';

  return i;
}
