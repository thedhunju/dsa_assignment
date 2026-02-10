#include<stdio.h>
#include<ctype.h>

char s[100];
int t = -1;

void add(char x) {
  s[++t] = x;
}

char rem() {
  return s[t--];
}

int prior(char x) {
  if(x == '+' || x == '-') return 1;
  if(x == '*' || x == '/') return 2;
  return 0;
}

void convert(char* in, char* out) {
  int i = 0, k = 0;
  while(in[i]) {
    if(isalnum(in[i])) {
      out[k++] = in[i];
    }
    else if(in[i] == '(') {
      add(in[i]);
    }
    else if(in[i] == ')') {
      while(t >= 0 && s[t] != '(') {
        out[k++] = rem();
      }
      rem();
    }
    else {
      while(t >= 0 && prior(s[t]) >= prior(in[i])) {
        out[k++] = rem();
      }
      add(in[i]);
    }
    i++;
  }
  while(t >= 0) {
    out[k++] = rem();
  }
  out[k] = '\0';
}

int calc(char* post) {
  int arr[100];
  int p = -1;
  int i = 0;
  while(post[i]) {
    if(isdigit(post[i])) {
      arr[++p] = post[i] - '0';
    }
    else {
      int b = arr[p--];
      int a = arr[p--];
      if(post[i] == '+') arr[++p] = a + b;
      else if(post[i] == '-') arr[++p] = a - b;
      else if(post[i] == '*') arr[++p] = a * b;
      else if(post[i] == '/') arr[++p] = a / b;
    }
    i++;
  }
  return arr[p];
}

int main() {
  char in[100], out[100];
  printf("Enter infix: ");
  scanf("%s", in);
  convert(in, out);
  printf("Postfix: %s\n", out);
  printf("Result: %d\n", calc(out));
  return 0;
}
