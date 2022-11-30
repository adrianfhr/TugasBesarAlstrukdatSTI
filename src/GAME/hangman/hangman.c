
#include "hangman.h"
#include "string.h"


ArrayDin ListKataHangman, ListJawabUser, ListSoal, hangman;
boolean exithangman, win;
int commandhangman, skorhangman;

void hangmanart(ArrayDin* hangman){
    InsertKataLast(hangman, "          \n");
    InsertKataLast(hangman, "\n=========\n");
    InsertKataLast(hangman, "      |\n      |\n      |\n      |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n      |\n      |\n      |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n");    
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n");
    InsertKataLast(hangman, "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\nGAME OVER\n");
}

boolean hangmancompare(ElType S1, ElType S2){
    boolean found = true;
    int i = 0;
    while(S1[i] != '\0' && S2[i] != '\0' && found)
    {
        if (S1[i] != S2[i])
        {
            found = false;
        }else{
            i++;
        }
    }
    return found;
}

void STARTHANGMAN(){
    system("cls");
    char *file = "..\\data\\hangman.txt";
    STARTREADGAME(file);
    ListKataHangman = MakeArrayDin();
    char *jlhkata = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, jlhkata);
    int jumlahkata = stringtoint(jlhkata);
    ADVREADGAME();
    for(int i = 0; i < jumlahkata; i++){
        char *temp = (char*) malloc(currentWord.Length * sizeof(ElType));
        KataToString(currentWord, temp);
        InsertKataLast(&ListKataHangman, temp);
        ADVREADGAME();
    }
}

void SoalHangman(int *alreadypicked, int* alreadypickedcount){
    time_t t;
    t = time(NULL);
    int random = (t+1) % ListKataHangman.Neff;
    if(*alreadypickedcount < ListKataHangman.Neff){
        for(int i = 0; i < *alreadypickedcount; i++){
            if(alreadypicked[i] == random){
                random = (random+1) % ListKataHangman.Neff;
                i = 0;
            }
        }
        alreadypicked[*alreadypickedcount] = random;
        *alreadypickedcount = *alreadypickedcount + 1;
        ListSoal = MakeArrayDin();
        char *tempsoal = (char*) malloc (100* sizeof(ElType));
        tempsoal = ListKataHangman.A[random];
        for(int i = 0; i < strlen(ListKataHangman.A[random]); i++){ //STRLEN GANTI!!!
            char*temp = (char*) malloc(2 * sizeof(ElType));
            temp[0] = tempsoal[i];
            temp[1] = 'z';
            InsertKataLast(&ListSoal, temp);
        }
    } 
}

void CekAnswer(ElType x, int* kesempatan){
    boolean found = false;
    int i = 0;
    while(!found && i < ListSoal.Neff){
        if(hangmancompare(x, ListSoal.A[i]) == 1){
            found = true;
        }
        else{
            i++;
        }
    }
    if(!found){
        *kesempatan = *kesempatan - 1;
    }
}


void JawabUser(ElType jawab){
    if(ListJawabUser.Neff == 0){
        for(int i = 0; i < ListSoal.Neff; i++){
            jawab[i] = '_';
        }
    }else{
        for(int i = 0; i < ListSoal.Neff; i++){
            for (int j = 0; j < ListJawabUser.Neff; j++)
            {
                if(hangmancompare(ListSoal.A[i], ListJawabUser.A[j]) == 1){
                    jawab[i] = ListJawabUser.A[j][0];
                }
            }
        }
    }

    jawab[ListSoal.Neff] = '\0';
}

void CekWin(ElType jawab, boolean *win){
    boolean found = true;
    int i = 0;
    while(i < ListSoal.Neff && found){
        if(jawab[i] == '_'){
            found = false;
        }else{
            i++;
        }
    }

    *win = found;
}

void addkatahangman(ArrayDin *ListKataHangman, char *kata){
    InsertKataLast(ListKataHangman, kata);
}

boolean alreadyhangman(ElType x){
    boolean found = false;
    int i = 0;
    while(i < ListJawabUser.Neff && !(found)){
        if(hangmancompare(x, ListJawabUser.A[i]) == 1){
            printf("Kata Masukan : %s Sudah Ada\n", x);
            printf("kata compare : %s\n",ListJawabUser.A[i]);
            found = true;
        }else{
            i++;
        }
    }
    return found;
}

