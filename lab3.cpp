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

void MaxHeapify(){

}

void  BuildMaxHeap(){

}

void HeapSort(){

}


// i specifies a node, depth specifies the depth of the "tree"
void print(int * arr, int i, int depth){ 

}


int main(){
    int arr= new int [10];
    //hi 
    int a;
}





