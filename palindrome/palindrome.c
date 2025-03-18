#include <stdio.h>

#define MAXLINE 80 /* maximum input line size */

void printinput(char s[], int length);
int readline(char s[], int maxline);
int palindrome(char s[], int length);

int main(void) {
  char s[MAXLINE];
  int res, length;

  printf("Welcome to the all-mighty palindrome detector!\n");
  printf("Please provide input:\n");

  length = readline(s, MAXLINE);

  printinput(s, length);

  res = palindrome(s, length);

  printf("Result it: %d\n", res);

  return res;
}

int palindrome(char s[], int length) {
  int i;

  for (i = 0; i < length / 2; ++i) {
    if (s[i] != s[length - i - 2]) return 0;
  }

  return 1;
}

void printinput(char s[], int length) {
  int i;

  printf("Input string is: ");

  for (i = 0; i < length - 1; ++i) {
    printf("%c", s[i]);
  }

  printf("\n");
}

int readline(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    if (c != '\t' && c != ' ')
      s[i] = c;
    else --i;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
