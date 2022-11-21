#include "set.c"

int main(){
    Set S;
    CreateEmptySet(&S);
    if(IsEmptySet(S)){
        printf("Set kosong\n");
    }else{
        printf("Set tidak kosong\n");
    }
    InsertSet(&S, "COBA 1");
    InsertSet(&S, "COBA 2");
    InsertSet(&S, "COBA 3");

    if(IsEmptySet(S)){
        printf("Set kosong\n");
    }else{
        printf("Set tidak kosong\n");
    }

    if(IsFullSet(S)){
        printf("Set penuh\n");
    }else{
        printf("Set tidak penuh\n");
    }

    for(int i = 0; i<S.Count; i++){
        printf("Elemen ke-%d: %s\n", i, S.Elements[i]);
    }

    DeleteSet(&S, "COBA 2");

    if(IsMemberSet(S, "COBA 2")){
        printf("COBA 2 masih ada\n");
    }else{
        printf("COBA 2 sudah tidak ada\n");
    }

    for(int i = 0; i<S.Count; i++){
        printf("Elemen ke-%d: %s\n", i, S.Elements[i]);
    }
}