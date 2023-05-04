#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; // initialize the largest as root
   int left = 2 * root + 1;  // left child
   int right = 2 * root +2; // right child
   //if left child is larger than root then largest is left 
   if (left < n && arr[left] > arr[largest] )
        largest = left;
   //if right child is larger than root then largest is right
   if (right < n && arr[right] > arr[largest])
        largest = right;
   // if largest is not root
   if (largest != root){
      swap(arr[root],arr[largest]);
      // recursively heapyfy the affected sub-tree
      heapify (arr,n,largest);
   }  
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int j = n/2 - 1; j >= 0; j--){
      heapify (arr,n,j);
   }
   // extracting elements from heap one by one
   for(int j = n - 1 ; j >= 0 ; j--){
      // move current root to end
      swap (arr[0],arr[j]);
      // call max-heapify
      heapify(arr,j,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   
   // get the input array elements from user
   int n;
   cout<<"input the size of the array"<<endl;
   cin >> n;
   cout<<"Input array"<<endl;
   int heap_arr[n];
   for (int k = 0 ; k<n ; k++){
      cin >>heap_arr[k];
   }
   //displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}