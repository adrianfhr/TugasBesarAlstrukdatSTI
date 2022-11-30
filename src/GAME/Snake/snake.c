#include"snake.h"

int Numbersnake(int rng){
    struct tm* ptr;
    long int t;
    long int a,b,c;
    t = time(NULL);
    b=t%223;
    a=b*(t%11);
    c=a%rng;
    return c;
}

boolean listcompare(ElType S1, ElType S2){
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

void arenagame(int Fruit, int Meteor, List *snake, int obstacle){
    int i;
    intMap m;
    addressl p,temp;
    boolean hit, Hhit, Ohit;
    int a;
    char b[10];
    char arr[25][10]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
hit = false;
Hhit = false;
Ohit  = false;
CreateEmptyintMap(&m);
printf("\n");
for(i=0;i<25;i=i+1){
DeleteintMap(&m,i);
InsertintMap(&m,i," ");
}
DeleteintMap(&m,Fruit);
InsertintMap(&m,Fruit,"O");
p=First(*snake);
a=Infox(p)+Infoy(p)*5;
if(a==obstacle){
    Ohit=true;
}
if(a==Meteor){
    Hhit=true;
}
DeleteintMap(&m,a);
InsertintMap(&m,a,"H");
for (i=0;i<NbElmt(*snake)-1;i=i+1){
p=Next(p);
a=Infox(p)+Infoy(p)*5;
if(a==Meteor){
    hit=true;
    temp=p;
}
DeleteintMap(&m,a);
InsertintMap(&m,a,arr[i]);
}   
DeleteintMap(&m,Meteor);
InsertintMap(&m,Meteor,"M");
DeleteintMap(&m,obstacle);
InsertintMap(&m,obstacle,"^");
printf("Berikut merupakan peta permainan\n");
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,0),ValueintMap(m,1),ValueintMap(m,2),ValueintMap(m,3),ValueintMap(m,4));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,5),ValueintMap(m,6),ValueintMap(m,7),ValueintMap(m,8),ValueintMap(m,9));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,10),ValueintMap(m,11),ValueintMap(m,12),ValueintMap(m,13),ValueintMap(m,14));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,15),ValueintMap(m,16),ValueintMap(m,17),ValueintMap(m,18),ValueintMap(m,19));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,20),ValueintMap(m,21),ValueintMap(m,22),ValueintMap(m,23),ValueintMap(m,24));
printf("=========================\n");
if(!hit && !Ohit && !Hhit && Meteor!=25){
printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
}else if(Hhit){
printf("Kepala snake terkena meteor!\n");
}else if(Meteor==25){

}else if (Ohit){
printf("Kepala snake menabrak obstacle!\n");
}else{
printf("Anda terkena meteor!\n");
printf("Berikut merupakan peta permainan\n");
p=First(*snake);
DelPlist(snake,Infox(temp),Infoy(temp));
for (i=0;i<NbElmt(*snake)-1;i=i+1){
p=Next(p);
a=Infox(p)+Infoy(p)*5;
if(a==Meteor){

}else{
DeleteintMap(&m,a);
InsertintMap(&m,a,arr[i]);
}
}  
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,0),ValueintMap(m,1),ValueintMap(m,2),ValueintMap(m,3),ValueintMap(m,4));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,5),ValueintMap(m,6),ValueintMap(m,7),ValueintMap(m,8),ValueintMap(m,9));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,10),ValueintMap(m,11),ValueintMap(m,12),ValueintMap(m,13),ValueintMap(m,14));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,15),ValueintMap(m,16),ValueintMap(m,17),ValueintMap(m,18),ValueintMap(m,19));
printf("=========================\n");
printf("| %s || %s || %s || %s || %s |\n",ValueintMap(m,20),ValueintMap(m,21),ValueintMap(m,22),ValueintMap(m,23),ValueintMap(m,24));
printf("=========================\n");
printf("Silahkan lanjutkan permainan\n"); 
}
}

