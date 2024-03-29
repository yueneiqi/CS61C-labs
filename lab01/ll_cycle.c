// reference: https://en.wikipedia.org/wiki/Cycle_detection
#include "ll_cycle.h"
#include <stddef.h>

// Brent's algorithm
int ll_has_cycle(node *head) {
  if (head == NULL) {
    return 0;
  }

  node* slow = head;
  node* fast = head->next;
  size_t length = 1;
  size_t power = 1;
  while (fast != NULL) {
    if (fast == slow) {
      return 1;
    }
    if (length == power) {
      power *= 2;
      length = 0;
      slow = fast;
    }
    fast = fast->next;
    ++length;
  }
  return 1;
}

// Floyd's tortoise and hare
int ll_has_cycle2(node *head) {
  if (head == NULL) {
    return 0;
  }

  node* slow = head;
  node* fast = head->next;

  while (fast != slow) {
    if (fast->next == NULL || fast->next->next == NULL) {
      return 0;
    }
    fast = fast->next->next;
    slow = slow->next;
  }

  return 1;
}
