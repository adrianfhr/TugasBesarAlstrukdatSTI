#include "command.h"

FILE *file = NULL;
ArrayDin ListGame;
Queue GameQueue;
char *userplaygame;
int command = 9999;
int ingame = 0;
int score = 0;
arraymap scoreboardlist;
Stackstr HistoryGame;

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
        printf("7. SCOREBOARD\n");
        printf("8. RESET SCOREBOARD\n");
        printf("9. HISTORY <n>\n");
        printf("10. RESET HISTORY\n");
        printf("11. SAVE <txt>\n");
        printf("12. HELP\n");
        printf("13. QUIT\n");
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
                        CREATEGAME(&ListGame, &scoreboardlist);
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
                        DELETEGAME(&ListGame, &scoreboardlist, &HistoryGame);
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
                    SCOREBOARD(scoreboardlist);
                }else if (stringcompare(userCommand, "RESET") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(stringcompare(userCommand, "SCOREBOARD") == 1)
                    {   
                        RESETSCOREBOARD(&scoreboardlist);
                    }else if(stringcompare(userCommand, "HISTORY") == 1)
                    {   
                        RESETHISTORY(&HistoryGame);
                    }else{
                        COMMANDLAIN();
                    }
                    /* code */
                }else if(stringcompare(userCommand, "HISTORY") == 1)
                {
                    ADVLOADGAME();
                    KataToString(currentWord, userCommand);
                    if(userCommand[0] >= '0' && userCommand[0] <= '9')
                    {   
                        int x = atoi(userCommand);
                        HISTORY(x);
                    }else{
                        COMMANDLAIN();
                    }
                }else
                {
                    COMMANDLAIN();
                }
}
void STARTBNMO(){
    system("cls");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    char file[] = "..\\data\\default.txt";
    STARTREADGAME(file);
    ListGame = MakeArrayDin();
    CreateQueue(&GameQueue);
    CreateEmptyStackstr(&HistoryGame);
    int jumlahgame = currentWord.TabWord[0] - 48; // UBAH YAA
    ADVREADGAME();
    for(int i = 0; i < jumlahgame; i++)
    {
        char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
        KataToString(currentWord, game);
        InsertKataLast(&ListGame, game);
        ADVREADGAME();
    }
    STARTSCOREBOARD(&scoreboardlist);
}
void LOADBNMO(){ 
    STARTSCOREBOARD(&scoreboardlist);
    ADVLOADGAME();
    char *file = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, file);
    char filename[] = "..\\data\\";
    concat(filename, file);
    system("cls");
    boolean LOADBOOL = STARTREADGAME(filename);
    if(LOADBOOL){
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
        ListGame = MakeArrayDin();
        CreateQueue(&GameQueue);
        CreateEmptyStackstr(&HistoryGame);
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
        char *jlhhistory = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, jlhhistory);
        int jumlahhistory = stringtoint(jlhhistory);
        ADVREADGAME();
        for(int i = 0; i < jumlahhistory; i++)
        {
            char *history = (char*) malloc(currentWord.Length * sizeof(ElType));
            KataToString(currentWord, history);
            PushStackstr(&HistoryGame, history);
            ADVREADGAME();
        }

        for(int i = 0; i < jumlahgame; i++)
        {
            char *jmlhskor = (char*) malloc (currentWord.Length+1);
            KataToString(currentWord, jmlhskor);
            int jumlahskor = atoi(jmlhskor);
            if(jumlahskor != 0){
                for(int j = 0; j < jumlahskor; j++){
                    ADVREADGAME();
                    char *temp = (char*) malloc (currentWord.Length+1);
                    KataToString(currentWord, temp);
                    int index = 0;
                    int indexskor = 0;
                    int indexnama = 0;
                    boolean foundnama = false;
                    char *nama = (char*) malloc (currentWord.Length+1);
                    char *skor = (char*) malloc (currentWord.Length+1);
                    while(temp[index] != '\0' && !foundnama){
                        if(temp[index] == ' '){
                            foundnama = true;
                            index++;
                        }else{
                            nama[indexnama] = temp[index];
                            indexnama++;
                            index++;
                        }
                    }
                    while(temp[index] != '\0'){
                        skor[indexskor] = temp[index];
                        indexskor++;
                        index++;
                    }
                    skor[indexskor] = '\0';
                    nama[indexnama] = '\0';
                    int skorint = atoi(skor);
                    InsertMap(&scoreboardlist.A[i], nama, skorint);
                }
            }
            ADVREADGAME();
        }
    }else{
        printf("BNMO tidak dapat dijalankan.\n");
        command = 0;
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

    fprintf(savefile, "%d\n", lengthStackstr(HistoryGame));
    Stackstr stemp = ReverseStackstr(HistoryGame);
    for (int i = 0; i < lengthStackstr(HistoryGame); i++)
    {
        char *temp = (char*) malloc (100);
        PopStackstr(&stemp, &temp);
        fprintf(savefile, "%s\n", temp);
    }

    for(int i = 0; i<Lengtharrmap(scoreboardlist); i++){
        fprintf(savefile, "%d\n", scoreboardlist.A[i].Count);
        if(!IsEmptyMap(scoreboardlist.A[i])){
            for(int j = 0; j < scoreboardlist.A[i].Count; j++){
                fprintf(savefile, "%s %d\n", scoreboardlist.A[i].Elements[j].Key, scoreboardlist.A[i].Elements[j].Value);
            }
        }
    }

    fprintf(savefile, ".");
    printf("Save file berhasil disimpan.\n");
    fclose(savefile);
}

