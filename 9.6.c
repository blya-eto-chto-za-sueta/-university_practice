#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
typedef struct TNode {
    unsigned char key[4];
    unsigned int value;
}TNode;

void Radix_sort (TNode* arr, TNode* output, int N, int K){//K - номер байта key
    int count[256]= {0};
    int idx[256]={0};

    for (int j=0;j<N;j++){
        count[arr[j].key[K]]++;
    }
    for (int j=1;j<256;j++){
        idx[j]+= idx[j-1]+count[j-1];
    }
    for (int j=0;j<N;j++){
        output[idx[arr[j].key[K]]++]=arr[j];
    }
    for (int j=0;j<N;j++){
        arr[j]=output[j];
    }
}


int main(){
    FILE* fin = fopen("input.txt","rb");
    FILE* fout = fopen("output.txt","wb");

    int N;
    fread(&N, sizeof(int),1,fin);

    TNode* arr = (TNode*)malloc(N*sizeof (TNode));
    fread(arr,sizeof (TNode),N,fin);
    TNode* output = (TNode*)malloc(N*sizeof (TNode));

    Radix_sort (arr, output, N,0);
    Radix_sort (arr, output, N,1);
    Radix_sort (arr, output, N,2);
    Radix_sort (arr, output, N,3);

    free(output);

    fwrite(arr,sizeof (TNode),N,fout);

    return 0;
}
