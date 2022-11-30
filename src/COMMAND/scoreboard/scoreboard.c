void RESETSCOREBOARD (){

    printf("DAFTAR SCOREBOARD:\n"); 
    for (int i = 0; i<Lengtharrmap(scoreboardlist);i++){
        printf("%d. %s\n",i ,scoreboardlist.A[i]);
    }

    int reset;
    printf ("SCOREBOARD YANG INGIN DIHAPUS: "); 
    scanf("%d\n",&reset);
    char confirm;
    printf ("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ",scoreboardlist.A[reset]);
    scanf ("%c\n",&confirm);
    if (reset == "0" && confirm == "YA"){
        for (int i = 1; i<Lengtharrmap(scoreboardlist);i++){
            arr.A[i].Count = Nil;
        }
        printf("Scoreboard berhasil di-reset.");
    }
    else if (reset != 0 && reset < Lengtharrmap(scoreboardlist) && confirm == "YA"){
        arr.A[reset].Count = Nil; 
        printf("Scoreboard berhasil di-reset.");
    }
    else{ //tidak jadi reset scoreboard
        printf("Scoreboard tidak berhasil di-reset.");
    }
   
}

void STARTSCOREBOARD(){
    arraymap scoreboardlist = Makearraymap();
    Map ALL,DINERDASH,RNG,HANGMAN,TOH,SNAKEONMETEOR,KERANGAJAIB;
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&ALL);
    CreateEmptyMap(&RNG);
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&HANGMAN);
    CreateEmptyMap(&TOH);
    CreateEmptyMap(&SNAKEONMETEOR);
    CreateEmptyMap(&KERANGAJAIB);
    InsertLastarrmap(&scoreboardlist,ALL);
    InsertLastarrmap(&scoreboardlist,DINERDASH);
    InsertLastarrmap(&scoreboardlist,RNG);
    InsertLastarrmap(&scoreboardlist,HANGMAN);
    InsertLastarrmap(&scoreboardlist,TOH);
    InsertLastarrmap(&scoreboardlist,SNAKEONMETEOR);
    InsertLastarrmap(&scoreboardlist,KERANGAJAIB);
}

void PRINTSCOREBOARD(int x){
    printf("**** SCOREBOARD GAME KERANG AJAIB ****\n");
    if (IsEmptyMap()){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        for(int i=0;i<scoreboardlist.A[x].Count;i++){
            printf("|%s             | %d             |\n", scoreboardlist.A[x].Elements[i].Key, scoreboardlist.A[x].Elements[i].Value);
        }
    }
}

void INSERTSCOREBOARD(arraymap* scoreboardlist, int x, int skor){
    STARTWORD();
    printf("Masukkan nama: ");
    char* nama = (char*)malloc(currentWord.Length*sizeof(char));
    KataToString(currentWord, nama);
    if (IsEmptyMap(scoreboardlist->A[x])){
        InsertMap(&scoreboardlist->A[x],nama,skor);
    }
    else{
        if (IsMemberMap(scoreboardlist->A[x],nama)){
            int temp = GetMap(scoreboardlist->A[x],nama);
            if (temp < skor){
                UpdateMap(&scoreboardlist->A[x],nama,skor);
            }
        }
        else{
            InsertMap(&scoreboardlist->A[x],nama,skor);
        }
    }
}