void CREATEGAME(ArrayDin *ListGame, arraymap *scoreboardlist){
    Map GAMEASAL;
    system("cls");
    printf("CREATE GAME!\n");
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCREATE();
    char *game = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, game);
    boolean found = false;
    for(int i = 0; i < Length(*ListGame); i++){
        if(stringcompare(game, ListGame->A[i])){
            found = true;
        }
    }
    if(found){
        printf("Game sudah ada.\n");
        CREATEGAME(ListGame, scoreboardlist);
    }else{
        InsertKataLast(ListGame, game);
        printf("Game berhasil ditambahkan.\n"); 
        CreateEmptyMap(&GAMEASAL);
        InsertLastarrmap(scoreboardlist, GAMEASAL);
    }
       
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
void DELETEGAME(ArrayDin *ListGame, arraymap *scoreboardlist, Stackstr *HistoryGame){
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
        
        DeleteStackElmt(HistoryGame, ListGame->A[delete]);
        DeleteAt(ListGame, delete);
        DeleteAtarrmap(scoreboardlist, delete);
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
        if(stringcompare(GameQueue->buffer[GameQueue->idxHead], "RNG")){
            ingame = 1;
            printf("Game %d berhasil dimainkan.\n", ingame);
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead], "Diner DASH")){
            ingame = 2;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"Kerang Ajaib")){
            ingame = 4;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"HANGMAN")){
            ingame = 6;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"TOWER OF HANOI")){
            ingame = 5;
        }else if(stringcompare(GameQueue->buffer[GameQueue->idxHead],"SNAKE ON METEOR")){
            ingame = 7;
        }else{
            ingame = 3;

        }
        printf("\n");
        gamecurrent(&scoreboardlist, &HistoryGame);
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
    printf("1. START                <Menjalankan BNMO> \n");
    printf("2. LOAD                 <Membaca savefile> \n");
    printf("3. SAVE                 <Menyimpan state game pemain saat ini ke dalam file> \n");
    printf("4. CREATE GAME          <Menambah game baru pada daftar game> \n");
    printf("5. LIST GAME            <Menampilkan daftar game> \n");
    printf("6. DELETE GAME          <Menghapus suatu game dari daftar game> \n");
    printf("7. QUEUE GAME           <Mendaftarkan permainan kedalam daftar antrian game> \n");
    printf("8. PLAY GAME            <Memainkan sebuah permainan> \n");
    printf("9. SKIPGAME             <Melewatkan permainan> \n");
    printf("10. SCOREBOARD          <Menampilkan nama dan skor untuk semua game> \n");
    printf("11. RESET SCOREBOARD    <Melakukan reset terhadap scoreboard> \n");
    printf("12. HISTORY             <Menampilkan history permainan yang telah dimainkan> \n");
    printf("13. RESET HISTORY       <Menghapus semua history permainan yang dimainkan> \n");
    printf("14. QUIT                <Keluar dari program> \n");
    printf("15. HELP                <Bantuan command-command> \n");
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

