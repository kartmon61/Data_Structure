#include <iostream>

using namespace std;

//swap 함수
void swap(int arr[],int index1,int index2){
    int temp;
    temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

//quick 정렬 함수
void quickSort(int arr[], int left,int right){
    int pivot;
    int low,high;

    if(left < right){
        low = left;
        high = right+1;
        pivot = arr[left];

        do{
            //pivot 보다 큰값을 찾을때까지 low의 index 증가
            do{
                low++;
            } while(arr[low]<pivot);
            //pivot 보다 작은값을 찾을때까지 high의 index 감소
            do{
                high--;
            } while(arr[high]>pivot);

            //low 위치와 high 위치에 있는 값을 교환
            if(low < high){
                swap(arr,low,high);
            }
        } while(low<high); //low와 high가 cross 되기 전까지 반복

        //pivot이 있는 제일 왼쪽 위치와 high 위치의 값을 교체
        swap(arr,left,high);

        //low와 high가 교차되는 지점에서
        //high보다 작은 부분을 다시 퀵소트로 정렬
        quickSort(arr,left,high-1);
        //high 보다 큰 부분을 다시 퀵소트로 정렬
        quickSort(arr,high+1,right);
    }


}



int main() {
    int arr1[10] = {1,3,4,5,6,2,7,8,12,11};

    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "QuickSort" << endl;

    cout << endl;
    quickSort(arr1,0,9);
    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }


}