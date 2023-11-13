#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int first, int last){
    int LIdx, RIdx , mid;
    int* buffer=(int*)malloc((last-first+1)*sizeof (int));

    mid=(first+last)/2;
    LIdx= first;
    RIdx=mid+1;

    for(int i =first; i<=last; i++){
        if((LIdx<=mid)&&((RIdx>last)||(arr[LIdx]<arr[RIdx]))){
            buffer[i-first]= arr[LIdx];
            LIdx++;
        }
        else{
            buffer[i-first]= arr[RIdx];
            RIdx++;
        }
    }
    for(int i = first; i<= last; i++){
        arr[i]= buffer[i-first];
    }
}

void mergeSort(int* arr, int start, int end){
    if(start<end){
        mergeSort (arr,start,(start+end)/2);
        mergeSort (arr,(start+end)/2+1,end);

        merge(arr,start,end);
    }
}

int main(){
    FILE* fin= fopen("input.txt","rb");
    FILE* fout= fopen("output.txt","wb");

    int N;// ammount numbers in aArray
    fread(&N,sizeof (int),1,fin);

    int* aArray= (int*)malloc(sizeof (int)*N);// nosorted numb array
    fread(aArray,sizeof (int),N,fin);

    mergeSort(aArray,0,N-1);

    fwrite(aArray,sizeof (int),N,fout);
}
//https://www.youtube.com/watch?v=u8gHAAWH_TI
