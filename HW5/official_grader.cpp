#include <iostream>
// <string> is included in <iostream>
#include "Deque.h"

using namespace std;

void register_case(int T, const string &title) {
    cout << endl << "===== Test " << T << ": " << title << " =====" << endl;
}

string check(bool predicate) {
    return (predicate ? "Correct" : "Wrong");
}

string bool_to_str(bool predicate) {
    return (predicate ? "true" : "false");
}

// two iterators are equal iff all fields are equal
bool operator==(const Iterator &it1, const Iterator &it2) {
    return (it1.current == it2.current) &&
           (it1.first == it2.first) &&
           (it1.last == it2.last) &&
           (it1.node == it2.node);
}

Iterator next_ans(const Iterator& it) {
    Iterator it_temp = it;
    ++it_temp.current;
    if (it_temp.current == it_temp.last) {
        // this is set_node()
        Node* new_node = it_temp.node -> next;
        it_temp.node = new_node;
        it_temp.first = new_node -> arr;
        it_temp.last = it_temp.first + CHUNK_SIZE;
        it_temp.current = it_temp.first;
    }
    return it_temp;
}

void print_deque_simple(const Deque& deque) {
    cout << "Current deque: ";
    // try to not use student-implemented function
    for (Iterator it = deque.start; it.current != deque.end.current; it = next_ans(it)) {
        cout << *(it.current) << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cout << "Which test case do you want to run? ";
    cin >> T;
    cout << endl;

    // for Deque_Iterator tests
    // sentinel <-> node1 <-> node2
    Node *node1 = new Node{}, *node2 = new Node{};
    Node *sentinel = new Node{};
    sentinel->next = node1;
    node1->next = node2;
    node2->next = sentinel;
    sentinel->prev = node2;
    node1->prev = sentinel;
    node2->prev = node1;
    for (int i = 0; i < CHUNK_SIZE; ++i) {
        node1->arr[i] = i;
        node2->arr[i] = 1 + i;
    }

    if (T == 1) {
        register_case(T, "Check if set_node() correctly updates the iterator");

        // iterator points to node 1 before
        Iterator it{node1->arr, node1->arr, node1->arr + CHUNK_SIZE, node1};
        // set it to node 2
        set_node(it, node2);

        cout << "iterator.node points at node 2: " << check(it.node == node2) << endl;
        cout << "iterator.first points at arr[0] in node 2: " << check(it.first == node2->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 2: " <<
             check(it.last == node2->arr + CHUNK_SIZE) << endl;

        // set it to node 1
        set_node(it, node1);

        cout << "iterator.node points at node 1: " << check(it.node == node1) << endl;
        cout << "iterator.first points at arr[0] in node 1: " << check(it.first == node1->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 1: " <<
             check(it.last == node1->arr + CHUNK_SIZE) << endl;
    } else if (T == 2) {
        register_case(T, "Check if next() and prev() correctly updates iterator within a node");

        // iterator points to first pos of node 1 before
        Iterator it{node1->arr, node1->arr, node1->arr + CHUNK_SIZE, node1};

        it = next(it);
        cout << "iterator.node points at node 1: " << check(it.node == node1) << endl;
        cout << "iterator.first points at arr[0] in node 1: " << check(it.first == node1->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 1: " <<
             check(it.last == node1->arr + CHUNK_SIZE) << endl;
        cout << "iterator.current points at arr[1] in node 1: " <<
             check(it.current == &(node1->arr[1])) << endl;

        it = prev(it);
        cout << "iterator.node points at node 1: " << check(it.node == node1) << endl;
        cout << "iterator.first points at arr[0] in node 1: " << check(it.first == node1->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 1: " <<
             check(it.last == node1->arr + CHUNK_SIZE) << endl;
        cout << "iterator.current points at arr[0] in node 1: " <<
             check(it.current == &(node1->arr[0])) << endl;
    } else if (T == 3) {
        register_case(T, "Check if next() correctly updates iterator when crossing a node");

        // iterator points to last item of node 1 before
        Iterator it{&(node1->arr[7]), node1->arr, node1->arr + CHUNK_SIZE, node1};

        it = next(it);
        cout << "iterator.node points at node 2: " << check(it.node == node2) << endl;
        cout << "iterator.first points at arr[0] in node 2: " << check(it.first == node2->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 2: " <<
             check(it.last == node2->arr + CHUNK_SIZE) << endl;
        cout << "iterator.current points at arr[0] in node 2: " <<
             check(it.current == &(node2->arr[0])) << endl;
    } else if (T == 4) {
        register_case(T, "Check if prev() correctly updates iterator when crossing a node");

        // iterator points to first item of node 2 before
        Iterator it{node2->arr, node2->arr, node2->arr + CHUNK_SIZE, node2};

        it = prev(it);
        cout << "iterator.node points at node 1: " << check(it.node == node1) << endl;
        cout << "iterator.first points at arr[0] in node 1: " << check(it.first == node1->arr) << endl;
        cout << "iterator.last points at the pos next to arr[7] in node 1: " <<
             check(it.last == node1->arr + CHUNK_SIZE) << endl;
        cout << "iterator.current points at arr[7] in node 1: " <<
             check(it.current == &(node1->arr[7])) << endl;
    } else if (T == 5) {
        register_case(T, "Check equal() and val()");

        Iterator it1{&(node1->arr[1]), node1->arr, node1->arr + CHUNK_SIZE, node1};
        Iterator it2{node2->arr, node2->arr, node2->arr + CHUNK_SIZE, node2};

        cout << "it1 != it2: " << check(!equal(it1, it2)) << endl;
        cout << "it1.val == it2.val: " << check(value(it1) == value(it2)) << endl;

        it2.current = &(node2->arr[1]);
        cout << "it1 != it2: " << check(!equal(it1, it2)) << endl;
        cout << "it1.val != it2.val: " << check(value(it1) != value(it2)) << endl;

        Iterator it3 = {&(node1->arr[1]), node1->arr, node1->arr + CHUNK_SIZE, node1};
        cout << "it1 == it3: " << check(equal(it1, it3)) << endl;
        cout << "it1.val == it3.val: " << check(value(it1) == value(it3)) << endl;

        it3.current = &(node1->arr[2]);
        cout << "it1 != it3: " << check(!equal(it1, it3)) << endl;
        cout << "it1.val != it3.val: " << check(value(it1) != value(it3)) << endl;

        node1->arr[2] = 1;
        cout << "it1 != it3: " << check(!equal(it1, it3)) << endl;
        cout << "it1.val == it3.val: " << check(value(it1) == value(it3)) << endl;
    } else if (T == 6) {
        register_case(T, "Try to create and destroy a deque");

        Deque deque = create_deque();
        cout << "Deque created!" << endl;
        cout << "Check sentinel is not null: " << check(deque.sentinel != nullptr) << endl;
        cout << "Check deque.start == deque.end: " << check(deque.start == deque.end) << endl;
        cout << "Check there are at least one node other than sentinel: " <<
        check(deque.sentinel->next != deque.sentinel) << endl;
        cout << "Check there are at least one node other than sentinel: " <<
             check(deque.sentinel->prev != deque.sentinel) << endl;

        destroy_deque(deque);
    } else if (T == 7) {
        register_case(T, "begin() and end() should be the same for an empty deque");

        Deque deque = create_deque();
        cout << "begin() == end(): " << check(begin(deque) == end(deque)) << endl;
        destroy_deque(deque);
    } else if (T == 8) {
        register_case(T, "front() and back() give error for an empty deque");

        Deque deque = create_deque();
        int dummy = front(deque);
        dummy = back(deque);
        destroy_deque(deque);
    } else if (T == 9) {
        register_case(T, "Test push_back(), simple case");

        Deque deque = create_deque();
        push_back(deque, 1);
        print_deque_simple(deque);

        push_back(deque, 2);
        print_deque_simple(deque);

        push_back(deque, 1);
        print_deque_simple(deque);

        push_back(deque, 3);
        push_back(deque, 2);
        push_back(deque, 1);
        print_deque_simple(deque);

        destroy_deque(deque);
    } else if (T == 10) {
        register_case(T, "Test push_front(), simple case");

        Deque deque = create_deque();
        push_front(deque, 1);
        print_deque_simple(deque);

        push_front(deque, 2);
        print_deque_simple(deque);

        push_front(deque, 1);
        print_deque_simple(deque);

        push_front(deque, 3);
        push_front(deque, 2);
        push_front(deque, 1);
        print_deque_simple(deque);

        destroy_deque(deque);
    } else if (T == 11) {
        register_case(T, "Test push_back(), large case");

        Deque deque = create_deque();
        for (int i = 1; i <= 100; ++i) {
            push_back(deque, i);
            if (i % 20 == 0) {
                print_deque_simple(deque);
            }
        }
        for (int i = 99; i >= 0; --i) {
            push_back(deque, i);
            if (i % 20 == 0) {
                print_deque_simple(deque);
            }
        }

        destroy_deque(deque);
    } else if (T == 12) {
        register_case(T, "Test push_front(), large case");

        Deque deque = create_deque();
        for (int i = 1; i <= 100; ++i) {
            push_front(deque, i);
            if (i % 20 == 0) {
                print_deque_simple(deque);
            }
        }
        for (int i = 99; i >= 0; --i) {
            push_front(deque, i);
            if (i % 20 == 0) {
                print_deque_simple(deque);
            }
        }

        destroy_deque(deque);
    } else if (T == 13) {
        register_case(T, "Test push_back() and push_front(), large case");

        Deque deque = create_deque();
        for (int i = 1; i <= 300; ++i) {
            if (i % 3 == 0) push_back(deque, i - 100);
            else if (i % 3 == 1) push_back(deque, 2 * i - 50);
            else push_front(deque, i * 3 + 2);

            if (i % 30 == 0) {
                print_deque_simple(deque);
            }
        }
        destroy_deque(deque);
    } else if (T == 14) {
        register_case(T, "Test pop_back()");

        Deque deque = create_deque();
        pop_back(deque);

        for (int i = 0; i < 5; ++i) push_back(deque, i);
        for (int i = 0; i < 6; ++i) {
            print_deque_simple(deque);
            pop_back(deque);
        }

        destroy_deque(deque);
    } else if (T == 15) {
        register_case(T, "Test pop_front()");

        Deque deque = create_deque();
        pop_front(deque);

        for (int i = 0; i < 5; ++i) push_back(deque, i);
        for (int i = 0; i < 6; ++i) {
            print_deque_simple(deque);
            pop_front(deque);
        }

        destroy_deque(deque);
    } else if (T == 16) {
        register_case(T, "Test push and pop");

        Deque deque = create_deque();
        pop_front(deque);
        pop_back(deque);

        for (int i = 1; i <= 100; ++i) {
            switch (i % 5) {
                case 1:
                case 2:
                    push_back(deque, i * 2 + 1);
                    break;
                case 3:
                    push_front(deque, i * 3 - 2);
                    break;
                case 4:
                    pop_back(deque);
                    break;
                case 0:
                    pop_front(deque);
            }
            if (i % 10 == 0) {
                print_deque_simple(deque);
            }
        }

        destroy_deque(deque);
    } else if (T == 17) {
        register_case(T, "Test empty and size");

        Deque deque = create_deque();
        cout << "Deque is empty: " << check(empty(deque)) << endl;
        cout << "Deque size is 0: " << check(size(deque) == 0) << endl;

        for (int i = 1; i <= 20; ++i) {
            if (i % 3 == 0) push_back(deque, 3 * i - 2);
            else if (i % 3 == 1) push_back(deque, 2 * i + 1);
            else pop_back(deque);

            if (i % 2 == 0) {
                cout << "Deque is empty: " << bool_to_str(empty(deque)) << endl;
                cout << "Deque size is: " << size(deque) << endl;
            }
        }

        for (int i = 0; i < 200; ++i) push_back(deque, i);
        cout << "Deque size is: " << size(deque) << endl;

        destroy_deque(deque);
    } else if (T == 18) {
        register_case(T, "Test front and back");

        Deque deque = create_deque();

        for (int i = 1; i <= 20; ++i) {
            if (i % 3 == 0) push_back(deque, 3 * i - 2);
            else if (i % 3 == 1) push_back(deque, 2 * i + 1);
            else pop_back(deque);

            if (i % 2 == 0 && i > 2) {
                cout << "front: " << front(deque) << endl;
                cout << "back: " << back(deque) << endl;
            }
        }

        for (int i = 0; i < 200; ++i) push_back(deque, i);
        push_front(deque, 100);
        cout << "front: " << front(deque) << endl;
        cout << "back: " << back(deque) << endl;

        destroy_deque(deque);
    } else if (T == 19) {
        register_case(T, "Test print deque");

        Deque deque = create_deque();
        print_deque(deque);

        for (int i = 1; i <= 20; ++i) {
            if (i % 3 == 0) push_back(deque, 3 * i - 2);
            else if (i % 3 == 1) push_back(deque, 2 * i + 1);
            else pop_back(deque);

            if (i % 2 == 0) {
                print_deque(deque);
            }
        }

        for (int i = 0; i < 200; ++i) push_back(deque, i);
        print_deque(deque);
        push_front(deque, 100);
        print_deque(deque);

        destroy_deque(deque);
    } else if (T == 20) {
        register_case(T, "Test insert, simple cases");

        Deque deque = create_deque();

        insert(deque, deque.start, 2);
        print_deque_simple(deque);

        insert(deque, deque.end, 3);
        print_deque_simple(deque);

        insert(deque, next_ans(deque.start), 3);
        print_deque_simple(deque);

        insert(deque, deque.end, 2);
        print_deque_simple(deque);

        destroy_deque(deque);
    } else if (T == 21) {
        register_case(T, "Test insert, general cases");

        Deque deque = create_deque();

        for (int i = 0; i < 100; ++i) {
            int pos = i * 2 / 3;
            Iterator it = deque.start;
            for (int j = 0; j < pos; ++j) it = next_ans(it);
            insert(deque, it, i);

            if (i % 10 == 0) print_deque_simple(deque);
        }

        destroy_deque(deque);
    } else if (T == 22) {
        register_case(T, "Test erase, simple cases");

        Deque deque = create_deque();
        push_back(deque, 1);
        erase(deque, deque.start);
        print_deque_simple(deque);

        push_back(deque, 2);
        erase(deque, prev(deque.end));
        print_deque_simple(deque);

        for (int i = 0; i < 5; ++i) push_back(deque, i + 1);
        erase(deque, deque.start);
        print_deque_simple(deque);
        erase(deque, next_ans(deque.start));
        print_deque_simple(deque);
        erase(deque, next_ans(next_ans(deque.start)));
        print_deque_simple(deque);

        destroy_deque(deque);
    } else if (T == 23) {
        register_case(T, "Test erase, general cases");

        Deque deque = create_deque();
        for (int i = 0; i < 200; ++i) push_back(deque, i);

        for (int i = 0; i < 100; ++i) {
            int pos = i * 2 / 3;
            Iterator it = deque.start;
            for (int j = 0; j < pos; ++j) it = next_ans(it);
            erase(deque, it);

            if (i % 10 == 0) print_deque_simple(deque);
        }

        destroy_deque(deque);
    } else if (T == 24) {
        register_case(T, "Test store and load deque");

        Deque deque = create_deque();

        for (int i = 1; i <= 30; ++i) {
            push_back(deque, 2 * i - 2);
        }
        print_deque_simple(deque);
        store_deque(deque, "cute_deque.txt");
        cout << "Successfully store deque to cute_deque.txt" << endl;

        Deque loaded_deque = load_deque("cute_deque.txt");
        print_deque_simple(loaded_deque);
        store_deque(loaded_deque, "another_deque.txt");
        cout << "Successfully store deque to another_deque.txt" << endl;

        Deque loaded_deque2 = load_deque("another_deque.txt");
        print_deque_simple(loaded_deque2);

        destroy_deque(deque);
        destroy_deque(loaded_deque);
        destroy_deque(loaded_deque2);
    }else if (T == 25) {
        register_case(T, "Test store and load an empty deque");

        Deque deque = create_deque();

        print_deque_simple(deque);
        store_deque(deque, "cute_deque.txt");
        cout << "Successfully store deque to cute_deque.txt" << endl;

        Deque loaded_deque = load_deque("cute_deque.txt");
        print_deque_simple(loaded_deque);

        destroy_deque(deque);
        destroy_deque(loaded_deque);
    }

    // for Deque_Iterator tests
    delete node1;
    delete node2;
    delete sentinel;
}