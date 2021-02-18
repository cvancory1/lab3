/*

Chloe VanCory
COSC 320 
Lab3

Goals: 
- Develop a Heap data structure using arrays
*/

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include<unistd.h>
#include<cmath>


using namespace std;



struct Heap {
    int* arr; // the underlying array
    int length; // should always be the size of arr
    int heap_size; // will change based on which portion of arr is a valid heap



void makeArrRandom( ){
    arr= new int [length];
    for(int i=0;i<length;i++){
        arr[i]= rand() % 1000+ 2; 
    }
     
}

void makeArrSorted( ){
    arr= new int [length];

     for(int i=0;i<length;i++){
         arr[i]=i;
     }

}

void makeArrBackward( ){
    arr= new int [length];
    int backwards=length;
     for(int i=0;i<length;i++){
         arr[i]= backwards;
         backwards--;
     }
}

// creates an array where half of the numbers are 30 and the other half are random
void makeArrDuplicates(){
    arr= new int [length];
    for(int i=0;i<length;i++){
        if(i%2 == 0){
            arr[i]=30;
        }else{
             arr[i]= rand() % 1000+ 1;
        }
        
    }
}


  // give the struct an [] operator to pass through access to arr
  // we return an int reference so we can assign into the structure,
  // otherwise it would only return a copy of the indexed element


//   int& operator[](int i){
//         // good idea to also check that 1 <= i <= length!
//         if(i> 1 && i < length){
//             cout<<"HERE hi    ="<< i <<endl;

//             return arr[i-1]; // so A[1] is the first and A[n] is the last }
//         }
//     }

 

};


void printArr(Heap A){
    for(int i=0; i< A.length ;i++){
        cout<<A.arr[i]<<endl;
    }
}


void swap(int & num1, int& num2){
   // cout<<" num1 = "<<num1<< " num= "<< num2<<endl;

    int temp1=num1;
    int temp2=num2;
    num1= temp2;
    num2=temp1;

   // cout<<" num1 = "<<num1<< " num= "<< num2<<endl;

}



void print(Heap A, int i, int depth, int * arr ){
  
    if( i >= A.length  ){
        return ; 
    }


    if(2*i-1 < A.length ){
        arr[2*i -1]=A.arr[(2*i)-1];

    }

    if(2*i < A.length ){
        arr[(2*i)]=A.arr[(2*i)];
        
    }

    print(A,(2*i)+1,depth, arr); //print right child
    print(A,2*i,depth, arr);// print left child

}


// this print does not work if the heap includes -9999
void printHeap(Heap A, int i, int depth){
    int * arr = new int [A.length];
    int num=0;
    for(int j=0;j< A.length ;j++){
        arr[j]=-9999;
    }
    print(A, i , depth , arr); // calls the above function to fill the array to be printed

    int numNodes =0;
    int nodesPrinted=0;
    // prints the root
    cout<< "\n"<<A.arr[i-1]<<endl;
    int level=2;
    
    if(depth>1){

        for(int i= 1 ;i<depth ;i++){
            numNodes+= pow(2, i);

        }

        //cout<<"numNodes = "<<numNodes<<endl;
        for(int i=0 ;i < A.length ;i++){

            if(arr[i] != -9999 && nodesPrinted < numNodes){
                cout<< arr[i]<<" ";
                nodesPrinted++;
            }
            if(nodesPrinted== level){
                 puts("");
                 level *=2;
                 nodesPrinted=0;

            }
        }

        if(nodesPrinted != pow(2, depth-1)){
            for(int i=0 ;i < pow(2,depth-1) -nodesPrinted; i++){
                cout<<"* ";
            }
            cout<<endl;
        }
            
    }

    delete [] arr;
    cout<<endl;
}



/*
 * MaxHeapify which will perform maintenance on the heap to maintain the max-heap property. 
 * This should take only Θ(log n) time on an array of length n.
 * 
*/

