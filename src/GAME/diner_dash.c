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
    a=Number(4)+1;
    b=Number(3)+2;
    c=Number(4)+1;
    printf("Selamat Datang di Diner Dash!\n");
    Saldo(0);
    TOP();
    Menu(0,a,b,c* 10000);
    durasi->Capacity[0]=a;
    durasi->Capacity[1]=b;
    durasi->Capacity[2]=c;
    a=(Number(203)%3)+2;
    b=(Number(450)%4)+1;
    c=(Number(22)%4)+1;
    Menu(1,a,b,c*10000);
    ketahanan->Capacity[0]=a;
    ketahanan->Capacity[1]=b;
    ketahanan->Capacity[2]=c;
    a=(Number(59)%3)+1;
    b=(Number(36)%4)+1;
    c=(Number(97)%4)+1;
    Menu(2,a,b,c*10000);
    harga->Capacity[0]=a;
    harga->Capacity[1]=b;
    harga->Capacity[2]=c;
    Middle();
    Bottom();
}

int playdiner(){
    int saji,antri;
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
                if(stringcompare(input, "COOK") == 0)
                {
                STARTWORD();
                KataToString(currentWord, input);
                if(input[0]=='M'){
                a=input[1];
                sscanf(&a,"%d",&b);
                if(oncook.Capacity[b]==-1){
                    j=durasi.Capacity[b];
                    cooking.Capacity[b]=j;
                    oncook.Capacity[b]=2;
                    valid=true;
                }else{
                printf("Command salah\n");
                }
                }else{
                printf("Command salah\n");
                }
                }
                else if(stringcompare(input, "SERVE") == 0)
                {
                STARTWORD();
                KataToString(currentWord, input);
                if(input[0]=='M'){
                a=input[1];
                sscanf(&a,"%d",&b);
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
                else if(stringcompare(input, "SKIP") == 0)
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
        durasi.Capacity[d-1]=(Number(39)%5)+1;
        ketahanan.Capacity[d-1]=(Number(39)%5)+1;
        harga.Capacity[d-1]=((Number(39)%5)+1)*10000;
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
    return dompet;
}