# include<bits/stdc++.h>
using namespace std; 

class Heap{
    private:
        int* arr;
        int capacity;
        int index;

    public:
        Heap(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            index = 0; // initially
            arr[0] = 0;
        }

        void printHeap(){
            for(int i=0;i<capacity;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        
        void insertHeap(int val){
            // overflow condition
            if(index == capacity-1) {
                cout<<"overflow\n"; 
                return;
            };

            index++;
            arr[index] = val;
            int i = index;

            while(i>1){
                int parentidx = i/2;
                if(arr[parentidx]<arr[i]){
                    swap(arr[parentidx],arr[i]);
                    i  = parentidx;
                }
                else{
                    break; 
                }
            }
            return ;
        }

        void deleteHeap(){
            // 1st and last element replacement
            swap(arr[1],arr[index]);
            arr[index] = 0;
            // size decrease
            index--;
            heapify(arr,index,1);

        }

        void heapify(int* arr,int size, int currIdx){
            int i = currIdx; // jis element ko replace krna hai
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;

            int largestIdx = i;

            if(leftIdx<size && arr[leftIdx]>arr[largestIdx]){
                largestIdx = leftIdx;
            }
        
            if(rightIdx<size && arr[rightIdx]>arr[largestIdx]){
                largestIdx = rightIdx;
            }
            if(largestIdx != i){
                swap(arr[i],arr[largestIdx]);
                i = largestIdx;
                heapify(arr,size,i);
            }
        }

};


int main(){

    Heap pq(10);

    // building heap
    pq.insertHeap(10);
    pq.printHeap();
    pq.insertHeap(20);
    pq.printHeap();
    pq.insertHeap(30);
    pq.printHeap();
    pq.insertHeap(40);
    pq.printHeap();
    pq.insertHeap(50);
    pq.printHeap();

    pq.deleteHeap();
    pq.printHeap();
    pq.deleteHeap();
    pq.printHeap();

    

 return 0;
}









