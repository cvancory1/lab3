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

void swap(int & num1, int& num2){
    cout<<"ENTER SWAP \n\n\n";
    cout<<" num1 = "<<num1<< " num= "<< num2<<endl;

    int temp1=num1;
    int temp2=num2;
    num1= temp2;
    num2=temp1;

    cout<<" num1 = "<<num1<< " num= "<< num2<<endl;

}



int * print(Heap A, int i, int depth, int * arr){
    static int index=i;
    int numNodes=pow(2, depth);
    // if(2*i+1 > A.length && 2*i > A.length || i>= numNodes-1){

    //  if(2*i+1 > A.length && 2*i > A.length ){
            //  cout<<"i="<<i<<"numNodes="<<numNodes<<endl;

         if(i>=numNodes){
            //  cout<<"i="<<i<<"numNodes="<<numNodes<<endl;
            return arr; 
            
         }

    // }
    // cout<<"     here  ";
    //  cout<< A.arr[(2*i)-1]<<"  "<< A.arr[(2*i)]<<endl;// left and right child
    // // arr[index++]=A.arr[(2*i)-1];
    // arr[index++]=A.arr[(2*i)];

    arr[2*i -1]=A.arr[(2*i)-1];
    arr[(2*i)]=A.arr[(2*i)];

    print(A,(2*i)+1,depth, arr); //print right child
    print(A,2*i,depth, arr);// print left child

    

   

    
}
void printHeap(Heap A, int i, int depth){
    int * arr= new int [A.length];
    for(int j=0;j< A.length ;j++){
        arr[j]=-9;
        //cout<<arr[j];

    }
    int j=0;
    cout<< ""<<A.arr[i-1]<<endl;
    // cout<<"/ \\"<<endl;

    print(A,i,depth--,arr);
    //cout<<"Here"<<endl;

    int power=1;
    int nodesPrinted=0;
    int numNodes =2;
    //cout<<"numNodes="<<numNodes<<endl;

    for(int j=0;j< A.length ;j++){
        //cout<<arr[j]<<endl;

        if(arr[j] >= 0){
            cout<<arr[j]<<" ";
            nodesPrinted++;

            if(nodesPrinted % numNodes==0){
                //cout<<"numNodes="<<numNodes<<endl;
                cout<<endl;

                // ˚cout<<"/ \\"<<endl;
                nodesPrinted=0;
                numNodes*=2;
                //numNodes= pow(2,power++);


            }

        }
    }    
    cout<<endl;

    
}



/*
 * MaxHeapify which will perform maintenance on the heap to maintain the max-heap property. 
 * This should take only Θ(log n) time on an array of length n.
 * 
*/



void MaxHeapify(Heap A, int i){
    sleep(1);
    int left= 2*i;
    int right = (2*i)+1;
    int largest;

    cout<<"\nEnter Maxheapify"<<endl;

    printHeap(A, i, 2);

    // cout<<"left= "<<left<<" right= "<<right<< " i="<<i<<endl;
    // cout<<"arrays left="<<A.arr[left-1] <<" right="<<A.arr[right-1]<<" arr[i]="<< A.arr[i-1]<<endl;

    // Find the largest among node i and its children, and swap with i
    if(left <= A.heap_size && A.arr[left-1] > A.arr[i-1]){
        largest=left;
        cout<<"first"<<endl;

    }else {
        largest=i;
        cout<<"second"<<endl;

    }
    
    if(right <= A.heap_size && A.arr[right-1] > A.arr[largest-1] ){
        largest = right;
        cout<<"third"<<endl;

    }

        // cout<<"largest index= "<<largest<<endl;
        // cout<<"largest arr= "<<A.arr[largest-1]<<endl;
        // cout<<"i arr= "<<A.arr[i-1]<<endl;


    if(largest != i ){
       swap(A.arr[i-1], A.arr[largest-1]);
        cout<<"\n"<<endl;
        printHeap(A, i, 2);


        MaxHeapify(A, largest);
    }


}

/*
* BuildMaxHeap which takes as input an un-ordered array and creates a max-heap 
* from the elements using Θ(n)time.
*/
void  BuildMaxHeap(Heap A ){
    A.heap_size= A.length; // the whole array will be a heap when we’re done
    for( int i= A.length/2; i>0 ; i--){
        MaxHeapify(A,i);
    }
}


/* HeapSort to take an array argument and sort the array in-place using the above subroutines. 
*This procedure should take Θ(nlogn) time. 

*/
void HeapSort(Heap A ){
// Make sure the array is a valid heap, where the largest element must be A[1]
// CHECK 
    BuildMaxHeap(A);
    for ( int i= A.length; i<=2 ; i){
        // We know A[i] is the largest among A[1,...,i], so move it to the back of the heap and consider it removed from the heap
        swap(A.arr[i], A.arr[i]);
        A.heap_size--;
        // we moved one of the smaller elements to the root so now we have to Clean up
        MaxHeapify(A,1);
        

    }


}


   






int main(){
     int temp=0;
     int temp2=0;

    //Heap heap1= {new int[10]{ 16, 14, 10, 8, 7,9,3,2,4,1 }, 10, 4};
    Heap heap1= {new int[8]{10, 20,25,6,12,15, 4 ,16}, 8, 3};


    cout<<"heap1="<<heap1.length<<endl;

    printHeap(heap1, 1, 4);
    BuildMaxHeap(heap1);
   

    printHeap(heap1, 1, 3);

   






    // for(int i=1;i<10;i++){
    //     //  cin>>temp;
    //     //  heap1.arr[i]=temp;
    

    //     cout<<heap1.arr[i]<<endl;
    // }

    // puts("print 1");
    // printHeap(heap1, 2, 2);

    // puts("print 2");
    // printHeap(heap1, 2, 3);

    // puts("print 3");
    // printHeap(heap1, 1, 1);

    // puts("print 4");
    // printHeap(heap1, 1, 3);

    // cout<<"bye"<<endl;

    delete heap1.arr;
    
}





