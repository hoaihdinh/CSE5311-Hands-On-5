#include "heap.hpp"

/* === Constructors === */
template <class T>
Heap<T>::Heap(heap_mode_e heap_type, vector<heap_item_t<T>> &items) {
    mode = heap_type;
    heap = new vector<heap_item_t<T>>(items);
    for(int i = parent(items.size() - 1); i >= 0; i--) {
        heapify(i);
    }
}


/* === Public Methods === */
template <class T>
heap_mode_e Heap<T>::get_mode() {
    return mode;
}

template <class T>
heap_item_t<T> Heap<T>::pop() {
    if(heap.empty()) {
        return NULL;
    }
    T root = heap[0];
    heap_item_t<T> temp = new heap_item_t<T>(heap[0].key, heap[0].data);
    heap[0] = heap.back();
    heap.back() = temp;
    heap.pop_back();
    return temp;
}

/* === Private Methods ===*/
template <class T>
void Heap<T>::heapify(int i) {
    int l = l_child(i);
    int r = r_child(i);
    int chosen_idx = i;
    int heap_size = heap.size();

    if ((mode == heap_mode_e::MAX && l < heap_size && heap[l] > heap[chosen_idx]) ||
        (mode == heap_mode_e::MIN && l < heap_size && heap[l] < heap[chosen_idx])) {
            chosen_idx = l;
    }
    if ((mode == heap_mode_e::MAX && r < heap_size && heap[r] > heap[chosen_idx]) ||
        (mode == heap_mode_e::MIN && r < heap_size && heap[r] < heap[chosen_idx])) {
            chosen_idx = r;
    }
    if(chosen_idx != i) {
        heap_item_t<T> temp = new heap_item_t(heap[chosen_idx].key, heap[chosen_idx].data);
        heap[chosen_idx] = heap[i];
        heap[i] = temp;
    }
}

template <class T>
int Heap<T>::parent(int i) {
    return (i - 1) >> 1;
}

template <class T>
int Heap<T>::l_child(int i) {
    return (i << 1) + 1;
}

template <class T>
int Heap<T>::r_child(int i) {
    return (i << 1) + 2;
}