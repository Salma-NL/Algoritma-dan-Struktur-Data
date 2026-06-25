#include "searching_algorithms.h"
#include <chrono>



using Clock = std::chrono::high_resolution_clock;


void linear_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

    m.found_index = -1;
    m.comparisons = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        m.comparisons++;
        if (data[i] == target) {
            m.found_index = static_cast<long long>(i);
            break;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}



void binary_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

    m.found_index = -1;
    m.comparisons = 0;

    int low = 0;
    int high = static_cast<int>(data.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        m.comparisons++;

        if (data[mid] == target) {
            m.found_index = mid;
            break;
        } else if (data[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}