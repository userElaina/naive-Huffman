//Code By 1677
#include<bits/stdc++.h>
#define IMX 2147483647
#define LL long long
#define pt putchar
#define gt getchar
#define MXC 512
#define MXC2 1536
int s[MXC2][2],fa[MXC2],ans[MXC][MXC],ss[MXC],
	ht,c,p,q,ssr,L63[MXC],L62[MXC];
LL bg,inchar,outchar;
char PASSWORD[MXC]="Glgjssyqyhfbqz19260817",_OF[MXC],EOFC='@',
	R63[MXC]="DyY4wGlIhf9LSVKFNAqW7b5oztcr6Rd.Uvj832aHu_pXmZ1OsxBgMPieCJTnEQ0k",
	R62[MXC]="123_567890POIUYTREWQasdfghjklMNBVCXZpoiuytrewqASDFGHJKLmnbvcxz4.";	
FILE *MB,*KB;
inline void _fre(){
    memset(s,0,sizeof(s));
    memset(ss,0,sizeof(ss));
    memset(fa,0,sizeof(fa));
    memset(ans,0,sizeof(ans));
    memset(L63,0,sizeof(L63));
    memset(R63,0,sizeof(R63));
    memset(L62,0,sizeof(L63));
    memset(R62,0,sizeof(R63));
    memset(_OF,0,sizeof(_OF));
    memset(PASSWORD,0,sizeof(PASSWORD));
	fclose(KB);fclose(MB);
    inchar=outchar=ht=c=p=q=ssr=bg=EOFC=0;
    system("pause");
    exit(0);
}
inline void _help(){
    printf("\n-d INPUT_FILE_ADDRESS\n    INPUT_FILE_ADDRESS will be compressed.\n");
    printf("-c INPUT_FILE_ADDRESS\n    INPUT_FILE_ADDRESS will be decompressed.\n");
	printf("There should be only one of these two parameters. It should be given first.\n\n");
    printf("-o OUTPUT_FILE_ADDRESS\n    OUTPUT_FILE_ADDRESS will be *.QwQ by default where * is INPUT_FILE_ADDRESS.\n");
    printf("-p PASSWORD\n    Compress or Decompress with PASSWORD. It should be given last.\n");
	printf("These two parameters are not necessary.\n\n");
	printf("You can use it like this:\n");
	printf("    QwQ -d D:\\huffman\\en.txt -o D:\\huffman\\en -p en\n");
	printf("    QwQ -c D:\\huffman\\en -p en\n\n");
	printf("Warning:\n");
	printf("If the input file is unviewable as a text document, a compression error may occur without any indication.\n");
	printf("If the output address exists in a file, it will disappear forever.\n\n");
	printf("Or you can read README.md to get help.\n\n");
    _fre();
}
inline void _empty(){printf("You can use -h to get help.\n");_fre();}
inline void _notfound(){printf("Illegal input file address!\n");_fre();}
inline void _cannot(){printf("This file can not be decompressed with this program!\n");_fre();}
inline void _wp(){printf("Wrong password!\n");_fre();}
inline void llt(LL a){if(a>9)llt(a/10);pt(a%10+48);}
class P{
private:
	int c;
	void wp(int x){if(x!=EOF)return;_wp();}
public:
	void _in(char*s){c=127;for(int i=0;s[i];i++)c^=s[i];c>>=1;}
	int e(int x){wp(x);return x^c;}
	int cr(int x){return e(x-128);}
	int cl(int x){return e(x)+128;}
}P;
class D{
public:
	int c,num;
	bool operator<(D&r){return num<r.num;}
}DMX={0,IMX},a[MXC2];
class H{
public:
	D *a;
	int t=0;
	void s(int x,int y){
		D xy=a[x];
		a[x]=a[y];
		a[y]=xy;
	}
	void up(int x){
		int y=x>>1;
		if(y){
			if(a[x]<a[y]){
				s(x,y);
				up(y);
			}
		}
	}
	void dn(int x){
		int l=x<<1,r=x<<1|1;
		if(l>t)return;
		if(a[l]<a[r])r=l;
		if(a[r]<a[x]){
			s(x,r);
			dn(r);
		}
	}
	void pu(D x){
		a[++t]=x;
		up(t);
	}
	D po(){
		D x=a[1];
		a[1]=a[t];
		a[t--]=DMX;
		dn(1);
		return x;
	}
}h;
inline void _ttoh(int x){
	if(!x)return;
	if(!(x&MXC))for(int i=0;i<ssr;i++)ans[x][i]=ss[i];
	ss[ssr++]=2;_ttoh(s[x][0]);
	ss[ssr-1]=1;_ttoh(s[x][1]);
	ssr--;
}
inline void ttoh(int x){ssr=0;memset(ans,0,sizeof(ans));memset(ss,0,sizeof(ss));_ttoh(x);}
inline void htoc(){
	for(int i=0;ans[c][i];i++){
		p=(p<<1)|(ans[c][i]&1);
		if(q^7)q++;else{
			fputc(P.e(p),KB),outchar++;
			q=p=0;
		}
	}
}
inline void ctoh(LL x){if(x>3)ctoh(x>>2);ans[c][q++]=x&3;}
inline void Fintot(LL a){if(a&(~63))Fintot(a>>6);fputc(P.e(R63[a&63]),KB),outchar++;}
inline void execute(){
	fputc('Q',KB),outchar++;
	fputc('w',KB),outchar++;
	fputc('Q',KB),outchar++;
	for(int i=0;PASSWORD[i];i++)fputc(P.e(R62[L63[PASSWORD[i]]]),KB),outchar++;
	memset(fa,0,sizeof(fa));
	c=fgetc(MB),inchar++;
	while(c!=EOF){fa[c+128]++;c=fgetc(MB),inchar++;}
	fa[EOFC+128]+=16;fa[EOFC^1]++;
	h.a=a;
	h.pu(DMX);
	for(int i=0;i<512;i++)if(fa[i])h.pu((D){i,fa[i]});
	memset(s,0,sizeof(s));memset(fa,0,sizeof(fa));
    p=MXC;
	while(h.t>2){
		D x=h.po(),y=h.po(),z;
		z.c=p;
		z.num=x.num+y.num;
		s[p][0]=x.c;
		s[p][1]=y.c;
		h.pu(z);
		fa[x.c]=fa[y.c]=p;
		p++;
	}
	D z=h.po();
	ttoh(z.c);
	ht=0;
	for(int i=0;i<512;i++)if(ans[i][0]){
        bg=0;
		for(int j=0;ans[i][j];j++)bg=(bg<<2)|ans[i][j];
		fputc(P.cr(i),KB),outchar++;
		Fintot(bg);
		fputc(P.e(EOFC),KB),outchar++;
	}
    fputc(P.e(EOFC),KB),outchar++;
    fputc(P.e(EOFC),KB),outchar++;
    rewind(MB);
	c=fgetc(MB);
	p=q=0;
	while(c!=EOF){
		c+=128;
		htoc();
		c=fgetc(MB);
	}
	c=EOFC+128;
	for(int k=0;k<16;k++)htoc();
    printf("Compressed.\nIt's compressibility is %.5lf% = ",(100.0*outchar)/inchar);
	llt(outchar);pt(32);pt('/');pt(32);llt(inchar);pt('.');pt(10);
    _fre();
}
inline void search(){
	if(fgetc(KB)^'Q')_cannot();outchar++;
	if(fgetc(KB)^'w')_cannot();outchar++;
	if(fgetc(KB)^'Q')_cannot();outchar++;
	for(int i=0;PASSWORD[i];i++){if(R63[L62[P.e(fgetc(KB))]]^PASSWORD[i])_wp();outchar++;}
	memset(s,0,sizeof(s));
	memset(fa,0,sizeof(fa));
	memset(ans,0,sizeof(ans));
	c=P.cl(fgetc(KB)),inchar++;
	q=P.e(fgetc(KB)),inchar++;
	ht=MXC|1;
	while(q^EOFC){
		bg=0;
		while(q^EOFC){
			bg=(bg<<6)|L63[q];
			q=P.e(fgetc(KB)),inchar++;
		}
		q=0;
		ctoh(bg);
		q=MXC;
		int j=0;
		for(;ans[c][j];j++)
			if(!s[q][ans[c][j]&1]){
				s[fa[ht]=q][ans[c][j]&1]=ht;
				q=ht++;
			}else q=s[q][ans[c][j]&1];
		s[fa[q]][ans[c][j-1]&1]=c;
		fa[c]=fa[q];
		fa[ht=q]=0;
		c=P.cl(fgetc(KB)),inchar++;
		q=P.e(fgetc(KB)),inchar++;
	}
	ttoh(MXC);
	p=ssr=0;ht=MXC;
	c=fgetc(KB),inchar++;
	while(c!=EOF){
		c=P.e(c);
		for(int i=8;i;i--){fa[i]=c&1;c>>=1;}
		for(int i=1;i<=8;i++){
			ht=s[ht][fa[i]];
			if(ht&MXC)continue;
			ht-=128;
			if(ht^EOFC){
				if(ssr)ssr=0,fputc(EOFC,MB),outchar++;
				fputc(ht,MB),outchar++;
			}else if(ssr){
                printf("Decompressed.\n");
				//printf("It's compressibility is %.5lf% = ",(100.0*inchar)/outchar);
				//llt(inchar);pt(32);pt('/');pt(32);llt(outchar);pt('.');pt(10);
                _fre();
            }else ssr=1;
			ht=MXC;
		}
		c=fgetc(KB),inchar++;
	}
}
int main(int argc,char**argv){
    if(argc<2)_empty();
    if(argv[1][0]^'-')_empty();
    if(!strcmp("-h",argv[1]))_help();
	if(argc^3&&argc^5&&argc^7)_empty();
    for(int i=0;i<strlen(argv[2]);i++)_OF[i]=argv[2][i];
	_OF[strlen(argv[2])]=0;
	strcat(_OF,".QwQ");
	P._in(PASSWORD);
	for(int i=0;i<64;i++)L63[R63[i]]=i;
	for(int i=0;i<64;i++)L62[R62[i]]=i;
	inchar=outchar=0;
    if(argc==3){
        if(!strcmp("-d",argv[1])){
            MB=fopen(argv[2],"r");
            if(MB==NULL)_notfound();
            KB=fopen(_OF,"wb");
            execute();
        }else if(!strcmp("-c",argv[1])){
            KB=fopen(argv[2],"rb");
            if(KB==NULL)_notfound();
            MB=fopen(_OF,"w");
            search();
        }else _empty();
    }else if(argc==5&&!strcmp("-p",argv[3])){
        P._in(argv[4]);
        if(!strcmp("-d",argv[1])){
            MB=fopen(argv[2],"r");
            if(MB==NULL)_notfound();
            KB=fopen(_OF,"wb");
            execute();
        }else if(!strcmp("-c",argv[1])){
            KB=fopen(argv[2],"rb");
            if(KB==NULL)_notfound();
            MB=fopen(_OF,"w");
            search();
        }else _empty();
    }else if(argc==5&&!strcmp("-o",argv[3])){
        if(!strcmp("-d",argv[1])){
            MB=fopen(argv[2],"r");
            if(MB==NULL)_notfound();
            KB=fopen(argv[4],"wb");
            execute();
        }else if(!strcmp("-c",argv[1])){
            KB=fopen(argv[2],"rb");
            if(KB==NULL)_notfound();
            MB=fopen(argv[4],"w");
            search();
        }else _empty();
    }else if(argc==7&&!strcmp("-o",argv[3])&&!strcmp("-p",argv[5])){
        P._in(argv[6]);
        if(!strcmp("-d",argv[1])){
            MB=fopen(argv[2],"r");
            if(MB==NULL)_notfound();
            KB=fopen(argv[4],"wb");
            execute();
        }else if(!strcmp("-c",argv[1])){
            KB=fopen(argv[2],"rb");
            if(KB==NULL)_notfound();
            MB=fopen(argv[4],"w");
            search();
        }else _empty();
    }
	_empty();
}
//QwQ -d C:\All\Mili\C\Class\CS\work\Baiyu2\huffman\en.txt -o C:\All\Mili\C\Class\CS\work\Baiyu2\huffman\en -p en
//QwQ -c C:\All\Mili\C\Class\CS\work\Baiyu2\huffman\en -p en
