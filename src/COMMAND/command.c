#include "command.h"

FILE *file = NULL;
ArrayDin ListGame;
Queue GameQueue;
char *userplaygame;
int command = 9999;
int ingame = 0;
arraymap scoreboardlist;


void mainmenu(){
        printf("Welcome to BNMO!\n");
        printf("================\n");
        printf("Choose your command:\n");
        printf("1. START\n");
        printf("2. LOAD\n");
        printf("Example Command: START\n");
        printf(">> ");
}

void commandmenu(){
        printf("\n");
        printf("Welcome to BNMO!\n");
        printf("Choose your command:\n");
        printf("1. CREATE GAME\n");
        printf("2. LIST GAME\n");
        printf("3. DELETE GAME\n");
        printf("4. QUEUE GAME\n");
        printf("5. PLAY GAME\n");
        printf("6. SKIPGAME\n");
        printf("7. SAVE\n");
        printf("8. QUIT\n");
        printf("9. HELP\n");
        printf("10. SCOREBOARD\n");
        printf("11. RESET SCOREBOARD\n");
        printf("Example Command: CREATE GAME\n");
        printf(">> ");
}

void commandconfig(){
                commandmenu();
                STARTWORD();
                char *userCommand = (char*) malloc (currentWord.Length+1);
                KataToString(currentWord, userCommand);
                if(stringcompare(userCommand, "CREATE") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "GAME") == 1)
                    {   
                        CREATEGAME(&ListGame);
                    }else{
                        COMMANDLAIN();
                    }
                }
                else if(stringcompare(userCommand, "LIST") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "GAME") == 1)
                    {   
                       LISTGAME();
                    }else{
                        COMMANDLAIN();
                    }
                }
                else if(stringcompare(userCommand, "DELETE") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "GAME") == 1)
                    {   
                        DELETEGAME(&ListGame);
                    }else{
                        COMMANDLAIN();
                    }
            
                }
                else if(stringcompare(userCommand, "QUEUE") == 1)
                {
                    
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "GAME") == 1)
                    {   
                        QUEUEGAME(&GameQueue);
                    }else{
                        COMMANDLAIN();
                    }
                }
                else if(stringcompare(userCommand, "PLAY") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "GAME") == 1)
                    {   
                        PLAYGAME(&GameQueue, &userplaygame);
                    }else{
                        COMMANDLAIN();
                    }
                }
                else if(stringcompare(userCommand, "SKIPGAME") == 1)
                {
                    SKIPGAME(&GameQueue, &userplaygame);
                }
                else if(stringcompare(userCommand, "SAVE") == 1)
                {
                    SAVE();
                }
                else if(stringcompare(userCommand, "QUIT") == 1)
                {
                    QUIT();
                }
                else if(stringcompare(userCommand, "HELP") == 1)
                {
                    HELP();
                }else if (stringcompare(userCommand, "SCOREBOARD") == 1)
                {
                    SCOREBOARD();
                }else if (stringcompare(userCommand, "RESET") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "SCOREBOARD") == 1)
                    {   
                        //RESETSCOREBOARD();
                    }else{
                        COMMANDLAIN();
                    }
                    /* code */
                }else
                {
                    COMMANDLAIN();
                }
}

void STARTBNMO(){
    system("cls");
    STARTSCOREBOARD();
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    char *file = "..\\data\\default.txt";
    STARTREADGAME(file);
    ListGame = MakeArrayDin();
    CreateQueue(&GameQueue);
    int jumlahgame = currentWord.TabWord[0] - 48; // UBAH YAA
    ADVREADGAME();
    for(int i = 0; i < jumlahgame; i++)
    {
        char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
        KataToString(currentWord, game);
        InsertKataLast(&ListGame, game);
        ADVREADGAME();
    }
}

void LOADBNMO(){ 
    STARTSCOREBOARD();
    ADVLOADGAME();
    char *file = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, file);
    char filename[] = "..\\data\\";
    concat(filename, file);
    system("cls");
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    STARTREADGAME(filename);
    if(currentChar != MARK){
        ListGame = MakeArrayDin();
        CreateQueue(&GameQueue);
        char *jlhgame = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, jlhgame);
        int jumlahgame = stringtoint(jlhgame);
        ADVREADGAME();
        for(int i = 0; i < jumlahgame; i++)
        {
            char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
            KataToString(currentWord, game);
            InsertKataLast(&ListGame, game);
            ADVREADGAME();
        }
        
        for(int i = 0; i < jumlahgame; i++)
        {
            char *jmlhskor = (char*) malloc (currentWord.Length+1);
            KataToString(currentWord, jmlhskor);
            int jumlahskor = stringtoint(jmlhskor);
            if(jumlahskor != 0){
                for(int j = 0; j < jumlahskor; j++){
                    ADVLOADGAME();
                    char *nama = (char*) malloc (currentWord.Length+1);
                    KataToString(currentWord, nama);
                    ADVLOADGAME();
                    char *skor = (char*) malloc (currentWord.Length+1);
                    KataToString(currentWord, skor);
                    int skorint = stringtoint(skor);
                    InsertMap(&scoreboardlist.A[0], nama, skorint);
                }
            }
            ADVLOADGAME();
        }
        
    }
}

