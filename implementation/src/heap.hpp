#pragma once

#include <vector>

using std::vector;

enum heap_mode_e {
    MIN,
    MAX
};

template <typename T>
struct heap_item_t {
    int key;
    T data;

    heap_item_t(int keyA, T& dataA) {
        key = keyA;
        data = T(dataA);
    }

    heap_item_t<T> operator=(const heap_item_t<T>& new_value) {
        if(this != &new_value) {
            key = new_value.key;
            data = T(new_value.data);
        }
    }
};

template <class T>
class Heap {
    private:
        int mode;
        vector<heap_item_t<T>> heap;
        void heapify(int i);
        int parent(int i);
        int l_child(int i);
        int r_child(int i);
    public:
        Heap(heap_mode_e heap_type, vector<heap_item_t<T>> &items);
        heap_mode_e get_mode();
        heap_item_t<T> pop();
        void insert(heap_item_t<T> item);
};