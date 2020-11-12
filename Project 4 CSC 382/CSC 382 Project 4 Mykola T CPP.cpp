#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>   
#include <ctime>


using namespace std;


void Insertion(int A[], int n);
void Merge(int arr[], int low, int mid, int high);
void MergeSort(int arr[], int low, int high);
void HeapSort(int arr[], int num);
void Heapify(int arr[], int num, int i);

int main() {
    //{1000, 10000, 25000, 50000, 150000, 250000
    int arrSizes[6] = { 1000, 10000, 25000, 50000, 150000, 250000 };
    int SIZE = 0;
    int num = 0;

    int input = 0;
    //variables to hold time
    double heapTime, insertionTime, mergeTime;
    string best = "None is best";

    clock_t time_req;

    srand(time(NULL));


    cout << fixed << setprecision(4);
    cout << "---------------------------------------------PROJECT 4---CSC 382---MYKOLA TOROPOV--------------------------------------------------\n" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << left << setw(30) << "INPUT LENGTH" << setw(30) << "HEAP SORT(seconds)" << setw(30) << "INSERTION SORT(seconds)" << setw(30) << "MERGE SORT(seconds)" << setw(30) << "BEST TIME" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 6; i++)
    {
        //assign {1000, 10000, 25000, 50000, 150000, 250000} from arrSizes
        SIZE = arrSizes[i];

        //Creation of 3 heaps of size SIZE that hold values from arrSizes
        int* myArrayInsertion = new int[SIZE];
        int* myArrayMerge = new int[SIZE];
        int* myArrayHeap = new int[SIZE];

        //loop that generates the same random values for each array will delete the array after use in the sort algos
        for (int j = 0; j < arrSizes[i]; j++)
        {
            //creates random number between the Size of the array and 1
            num = rand() % SIZE + 1;

            //each array assigned the random number
            myArrayHeap[j] = num;
            myArrayMerge[j] = num;
            myArrayInsertion[j] = num;

        }
        //processing the data generated for each sorting algorithim

        //running Insertion
        {
            time_req = clock();
            //running actual Insertion Sort
            Insertion(myArrayInsertion, SIZE);
            time_req = clock() - time_req;
            insertionTime = time_req / (double)CLOCKS_PER_SEC;
        }

        ////running Merge
        {
            time_req = clock();
            //running actual Merge Sort
            MergeSort(myArrayMerge, 0, SIZE - 1);
            time_req = clock() - time_req;
            mergeTime = time_req / (double)CLOCKS_PER_SEC;

        }

        //running Heap
        {
            time_req = clock();
            //running actual Heap Sort
            HeapSort(myArrayHeap, SIZE);
            time_req = clock() - time_req;
            heapTime = time_req / (double)CLOCKS_PER_SEC;
        }

        //comparing times for all the times
        if (heapTime < insertionTime && heapTime < mergeTime)
        {
            best = "Heap Sort";
        }
        else if (insertionTime < heapTime && insertionTime < mergeTime)
        {
            best = "Insertion Sort";
        }
        else if (mergeTime < heapTime && mergeTime < insertionTime)
        {
            best = "Merge Sort";
        }


        //printing data 
        cout << left << setw(30) << SIZE << setw(30) << heapTime << setw(30) << insertionTime << setw(30) << mergeTime << setw(30) << best << endl;


        delete[] myArrayHeap;
        delete[] myArrayMerge;
        delete[] myArrayInsertion;

    }

}


///////////////////////////////////////////INSERTION///////////////////////////////////////////////////////

//Insertion Sort
void Insertion(int A[], int n) // in reality the elements to be sorted are indexed from
                                                // index 1 to index n
{
    int i, j, temp;
    
    //A[0] = -32768; //smallest possible integer using 2 bytes integer representation
    //not sure of the point of this ^^^^

    for (i = 1; i <= n - 1; i++) {
        j = i;
         while (A[j] < A[j - 1]) { // swap 
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j--;
        }
    }
}

/////////////////////////////////////////////MERGE////////////////////////////////////////////////////////

//Merge
//Merge Sort from class didnt work for me
void Merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    // Create temp arrays  
    int* Low = new int[n1];
    int* High = new int[n2];
    // Giving value to arrays
    for (int i = 0; i < n1; i++)
        Low[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        High[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into array 
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (Low[i] <= High[j])
        {
            arr[k] = Low[i];
            i++;
        }
        else
        {
            arr[k] = High[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of Low
    while (i < n1)
    {
        arr[k] = Low[i];
        i++;
        k++;
    }
    // Copy the remaining elements of High 
    while (j < n2)
    {
        arr[k] = High[j];
        j++;
        k++;
    }
    delete[] Low;
    delete[] High;
}

//Merge Sort
//Merge sort from class didnt work for me 
void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        // we call Mergesort for the first half
        MergeSort(arr, low, mid);
        //we call Mergesort for the second half
        MergeSort(arr, mid + 1, high);
        // at this point the two halves are sorted so we merge
        Merge(arr, low, mid, high);
    }
}

////////////////////////////////////////////////////HEAP///////////////////////////////////////////////////
//not heap sort from class notes
//heap sort 
void HeapSort(int arr[], int num)
{
    // Build heap 
    for (int i = num / 2 - 1; i >= 0; i--)
        Heapify(arr, num, i);

    // One by one extract an element from heap 
    for (int i = num - 1; i > 0; i--)
    {
        // Move current root to end 
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap 
        Heapify(arr, i, 0);
    }
}
// Heapify a subtree rooted with node i 
void Heapify(int arr[], int num, int i)
{
    // Initialize largest as root 
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2; 

    // If left child is larger than root 
    if (left < num && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest 
    if (right < num && arr[right] > arr[largest])
        largest = right;

    // If largest is not root 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the subtree 
        Heapify(arr, num, largest);
    }
}