void snakestart(int *fruit, List *l, int *obstacle){
    int i;
    int meteor;
    int x,y,r,a;
    boolean down;
printf("Selamat datang di snake on meteor!\n\n");
printf("Mengenerate peta, snake dan makanan . . . \n\n");
printf("Berhasil digenerate!\n");
printf("==========================================================\n");
down=false;
meteor=25;
CreateEmptylist(l);
r=5;
a=Numbersnake(22)%25;
x=a%5;
y=(a-x)/5;
*fruit=Numbersnake(45)%25;
while(*fruit==(x+y*5) ){
*fruit=Numbersnake(45+r)%25;
r=r+6;
}
*obstacle=Numbersnake(45)%25;
while(*obstacle==(x+y*5) || *obstacle==*fruit){
*obstacle=Numbersnake(45+r)%25;
r=r+7;
}
InsertLastlist(l,Alokasilist(x,y));
for(i=0;i<2;i=i+1){
        x=x-1;
        if(down){
            if((x+y*5)==*fruit || (x+y*5)==*obstacle){
            }else{
            x=x+1;
            y=y+1;
            }
            if(y>4){
                y=y-5;
            }
        }
        if(x<0){
            x=x+5;
        }else if((x+y*5)==*fruit || (x+y*5)==*obstacle){
            x=x+1;
            y=y+1;
            if(y>4){
                y=y-5;
            }
            down=true;
        }
        if((x+y*5)==*fruit || (x+y*5)==*obstacle){
            x=x-4;
            y=y+1;
            if(y>4){
                y=y-5;
            }
            down=true;
        }
        InsertLastlist(l,Alokasilist(x,y));
}
arenagame(*fruit,meteor,l,*obstacle);
}

