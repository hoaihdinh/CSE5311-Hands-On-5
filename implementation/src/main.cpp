#include <chrono>
#include <iostream>
#include <sstream>

#include "heap.hpp"

int main() {
    vector<int> data = {33, 28, 13, 26, 22, 48, 38, 1, 41, 29, 3, 28, 26, 32, 18};
    vector<heap_item_t<int>> heap_item_data = {};
    for(int i = 0; i < data.size(); i++) {
        heap_item_data.push_back({data[i], data[i]});
    }

    Heap<int> heap(heap_mode_e::MIN, heap_item_data);

    return 0;
}