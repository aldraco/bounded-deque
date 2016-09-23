//
//  deque.c
//  deque
//
//  Created by Ashley Drake on 9/22/16.
//  Using https://gist.github.com/Wollw/2318276 as a learning resource
//  Copyright © 2016 Ashley Drake. All rights reserved.
//

#include "deque.h"
#include <stdlib.h>
#include <assert.h>

struct node_struct {
    struct node_struct *next;
    struct node_struct *prev;
    deque_val_type val;
};

struct deque_struct {
    struct node_struct *head;
    struct node_struct *tail;
    int length;
    int max_length;
};

deque_type * deque_alloc(int max_length) {
    deque_type *d = malloc(sizeof(deque_type));
    if (d != NULL) {
        d->head = d->tail = NULL;
        d->length = 0;
        d->max_length = max_length;
    }
    
    return d;
}

void deque_free(deque_type *d) {
    free(d);
}

bool deque_is_empty(deque_type *d) {
    return d->head == NULL;
}

int get_deque_length(deque_type *d) {
    return d->length;
}

void deque_push_front(deque_type *d, deque_val_type v) {
    struct node_struct *n = malloc(sizeof(struct node_struct));
    assert(n != NULL);
    n->val = v;
    n->next = d->head;
    n->prev = NULL;
    if (d->tail == NULL) {
        d->head = d->tail = n;
    } else {
        d->head->prev = n;
        d->head = n;
    }
    d->length += 1;
    
    if (d->length >= d->max_length) {
        deque_pop_back(d);
    }
}

deque_val_type deque_pop_front(deque_type *d) {
    deque_val_type popped = d->head->val;
    struct node_struct *n = d->head;
    if (d->head == d->tail) {
        d->head = d->tail = NULL;
    } else {
        d->head = n->next;
    }
    free(n);
    d->length -=1;
    return popped;
}

deque_val_type deque_pop_back(deque_type *d) {
    deque_val_type popped = d->tail->val;
    struct node_struct *n = d->tail;
    if (d->head == d->tail) {
        d->head = d->tail = NULL;
    } else {
        d->tail = n->prev;
    }
    free(n);
    d->length -=1;
    return popped;
}

