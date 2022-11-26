#include"list.c"
int main(){
List l;
addressl p;
CreateEmptylist(&l);
InsertLastlist(&l,Alokasilist(1,9));
InsertLastlist(&l,Alokasilist(2,8));
InsertLastlist(&l,Alokasilist(3,7));
printf("Jumlah list : %d\n",NbElmt(l));
DelFirstlist(&l,&p);
printf("List X ke 1 = %d\nList Y ke 1 = %d\n",Infox(p),Infoy(p));
DelLastlist(&l,&p);
printf("List X ke 3 = %d\nList Y ke 3 = %d\n",Infox(p),Infoy(p));
if (IsEmptylist(l)){
    printf("List kosong");
}else{
    printf("List tidak kosong"); 
}
    return 0;
}