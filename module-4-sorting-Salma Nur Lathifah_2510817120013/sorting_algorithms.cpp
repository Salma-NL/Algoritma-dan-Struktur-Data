#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0) {
            m.comparisons++;
            if (data[j] > key) {
                data[j + 1] = data[j];
                m.shifts++;
                j--;
            } else {
                break;
            }
        }
        data[j + 1] = key;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void merge_helper(std::vector<int>& data, int left, int mid, int right, Metrics& m) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> Left(n1), Right(n2);
    for (int i = 0; i < n1; i++) Left[i] = data[left + i];
    for (int j = 0; j < n2; j++) Right[j] = data[mid + 1 + j];

    int i = 0, j = 0, targetIndex = left;
    while (i < n1 && j < n2) {
        m.comparisons++;
        if (Left[i] <= Right[j]) {
            data[targetIndex] = Left[i];
            i++;
        } else {
            data[targetIndex] = Right[j];
            j++;
        }
        targetIndex++;
    }

    while (i < n1) {
        data[targetIndex] = Left[i];
        i++;
        targetIndex++;
    }
    while (j < n2) {
        data[targetIndex] = Right[j];
        j++;
        targetIndex++;
    }
}

void merge_sort_recursive(std::vector<int>& data, int left, int right, Metrics& m) {
    m.recursive_calls++;
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_recursive(data, left, mid, m);
    merge_sort_recursive(data, mid + 1, right, m);
    merge_helper(data, left, mid, right, m);
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    merge_sort_recursive(data, 0, data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}




int partition_helper(std::vector<int>& data, int low, int high, Metrics& m) {
    int mid = low + (high - low) / 2;
    
    if (mid != high) {
        std::swap(data[mid], data[high]);
        m.swaps++;
    }

    int pivot = data[high];
    int i = low - 1;
 
    for (int j = low; j < high; j++) {
        m.comparisons++;
        if (data[j] < pivot) {
            i++;
            if (i != j) {
                std::swap(data[i], data[j]);
                m.swaps++;
            }
        }
    }
    
    if (i + 1 != high) {
        std::swap(data[i + 1], data[high]);
        m.swaps++;
    }
    
    return i + 1;
}

void quick_sort_recursive(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;
    if (low < high) {
        int pi = partition_helper(data, low, high, m);
        quick_sort_recursive(data, low, pi - 1, m);
        quick_sort_recursive(data, pi + 1, high, m);
    }
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    quick_sort_recursive(data, 0, data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void counting_sort_for_radix(std::vector<int>& data, int exp, Metrics& m) {
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses++; 
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        m.array_accesses++;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses += 2;
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int max_val = data[0];
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_for_radix(data, exp, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}