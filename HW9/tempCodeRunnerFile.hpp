for (Node* curr = this->head; curr != nullptr; curr = curr->nexts[0]) {
            //     if (curr == this->head) {
            //         std::cout << "HEAD" << std::endl;
            //     } else {
            //         std::cout << "Key: " << curr->key << std::endl;
            //         std::cout << "Value: " << curr->value << std::endl;
            //     }
            //     std::cout << "Levels: [";
            //     for (int i = 0; i < curr->levels - 1; i++) {
            //         if (curr->nexts[i] != nullptr)
            //             std::cout << curr->nexts[i]->key;
            //         else
            //             std::cout << "nullptr";
            //         std::cout << ", ";
            //     }
            //     if (curr->nexts[curr->levels - 1] != nullptr)
            //         std::cout << curr->nexts[curr->levels - 1]->key;
            //     else
            //         std::cout << "nullptr";
            //     std::cout << "]" << std::endl;
            //     std::cout << "======================================" << std::endl;
            // }