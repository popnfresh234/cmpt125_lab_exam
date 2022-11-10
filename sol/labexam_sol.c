#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int compare_chars(const void* a, const void* b) {
  char c_a = *(char*)a;
  char c_b = *(char*)b;
  return c_a-c_b;
}

void sort_string(char* str) {
  qsort(str, strlen(str), 1, compare_chars);
  return;
}


int filter_to_zero(int* ar, int n, bool(*pred)(int)) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!pred(ar[i])) {
      ar[i]=0;
      count++;
    }
  }
  return count;
}


int queue_remove_last(queue_t* q) {
  queue_t* tmp = queue_create();
  
  int ret = dequeue(q);
  while(!queue_is_empty(q)) {
    enqueue(tmp, ret);
    ret = dequeue(q);
  }
  // tmp contains all but the last element
  // ret holds the last element

  // move everything back from tmp to queue
  while(!queue_is_empty(tmp))
    enqueue(q, dequeue(tmp));

  queue_free(tmp);
  return ret;
}