void MaxHeapify(Heap A, int i){
   // sleep(1);
    int left= 2*i;
    int right = (2*i)+1;
    int largest;


    // Find the largest among node i and its children, and swap with i
    if(left <= A.heap_size && A.arr[left-1] > A.arr[i-1]){
        largest=left;
        //cout<<"first"<<endl;

    }else {
        largest=i;
        //cout<<"second"<<endl;

    }
    
    if(right <= A.heap_size && A.arr[right-1] > A.arr[largest-1] ){
        largest = right;
       // cout<<"third"<<endl;

    }

        // cout<<"largest index= "<<largest<<endl;
        // cout<<"largest arr= "<<A.arr[largest-1]<<endl;
        // cout<<"i arr= "<<A.arr[i-1]<<endl;


    if(largest != i ){
       swap(A.arr[i-1], A.arr[largest-1]);
        // cout<<"\n"<<endl;
        //printHeap(A, i, 2);

        MaxHeapify(A, largest);
    }


}

/*
* BuildMaxHeap which takes as input an un-ordered array and creates a max-heap 
* from the elements using Θ(n)time.
*/
void  BuildMaxHeap(Heap A ){
   // puts("Enter buildmaxheap");    

    A.heap_size= A.length; // the whole array will be a heap when we’re done
    for( int i= A.length/2; i>0 ; i--){
        //cout<< "i"<<i<<endl;
        MaxHeapify(A,i);
    }

    //puts("exit buildmaxheap");    
   // printHeap(A,1,4);

}


/* HeapSort to take an array argument and sort the array in-place using the above subroutines. 
*This procedure should take Θ(nlogn) time. 

*/
void HeapSort(Heap A ){
// Make sure the array is a valid heap, where the largest element must be A[1]
    //puts("Enter HEAPSORT");    
    BuildMaxHeap(A);
    //puts("BuildMaxheap finish");    
    //printArr(A);
    //printHeap(A,1 ,4);


    for ( int i= A.length; i>=2 ; i--){
        // We know A[i] is the largest among A[1,...,i], so move it to the back of the heap and consider it removed from the heap
        // cout<<" num1 = "<<A.arr[0]<< " num= "<< A.arr[i-1]<<endl;

        swap(A.arr[0], A.arr[i-1]);
        A.heap_size--;
        // we moved one of the smaller elements to the root so now we have to Clean up
        MaxHeapify(A,1);
        //printArr(A);



    }


}

void timeHeapSort( Heap A){

 
  auto begin = std::chrono::system_clock::now();
  HeapSort(A);


  auto finish = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = finish-begin;
  std::time_t end_time = std::chrono::system_clock::to_time_t(finish);
  std::cout << " finished at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << " seconds\n\n";

    
}







int main(){

    // things to send to maxheapify(A, any index where you want to compare a small baby tree aka size=3)
    // buildmaxheap- uses maxheapify starting at the bottom of the array to the top
    // heap sort- moves the largest elem aka i=0 to the back then maxheapifys everything to make sure it is still a valid max heap
    
    
     //int length=10;
    int length=250000;

    
    // while( length!= 101000){
         Heap heap1,heap2,heap3,heap4;

        cout<<"length= "<<length<<endl;
        heap1.length= length;
        heap1.heap_size = length;
        heap2.length= length;
        heap2.heap_size = length;
        heap3.length= length;
        heap3.heap_size = length;
        heap4.length= length;
        heap4.heap_size = length;

        cout<<"random "<<length<<endl;
        heap1.makeArrRandom();
        timeHeapSort(heap1);
       
        cout<<"backward "<<length<<endl;
        heap2.makeArrBackward();
        timeHeapSort(heap2);


        cout<<"sorted "<<length<<endl;
        heap3.makeArrSorted();
        timeHeapSort(heap3);


        cout<<"duplicates "<<length<<endl;
        heap4.makeArrDuplicates();
        timeHeapSort(heap4);


        length+=10000;

        delete [] heap1.arr;
        delete [] heap2.arr;
        delete [] heap3.arr;
        delete [] heap4.arr;

    // }


    
}