void SAVE(){
    system("cls");
    ADVLOADGAME();
    char *file = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, file);
    char filename[] = "..\\data\\";
    concat(filename, file);
    FILE *savefile = fopen(filename, "w");
    fprintf(savefile, "%d\n", Length(ListGame));
    for(int i = 0; i < Length(ListGame); i++)
    {
        fprintf(savefile, "%s\n", ListGame.A[i]);
    }
    fprintf(savefile, ".");
    printf("Save file berhasil disimpan.\n");
    fclose(savefile);
}

void CREATEGAME(ArrayDin *ListGame){
    system("cls");
    printf("CREATE GAME!\n");
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCREATE();
    char *game = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, game);
    InsertKataLast(ListGame, game);
    printf("Game berhasil ditambahkan.\n");
}

void LISTGAME(){
    printf("\n");
    printf("LIST GAME!\n");
    printf("Berikut adalah daftar game yang tersedia:\n");
    for(int i = 0; i < Length(ListGame); i++)
    {
        printf("%d. %s\n", i+1, ListGame.A[i]);
    }
}

void DELETEGAME(ArrayDin *ListGame){
    system("cls");
    printf("DELETE GAME!\n");
    LISTGAME();
    printf("Masukkan nomor game yang ingin dihapus: ");
    STARTWORD();
    char *deletegame = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, deletegame);
    int delete = stringtoint(deletegame)-1;
    boolean found = false;
    for(int i = 0; i < length(GameQueue); i++)
    {
        if(stringcompare(GameQueue.buffer[i], ListGame->A[delete]) == 1)
        {
            found = true;
        }
    }

    if(delete < Length(*ListGame) && delete > 5 && !found)
    {
        DeleteAt(ListGame, delete);
        printf("Game berhasil dihapus.\n");
    }
    else
    {
        printf("Game gagal dihapus.\n");
    }
}

void QUEUEGAME(Queue *GameQueue){
    system("cls");
    if(isEmpty(*GameQueue)){
        printf("Kamu belum memiliki antrian game\n");
    }else
    {
        DisplayGame();
    }
    LISTGAME();
    printf("Nomor Game yang mau ditambahkan ke antrian : ");
    STARTWORD();
    char *antrian = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, antrian);
    int antriangame = stringtoint(antrian);
    char *game = (char*) malloc (100);
    game = ListGame.A[antriangame-1];
    if(antriangame-1 < Length(ListGame))
    {
        printf("Game %s berhasil ditambahkan ke antrian.\n", ListGame.A[antriangame-1]);
       
        enqueue(GameQueue, game);
    }
    else
    {
        printf("Game tidak ditemukan.\n");
    }
}

void PLAYGAME(Queue *GameQueue, char *userplaygame){
    system("cls");
    if(isEmpty(*GameQueue)){
        printf("Kamu belum memiliki antrian game\n");
    }else
    {
        DisplayGame();
        printf("Loading %s ...\n", GameQueue->buffer[GameQueue->idxHead]);
        char *ingamestr;
        ingamestr = GameQueue->buffer[GameQueue->idxHead];
        if(stringcompare(GameQueue->buffer[GameQueue->idxHead], "RNG") == 1){
            ingame = 1;
            printf("Game %d berhasil dimainkan.\n", ingame);
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead], "Diner DASH") == 1){
            ingame = 2;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"Kerang Ajaib") == 1){
            ingame = 4;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"HANGMAN") == 1){
            ingame = 6;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"TOWER OF HANOI") == 1){
            ingame = 5;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"SNAKE ON METEOR") == 1){
            ingame = 7;
        }else{
            ingame = 3;
        }
        printf("\n");
        gamecurrent();
        dequeue(GameQueue, &userplaygame);
    }
}

void SKIPGAME(Queue *GameQueue, char *userplaygame){
    system("cls");
    if(isEmpty(*GameQueue)){
        ADVLOADGAME();
        printf("Kamu belum memiliki antrian game\n");
    }else
    {
        ADVLOADGAME();
        char*skip = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, skip);
        int skipgame = stringtoint(skip);
        if(!isEmpty(*GameQueue) && skipgame <= length(*GameQueue)){
            for (int i = 0; i < skipgame; i++){
                dequeue(GameQueue, &userplaygame);
                }
        }else if(skipgame > length(*GameQueue)){
            for (int i = 0; i < length(*GameQueue); i++){
                dequeue(GameQueue, &userplaygame);
            }
        }
        if(!isEmpty(*GameQueue)){
            PLAYGAME(GameQueue, userplaygame);
        }else{
            printf("Tidak ada permainan lagi dalam daftar game-mu\n");
        }
    }
}

void QUIT(){
    system("cls");
    printf("QUIT GAME!\n");
    printf("Terima kasih telah bermain BNMO!\n");
    command = 0;
}

