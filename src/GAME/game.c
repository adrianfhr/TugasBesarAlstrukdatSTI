
#include "game.h"
#include "diner_dash.h"
void RNG(){
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
    count =0;
    while (play){
        printf("Tebakan :");
        STARTWORD();
        KataToString(currentWord, input);
        a=atoi(input);
        count = count+1;
        if (a==c){
            printf ("Ya, X adalah %d.\n",c);
            play = false;
        }else if (a<c){
            printf("Lebih besar\n");
        }else if (a>c){
            printf("Lebih kecil\n");
        }
    }
} 

void DinerDash(){

}
/*Indra dan Doni juga suka permainan yang menegangkan. Oleh karena itu, ia ingin ada sebuah game Diner Dash dalam BNMO. Secara singkat, Diner Dash merupakan permainan mengantar makanan namun terurut berdasarkan prioritasnya. Berikut adalah spesifikasi game ini:
Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE
COOK merupakan command yang bertujuan untuk memasak makanan
SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
Permainan akan dimulai dengan 3 pelanggan. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan secara random dengan menggunakan random number generator. Durasi dan ketahanan makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000.
Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian.
Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan.
Pada setiap putaran, akan terdapat 1 pelanggan baru. 
Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE.
Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan.
Skor akhir dari pemain adalah total uang yang diterima oleh pemain.
*/

void GameTambahan(){
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
