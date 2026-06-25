#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    int A[MAX];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i <= n - k; i++) {
        int current_sum = 0;
        Queue q;
        init(&q);

        for (int j = i; j < i + k; j++) {
            enqueue(&q, A[j]);
            current_sum += A[j];
        }

        std::cout << current_sum << (i == n - k ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}