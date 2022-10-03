#include "Deque.h"
#include <iostream>
#include <fstream>

// cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW5\" ; if ($?) { g++ Deque_Iterator.cpp Deque.cpp main.cpp -o main } ; if ($?) { .\main }

Deque create_deque() {
    Node *sentinel = new Node; // stored in heap, memory address is preserved
    Node *empty_node = new Node;
    
    sentinel->next = empty_node;
    sentinel->prev = empty_node;

    empty_node->next = sentinel;
    empty_node->prev = sentinel;

    Iterator it;
    set_node(it, empty_node);
    it.current = it.first;

    Deque new_queue = {
        it,        // Iterator start;     
        it,        // Iterator end;      
        sentinel,        // Node* sentinel;     
        1,               // int ll_size;    
    };

    return new_queue;
}

void destroy_deque(Deque& deque) {
    Node* curr_node = deque.sentinel->next;
    while (curr_node != deque.sentinel) {
        curr_node = curr_node->next;
        delete curr_node->prev;
    }
    delete deque.sentinel;
    deque.sentinel = nullptr;
}

Iterator begin(const Deque& deque) {
    return deque.start;
}

Iterator end(const Deque& deque) {
    return deque.end;
}

int front(const Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot get front: deque is empty" << endl;
        return -1;
    } else {
        return *deque.start.current; // guarunteed to be an element
    }
}

int back(const Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot get back: deque is empty" << endl;
        return -1;
    } else {
        return *(deque.end.current - 1); // before it is guarunteed to be an element
    }
}

bool empty(const Deque& deque) { // should be correct
    return equal(deque.start, deque.end);
}

int size(const Deque& deque) { // should be correct
    // cout << deque.start.first << deque.start.current << deque.start.last
    //             << deque.end.first << deque.end.current << deque.end.last << endl;
    if (deque.ll_size <= 1) {
        return (deque.end.current - deque.start.current);
    } else {
        return (deque.ll_size - 2) * CHUNK_SIZE \
            + (deque.end.current - deque.end.first) \
            + (deque.start.last - deque.start.current);
    }
}

void push_back(Deque& deque, int val) {
    /**
     * three cases:
     * [0][1][2][3][4][5][6][7]:8:
     * 
     * end is 0 ~ 6:
     * - set end as val
     * - increment end
     * end is 7:
     * - set end as val
     * - set end as :8:
     * end is 8:
     * - create new node
     * - set new node [0] as val
     * - increment end
     */

    if (deque.end.current == deque.end.last) { 
        // creates next node
        Node* new_node = new Node;
        Node* end_node = const_cast<Node *>(deque.end.node);
        end_node->next = new_node;
        deque.sentinel->prev = new_node;
        new_node->prev = end_node;
        new_node->next = deque.sentinel;
        deque.ll_size++;
        // increment end
        deque.end = next(deque.end);
        // set new node [0] as val
        *(deque.end.current-1) = val; 
     } else {
        // increment end and set end as val
        *(deque.end.current++) = val;
     }
}

void push_front(Deque& deque, int val) {
    /**
     * three cases:
     * [0][1][2][3][4][5][6][7]:8:
     * 
     * start is 7 ~ 1:
     *  - [x]--
     *  - add item at [x]
     * start is 0:
     *  - create new node in front
     *  - [x]--
     * - add item at [x]
     */
    if (deque.start.current == deque.start.first) {
        Node* new_node = new Node;
        Node* start_node = const_cast<Node *>(deque.start.node);
        start_node->prev = new_node;
        deque.sentinel->next = new_node;
        new_node->next = start_node;
        new_node->prev = deque.sentinel;
        deque.ll_size++;
    }
    deque.start = prev(deque.start);
    *deque.start.current = val;
}

void pop_back(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_back: deque is empty" << endl;
        return;
    }

    /**
     * [0][1][2][3][4][5][6][7]:8:
     * if 8 ~ 2:
     * - dec end by 1
     * if 1: 
     * - if node in front is not sentinel (i.e. last element in array)
     *   - pop and do not decrement 
     * - else
     *   - pop and set to prev array's :8:
     * 
     */
    // cout << deque.end.current << " " << *deque.end.current << " " << prev(deque.end.current) << " " << *prev(deque.end.current) << endl;
    if (deque.end.current == deque.end.first + 1) {
        if (deque.ll_size <= 1) {
            deque.end = prev(deque.end);
        } else {
            // del node
            Node* del_node = const_cast<Node *>(deque.end.node);
            del_node->prev->next = del_node->next;
            deque.sentinel->prev = del_node->prev;
            delete del_node;
            deque.ll_size--;
            // set to :8:
            deque.end = prev(prev(deque.end));
            deque.end.current++;
        }
    } else {
        deque.end = prev(deque.end);
    }
 }

