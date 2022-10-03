#include "Deque_Iterator.h"
#include <iostream>

bool equal(const Iterator& it1, const Iterator& it2) {
    return (it1.current == it2.current);
}

int value(const Iterator& it) {
    return *(it.current);
}

void set_node(Iterator& it, Node* new_node) {
    it.first = new_node->arr;
    it.last = new_node->arr + CHUNK_SIZE;
    it.node = new_node;
}

Iterator next(const Iterator& it) {
    /**
     * [0][1][2][3][4][5][6][7]:8: [0][1][2]...
     * 
     * [0] ~ [6]: return [x] + 1
     * [7]: return [0]
     * [8]: return [1]
     * 
     */
    Iterator next_it = it;
    if (it.current == it.last - 1) {
        set_node(next_it, it.node->next);
        next_it.current = next_it.first;
    } else if (it.current == it.last) {
        set_node(next_it, it.node->next);
        next_it.current = next_it.first + 1;
    } else {
        next_it.current++;
    }
    return next_it;
}

Iterator prev(const Iterator& it) { 
        /**
     * [6][7]:8: [0][1][2][3][4][5][6][7]:8: 
     * 
     * [0]: return [7]
     * [1] ~ [7]: return [x] - 1
     * :8:: return [7], i.e. [x] - 1
     */
    Iterator prev_it;
    if (it.current == it.first) {
        set_node(prev_it, it.node->prev);
        prev_it.current = prev_it.last - 1;
    } else {
        prev_it = it;
        prev_it.current = it.current - 1;
    }
    return prev_it;
}
