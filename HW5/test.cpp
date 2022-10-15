#include <iostream>
#include "Deque.h"
using namespace std;

void fancy_print_deque(const Deque &d) {
    cout << "deque is now:\n\t";
    cout << "empty: " << (empty(d) ? "yes" : "no") << ", length: " << size(d) << "\n";
    cout << "\t";
    print_deque(d);

#define addr(at) (((long long) (at) & 0xFFFF) >> 2)

    // cout << "[size: " << size(d) << ", empty: " << empty(d) << "]" << endl;
    // cout << "start: " << addr(d.start.current) << ", end: " << addr(d.end.current) << 
    //     ", next(end): " << addr(next(d.end.current)) << ", size: " << d.ll_size <<
    //     ", sen->arr: " << addr(d.sentinel->arr) << endl;

    // Node* node = d.sentinel;
    // node = node->next;
    // while (node != d.sentinel) {
    //     cout << "[";
    //     for (int i = 0; i < CHUNK_SIZE; i++) {
    //         if (node->arr+i == d.start.current || node->arr+i == prev(d.end).current) {
    //             cout << "*" << addr(node->arr+i) << "*: " << (((d.start.node == node && node->arr+i < d.start.current) || (d.end.node == node && node->arr+i >= d.end.current)) ? 0 : node->arr[i]) << ", ";
    //         } else {
    //             cout << addr(node->arr+i) << ": " << (((d.start.node == node && node->arr+i < d.start.current) || (d.end.node == node && node->arr+i >= d.end.current)) ? 0 : node->arr[i])  << ", ";
    //         }
    //     }
    //     cout << "]\n";
    //     node = node->next;
    // }
}

int main() {
    Deque d = create_deque();

    while (true) {
        cout << "-+= Welcome to the deque testing centre human =+-\n";
        cout << "p - print the deque.\n";
        cout << "f - push front.\n";
        cout << "b - push back.\n";
        cout << "a - pop front.\n";
        cout << "d - pop back.\n";
        cout << "g - get front & back.\n";
        cout << "i - insert at position.\n";
        cout << "e - erase at position.\n";
        cout << "l - test load and save.\n";
        cout << "q - quit.\n";
        cout << "\nyour choice: ";

        char choice;
        cin >> choice;

        int val;
        int pos;
        Iterator it = begin(d);
        
        switch(choice) {
            case 'p': fancy_print_deque(d); break;
            case 'f':
                cout << "value to push front: ";
                cin >> val;
                push_front(d, val);

                cout << "\n=============\n";
                cout << "your action: PUSH FRONT " << val << "\n";
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'b':
                cout << "value to push back: ";
                cin >> val;
                push_back(d, val);
                cout << "\n=============\n";
                cout << "your action: PUSH BACK " << val << "\n";
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'a':
                    cout << "\n=============\n";
                cout << "your action: POP FRONT\n";
                pop_front(d); 
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'd':
                    cout << "\n=============\n";
                cout << "your action: POP BACK\n";
                pop_back(d); 
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'g':
                cout << "front:\t" << front(d) << "\n";
                cout << "back:\t" << back(d) << "\n";
                break;
            case 'i':
                cout << "position to push to: ";
                cin >> pos;
                cout << "value to insert: ";
                cin >> val;
                for (int i = 0; i < pos; ++i) it = next(it);
                insert(d, it, val);
                cout << "\n=============\n";
                cout << "your action: BEFORE POSITION " << pos << ", INSERT " << val << "\n"; 
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'e':
                cout << "position to erase: ";
                cin >> pos;
                for (int i = 0; i < pos; ++i) it = next(it);
                erase(d, it);
                cout << "\n=============\n";
                cout << "your action: ERASE POSITION " << pos << "\n";
                fancy_print_deque(d);
                cout << "=============\n";
                break;
            case 'l':
                cout << "The deque now is: ";
                print_deque(d);

                store_deque(d, "deque_demo.txt");
                cout << "Successfully stored deque to 'deque_demo.txt'" << endl;

                destroy_deque(d);

                d = load_deque("deque_demo.txt");
                cout << "The restored deque is: ";
                fancy_print_deque(d);
                break;
            case 'q':
                destroy_deque(d);
                return 0;
            default:
                break;
        }
    }

    return 0;
}
