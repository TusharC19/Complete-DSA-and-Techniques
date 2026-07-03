#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    vector<int>arr;
    int size;
    int ind;

    void initialize(int n)
    {   
        // arr.assign(n,1e9);
        size = 0;
        ind = -1;
    }

    void heapifyUp()
    {
    }

    void heapifyDown()
    {
        for (int i = 0; i < (size / 2); i++)
        {
            int lc = 2 * i + 1, rc = 2 * i + 2;

            while (arr[i] > arr[lc] || arr[i] > arr[rc])
            {
                if (arr[i] > arr[lc])
                    swap(arr[i], arr[lc]);
                else
                    swap(arr[i], arr[rc]);
            }
        }
    }

    void push(int val)
    {
        arr.push_back(val);
        size++;
        ind++;
        if (size == 1)
            return;

        // heapify Up
        heapifyUp();
    }
    // pop
    void extractmin()
    {
        if (size == 0)
        {
            cout << "empty heap\n";
            return;
        }
        swap(arr[0], arr[size - 1]);
        size--;
        arr.pop_back();
        // heapify down
        heapifyDown();
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    int getMin()
    {
        if (size != 0)
            return arr[0];
        return INT_MIN;
    }

    int heapSize()
    {
        return size;
    }
};

int main()
{
    heap h;
    h.push(10);
    return 0;
}