#include <iostream>
using namespace std;

class MinHeap {
    int* arr;
    int capacity;
    int size;

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    // Get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get left child index
    int left(int i) { return 2 * i + 1; }

    // Get right child index
    int right(int i) { return 2 * i + 2; }

    // Insert element
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // Insert at end
        int i = size;
        arr[size++] = key;

        // Fix the min heap property
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify (downward)
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Extract minimum element
    int extractMin() {
        if (size <= 0)
            return -1;

        if (size == 1)
            return arr[--size];

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
        return root;
    }

    // Display heap
    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(6);
    h.insert(1);

    cout << "Min Heap: ";
    h.printHeap();

    cout << "Extracted Min: " << h.extractMin() << endl;

    cout << "After extraction: ";
    h.printHeap();

    return 0;
}