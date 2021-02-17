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


#include <unistd.h> 
#include <fcntl.h> 
using namespace std;



struct Heap {
    int* arr; // the underlying array
    int length; // should always be the size of arr
    int heap_size; // will change based on which portion of arr is a valid heap


  // give the struct an [] operator to pass through access to arr
  // we return an int reference so we can assign into the structure,
  // otherwise it would only return a copy of the indexed element
  int& operator[](int i){
        // good idea to also check that 1 <= i <= length!
        if(i> 1 && i > length){
            return arr[i-1]; // so A[1] is the first and A[n] is the last }
        }
    }


};

void MaxHeapify(Heap A, int i){
    int left= 2*i;
    int right = (2*i)+1;
    int largest;

    // Find the largest among node i and its children, and swap with i
    if(left <= A.heap_size && A[left] > A[i] ){
        largest=left;
    }else if(right < A.heap_size && A[right] > A[largest]){
        largest = right;
    }else{
        largest=i;
    }

    if(largest != i){
        swap(A[i], A[largest]);
        // MaxHeapify(A, largest);
    }


}

void  BuildMaxHeap(Heap A ){
    A.heap_size= A.length; // the whole array will be a heap when we’re done
    for( int i= A.length/2; i>=0 ; i--){
        MaxHeapify(A,i);
    }
}

void HeapSort(Heap A ){
// TO DO
// // Make sure the array is a valid heap, where the largest element must be A[1]
//     BuildMaxHeap(A);
//     for ( int i= A.length; i<=2 ; i)


}

// void printChildren(Heap A, int left , int right ){

// }

//utiliy functions

//prints node at lable i
int returnNode(Heap A, int lable){
    if(lable - 1 <= A.length)
        return A.arr[lable - 1];
    else {
        return -999;
    }
}

//prints left child of node at lable i
int returnLeftChild(Heap A, int lable){
    if((2 * lable) - 1 <= A.length)
        return A.arr[(2 * lable) - 1];
    else
        return -999;
}

//returns right child of node at lable i
int returnRightChild(Heap A, int lable){
    if((2 * lable) <= A.length)
        return A.arr[(2 * lable)];
    else
        return -999;
}

// i specifies a node which will print looking like the root, depth specifies the depth of the "sub -tree"



// int * findChildren(Heap A , int i , int * childArr, int j){

//     //if(i>= A.length+1 || i >=A.length+1){
//     if( i > A.length ){
    
//         return childArr;

//     }else{
//         return findChildren( A ,  2*i+1 , childArr,  j);
//         return findChildren( A ,  2*i , childArr,  j+5);

//         childArr[j++]= A.arr[2*i-1] ;
//         childArr[j++]= A.arr[2*i] ;

//     }

// }

// void print(Heap A, int i, int *array, int count){
//     if(2*i+1 > A.length && 2*i > A.length){
//         return;
//     }

    // print(A, 2*i, array, count-1);

    // print(A, 2*i+1, array, count-2);

    // //print left child
    // array[count] = returnLeftChild(A, i);
    // count--;

    // //print right child
    // array[count] = returnRightChild(A, i);
    // count--;


// _______
    //print node
    //printNode(A, i);

    // int * left= new int [A.length];
    

    // for(int k=0 ;k< depth ;k++){
    //     left= findChildren(A,i,left,0);
    //     for (int l=0 ; l< A.length;l++){
    //         cout<<left[l];
    //     }
    

    //     puts("");
    // }


//  if(i > A.length/2){

//      return;
//     }

    //    print(A,2*i,depth);// print left child
    //     print(A,(2*i)+1,depth); //print right child

    //  cout<<A.arr[i-1]<<endl; //root
    
//     cout<< A.arr[(2*i)-1]<<"  "<<A.arr[(2*i)]<<endl;// left and right child
    
   // cout<<endl;

    // print(A,2*i,depth);
 
    

    

// }

// void printHeap(Heap A, int i, int depth){
//     int numNodes = 0;
//     for(int j = 0; j < depth; j++){
//         numNodes += (int)pow(2.0, (double)j);
//     }

//     int outputNodes[numNodes];
    
//     print(A, i, outputNodes, 5);

//     outputNodes[numNodes - 1] = returnNode(A, i);

//     for(int j = 0; j < numNodes; j++){
//         cout << outputNodes[j] << " ";
//     }
// }


char * print(Heap A, int i, int depth){
    
     if(2*i+1 > A.length && 2*i > A.length){
        return
     }

    print(A,2*i,depth);// print left child
    print(A,(2*i)+1,depth); //print right child

  
    

   cout<< A.arr[(2*i)-1]<<"  "<<A.arr[(2*i)]<<endl;// left and right child

    
}
void printHeap(Heap A, int i, int depth){
    
    cout<< A.arr[i-1]<<endl;
    print(A,i,depth);

    
}

   

// void swap(int & num1, int& num2){

//     int temp1=num1;
//     int temp2=num2;
//     num1= temp2;
//     num2=temp1;

    

// }





int main(){
    int temp;
    Heap heap1= { {new int[10]{ 16, 14, 10, 8, 7,9,3,2,4,1 } }, 10, 4};
    // heap1.arr= new int [heap1.length];
    // heap1.length=10;
    // heap1.heap_size=10;
    cout<<"heap1="<<heap1.length<<endl;


    // cout<<"hi" <<endl;

    for(int i=1;i<10;i++){
        //  cin>>temp;
        //  heap1.arr[i]=temp;
    

        cout<<heap1.arr[i]<<endl;
    }

    puts("");
    
    printHeap(heap1, 2, 3);
    // cout<<"bye"<<endl;
    
}




