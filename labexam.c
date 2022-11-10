#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void swap(char* x, char* y) {
  char temp = *x;
  *x = *y;
  *y = temp;
}

int comparator(const void* p1, const void* p2) {
  char c1 = *(char*)p1;
  char c2 = *(char*)p2;
  return c1 - c2;
}

void sort_string(char* str) {
  qsort(str, strlen(str), sizeof(char), comparator);
}

int filter_to_zero(int* ar, int n, bool (*pred)(int)) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (!pred(ar[i])) {
      ar[i] = 0;
      c++;
    }
  }
  return c;
}

int queue_remove_last(queue_t* q) {
  int size = 0;
  queue_t* tmp = queue_create();
  while (!queue_is_empty(q)) {
    enqueue(tmp, dequeue(q));
    size++;
  }

  for (int i = 0; i < size - 1; i++) {
    enqueue(q, dequeue(tmp));
  }

  return dequeue(tmp);
}
