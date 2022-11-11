#include "command.h"

FILE *file = NULL;
ArrayDin ListGame;
Queue GameQueue;
char *userplaygame;
int command = 9999;
int ingame = 0;


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
        printf("1. CREATE\n");
        printf("2. LISTGAME\n");
        printf("3. DELETE\n");
        printf("4. QUEUE\n");
        printf("5. PLAY\n");
        printf("6. SKIP\n");
        printf("7. SAVE\n");
        printf("8. QUIT\n");
        printf("9. HELP\n");
        printf("Example Command: CREATE\n");
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
                       commandmenu();
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
                }
                else
                {
                    COMMANDLAIN();
                }
}

void STARTBNMO(){
    system("cls");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    char *file = "..\\data\\default.txt";
    STARTREADGAME(file);
    ListGame = MakeArrayDin();
    CreateQueue(&GameQueue);
    int jumlahgame = currentWord.TabWord[0] - 48;
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
        int jumlahgame = currentWord.TabWord[0] - 48;
        ADVREADGAME();
        for(int i = 0; i < jumlahgame; i++)
        {
            char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
            KataToString(currentWord, game);
            InsertKataLast(&ListGame, game);
            ADVREADGAME();
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

    if(delete < Length(*ListGame) && delete > 4 && !found)
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
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead], "Diner Dash") == 1){
            ingame = 2;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"Xloming") == 1){
            ingame = 3;
        }else{
            printf("Game %s masih dalam maintenance,belum dapat dimainkan.\nSilahkan pilih game lain.", GameQueue->buffer[GameQueue->idxHead]);
        }
        gamecurrent();
        dequeue(GameQueue, &userplaygame);
    }
}

void SKIPGAME(Queue *GameQueue, char *userplaygame){
    system("cls");
    if(isEmpty(*GameQueue)){
        printf("Kamu belum memiliki antrian game\n");
    }else
    {
        ADVLOADGAME();
        DisplayGame();
        char*skip = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, skip);
        int skipgame = stringtoint(skip);
        printf("Loading %s ...", GameQueue->buffer[skipgame]);
        dequeueAt(GameQueue, skipgame, &userplaygame);
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
    printf("4. CREATE       <Menambah game baru pada daftar game> \n");
    printf("5. LISTGAME     <Menampilkan daftar game> \n");
    printf("6. DELETE       <Menghapus suatu game dari daftar game> \n");
    printf("7. QUEUE        <Mendaftarkan permainan kedalam daftar antrian game> \n");
    printf("8. PLAY         <Memainkan sebuah permainan> \n");
    printf("9. SKIP         <Melewatkan permainan> \n");
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

int stringtoint(char *string)
{
    int i = 0;
    int hasil = 0;
    while(string[i] != '\0')
    {
        hasil = hasil * 10 + (string[i] - 48);
        i++;
    }
    return hasil;
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
    }
}