void gamecurrent(arraymap *scoreboardlist, Stackstr *HistoryGame){
    if(ingame == 1){
        score = RNG();
        INSERTSCOREBOARD(scoreboardlist, 0, score);
        PushStackstr(HistoryGame, "RNG");
    }else if(ingame == 2){
        score = DinerDash();
        INSERTSCOREBOARD(scoreboardlist, 1, score);
        PushStackstr(HistoryGame, "Diner DASH");
    }else if (ingame == 3)
    {
        score = GameTambahan();
        INSERTSCOREBOARD(scoreboardlist,6, score);
        PushStackstr(HistoryGame, ListGame.A[6]);
    }else if (ingame == 4)
    {
        kerangajaib();
        score = 0;
        INSERTSCOREBOARD(scoreboardlist, 5, score);
        PushStackstr(HistoryGame, "Kerang Ajaib");
    }else if (ingame == 5)
    {
        score = TOH();
        INSERTSCOREBOARD(scoreboardlist, 3, score);
        PushStackstr(HistoryGame, "TOWER OF HANOI");
    }else if(ingame == 6){
        score = Hangman();
        INSERTSCOREBOARD(scoreboardlist, 2, score);
        PushStackstr(HistoryGame, "HANGMAN");
    }else if(ingame == 7){
        score = Snake();
        INSERTSCOREBOARD(scoreboardlist, 4, score);
        PushStackstr(HistoryGame, "SNAKE ON METEOR");
    }
}

void RESETSCOREBOARD( arraymap *scoreboardlist){
    printf("\nDAFTAR SCOREBOARD:\n"); 
    printf("0. ALL\n");
    for(int i = 0; i < Length(ListGame); i++){
        printf("%d. %s\n", i+1, ListGame.A[i]);
    }
    printf("Masukkan nomor game yang ingin direset: ");
    STARTWORD();
    char*reset = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, reset);
    int resetgame = atoi(reset);
    printf("RESET : %d", resetgame);
    if(resetgame == 0){
        printf("\n\nAPAKAH ANDA YAKIN INGIN MERESET SEMUA SCOREBOARD? (YA/TIDAK)\n");
    }else if(resetgame > 0 && resetgame <= Length(ListGame)){
        printf("\n\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD GAME %s ? (YA/TIDAK)\n", ListGame.A[resetgame-1]);
    }else{
        printf("Nomor game tidak valid\n");
    }
    if(resetgame >= 0 && resetgame <= Length(ListGame)){
        STARTWORD();
        char *answer = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, answer);
        if(stringcompare(answer, "YA")){
            if(resetgame == 0){
                for(int i = 0; i < Lengtharrmap(*scoreboardlist); i++){
                    scoreboardlist->A[i].Count= 0;
                }
            }else if(resetgame > 0 && resetgame <= Lengtharrmap(*scoreboardlist)){
                scoreboardlist->A[resetgame-1].Count = 0;
            }
            printf("\nSCOREBOARD BERHASIL DI RESET\n");
        }else if(stringcompare(answer, "TIDAK")){
            printf("Reset scoreboard dibatalkan\n");
        }else{
            printf("Input tidak valid\n");
        }
    }
}
void STARTSCOREBOARD(arraymap *arrmap){
    *arrmap = Makearraymap();
    Map DINERDASH,RNG,HANGMAN,TOH,SNAKEONMETEOR,KERANGAJAIB,GAMETAMBAHAN;
    CreateEmptyMap(&RNG);
    CreateEmptyMap(&DINERDASH);
    CreateEmptyMap(&HANGMAN);
    CreateEmptyMap(&TOH);
    CreateEmptyMap(&SNAKEONMETEOR);
    CreateEmptyMap(&KERANGAJAIB);
    InsertLastarrmap(arrmap,RNG);
    InsertLastarrmap(arrmap,DINERDASH);
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
    else{
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
        InsertMap(&scoreboardlist->A[x],nama,skor);
    }else{
        if(IsMemberMap(scoreboardlist->A[x],nama)){
            printf("\nNama sudah ada di scoreboard\n");
            printf("Silahkan input dengan nama yang berbeda\n\n");
            INSERTSCOREBOARD(scoreboardlist,x,skor);
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

void HISTORY(int x){
    if(IsEmptyStackstr(HistoryGame)){
        printf("Belum ada permainan yang pernah kamu mainkan\n");
    }else{
        printf("Berikut adalah daftar permainan yang pernah kamu mainkan:\n");
        if(x <= lengthStackstr(HistoryGame)){
            for(int i = 0 ; i < x ; i++){
                printf("%d. %s\n", i+1, HistoryGame.T[i]);
            }
        }else{
            printStackstr(HistoryGame);
        }

    }
}

void RESETHISTORY(Stackstr *HistoryGame){
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK)\n");
    STARTWORD();
    char *answer = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, answer);
    if(stringcompare(answer, "YA")){
            CreateEmptyStackstr(HistoryGame);
            printf("Reset history berhasil\n");
    }else if(stringcompare(answer, "TIDAK")){
        printf("Reset history dibatalkan\n");
        HISTORY(lengthStackstr(*HistoryGame));
    }else{
        printf("Input tidak valid\n");
    }
}