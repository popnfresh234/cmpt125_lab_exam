#ifndef LAB_EXAM_107_108_H
#define LAB_EXAM_107_108_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"


// the function gets a string consisting of lower case letters
// and sorts the chars in the string
void sort_string(char* str);


// the function gets an array of ints of length n, and a predicate
// for each entry a[i]: if pred(ar[i]) is true, it remains unchanged
// and if pred(ar[i]) is false, then it is changed to zero
// the function returns the number of changed entries
int filter_to_zero(int* ar, int n, bool(*pred)(int));


// gets a queue of ints
// it removes from the queue the last element, and returns it
// assumption: q is not empty
int queue_remove_last(queue_t* q);


#endif
