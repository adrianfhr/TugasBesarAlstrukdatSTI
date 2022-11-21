#include"diner_dash.h"

void TOP(){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
}

void Saldo(int s){
    printf("SALDO: %d\n",s);
}

void Middle(){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");  
}

void Bottom(){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-----------------------------\n");  
}

void Menu(int m, int d, int k, int h){
    printf("M%d      | %d              | %d         | %d\n",m,d,k,h);
}

void Cook(int m, int d){
    printf("M%d      | %d\n",m,d); 
}

void Serve(int m, int k){
    printf("M%d      | %d\n",m,k); 
}

void berhasil(int status, int m, int c){
    if (m==c){
        if(status==1){
            printf("Berhasil mengantar M%d\n",m);
        }else{ 
            printf("Berhasil memasak M%d\n",m);
            }
    }else{
    printf("M%d belum dapat disajikan karena M%d belum selesai\n",m,c);
    }
    
}

int Number(int rng){
    struct tm* ptr;
    long int t;
    long int b,c;
    t = time(NULL);
    b=t%100;
    c=b%rng;
    return c;
}

void turun(Array *cooking,Array *serving){
    int i;
            for (i=0;i<15;i=i+1){
                if (cooking->Capacity[i]>0){
            cooking->Capacity[i]=cooking->Capacity[i]-1;
            }
                }
        for (i=0;i<15;i=i+1){
            if (serving->Capacity[i]>0){
            serving->Capacity[i]=serving->Capacity[i]-1;
            }
        }
}

void Beginning(Array *durasi,Array *ketahanan,Array *harga){
    int a,b,c;
    a=Number(2)+1;
    b=Number(2)+2;
    c=Number(2)+1;
    printf("Selamat Datang di Diner Dash!\n");
    Saldo(0);
    TOP();
    Menu(0,a,b,c* 10000);
    durasi->Capacity[0]=a;
    durasi->Capacity[1]=b;
    durasi->Capacity[2]=c;
    a=(Number(203)%2)+2;
    b=(Number(450)%2)+1;
    c=(Number(22)%2)+1;
    Menu(1,a,b,c*10000);
    ketahanan->Capacity[0]=a;
    ketahanan->Capacity[1]=b;
    ketahanan->Capacity[2]=c;
    a=(Number(59)%2)+1;
    b=(Number(36)%2)+1;
    c=(Number(97)%2)+1;
    Menu(2,a,b,c*10000);
    harga->Capacity[0]=a;
    harga->Capacity[1]=b;
    harga->Capacity[2]=c;
    Middle();
    Bottom();
}