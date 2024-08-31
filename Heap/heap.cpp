#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Heap{
    public:
    int arr[101];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;//i indexed heap
        arr[size]=val;
        int index=size;
        while(index>1){
            int parentIndex=index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleted(){
        arr[1]=arr[size];
        size--;//throw or delete the element by put in the size index and decrease size by 1;
        
        //heapify the rest of the element
        int index=1;
        // we cant take <= because at equal to index at last element and last element not have left or right node
        while(index<size){
            int left=2*index;
            int right=2*index+1;
            int largest=index;
            if(index<=size&&arr[largest]<arr[left]){
                largest=left;
            }
            if(right<=size&&arr[largest]<arr[right]){
                largest=right;
            }
            if(largest==index){
                return;
            }
            else{
                swap(arr[largest],arr[index]);
                index=largest;
            }
        }

    }

    void printArr(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

void heapify(int arr[],int n,int index){
    int left=2*index;
    int right=2*index+1;
    int largest=index;
    int size=n;
        if(left<size&&arr[index]<arr[left]){
            largest=left;
        }
        if(right<size&&arr[index]<arr[right]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[index],arr[largest]);
            index=largest;
            heapify(arr,n,index);
        }

}


void buildHeap(int arr[],int n){
    for(int i=(n)/2;i>0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n){
    int index=n;
    buildHeap(arr,n);
    while(index!=1){
        swap(arr[1],arr[index]);
        index--;
        n--;
        heapify(arr,n,1);
    }
}

int main(){
    Heap h;
    h.insert(10);
    h.insert(34);
    h.insert(7);
    h.insert(19);
    h.insert(3);
    h.insert(100);
    h.printArr();

    int arr[]={-1,10,34,7,19,3,100};
    heapSort(arr,7);
    for(int i=1;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}