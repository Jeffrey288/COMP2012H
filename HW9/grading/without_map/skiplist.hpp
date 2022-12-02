#include <stdlib.h>

extern std::minstd_rand pa9_rand;

template <typename K, typename V>
class Skiplist {
    public:
        struct Node {
            K key;
            V value;
            Node** nexts;
            int levels;

            Node(); //nexts = new Node*[1]; levels = 1
            Node(K key, V value, int levels); //nexts = new Node*[1]; levels = 1
            ~Node();

            Node(std::string grading);
            Node(std::string grading, K key, V value, int levels);
        };

    private:
        Node* head;   //Head node
        double prob;

        //Function to get random number of levels
        int getRandomLevels() const {
            int lvl = 1;
            while(pa9_rand() % 1000000 < 1000000 * prob)
               lvl += 1;
            return lvl;
        }

    public:
        Skiplist(double prob = 0.25); //Constructor for empty skiplist
        Skiplist(const Skiplist& other);
        ~Skiplist();

        bool get(const K& get_key, V& rtn_value) const;
        void update(const K& update_key, const V& update_value);
        bool remove(const K& remove_key);

        int size() const;
        bool empty() const;
        void print() const;

        template <typename T>
        Skiplist<K, T> map(T (*f)(V value)) const;
        Skiplist<K, V> filter(bool (*f)(V value)) const;

        Skiplist<K, V>& operator=(const Skiplist& other);
        Skiplist<K, V> operator+(const Skiplist& other) const;

        void print_full() const {
            std::cout << "========== Skiplist content ==========" << std::endl;
            std::cout << "Prob: " << this->prob << std::endl;
            
            for (Node* curr = this->head; curr != nullptr; curr = curr->nexts[0]) {
                if (curr == this->head) {
                    std::cout << "HEAD" << std::endl;
                } else {
                    std::cout << "Key: " << curr->key << std::endl;
                    std::cout << "Value: " << curr->value << std::endl;
                }
                std::cout << "Levels: [";
                for (int i = 0; i < curr->levels - 1; i++) {
                    if (curr->nexts[i] != nullptr)
                        std::cout << curr->nexts[i]->key;
                    else
                        std::cout << "nullptr";
                    std::cout << ", ";
                }
                if (curr->nexts[curr->levels - 1] != nullptr)
                    std::cout << curr->nexts[curr->levels - 1]->key;
                else
                    std::cout << "nullptr";
                std::cout << "]" << std::endl;
                std::cout << "======================================" << std::endl;
            }
        }

        Skiplist(std::string grading, double prob = 0.25);
        void grade_update(const K& update_key, const V& update_value);
        bool grade_get(const K& get_key, V& rtn_value) const;
        bool grade_remove(const K& remove_key);
        void grade_print() const;
};

#include "skiplist.tpp"
#include "skiplist_grading.tpp"