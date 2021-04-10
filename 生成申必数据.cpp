#include<bits/stdc++.h>
int main(){
    int a[100],i=0,b[100];
    for(int c='a';c<='z';c++)a[i++]=c;
    a[i++]='.';a[i++]=',';a[i++]=' ';
    a[i++]=10;a[i++]='_';a[i++]=':';
    //for(int c='0';c<='9';c++)a[i++]=c;
    //for(int c='A';c<='Z';c++)a[i++]=c;
    //for(int c=0;c<64;c++){
    //    i=rand()&63;
    //    while(!a[i])i=(i+7)&63;
    //    b[c]=a[i];
    //    a[i]=0;
    //}
    FILE*A=fopen("1.txt","wb");
    for(int i=0;i<998244353;i++)fputc('@',A);
    //for(int i=0;i<7221457;i++)
    //    fputc(a[rand()&31],A);
    fclose(A);
    system("pause");
}
