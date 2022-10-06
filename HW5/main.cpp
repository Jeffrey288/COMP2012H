#include <iostream>
#include "Deque.h"
using namespace std;

// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>

void test_create_destroy() {
    cout << "===== Test create and destroy deque =====" << endl;
    Deque deque = create_deque();
    cout << "Deque created" << endl;

    if (deque.sentinel == nullptr) {
        cout << "[FAIL] sentinel node for empty deque should not be nullptr" << endl;
    }

    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "Deque destroyed" << endl;

    cout << "===== End Test =====" << endl << endl;
}

void test_push_back() {
    cout << "===== Test push back =====" << endl;
    Deque deque = create_deque();

    push_back(deque, 10);
    push_back(deque, 2012);
    push_back(deque, 2022);

    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_push_front() {
    cout << "===== Test push front =====" << endl;
    Deque deque = create_deque();

    push_front(deque, 10);
    push_front(deque, 2012);
    push_front(deque, 2022);

    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_front_back() {
    cout << "===== Test get front and back =====" << endl;
    Deque deque = create_deque();

    // when deque is empty, the returned value doesn't matter
    int front_item = front(deque);
    int back_item = back(deque);

    push_back(deque, 10);
    front_item = front(deque);
    back_item = back(deque);
    cout << "front: " << front_item << ", back: " << back_item << endl;

    push_back(deque, 15);
    front_item = front(deque);
    back_item = back(deque);
    cout << "front: " << front_item << ", back: " << back_item << endl;

    push_front(deque, 20);
    front_item = front(deque);
    back_item = back(deque);
    cout << "front: " << front_item << ", back: " << back_item << endl;

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_empty_size() {
    cout << "===== Test empty and size =====" << endl;
    Deque deque = create_deque();

    cout << "deque is empty: " << (empty(deque) ? "true" : "false") << endl;
    cout << "size of deque: " << size(deque) << endl;

    push_back(deque, 10);
    cout << "deque is empty: " << (empty(deque) ? "true" : "false") << endl;
    cout << "size of deque: " << size(deque) << endl;

    push_back(deque, 15);
    cout << "deque is empty: " << (empty(deque) ? "true" : "false") << endl;
    cout << "size of deque: " << size(deque) << endl;

    push_front(deque, 20);
    cout << "deque is empty: " << (empty(deque) ? "true" : "false") << endl;
    cout << "size of deque: " << size(deque) << endl;

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_pop_back() {
    cout << "===== Test pop back =====" << endl;
    Deque deque = create_deque();

    pop_back(deque);

    push_back(deque, 10);
    push_back(deque, 15);
    push_front(deque, 20);

    cout << "The deque now is: ";
    print_deque(deque);

    pop_back(deque);
    cout << "The deque now is: ";
    print_deque(deque);

    pop_back(deque);
    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_pop_front() {
    cout << "===== Test pop front =====" << endl;
    Deque deque = create_deque();

    pop_front(deque);

    push_back(deque, 10);
    push_back(deque, 15);
    push_front(deque, 20);

    cout << "The deque now is: ";
    print_deque(deque);

    pop_front(deque);
    cout << "The deque now is: ";
    print_deque(deque);

    pop_front(deque);
    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_insert() {
    cout << "===== Test insert =====" << endl;
    Deque deque = create_deque();

    push_back(deque, 10);
    push_back(deque, 15);
    push_back(deque, 25);

    cout << "The deque now is: ";
    print_deque(deque);

    insert(deque, begin(deque), 5);
    cout << "The deque now is: ";
    print_deque(deque);

    insert(deque, prev(end(deque)), 20);
    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_erase() {
    cout << "===== Test erase =====" << endl;
    Deque deque = create_deque();

    push_back(deque, 10);
    push_back(deque, 15);
    push_back(deque, 25);

    cout << "The deque now is: ";
    print_deque(deque);

    erase(deque, begin(deque));
    cout << "The deque now is: ";
    print_deque(deque);

    erase(deque, prev(end(deque)));
    cout << "The deque now is: ";
    print_deque(deque);

    destroy_deque(deque);
    cout << "===== End Test =====" << endl << endl;
}

void test_store_load() {
    cout << "===== Test store and load deque =====" << endl;
    Deque deque = create_deque();

    push_back(deque, 10);
    push_back(deque, 15);
    push_back(deque, 25);

    cout << "The deque now is: ";
    print_deque(deque);

    store_deque(deque, "deque_demo.txt");
    cout << "Successfully stored deque to 'deque_demo.txt'" << endl;

    destroy_deque(deque);

    Deque restored_deque = load_deque("deque_demo.txt");
    cout << "The restored deque is: ";
    print_deque(restored_deque);
    destroy_deque(restored_deque);

    cout << "===== End Test =====" << endl;
}

void test_gen_big_deque() {

    Deque deque = create_deque();
    for (int i = 0; i < 16; i++) {
        // push_back(deque, i);
        insert(deque, end(deque), i);
        cout << "front: " << front(deque) << ", back: "<< back(deque) << " "; print_deque(deque);
    }
    for (int i = 0; i < 10; i++) {
        // push_front(deque, -i);
        insert(deque, begin(deque), -i);
        cout << "front: " << front(deque) << ", back: "<< back(deque) << " "; print_deque(deque);
    }
    for (int i = 0; i < 22; i++) {
        Iterator it = begin(deque);
        for (int j = 0; j < 3 * i % 5 + i / 7; j++) {
            it = next(it);
        }
        // push_front(deque, -i);
        insert(deque, it, i);
        cout << "front: " << front(deque) << ", back: "<< back(deque) << " "; print_deque(deque);
    }
    store_deque(deque, "sanity_test.txt");
    Deque deque2 = load_deque("sanity_test.txt");
    // for (int i = 0; i < 46; i++) {
    //     // pop_front(deque);
    //     erase(deque2, begin(deque2));
    //     print_deque(deque2);
    // }
    // for (int i = 0; i < 46; i++) {
    //     // pop_front(deque);
    //     erase(deque2, prev(end(deque2)));
    //     print_deque(deque2);
    // }
    
    for (int i = 0; i < 48; i++) {
        Iterator it = begin(deque2);
        for (int j = 0; j < (46-i)/2; j++) {
            it = next(it);
        }
        erase(deque2, it);
        cout << "size " << size(deque2) << " "; print_deque(deque2);
    }
    destroy_deque(deque);
    destroy_deque(deque2);
    // cout << "destroy! " << endl;

}

int main() {
    test_create_destroy();
    test_push_back();
    test_push_front();
    test_front_back();
    test_empty_size();
    test_pop_back();
    test_pop_front();
    test_insert();
    test_erase();
    test_store_load();

    test_gen_big_deque();
    // test_gen_big_deque();
    // test_gen_big_deque();
    // test_gen_big_deque();
    // test_gen_big_deque();
    // test_gen_big_deque();
    // _CrtDumpMemoryLeaks();

    return 0;
}