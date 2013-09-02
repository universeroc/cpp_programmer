#ifndef __LINKED_NODE__
#define __LNIKED_NODE__

typedef struct LinkNode {
  int value;
  LinkNode* next;
} LinkNode, *pLinkNode;

//
// A && B are desc sorted, we want the result desc also
//
void merge(pLinkNode a, pLinkNode b) {
  pLinkNode c = a;

  pLinkNode i = a->next, j = b->next;
  while (i && j) {
    if (i->value < j->value) {
      c->next = i;
      c = c->next;
      i = i->next;
    } else {
      c->next = j;
      c = c->next;
      j = j->next;
    }
  }

  c->next = i ? i : j;
  delete b;  // free link head node
}

// whether has a ring in the list
bool ring(pLinkNode a) {
  pLinkNode i = a->next;
  pLinkNode j = NULL;
  if (!i)  // if there is a ring, at least three nodes.
    return false;

  j = i->next;
  while (i && j && i != j) {
    i = i->next;
    j = j->next->next;
  }
  if (i == j)
    return true;
  return false;
}

// find the N node from the reverse order in the list
pLinkNode find_n_from_the_right(pLinkNode r, int n) {
  pLinkNode i = r, j = r;

  restart:
  int m = 0;
  for (; m < n && i; ++m)
    i = i->next;

  // reach the list end, the n is bigger than the list length
  if (!i) {
    n %= m;
    goto restart;
  }

  while (i && j) {
    i = i->next;
    j = j->next;
  }
  return j;
}

#endif