void pop_front(Deque& deque) {
    if (empty(deque)) {
        cout << "Cannot pop_front: deque is empty" << endl;
        return;
    }

    // cout << deque.start.first << " " << *deque.start.current << " " << next(deque.start.current) << " " << *next(deque.start.current) << endl;
    /**
     * [0][1][2][3][4][5][6][7]:8:
     * if 0 ~ 6:
     * - inc end by 1
     * if start.current is 7: 
     * - if ll = 1:
     *  - set end.current to 7
     * - else
     *  - del node and move to next array
     * 
     */
    if (deque.start.current == prev(deque.start.last)) {
        if (deque.ll_size <= 1) {
            deque.end = deque.start;
        } else {
            Node* del_node = const_cast<Node *>(deque.start.node);
            deque.start = next(deque.start);
            del_node->next->prev = del_node->prev;
            deque.sentinel->next = del_node->next;
            delete del_node;
            deque.ll_size--;
        }
    }  else {
        deque.start = next(deque.start);
    }
}

void print_deque(const Deque& deque) {
    // cout << "[" << size(deque) << empty(deque) << "]";
    // cout << deque.start.current << " " << deque.end.current << " " << next(deque.end.current) << " " << deque.ll_size << " " << deque.sentinel->arr << endl;
    if (empty(deque)) {
        cout << "[]" << endl;
        return;
    }

    Iterator it = deque.start;

    cout << "[";
    // cout << it.current << ": " << *it.current;
    cout << *it.current;
    while (!equal(it, prev(deque.end))) {
        it = next(it);
        // cout << ", " << it.current << ": " << *it.current;
        cout << ", " << *it.current;
    }
    cout << "]" << endl;
}

void insert(Deque& deque, const Iterator& pos, int val) {
    // cout << pos.current << " " << val << " " << deque.start.current << " " << deque.end.current << endl;
    /**
     * [0][1][2][3][4][5][6][7]:8: [0][1][2][3][4]...
     * 
     * it = [1]
     * 
     * temp = [1]
     * [1] = val
     * val = temp
     * 
     * it++
     * 
     * temp = [2]
     * [2] = val
     * val = temp
     * 
     * it++
     * 
     * etc.
     * until it reaches prev(end)
     * then just simply push_back(val)
     * assumption: deque is non-empty
     */

    int temp;
    Iterator it = pos;

    if (!equal(pos, deque.end)) {
        temp = *it.current;
        *it.current = val;
        val = temp;

        while (!equal(it, prev(deque.end))) {
            it = next(it);
            temp = *it.current;
            *it.current = val;
            val = temp;
        }
    }

    push_back(deque, val);

}

void erase(Deque& deque, const Iterator& pos) {
    /**
     * [0][1][2][3][4][5][6][7]:8: [0][1][2][3][4]...
     * 
     * del [2]:
     * 
     * [2] = [3]
     * if [3] is not prev(end), then
     * it = [3]
     * [3] = [4]
     * if [4] is not prev(end), then
     * it = [4]
     * [4] = [5]
     * since [5] is prev(end), we stop
     * pop_back()
     * 
     * ...
     * until it = prev(end)
     * then just simply pop_back(end)
     * assumption: deque has at least one element
     * 
     * if only one element, simply popback
     * 
     */
    
    Iterator it = pos;

    while (!equal(next(it), prev(deque.end))) { // todo: debug this
        *it.current = *(next(it).current);
        it = next(it);
    }

    // if (size(deque) > 1) {
    //     *it.current = *(next(it).current);
    //     while (!equal(next(it), prev(deque.end))) {
    //         it = next(it);
    //         *it.current = *(next(it).current);
    //     }
    // }

    pop_back(deque);
}

void store_deque(const Deque& deque, const char* filename) {
    ofstream ofs(filename);
    Iterator it = deque.start;
    ofs << size(deque) << endl;
    if (!empty(deque)) {
        ofs << *it.current << endl;
        while (!equal(it, prev(deque.end))) {
            it = next(it);
            ofs << *it.current << endl;
        }
    }
    ofs.close();
}

Deque load_deque(const char* filename) {
    Deque deque = create_deque();
    ifstream ifs(filename);
    int size, temp;
    ifs >> size;
    for (; size > 0; size--) {
        ifs >> temp;
        push_back(deque, temp);
    }
    ifs.close();
    return deque;
}