boolean CekKapital(ElType x){
    boolean found = false;
    int i = 0;
        if(x[i] >= 'A' && x[i] <= 'Z'){
            found = true;
        }else{
            found = false;
        }
    return found;
}


void HangmanMain(){
    system("cls");
    exithangman = false;
    hangman = MakeArrayDin();
    hangmanart(&hangman);
    STARTHANGMAN();
    while(!exithangman){
        printf("HANGMAN!\n");
        printf("Menu:\n");
        printf("1. START\n");
        printf("2. ADD\n");
        printf("3. EXIT\n");
        printf("Pilih Nomor Command: ");
        STARTWORD();
        commandhangman = currentWord.TabWord[0] - 48;
        if(commandhangman == 1){
            skorhangman = 0;
            int alreadypicked[ListKataHangman.Neff];
            int alreadypickedcount = 0;
            win = false;
            ElType katasoal = (char*) malloc(ListSoal.Neff * sizeof(ElType));
            ListJawabUser = MakeArrayDin();
            int kesempatan = 10;
            SoalHangman(alreadypicked, &alreadypickedcount);
            while(kesempatan > 0){
                printf("Kesempatan anda tinggal : %d\n\n", kesempatan);
                printf("%s\n", hangman.A[10-kesempatan]);
                printf("Tebakan Sebelumnya : ");
                if(!IsEmpty(ListJawabUser)){
                    for(int i = 0; i < ListJawabUser.Neff; i++){
                        printf("%s ", ListJawabUser.A[i]);
                    }
                }
                printf("\n");
                /*
                printf("hint :");
                for(int i = 0; i < ListSoal.Neff; i++){
                    printf("%s", ListSoal.A[i]);
                }*/
                printf("\n");
                JawabUser(katasoal);
                printf("Kata : \n");
                int index = 0;
                while(katasoal);
                printf("\n");
                CekWin(katasoal, &win);
                if(win){
                    skorhangman = skorhangman +  ListSoal.Neff;
                    if(alreadypickedcount < ListKataHangman.Neff){
                        system("cls"); 
                        printf("Selamat Kamu Menang!\n\n");
                        SoalHangman(alreadypicked, &alreadypickedcount);
                        printf("kata yang sudah dipilih : %d", alreadypickedcount);
                        win = false;
                        ListJawabUser.Neff = 0;
                    }else{
                        printf("Semua Kata Sudah Ditebak\n");
                        kesempatan = 0;
                    }
                }else{
                    printf("Masukkan Tebakan : ");
                    STARTWORD();
                    char *tebakan = (char*) malloc(currentWord.Length * sizeof(ElType));
                    KataToString(currentWord, tebakan);
                    printf("\n");
                    if(CekKapital(tebakan)){
                        if(!alreadyhangman(tebakan)){
                            system("cls");  
                            InsertKataLast(&ListJawabUser, tebakan);
                            CekAnswer(tebakan, &kesempatan); 
                        }else{
                            system("cls");
                            printf("Huruf '%s' Sudah Pernah Ditebak\n\n", tebakan);
                        }
                    }else{
                        system("cls");
                        printf("Masukkan Huruf Kapital\n\n");
                    }
                }
            }
                printf("%s\n", hangman.A[10]);
                printf("Kata yang benar adalah : ");
                for(int i = 0; i < ListSoal.Neff; i++){
                    printf("%s ", ListSoal.A[i]);
                }
                printf("\nSkor Kamu : %d\n", skorhangman);
                printf("\n\n");
        }else if(commandhangman == 2){
            printf("Masukkan Kata: ");
            STARTWORD();
            char *temp = (char*) malloc(currentWord.Length * sizeof(ElType));
            KataToString(currentWord, temp);
            addkatahangman(&ListKataHangman, temp);
            char hangmanfile[] = "..\\data\\hangman.txt";
            FILE *savehangman = fopen(hangmanfile, "w");
            fprintf(savehangman, "%d\n", Length(ListKataHangman));
            for(int i = 0; i < Length(ListKataHangman); i++)
            {
                fprintf(savehangman, "%s\n", ListKataHangman.A[i]);
            }
            fprintf(savehangman, ".");
            printf("Kata berhasil ditambahkan.\n");
            fclose(savehangman);
        }else if(commandhangman == 3){
            exithangman = true;
        }
    }
}




