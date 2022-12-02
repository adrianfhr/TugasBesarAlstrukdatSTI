#include "game.h"
#include "diner_dash.h"

int RNG(){
    int a;
    int i,count;
    char input[10];
    time_t t;
    int b,c;
    t = time(NULL);
    b=t%100;
    c=t%b+1;
    boolean play;
    play = true;
    count = 0;
    while (play){
        printf("Tebakan :");
        STARTWORD();
        KataToString(currentWord, input);
        a=atoi(input);
        count = count+1;
        if (a==c){
            printf ("Ya, X adalah %d.\n",c);
            int skor = 100 - count;
            play = false;
            printf("Skor kamu adalah : %d\n",skor);
            return skor;
        }else if (a<c){
            printf("Lebih besar\n");
        }else if (a>c){
            printf("Lebih kecil\n");
        }
    }
} 

int DinerDash(){
    int saji,antri,saldo;
    int current_serve;
    int c,d,i,j;
    char input[30];
    char a;
    int b;
    int dompet;
    boolean valid;
    int target; 
    Array cooking;
    Array serving;
    Array ready;
    Array oncook;
    Array durasi,ketahanan,harga;
    saldo=0;
    for(i=0;i<15;i=i+1){
        cooking.Capacity[i]=-1;
        serving.Capacity[i]=-1;
        ready.Capacity[i]=-1;
        oncook.Capacity[i]=-1;
    }
    dompet=0;
    current_serve=0;
    c=0;
    d=3;
    saji=0;
    antri=3;
    valid=false;
    Beginning(&durasi,&ketahanan,&harga);
    while(antri<7 && saji<15){
        while(valid==false){
        printf("MASUKKAN COMMAND:");
                STARTWORD();
                KataToString(currentWord, input);
                if(stringcompare(input, "COOK") == 1)
                {
                STARTWORD();
                KataToString(currentWord, input);
                if(input[0]=='M'){
                    int indexM = 1;
                    char *tempM = (char*)malloc(sizeof(char)*currentWord.Length);
                    while(input[indexM] != '\0'){
                        tempM[indexM-1] = input[indexM];
                        indexM++;
                    }
                    tempM[indexM] = '\0';
                a=atoi(tempM);
                b=a;
                if(durasi.Capacity[b]<1){
                printf("Command salah\n");
                }else{
                if(oncook.Capacity[b]==-1){
                    j=durasi.Capacity[b];
                    cooking.Capacity[b]=j;
                    oncook.Capacity[b]=2;
                    valid=true;
                
                }else{
                printf("Command salah\n");
                }
                }
                }else{
                printf("Command salah\n");
                }
                }
                else if(stringcompare(input, "SERVE") == 1)
                {
                STARTWORD();
                KataToString(currentWord, input);
                if(input[0]=='M'){
                    int indexM = 1;
                    char *tempM = (char*)malloc(sizeof(char)*currentWord.Length);
                    while(input[indexM] != '\0'){
                        tempM[indexM-1] = input[indexM];
                        indexM++;
                    }
                    tempM[indexM] = '\0';
                a=atoi(tempM);
                b=a;
                if(ready.Capacity[b]==2){
                    if(current_serve!=b){
                        berhasil(3,b,current_serve);
                    }else{
                        ready.Capacity[b]=1;
                        dompet=dompet+harga.Capacity[b];
                        saji=saji+1;
                        berhasil(1,b,current_serve);
                        c=c+1;
                        antri=antri-1;
                        valid=true;
                    }
                }else{
                printf("Belum bisa menyajikan M%d\n",b);
                }
                }else{
                printf("Command salah\n");
                }
                }
                else if(stringcompare(input, "SKIP") == 1)
                {
                    valid=true;
                }else
                {
                    printf("Command salah\n");
                }
        }
        valid=false;
        turun(&cooking,&serving);
        for(i=0;i<15;i=i+1){
            if(cooking.Capacity[i]==0){
                ready.Capacity[i]=2;
                cooking.Capacity[i]=cooking.Capacity[i]-1;
                serving.Capacity[i]=ketahanan.Capacity[i];
                berhasil(0,i,current_serve);
            }
            if(serving.Capacity[i]==0){
                serving.Capacity[i]=serving.Capacity[i]-1;
                ready.Capacity[i]=-1;
                oncook.Capacity[i]=-1;
            }
        }
        printf("==========================================================\n");
        d=d+1;
        antri=antri+1;
        durasi.Capacity[d-1]=(Number(39)%2)+1;
        ketahanan.Capacity[d-1]=(Number(39)%2)+1;
        harga.Capacity[d-1]=((Number(39)%2)+1)*10000;
        Saldo(dompet);
        TOP();
        for(i=c;i<d;i=i+1){
            Menu(i,durasi.Capacity[i],ketahanan.Capacity[i],harga.Capacity[i]);
        }
        Middle();
        for(i=0;i<15;i=i+1){
            if (oncook.Capacity[i]==2&& cooking.Capacity[i]>0){
                Cook(i,cooking.Capacity[i]);
            }
        }
        Bottom();
        for(i=0;i<15;i=i+1){
            if (ready.Capacity[i]==2){
                Serve(i,serving.Capacity[i]);
            }
        }
    }
        printf("GAME OVER\n");
    if(antri>=7){
        printf("Anda Kalah\n");
    }else{
        printf("Selamat Anda Menang\n");
    }
    saldo= saldo/ 10000;
    printf("Skor akhir = %d\n");
    return saldo;
}
int GameTambahan(){
    struct tm* ptr;
    time_t t;
    int a,b,c;
    t = time(NULL);
    ptr = localtime(&t);
    a =mktime(ptr);
    b=a%100;
    c=a%b;
    printf("GAME OVER\n");
    printf("FINAL SCORE : %d \n",c);
    return c;
}

void kerangajaib(){
    time_t t;
    int a,b;
    boolean play = true;
    while(play)
    {
    t = time(NULL);
    b=t%5;
    printf("Ketik 'QUIT' jika anda ingin keluar game \n");
    printf("Apa yang kau ingin tanyakan pada kerang ajaib :\n",b);
    STARTCREATE();
    b = (b*currentWord.Length)*t % 5 ;
    char *inputkerang = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, inputkerang);
    if(stringcompare(inputkerang, "QUIT") == 1){
        play = false;
    }else if (b==0){
        printf("Kerang Ajaib : Ya\n");
    }else if (b==1){
        printf("Kerang Ajaib : Tidak\n");
    }else if(b==2){
        printf("Kerang Ajaib : Mungkin\n");
    }else if(b==3){
        printf("Kerang Ajaib : Tidak Mungkin\n");
    }else{
        printf("Kerang Ajaib : Tidak Tahu\n");
    }

    printf("\n");
    }
}
int TOH(){
    return towerofhanoimain();
}

int Hangman(){
   return HangmanMain();
}

int Snake(){
    return snakegame();
}