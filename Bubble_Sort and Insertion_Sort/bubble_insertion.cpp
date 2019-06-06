#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    int flag = 1;

    //if something change the flag,keep going on loop
    for(int i = n-1;flag>0;i--){

        flag = 0;
        for(int j = 0;j<i;j++){
            //if follow array is bigger than current array
            if(arr[j]>arr[j+1]){
                //swapping position
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
    }

}


void insertionSort(int arr[],int n){

    int j;

    int next;

    for(int i=1;i<n;i++){
        next = arr[i];
        //find the next's position
        //change the position
        //until j>=0
        //next is smaller than array's position
        for(j = i-1;j>=0 && next < arr[j];j--){
            arr[j+1] = arr[j];
        }
        //insert the next
        arr[j+1] = next;
    }
}

int main() {
    int arr1[10] = {1,3,4,5,6,2,7,8,12,11};
    int arr2[10] = {1,3,4,5,6,2,7,8,12,11};

    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    bubbleSort(arr1,10);
    cout << "bubbleSort" << endl;
    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "==============" << endl;
    for(int i=0;i<10;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;


    insertionSort(arr2,10);
    cout << "insertion Sort"<< endl;
    for(int i=0;i<10;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

}