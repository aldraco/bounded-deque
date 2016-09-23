//
//  main.c
//  deque
//
//  Created by Ashley Drake on 9/22/16.
//    after studying https://gist.github.com/Wollw/2318276
//  Copyright © 2016 Ashley Drake. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "deque.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    // let's try out the deque
    int max_length = 20;
    deque_type *my_deque = deque_alloc(max_length);
    
    assert(my_deque != NULL);
    
    for (int i = 1; i <= max_length + 10; i+=1) {
        deque_push_front(my_deque, i);
        printf("%d items in the deque\n", get_deque_length(my_deque));
    }
    
    while (deque_is_empty(my_deque) != true) {
        printf("%d\n", deque_pop_front(my_deque));
    }
    
    
    
    
    
    return 0;
}
