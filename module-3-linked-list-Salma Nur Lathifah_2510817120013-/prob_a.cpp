#include "single_linked_list.h"
#include <iostream>

int main() {
    int jumlah_batu;
    long long langkah_awal;
    
    if (!(std::cin >> jumlah_batu >> langkah_awal)) return 0;

    SingleLinkedList list_batu;
    list_batu.init();

    for (int i = 0; i < jumlah_batu; i++) {
        int nilai_batu;
        std::cin >> nilai_batu;
        list_batu.add_back(nilai_batu);
    }

    int ptr_indeks_sekarang = 0; 
    long long langkah_sekarang = langkah_awal;

    while (list_batu.size > 1) {
        long long indeks_target = (ptr_indeks_sekarang + langkah_sekarang - 1) % list_batu.size;
        
        if (indeks_target < 0) indeks_target += list_batu.size;
        
        int batu_hancur = list_batu.get(indeks_target);
        list_batu.delete_idx(indeks_target);

        if (batu_hancur % 2 == 0) {
            langkah_sekarang++;
        } else {
            langkah_sekarang--;
        }

        if (langkah_sekarang <= 0) {
            langkah_sekarang = langkah_awal;
        }

        ptr_indeks_sekarang = indeks_target;
        if (ptr_indeks_sekarang >= list_batu.size) {
            ptr_indeks_sekarang = 0;
        }
    }

    std::cout << list_batu.get(0) << std::endl;
    list_batu.clear();

    return 0;
}