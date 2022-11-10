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

void sort_string(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    for (int j = i; j < strlen(str); j++) {
      if (str[i] > str[j]) {
        swap(&str[i], &str[j]);
      }
    }
  }
  return;
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