void HELP(){
    system("cls");
    printf("HELP GAME!\n");
    printf("Daftar perintah yang tersedia:\n");
    printf("1. START        <Menjalankan BNMO> \n");
    printf("2. LOAD         <Membaca savefile> \n");
    printf("3. SAVE         <Menyimpan state game pemain saat ini ke dalam file> \n");
    printf("4. CREATE GAME  <Menambah game baru pada daftar game> \n");
    printf("5. LIST GAME    <Menampilkan daftar game> \n");
    printf("6. DELETE GAME  <Menghapus suatu game dari daftar game> \n");
    printf("7. QUEUE GAME   <Mendaftarkan permainan kedalam daftar antrian game> \n");
    printf("8. PLAY GAME    <Memainkan sebuah permainan> \n");
    printf("9. SKIPGAME     <Melewatkan permainan> \n");
    printf("10. QUIT        <Keluar dari program> \n");
    printf("11. HELP        <Bantuan command-command> \n");
}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}

void DisplayGame(){
    if(isEmpty(GameQueue)){
        printf("kamu belum memiliki antrian game\n");
    }else{
        int x = 0;
    printf("\n");
    printf("Berikut adalah daftar antrian game-mu :\n");
        for(int i = GameQueue.idxHead; i <= GameQueue.idxTail; i = (i+1)%CAPACITY)
        {
            x++;
            printf("%d. %s\n", x, GameQueue.buffer[i]);
        }
    printf("\n");
    }
}


void WelcomeBNMO(FILE *w){
char welcome[500];
while(fgets(welcome, sizeof(welcome), w) != NULL) {
        printf("%s",welcome);
    }
}

void gamecurrent(){
    if(ingame == 1){
        RNG();
    }else if(ingame == 2){
        DinerDash();
    }else if (ingame == 3)
    {
        GameTambahan();
    }else if (ingame == 4)
    {
        kerangajaib();
    }else if (ingame == 5)
    {
        TOH();
    }else if(ingame == 6){
        Hangman();
    }

    // }else if(ingame == 7){
    //     Snake();
    // }

}

// void RESETSCOREBOARD (){

//     printf("DAFTAR SCOREBOARD:\n"); 
//     for (int i = 0; i<Lengtharrmap(scoreboardlist);i++){
//         printf("%d. %s\n",i ,scoreboardlist.A[i]);
//     }

//     int reset;
//     printf ("SCOREBOARD YANG INGIN DIHAPUS: "); 
//     scanf("%d\n",&reset);
//     char confirm;
//     printf ("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ",scoreboardlist.A[reset]);
//     scanf ("%c\n",&confirm);
//     if (reset == "0" && confirm == "YA"){
//         for (int i = 1; i<Lengtharrmap(scoreboardlist);i++){
//             arr.A[i].Count = Nil;
//         }
//         printf("Scoreboard berhasil di-reset.");
//     }
//     else if (reset != 0 && reset < Lengtharrmap(scoreboardlist) && confirm == "YA"){
//         arr.A[reset].Count = Nil; 
//         printf("Scoreboard berhasil di-reset.");
//     }
//     else{ //tidak jadi reset scoreboard
//         printf("Scoreboard tidak berhasil di-reset.");
//     }
   
// }

void STARTSCOREBOARD(){
    arraymap scoreboardlist = Makearraymap();
    Map DINERDASH,RNG,HANGMAN,TOH,SNAKEONMETEOR,KERANGAJAIB;
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&RNG);
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&HANGMAN);
    CreateEmptyMap(&TOH);
    CreateEmptyMap(&SNAKEONMETEOR);
    CreateEmptyMap(&KERANGAJAIB);
    InsertLastarrmap(&scoreboardlist,DINERDASH);
    InsertLastarrmap(&scoreboardlist,RNG);
    InsertLastarrmap(&scoreboardlist,HANGMAN);
    InsertLastarrmap(&scoreboardlist,TOH);
    InsertLastarrmap(&scoreboardlist,SNAKEONMETEOR);
    InsertLastarrmap(&scoreboardlist,KERANGAJAIB);
}

void PRINTSCOREBOARD(int x){
    printf("**** SCOREBOARD GAME KERANG AJAIB ****\n");
    if (IsEmptyMap(scoreboardlist.A[x])){
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

void SCOREBOARD(){
    for(int i=0;i<Lengtharrmap(scoreboardlist);i++){
        PRINTSCOREBOARD(i);
    }

}

// void INSERTSCOREBOARD(arraymap* scoreboardlist, int x, int skor){
//     STARTWORD();
//     printf("Masukkan nama: ");
//     char* nama = (char*)malloc(currentWord.Length*sizeof(char));
//     KataToString(currentWord, nama);
//     if (IsEmptyMap(scoreboardlist->A[x])){
//         InsertMap(&scoreboardlist->A[x],nama,skor);
//     }
//     else{
//         if (IsMemberMap(scoreboardlist->A[x],nama)){
//             int temp = GetMap(scoreboardlist->A[x],nama);
//             if (temp < skor){
//                 UpdateMap(&scoreboardlist->A[x],nama,skor);
//             }
//         }
//         else{
//             InsertMap(&scoreboardlist->A[x],nama,skor);
//         }
//     }
// }