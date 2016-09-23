//
//  deque.h
//  deque
//
//  Created by Ashley Drake on 9/22/16.
//  Copyright © 2016 Ashley Drake. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <stdio.h>
#include <stdbool.h>

typedef struct deque_struct deque_type;

typedef int deque_val_type;

deque_type * deque_alloc();
void deque_free(deque_type *d);
bool deque_is_empty(deque_type *d);
int get_deque_length(deque_type *d);

void deque_push_front(deque_type *d, deque_val_type v);

deque_val_type deque_pop_front(deque_type *d);
deque_val_type deque_pop_back(deque_type *d);

deque_val_type deque_peek_front(deque_type *d);
deque_val_type deque_peek_back(deque_type *d);

// TODO taking summary statistics of the head N elements of the deque

#endif /* deque_h */
