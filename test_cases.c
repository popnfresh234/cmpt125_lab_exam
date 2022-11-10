#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() {
  char str1[] = "abcabc";
  char str2[] = "zyxzabc";
  char str3[] = "ooooooooooooo";
  char str4[] = "";

  sort_string(str1);
  sort_string(str2);
  sort_string(str3);

  /**********test answer**********/
  char* correct1 = "aabbcc";
  char* correct2 = "abcxyzz";
  char* correct3 = "ooooooooooooo";
  char* correct4 = "";
  if (strcmp(str1, correct1) == 0 && strcmp(str2, correct2) == 0 &&
      strcmp(str3, correct3) == 0 && strcmp(str4, correct4) == 0)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

bool is_odd(int x) { return x % 2 == 1; }
bool is_greater_equal_zero(int x) { return x >= 0; }

void test_q2() {
  int ar1[] = {2, 6, 2, 3, 8, 9};
  int ar2[] = {1, -6, -3, 9, 7, 9, 0, 1};
  int ar3[] = {-1};
  int ans1 = filter_to_zero(ar1, 6, is_odd);
  int ans2 = filter_to_zero(ar2, 8, is_greater_equal_zero);
  int ans3 = filter_to_zero(ar3, 1, is_greater_equal_zero);
  /**********test answer**********/
  int correct1[] = {0, 0, 0, 3, 0, 9};
  int correct2[] = {1, 0, 0, 9, 7, 9, 0, 1};
  int correct3[] = {0};

  bool okFlagAns = (ans1 == 4 && ans2 == 2 && ans3 == 1);
  if (!okFlagAns)
    printf("Q2 ERROR: incorrect return value\n");

  bool okFlagArr = true;
  for (int i = 0; i < 6; i++)
    if (ar1[i] != correct1[i])
      okFlagArr = false;
  for (int i = 0; i < 8; i++)
    if (ar2[i] != correct2[i])
      okFlagArr = false;
  for (int i = 0; i < 1; i++)
    if (ar3[i] != correct3[i])
      okFlagArr = false;

  if (!okFlagArr)
    printf("Q2 ERROR: incorrect array\n");

  if (okFlagAns && okFlagArr)
    printf("Q2 ok\n");
}

void test_q3() {
  queue_t* q = queue_create();
  for (int i = -10; i <= 10; i++)
    enqueue(q, i);

  int ans = queue_remove_last(q);

  /**********test answer**********/
  bool okFlagAns = true;

  if (ans != 10) {
    printf("Q3 ERROR: incorrect return value\n");
    okFlagAns = false;
  }

  bool okFlagQueue = true;

  queue_t* q_correct_ans = queue_create();
  for (int i = -10; i <= 9; i++)
    enqueue(q_correct_ans, i);
  if (!LL_equal(q->list, q_correct_ans->list)) {
    printf("Q3 ERROR: the resulting queue is incorrect \n");
    okFlagQueue = false;
  }

  queue_free(q_correct_ans);
  queue_free(q);

  if (okFlagAns && okFlagQueue)
    printf("Q3 ok\n");
}

int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
