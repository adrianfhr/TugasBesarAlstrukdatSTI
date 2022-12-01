#include <stdio.h>
#include "map.h"
#include "arraydinmap.h"

void STARTSCOREBOARD(arraymap *arrmap){
    *arrmap = Makearraymap();
    Map DINERDASH,RNG,HANGMAN,TOH,SNAKEONMETEOR,KERANGAJAIB;
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&RNG);
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&HANGMAN);
    CreateEmptyMap(&TOH);
    CreateEmptyMap(&SNAKEONMETEOR);
    CreateEmptyMap(&KERANGAJAIB);
    InsertLastarrmap(arrmap,DINERDASH);
    InsertLastarrmap(arrmap,RNG);
    InsertLastarrmap(arrmap,HANGMAN);
    InsertLastarrmap(arrmap,TOH);
    InsertLastarrmap(arrmap,SNAKEONMETEOR);
    InsertLastarrmap(arrmap,KERANGAJAIB);
}

void PRINTSCOREBOARD(int x){

    if(scoreboardlist.A[x].Count == 0){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        for(int i=0;i<scoreboardlist.A[x].Count;i++){
            if(stringlen(scoreboardlist.A[x].Elements[i].Key) < 6){
                printf("| %s\t\t| %d\t\t|\n", scoreboardlist.A[x].Elements[i].Key, scoreboardlist.A[x].Elements[i].Value);
            }else if(stringlen(scoreboardlist.A[x].Elements[i].Key) < 14){
                printf("| %s\t| %d\t\t|\n", scoreboardlist.A[x].Elements[i].Key, scoreboardlist.A[x].Elements[i].Value);
            }
        }
    }
}

void SCOREBOARD(arraymap scoreboardlist){
    for(int i=0;i<Lengtharrmap(scoreboardlist);i++){
        printf("**** SCOREBOARD %s ****\n", ListGame.A[i]);
        PRINTSCOREBOARD(i);
        printf("\n");
    }

}

void INSERTSCOREBOARD(arraymap* scoreboardlist, int x, int skor){
    printf("Masukkan nama: ");
    STARTWORD();
    if(currentWord.Length > 13){
        printf("Nama terlalu panjang, maksimal 13 karakter.\n");
        while(currentWord.Length > 13){
            printf("Masukkan nama: ");
            STARTWORD();
        }
    }
    char* nama = (char*)malloc(currentWord.Length*sizeof(char));
    KataToString(currentWord, nama);
    if(IsEmptyMap(scoreboardlist->A[x])){
        printf("Masuk sini \n");
        InsertMap(&scoreboardlist->A[x],nama,skor);
    }else{
        if(IsMemberMap(scoreboardlist->A[x],nama)){
            int temp = ValueMap(scoreboardlist->A[x],nama);
            if(temp < skor){
                UpdateMap(&scoreboardlist->A[x],nama,skor);
            }
        }else{
            int index = 0;
            boolean found = false;
            while (index < scoreboardlist->A[x].Count && !found){
                if (scoreboardlist->A[x].Elements[index].Value < skor){
                    found = true;
                }
                else{
                    index++;
                }
                InsertAtMap(&scoreboardlist->A[x],nama,skor,index);
            }
        }
    }
    
}