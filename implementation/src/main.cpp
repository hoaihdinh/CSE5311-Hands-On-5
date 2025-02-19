#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>

using std::vector;

template <typename T>
struct heap_item_t {
    int key;
    T data;

    heap_item_t(int keyA, T dataA) {
        key = keyA;
        data = dataA;
    }

    void operator=(const heap_item_t<T>& new_value) {
        if(this != &new_value) {
            key = new_value.key;
            data = new_value.data;
        }
    }
};

template <class T>
class Heap {
    private:
        vector<heap_item_t<T>> heap;
        void heapify(int i) {
            int l = l_child(i);
            int r = r_child(i);
            int chosen_idx = i;
            int heap_size = heap.size();

            if (l < heap_size && heap[l].key < heap[chosen_idx].key) {
                    chosen_idx = l;
            }
            if (r < heap_size && heap[r].key < heap[chosen_idx].key) {
                    chosen_idx = r;
            }
            if(chosen_idx != i) {
                std::swap(heap[chosen_idx], heap[i]);
                heapify(chosen_idx);
            }
        }

        int parent(int i) {
            return (i - 1) >> 1;
        }

        int l_child(int i) {
            return (i << 1) + 1;
        }

        int r_child(int i) {
            return (i << 1) + 2;
        }
    public:
        Heap(vector<heap_item_t<T>> &items) {
            heap = items;
            for(int i = parent(items.size() - 1); i >= 0; i--) {
                heapify(i);
            }
        }

        T pop() {
            if(heap.empty()) {
                throw std::runtime_error("Empty heap");
            }
            heap_item_t<T> temp(heap[0].key, heap[0].data);
            heap[0] = heap.back();
            heap.back() = temp;
            heap.pop_back();
            heapify(0);
            return temp.data;
        }

        void print_heap() {
            std::cout << "Heap: ";
            for(int i = 0; i < heap.size(); i++) {
                std::cout << heap[i].data << " ";
            }
            std::cout << std::endl;
        }
};

int main() {
    vector<int> data = {33, 28, 13, 26, 22, 48, 38, 1, 41, 29, 3, 28, 26, 32, 18};
    vector<heap_item_t<int>> heap_item_data = {};
    std::cout << "Data: ";
    for(int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
        heap_item_data.push_back({data[i], data[i]});
    }
    std::cout << std::endl;

    Heap<int> heap(heap_item_data);

    vector<int> pop_order = {};

    for(int i = 0; i < data.size(); i++) {
        heap.print_heap();
        int popped = heap.pop();
        pop_order.push_back(popped);
        std::cout << "Pop: " << popped << std::endl;
    }

    std::cout << "Pop order: ";
    for(int i = 0; i < data.size(); i++) {
        std::cout << pop_order[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}