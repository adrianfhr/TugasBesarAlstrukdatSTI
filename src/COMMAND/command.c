#include "command.h"

FILE *file = NULL;
ArrayDin ListGame;
Queue GameQueue;
char *userplaygame;
int command = 9999;


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
                if(strcmp(userCommand, "CREATE") == 0)
                {
                    CREATEGAME(&ListGame);
                }
                else if(strcmp(userCommand, "LISTGAME") == 0)
                {
                    LISTGAME();
                }
                else if(strcmp(userCommand, "DELETE") == 0)
                {
                    DELETEGAME(&ListGame);
                }
                else if(strcmp(userCommand, "QUEUE") == 0)
                {
                    QUEUEGAME(&GameQueue);
                }
                else if(strcmp(userCommand, "PLAY") == 0)
                {
                    PLAYGAME(&GameQueue, &userplaygame);
                }
                else if(strcmp(userCommand, "SKIP") == 0)
                {
                    SKIPGAME(&GameQueue, &userplaygame);
                }
                else if(strcmp(userCommand, "SAVE") == 0)
                {
                    SAVE();
                }
                else if(strcmp(userCommand, "QUIT") == 0)
                {
                    QUIT();
                }
                else if(strcmp(userCommand, "HELP") == 0)
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
    printf("START GAME!\n");
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
    strcat(filename, file);
    system("cls");
    printf("LOAD GAME!\n");
    STARTREADGAME(filename);
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

void SAVE(){
}

void CREATEGAME(ArrayDin *ListGame){
    system("cls");
    printf("CREATE GAME!\n");
    printf("Masukkan nama game: ");
    STARTWORD();
    char *game = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, game);
    InsertKataLast(ListGame, game);
}

void LISTGAME(){
    printf("\n");
    printf("LIST GAME!\n");
    printf("Daftar game yang tersedia:\n");
    for(int i = 0; i < Length(ListGame); i++)
    {
        printf("%d. %s\n", i+1, ListGame.A[i]);
    }
}

void DELETEGAME(ArrayDin *ListGame){
    system("cls");
    printf("DELETE GAME!\n");
    printf("Berikut adalah daftar game yang tersedia:\n");
    LISTGAME();
    printf("Masukkan nomor game yang ingin dihapus: ");
    STARTWORD();
    char *deletegame = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, deletegame);
    int delete = stringtoint(deletegame)-1;
    if(delete < Length(*ListGame))
    {
        DeleteAt(ListGame, delete);
        printf("Game berhasil dihapus.\n");
    }
    else
    {
        printf("Game tidak ditemukan.\n");
    }
}

void QUEUEGAME(Queue *GameQueue){
    system("cls");
    if(isEmpty(*GameQueue)){
        printf("kamu Belum memiliki antrian game\n");
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
        printf("kamu Belum memiliki antrian game\n");
    }else
    {
        DisplayGame();
        printf("Loading %s ...", GameQueue->buffer[GameQueue->idxHead]);
        dequeue(GameQueue, &userplaygame);
    }
}

void SKIPGAME(Queue *GameQueue, char *userplaygame){
    system("cls");
    if(isEmpty(*GameQueue)){
        printf("kamu Belum memiliki antrian game\n");
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
        printf("kamu Belum memiliki antrian game\n");
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

