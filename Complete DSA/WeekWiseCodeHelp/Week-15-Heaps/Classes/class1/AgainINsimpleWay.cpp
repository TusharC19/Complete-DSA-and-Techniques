#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int capacity;
    int idx;
    int *heap;
    // vector<int>heap;

    Heap(int capacity)
    {
        this->capacity = capacity;
        heap = new int[capacity];
        // heap(capacity,0);
        idx = 0;
        heap[0] = 0;
    }

    ~Heap() { cout << "dtor called" << endl; }

    void printHeap()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void insert(int val)
    {
        // that is
        if (idx == capacity - 1)
        {
            cout << "overflow" << endl;
            return;
        }

        idx++;
        heap[idx] = val;

        int curridx = idx;
        while (curridx > 1)
        {
            int parentidx = curridx / 2;

            if (heap[curridx] > heap[parentidx])
            {
                swap(heap[curridx], heap[parentidx]);
                curridx = parentidx;
            }
            else
            {
                // nhi hai chota parent
                break;
            }
        }
    }

    /*
    void heapify(int* heap,int n,int curridx){
        // base case not needed here
        int leftnodeidx = curridx*2;
        int rightnodeidx = curridx*2 + 1;


        // let largest element at curridx itself
        int largestidx = curridx;

        // leftcheck
        // n = no of elements
        if(leftnodeidx < n && heap[leftnodeidx]>heap[largestidx]){
            largestidx = leftnodeidx;
        }

        if(rightnodeidx<n && heap[rightnodeidx]>heap[largestidx]){
            largestidx = rightnodeidx;
        }

        if(largestidx != curridx){
            swap(heap[curridx],heap[largestidx]);
            heapify(heap,n,curridx);
        }

    }
    */

    void deleteFromHeap()
    {
        // step1: swap first and last
        swap(heap[1], heap[idx]);
        heap[idx] = 0;

        // decrese the index to delete
        idx--;

        // place the root node to its correct position
        // heapify(heap, idx, 1);
    }
};

void heapify(int *arr, int n, int currIdx)
{
    // n - no of elements
    int i = currIdx; // jis element ko replace krna hai
    int leftIdx = 2 * i;
    int rightIdx = 2 * i + 1;

    int largestIdx = i;

    if (leftIdx < n && arr[leftIdx] > arr[largestIdx])
    {
        largestIdx = leftIdx;
    }

    if (rightIdx < n && arr[rightIdx] > arr[largestIdx])
    {
        largestIdx = rightIdx;
    }

    if (largestIdx != i)
    {
        swap(arr[i], arr[largestIdx]);
        i = largestIdx;
        heapify(arr, n, i);
    }
}


void buildHeap(int arr[],int n,int capacity){
    // n- no of elements
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}


// Heap Sort Logic

// 1) MIN HEAP
void heapSort(int arr[],int size){
    // first delete element by swap
    int eidx = size-1;
    while(eidx>1){
        swap(arr[1],arr[eidx]);
        // delete last element
        eidx--;
        // now heapify from 1 to eidx elements
        // curridx = 1 | since 1 se eidx tak heapify kar rhe hai
        heapify(arr,eidx+1,1);
    }
}

int main()
{
    // Heap pq(10);
    // pq.insert(10);
    // pq.insert(20);
    // pq.insert(30);
    // pq.insert(40);
    // pq.insert(50);

    // pq.printHeap();

    // pq.deleteFromHeap();

    // pq.printHeap();


    // buildHeap
    int arr[] = {-1,10,20,30,40,50};
    int n = 6;
    buildHeap(arr,n,10);
    for(int i=1;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    heapSort(arr,n);
    for(int i=1;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}