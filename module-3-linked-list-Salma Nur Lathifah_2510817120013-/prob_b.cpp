#include "double_linked_list.h"
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int banyak_karakter, banyak_ronde;
    if (!(std::cin >> banyak_karakter >> banyak_ronde)) return 0;

    DoubleLinkedList list_dimensi;
    list_dimensi.init();
    
    for (int i = 0; i < banyak_karakter; i++) {
        char karakter;
        std::cin >> karakter;
        list_dimensi.add_back(karakter);
    }

    if (list_dimensi.is_empty()) {
        std::cout << "EMPTY" << std::endl;
        return 0;
    }

    Node* ptr_alpha = list_dimensi.head;
    Node* ptr_beta = list_dimensi.tail;

    for (int i = 0; i < banyak_ronde; i++) {
        long long langkah_alpha, langkah_beta;
        if (!(std::cin >> langkah_alpha >> langkah_beta)) break;
        if (list_dimensi.size == 0) break;

        long long step_alpha = langkah_alpha % list_dimensi.size;
        for (long long j = 0; j < step_alpha; j++) {
            ptr_alpha = (ptr_alpha->next != nullptr) ? ptr_alpha->next : list_dimensi.head;
        }

        long long step_beta = langkah_beta % list_dimensi.size;
        for (long long j = 0; j < step_beta; j++) {
            ptr_beta = (ptr_beta->prev != nullptr) ? ptr_beta->prev : list_dimensi.tail;
        }

        if (ptr_alpha == ptr_beta) {
            Node* ptr_crash = ptr_alpha;
            Node* next_alpha = (ptr_crash->next != nullptr) ? ptr_crash->next : list_dimensi.head;
            Node* prev_beta = (ptr_crash->prev != nullptr) ? ptr_crash->prev : list_dimensi.tail;

            int idx_delete = 0;
            Node* ptr_navigasi = list_dimensi.head;
            while (ptr_navigasi != ptr_crash) {
                ptr_navigasi = ptr_navigasi->next;
                idx_delete++;
            }

            list_dimensi.delete_idx(idx_delete);

            if (list_dimensi.size == 0) {
                ptr_alpha = ptr_beta = nullptr;
                break;
            } else {
                ptr_alpha = (next_alpha == ptr_crash) ? list_dimensi.head : next_alpha;
                ptr_beta = (prev_beta == ptr_crash) ? list_dimensi.tail : prev_beta;
            }
        } 
        else if (ptr_alpha->next == ptr_beta || ptr_alpha->prev == ptr_beta) {
            char temp_data = ptr_alpha->data;
            ptr_alpha->data = ptr_beta->data;
            ptr_beta->data = temp_data;
        }
    }

    if (list_dimensi.size == 0) {
        std::cout << "EMPTY" << std::endl;
    } else {
        list_dimensi.display();
        std::cout << "\n";
    }

    list_dimensi.clear();
    return 0;
}