int snakegame (){
int fruit,meteor,obstacle;
int turn,i,a,b;
List snake;
char input[10];
boolean play,valid,collide,quit;
addressl p,temp;
play=true;
turn = 1;
meteor= 25;
collide=false;
quit=false;
snakestart(&fruit,&snake,&obstacle);
while(play){
    while(!valid){
printf("TURN %d:\n",turn);
printf("Silahkan masukkan command anda:");
STARTWORD();
KataToString(currentWord, input);
if(listcompare(input, "w") && stringcompare(input,"t")){
    DelFirstlist(&snake,&p);
    if((Infoy(p)-1)<0){
    b=Infox(p)+(Infoy(p)+4)*5;
    }else{
    b=Infox(p)+(Infoy(p)-1)*5;
    }
    temp=First(snake);
    for (i=0;i<NbElmt(snake);i=i+1){
    a=Infox(temp)+Infoy(temp)*5;
    if(a==b){
        collide=true;
    }
    temp=Next(temp);
    }
    if(meteor==b){
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(collide){
        collide=false;
        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(fruit==b){
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infoy(p)-1)<0){
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)+4));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)-1));
    }
        InsertLastlist(&snake,Alokasilist(Infox(temp),Infoy(temp)));
        valid=true;
    }else{
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infoy(p)-1)<0){
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)+4));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)-1));
    }
        valid=true;
    }
}else if(listcompare(input, "s") && stringcompare(input,"t")){
    DelFirstlist(&snake,&p);
    if((Infoy(p)+1)>4){
    b=Infox(p)+(Infoy(p)-4)*5;
    }else{
    b=Infox(p)+(Infoy(p)+1)*5;
    }
    temp=First(snake);
    for (i=0;i<NbElmt(snake);i=i+1){
    a=Infox(temp)+Infoy(temp)*5;
    if(a==b){
        collide=true;
    }
    temp=Next(temp);
    }
    if(meteor==b){
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(collide){
        collide=false;
        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(fruit==b){
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infoy(p)+1)>4){
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)-4));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)+1));
    }
        InsertLastlist(&snake,Alokasilist(Infox(temp),Infoy(temp)));
        valid=true;
    }else{
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infoy(p)+1)>4){
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)-4));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p),Infoy(p)+1));
    }
        valid=true;
    }
}else if(listcompare(input, "a") && stringcompare(input,"t")){
    DelFirstlist(&snake,&p);
    if((Infox(p)-1)<0){
    b=Infox(p)+4+(Infoy(p))*5;
    }else{
    b=Infox(p)-1+(Infoy(p))*5;
    }
    temp=First(snake);
    for (i=0;i<NbElmt(snake);i=i+1){
    a=Infox(temp)+Infoy(temp)*5;
    if(a==b){
        collide=true;
    }
    temp=Next(temp);
    }
    if(meteor==b){
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(collide){
        collide=false;
        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(fruit==b){
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infox(p)-1)<0){
    InsertFirstlist(&snake,Alokasilist(Infox(p)+4,Infoy(p)));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p)-1,Infoy(p)));
    }
        InsertLastlist(&snake,Alokasilist(Infox(temp),Infoy(temp)));
        valid=true;
    }else{
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infox(p)-1)<0){
    InsertFirstlist(&snake,Alokasilist(Infox(p)+4,Infoy(p)));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p)-1,Infoy(p)));
    }
        valid=true;
    }
}else if(listcompare(input, "d") && stringcompare(input,"t")){
    DelFirstlist(&snake,&p);
    if((Infox(p)+1)>4){
    b=Infox(p)-4+(Infoy(p))*5;
    }else{
    b=Infox(p)+1+(Infoy(p))*5;
    }
    temp=First(snake);
    for (i=0;i<NbElmt(snake);i=i+1){
    a=Infox(temp)+Infoy(temp)*5;
    if(a==b){
        collide=true;
    }
    temp=Next(temp);
    }
    if(meteor==b){
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(collide){
        collide=false;
        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
        printf("Silahkan masukkan command lainnya\n");
        InsertFirstlist(&snake,p);
    }else if(fruit==b){
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infox(p)+1)>4){
    InsertFirstlist(&snake,Alokasilist(Infox(p)-4,Infoy(p)));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p)+1,Infoy(p)));
    }
        InsertLastlist(&snake,Alokasilist(Infox(temp),Infoy(temp)));
        valid=true;
    }else{
        InsertFirstlist(&snake,p);
        DelLastlist(&snake,&temp);
    if((Infox(p)+1)>4){
    InsertFirstlist(&snake,Alokasilist(Infox(p)-4,Infoy(p)));
    }else{
    InsertFirstlist(&snake,Alokasilist(Infox(p)+1,Infoy(p)));
    }
        valid=true;
    }
}else if(listcompare(input, "q") && stringcompare(input,"t")){
play=false;
valid=true;
quit=true;
}else{
printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d atau quit dengan q\n");
}
}
if(!quit){
    valid=false;
p=First(snake);
while(fruit==Infox(p)+Infoy(p)*5 || fruit==obstacle){
fruit=Numbersnake(35)%25;
p=First(snake);
    for (i=0;i<NbElmt(snake)-1;i=i+1){
    a=Infox(p)+Infoy(p)*5;
    if(a==fruit){
        fruit=Numbersnake(35+4+i)%25;
    }
    p=Next(p);
    }
}
meteor=Numbersnake(27)%25;
i=0;
while(meteor==fruit || meteor==obstacle){
meteor=Numbersnake(27)%25+i;
i=i+1;
}
turn=turn+1;
printf("Berhasil bergerak!\n");
arenagame(fruit,meteor,&snake,obstacle);
if (meteor==(Infox(First(snake))+Infoy(First(snake))*5)){
    play=false;
    DelFirstlist(&snake,&p);
}else if(NbElmt(snake)==0 || obstacle==(Infox(First(snake))+Infoy(First(snake))*5)){
    play=false;
}
}
}
printf("Game berakhir. skor: %d",NbElmt(snake));
return NbElmt(snake);
}