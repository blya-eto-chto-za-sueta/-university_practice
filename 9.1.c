#include <stdio.h>
#include <stdlib.h>

int merge (const int* a, int ak, const int* b, int bk, int* res){
    int count=0;// ammount numbers in resSequensent
    int idxA=0, idxB=0;

    for(;count<=(ak+bk);){
        if (idxA!=ak && idxB!=bk){
            if (a[idxA]<=b[idxB]){
                res[count]=a[idxA];
                idxA++;
            }
            else{
                res[count]=b[idxB];
                idxB++;
            }
        }
        else if (idxA==ak && idxB!=bk){
            res[count]=b[idxB];
            idxB++;
        }
        else if (idxA!=ak && idxB==bk){
            res[count]=a[idxA];
            idxA++;
        }
        count++;
    }
    return count;
}

int main(){
    FILE* fin = ("input.txt","rb");
    FILE* fout= ("output.txt","wb");

    int N=0,M=0;// N - ammount numbers in first amd second sequence
    fread(&N,sizeof (int),1,fin);
    fread(&M,sizeof (int),1,fin);

    int* aSequence= (int*)malloc(sizeof (int)*N);
    int* bSequense =(int*)malloc(sizeof(int)*M);

    fread (aSequence,sizeof (int),N,fin);
    fread(bSequense,sizeof (int),M,fin);

    int* resSequence = (int*)malloc(sizeof(int)*(N+M));

    int resk= merge(aSequence,N,bSequense,M,resSequence);

    fwrite(resSequence,sizeof (int),resk,fout);
}

