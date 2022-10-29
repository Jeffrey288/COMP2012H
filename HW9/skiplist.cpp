#include "skiplist.hpp"

template <typename K, typename V>
Skiplist<K, V>::Node::Node() {
    nexts = new Skiplist<K, V>::Node*[1];
    levels = 1;
}

template <typename K, typename V>
Skiplist<K, V>::Node::Node(K key, V value, int levels) {
    nexts = new Skiplist<K, V>::Node*[levels];
    this->levels = levels;
    this->key = key;
    this->value = value;
}

template <typename K, typename V>
Skiplist<K, V>::Node::~Node() {
    delete [] nexts;
}

template <typename K, typename V>
Skiplist<K, V>::Skiplist(double prob) {
    this->prob = prob;
    head = new Node();
}

template <typename K, typename V>
Skiplist<K, V>::~Skiplist() {
    Node* prevNode = head;
    Node* curNode = prevNode->nexts[0];
    for (; prevNode; prevNode = curNode) {
        if (curNode) curNode = curNode->nexts[0];
        delete prevNode;
    }
}

template <typename K, typename V>
Skiplist<K, V>& Skiplist<K, V>::operator=(const Skiplist<K, V>& other) {
    // First, delete the old skiplist except the sentinel node
    Node* prevNode = head->nexts[0];
    if (prevNode) {
        Node* curNode = prevNode->nexts[0];
        for (; prevNode; prevNode = curNode) {
            if (curNode) curNode = curNode->nexts[0];
            delete prevNode;
        }
    }

    // Then, deep copy everything from the given skiplist
    this->prob = other.prob;

    // First, copy the sentinel node
    int height = other.head.levels;
    delete [] this->head.nexts;
    this->head.nexts = new Node*[height];

    // Stores the current rightmost node of each level
    Node* rightmostNodes = new Node*[height];
    // initialize it with the sentinel node
    for (int i = 0; i < height; i++) {
        rightmostNodes[i] = this->head;
    }

    // Create the nest of the nodes
    for (Node* node = other.head->nexts[0]; node; node = node->nexts[0]) {
        Node* curNode = new Node(node.key, node.value, node.levels);
        for (int i = 0; i < node.levels; i++) {
            rightmostNodes[i]->nexts[i] = curNode;
            rightmostNodes[i] = curNode;
        }
    }

    // Assign nullptr to the rest
    for (int i = 0; i < height; i++) {
        rightmostNodes[i]->next[i] = nullptr;
    }
    delete [] rightmostNodes;
}

template <typename K, typename V>
Skiplist<K, V>::Skiplist(const Skiplist<K, V>& other) {
    *this = other;
}

template <typename K, typename V>
bool Skiplist<K, V>::get(const K& get_key, V& rtn_value) const {
    int curLevel = head.levels;
    Node* curNode = head; // guarunteed to not be a nullptr
    while (curLevel >= 0) {
        if (curNode->nexts[curLevel]) {
            if (curNode->nexts[curLevel].key == get_key) {
                rtn_value = curNode->nexts[curLevel].val;
                return true;
            } else if (curNode->nexts[curLevel].key > get_key) {
                curLevel--;
            } else {
                curNode = curNode->nexts[curLevel];
            }
        } else {
            curLevel--;
        }
    }
    return false;
}

template <typename K, typename V>
void Skiplist<K, V>::update(const K& update_key, const V& update_value) {
    // find if the key exists
    int curLevel = head.levels;
    Node* curNode = head;
    Node** rightmostNodes = new Node*[head.levels];
    while (curLevel >= 0) {
        if (curNode->nexts[curLevel]) {
            if (curNode->nexts[curLevel].key == update_key) {
                curNode->nexts[curLevel].val = update_value;
                delete [] rightmostNodes;
                return;
            } else if (curNode->nexts[curLevel].key > update_key) {
                rightmostNodes[curLevel] = curNode;
                curLevel--;
            } else {
                curNode = curNode->nexts[curLevel];
            }
        } else {
            curLevel--;
        }
    }
    
    // now if it is not found, the rightmostnodes is just LESS than the update_key
    Node* newNode = new Node(update_key, update_value, getRandomLevels());
    for (int i = 0; i < head->levels; i++) {
        newNode->nexts[i] = rightmostNodes[i]->nexts[i];
        rightmostNodes[i]->nexts[i] = newNode;
    }
    if (newNode->levels > head->levels) {
        Node** newNexts = new Node*[newNode->levels];
        int i = 0;
        for (; i < head->levels; i++) {
            newNexts[i] = head->nexts[i];
        }
        for (; i < newNode->levels; i++) {
            newNexts[i] = newNode;
            newNode->nexts[i] = nullptr;
        }
    }
    delete [] rightmostNodes;
}

template <typename K, typename V>
bool Skiplist<K,V>::remove(const K& remove_key) {
    // find if the key exists
    int curLevel = head.levels;
    Node* curNode = head;
    Node** rightmostNodes = new Node*[head.levels];
    bool deleteFlag = false;
    while (curLevel >= 0) {
        if (curNode->nexts[curLevel]) {
            if (curNode->nexts[curLevel].key == remove_key) {
                deleteFlag = true;
                rightmostNodes[curLevel] = curNode;
                curLevel--;
            } else if (curNode->nexts[curLevel].key > remove_key) {
                rightmostNodes[curLevel] = curNode;
                curLevel--;
            } else {
                curNode = curNode->nexts[curLevel];
            }
        } else {
            curLevel--;
        }
    }

    if (deleteFlag) {
        // rightmostNodes now store all nodes immediately LESS than curNode, and
        Node* delNode = curNode->nexts[curLevel];
        int i;
        for (i = 0; i < head.levels; i++) {
            rightmostNodes[i]->nexts[i] = delNode->nexts[i];
            if (rightmostNodes[i]->nexts[i] == head) {
                break;
            }
        }
        if (i < head.levels) {
            Node** newNexts = new Node*[i];
            for (int j = 0; j < i; i++) {
                newNexts[j] = head->nexts[i];
            }
            delete [] head->nexts;
            head->nexts = newNexts;
        }
        delete delNode;
   
    }
    delete [] rightmostNodes;
}

template <typename K, typename V>
int Skiplist<K,V>::size() const {
    int i = 0;
    for (Node* node = head->nexts[0]; node; node = node->nexts[0], i++);
    return i;
}

template <typename K, typename V>
bool Skiplist<K,V>::empty() const {
    return (head->nexts[0] == nullptr);
}

template <typename K, typename V>
void Skiplist<K,V>::print() const {
    std::cout << "{";
    for (Node* node = head->nexts[0]; node; node = node->nexts[0]) {
        std::cout << node->key << ": " << node->value;
        if (node->nexts[0]) {
            std::cout << ",";
        }
    }
    std::cout << "}";
}

template <typename K, typename V>
template <typename T>
Skiplist<K, T> Skiplist<K,V>::map(T (*f)(V value)) const {

}

template <typename K, typename V>
Skiplist<K,V> Skiplist<K,V>::filter(bool (*f)(V value)) const {
    // Skiplist<K,T> newList(prob);
    // for (Node* node = head->nexts[0]; node; node = node->nexts[0]) {
    //     newList.
    // }
    // cout << "}";
}

template <typename K, typename V>
Skiplist<K,V> Skiplist<K,V>::operator+(const Skiplist<K,V>& other) const {

}