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

            // agar jagah avalable hai
            // baki normal case me insert
            index++; // since index initially initialize to zero
            arr[index] = val;
            int i = index;

            // now adjust according to the heap property
            // we adjust to whole length
            while(i>1){
                int parentidx = i/2;
                if(arr[parentidx]<arr[i]){
                    swap(arr[parentidx],arr[i]);
                    i  = parentidx;
                }
                else{
                    // arr[parentidx]>arr[i] -> no need to do anything
                    break; // just break the loop no need to adjust
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

            // heapify -> first and last ko apni correct jgh pe lana
            // heapify(arr,index,1);

        }

        // void heapify(int* arr,int size, int currIdx){
        //     // size is count of no of elements not the capacity of heap
        //     int i = currIdx; // jis element ko replace krna hai
        //     int leftIdx = 2*i;
        //     int rightIdx = 2*i+1;

        //     // check ki konsa bada hai
        //     // let assume ki ith idx hi largest hai 3 me se
        //     int largestIdx = i;

        //     // if left element is largest
        //     // also left and right index valid hai ya nhi vo check karna
        //     if(leftIdx<size && arr[leftIdx]>arr[largestIdx]){
        //         largestIdx = leftIdx;
        //     }
        //     // if right element is largest
        //     if(rightIdx<size && arr[rightIdx]>arr[largestIdx]){
        //         largestIdx = rightIdx;
        //     }

        //     // finally update i for currIdx for next recursive iteration 
        //     // agli baar next element compute hoga 
        //     // till jab tak left and right index exist kar rhe hai -> not out of bound
        //     if(largestIdx != i){
        //         swap(arr[i],arr[largestIdx]);
        //         i = largestIdx;
        //         heapify(arr,size,i);
        //     }
        // }



};



void heapify(int* arr,int size, int currIdx)
{
            // size is count of no of elements not the capacity of heap
            int i = currIdx; // jis element ko replace krna hai
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;

            // check ki konsa bada hai
            // let assume ki ith idx hi largest hai 3 me se
            int largestIdx = i;

            // if left element is largest
            // also left and right index valid hai ya nhi vo check karna
            if(leftIdx<size && arr[leftIdx]>arr[largestIdx]){
                largestIdx = leftIdx;
            }
            // if right element is largest
            if(rightIdx<size && arr[rightIdx]>arr[largestIdx]){
                largestIdx = rightIdx;
            }

            // finally update i for currIdx for next recursive iteration 
            // agli baar next element compute hoga 
            // till jab tak left and right index exist kar rhe hai -> not out of bound
            if(largestIdx != i){
                swap(arr[i],arr[largestIdx]);
                i = largestIdx;
                heapify(arr,size,i);
            }
}

void buildHeap(int* arr,int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

// MAX HEAP
void heapSort(int* arr,int size){
    // ending index
    // int eidx = size-1; // 6-1 = 5 => 0,1,2,3,4,5,
    // har bar hum 1st element ko hi swap kra rhe hai

    // or do
    // while(eidx>1){
    //     // swap 1st and last element
    //     swap(arr[1],arr[eidx]);
    //     // delete last element
    //     eidx--;
    //     // heapify 1st element
    //     heapify(arr,eidx+1,1);   // yha pe size = eidx+1 hoga
    
    // }

    while(size>1){
        // swap 1st and last element
        swap(arr[1],arr[size-1]);
        // delete last element
        size--;
        // heapify 1st element
        heapify(arr,size,1);   // yha pe size = eidx+1 hoga
    

    }
}

// MIN HEAP
// void heapSort(int* arr,int size){
//     // ending index
//     int eidx = size-1; // 6-1 = 5 => 0,1,2,3,4,5
//     // har bar hum 1st element ko hi swap kra rhe hai
//     while(eidx>1){
//         // swap 1st and last element
//         swap(arr[1],arr[eidx]);
//         // delete last element
//         eidx--;
//         // heapify 1st element
//         heapify(arr,eidx,1);
       

//     }
// }

int main(){

    // Heap pq(10);

    // building heap
    // 0 50 40 20 10 30 0 0 0 0
    int arr[] = {-1,10,20,30,40,50};
    buildHeap(arr,6);
    cout<<endl;
    for(int i=1;i<6;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    heapSort(arr,6);
    for(int i=1;i<6;i++) cout<<arr[i]<<" ";
    














    // pq.insertHeap(10);
    // pq.printHeap();
    // pq.insertHeap(20);
    // pq.printHeap();
    // pq.insertHeap(30);
    // pq.printHeap();
    // pq.insertHeap(40);
    // pq.printHeap();
    // pq.insertHeap(50);
    // pq.printHeap();

    // pq.deleteHeap();
    // pq.printHeap();
    // pq.deleteHeap();
    // pq.printHeap();

    

 return 0;
}









