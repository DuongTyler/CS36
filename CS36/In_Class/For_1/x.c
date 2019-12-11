#include <stdarg.h>
#include <stdio.h>

void foo(int type, ...)
{
  va_list l;
  int i;
  char *s;

  va_start(l, type);
  switch(type) {
  case 1: i = va_arg(l, int);    printf("int: %d\n", i); break;
  case 2: s = va_arg(l, char *); printf("str: %s\n", s); break;
  default: printf("unknown type\n");
  }

  va_end(l);
}

void main()
{
  foo(1, 5);
  foo(2, "hello");
}
