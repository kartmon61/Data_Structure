#include <iostream>

using namespace std;


void shellSort(int arr[],int len){
    int interv = len;
    int k;
    int temp;
    do{
        //define interval
        interv = interv / 3 + 1;
        cout << "interval is " << interv << endl;
        //set i in the startpoint between parsing
        for(int i=0;i<interv;i++){

            //insertionSort by using interval
            for(int j = i+interv ;j<len ;j +=interv){
                temp = arr[j];

                for(k=j-interv;k>=0;k-=interv){

                    if(temp < arr[k]) arr[interv+k] = arr[k];
                    else break;

                }
                arr[interv+k] = temp;
            }

        }
        //end sorting, if interval is 1
    } while(interv != 1);
}



int main() {
    int arr1[10] = {1,3,4,5,6,2,7,8,12,11};

    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "ShellSort" << endl;

    cout << endl;
    shellSort(arr1,10);
    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }


}