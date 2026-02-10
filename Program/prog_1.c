#include <stdio.h>
#include <string.h>

#define SIZE 100

char stk[SIZE];
int t = -1;

void add(char x) {
  stk[++t] = x;
}

char rem() {
  if (t < 0) return '\0';
  return stk[t--];
}

int match(char a, char b) {
  if (a == '(' && b == ')') return 1;
  if (a == '[' && b == ']') return 1;
  if (a == '{' && b == '}') return 1;
  return 0;
}

int check(char *str) {
  t = -1;
  int i = 0;
  while (str[i] != '\0') {
    char c = str[i];
    if (c == '(' || c == '[' || c == '{') {
      add(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (t < 0) return 0;
      char prev = stk[t];
      if (match(prev, c)) {
        rem();
      } else {
        return 0;
      }
    }
    i++;
  }
  if (t == -1) return 1;
  return 0;
}

int main() {
  char e1[] = "a + (b - c) * (d";
  char e2[] = "m + [a - b * (c + d * {m)]";
  char e3[] = "a + (b - c)";
  
  printf("Expression 1: %s\n", e1);
  if (check(e1)) {
    printf("Balanced\n\n");
  } else {
    printf("Not Balanced\n\n");
  }
  
  printf("Expression 2: %s\n", e2);
  if (check(e2)) {
    printf("Balanced\n\n");
  } else {
    printf("Not Balanced\n\n");
  }
  
  printf("Expression 3: %s\n", e3);
  if (check(e3)) {
    printf("Balanced\n\n");
  } else {
    printf("Not Balanced\n\n");
  }
  
  return 0;
}
