#include <iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int capacity;
    int size;

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Insert element
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        int i = size;
        arr[size++] = key;

        // Fix max heap property (bubble up)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify (downward)
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Extract maximum element
    int extractMax() {
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
    MaxHeap h(10);

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(6);
    h.insert(30);

    cout << "Max Heap: ";
    h.printHeap();

    cout << "Extracted Max: " << h.extractMax() << endl;

    cout << "After extraction: ";
    h.printHeap();

    return 0;
}