#include<stdio.h>
#include<string.h>
char culori[8][12],s[22],ss[22];
int a[8][5][5],b[8][5][5];

struct cub
{
    int x,y,z;
};
struct cub v[8][102];
///3,3,1 3,3,2 3,3,3 6,1,1 6,2,1 6,3,1 4,1,3 4,1,2 4,1,1 5,3,3 5,2,3 5,1,3 - F
///3,1,3 3,1,2 3,1,1 5,1,1 5,2,1 5,3,1 4,3,1 4,3,2 4,3,3 6,3,3 6,2,3 6,1,3 - B
///2,1,3 2,1,2 2,1,1 6,1,3 6,1,2 6,1,1 1,1,3 1,1,2 1,1,1 5,1,3 5,1,2 5,1,1 - U
///2,3,1 2,3,2 2,3,3 5,3,1 5,3,2 5,3,3 1,3,1 1,3,2 1,3,3 6,3,1 6,3,2 6,3,3 - D
///2,3,3 2,2,3 2,1,3 3,1,1 3,2,1 3,3,1 1,1,1 1,2,1 1,3,1 4,1,1 4,2,1 4,3,1 - L
///2,1,1 2,2,1 2,3,1 4,3,3 4,2,3 4,1,3 1,3,3 1,2,3 1,1,3 3,3,3 3,2,3 3,1,3 - R
void egalba()
{
    int i,j,l;
    for(i=1;i<=6;i++)
    for(j=1;j<=3;j++)
    for(l=1;l<=3;l++)
        b[i][j][l]=a[i][j][l];
}

void egalab()
{
    int i,j,l;
    for(i=1;i<=6;i++)
    for(j=1;j<=3;j++)
    for(l=1;l<=3;l++)
        a[i][j][l]=b[i][j][l];
}

void roteste(int k)
{
    int i,j,n=3;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        b[k][i][j]=a[k][n-j+1][i];
}

void muta(int k)
{
    int i;
    b[v[k][1].x][v[k][1].y][v[k][1].z]=a[v[k][10].x][v[k][10].y][v[k][10].z];
    b[v[k][2].x][v[k][2].y][v[k][2].z]=a[v[k][11].x][v[k][11].y][v[k][11].z];
    b[v[k][3].x][v[k][3].y][v[k][3].z]=a[v[k][12].x][v[k][12].y][v[k][12].z];
    for(i=4;i<=12;i++)
        b[v[k][i].x][v[k][i].y][v[k][i].z]=a[v[k][i-3].x][v[k][i-3].y][v[k][i-3].z];
}

void F()
{
    egalba();
    muta(1);
    roteste(1);
    egalab();
}

void B()
{
    egalba();
    muta(2);
    roteste(2);
    egalab();
}

void U()
{
    egalba();
    muta(3);
    roteste(3);
    egalab();
}

void D()
{
    egalba();
    muta(4);
    roteste(4);
    egalab();
}

void L()
{
    egalba();
    muta(5);
    roteste(5);
    egalab();
}

void R()
{
    egalba();
    muta(6);
    roteste(6);
    egalab();
}

int care()
{
    int i,n1,n2,j,ok;
    for(i=1;i<=6;i++)
    {
        n1=strlen(ss+1);
        n2=strlen(culori[i]+1);
        if(n1==n2)
        {
            ok=1;
            for(j=1;j<=n1;j++)
            if(ss[j]!=culori[i][j])
            {
                ok=0;
                break;
            }
            if(ok==1)
                return i;
        }
    }
    return 0;
}

void citeste()
{
    int i,j,k,l,n;
    for(i=1;i<=6;i++)
        scanf("%s",culori[i]+1);
    for(i=1;i<=6;i++)
    for(j=1;j<=3;j++)
    {
        scanf("%s",(s+1));
        k=1;
        while(s[k]!='.')
            ss[k]=s[k],k++;
        ss[k]='\0';
        a[i][j][1]=care();
        k++;
        l=k;
        while(s[k]!='.')
            ss[k-l+1]=s[k],k++;
        ss[k-l+1]='\0';
        a[i][j][2]=care();
        k++;
        l=k;
        n=strlen(s+1);
        while(k<=n)
            ss[k-l+1]=s[k],k++;
        ss[k-l+1]='\0';
        a[i][j][3]=care();
    }
}

void afis()
{
    int i,j;
    for(i=1;i<=6;i++)
    for(j=1;j<=3;j++)
        printf("%s.%s.%s\n",(culori[a[i][j][1]]+1),(culori[a[i][j][2]]+1),(culori[a[i][j][3]]+1));
}

void rez()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",(s+1));
        if(strlen(s+1)==1)
        {
            if(s[1]=='F')
                F();
            if(s[1]=='B')
                B();
            if(s[1]=='U')
                U();
            if(s[1]=='D')
                D();
            if(s[1]=='L')
                L();
            if(s[1]=='R')
                R();
        }
        else
        {
            if(s[1]=='F')
            {
                F();
                F();
                F();
            }
            if(s[1]=='B')
            {
                B();
                B();
                B();
            }
            if(s[1]=='U')
            {
                U();
                U();
                U();
            }
            if(s[1]=='D')
            {
                D();
                D();
                D();
            }
            if(s[1]=='L')
            {
                L();
                L();
                L();
            }
            if(s[1]=='R')
            {
                R();
                R();
                R();
            }
        }
    }
}

int main()
{
    citeste();
    struct cub p;
    p.x=3,p.y=3,p.z=1;
    v[1][1]=p;
    p.x=3,p.y=3,p.z=2;
    v[1][2]=p;
    p.x=3,p.y=3,p.z=3;
    v[1][3]=p;
    p.x=6,p.y=1,p.z=1;
    v[1][4]=p;
    p.x=6,p.y=2,p.z=1;
    v[1][5]=p;
    p.x=6,p.y=3,p.z=1;
    v[1][6]=p;
    p.x=4,p.y=1,p.z=3;
    v[1][7]=p;
    p.x=4,p.y=1,p.z=2;
    v[1][8]=p;
    p.x=4,p.y=1,p.z=1;
    v[1][9]=p;
    p.x=5,p.y=3,p.z=3;
    v[1][10]=p;
    p.x=5,p.y=2,p.z=3;
    v[1][11]=p;
    p.x=5,p.y=1,p.z=3;
    v[1][12]=p;
    p.x=3,p.y=1,p.z=3;
    v[2][1]=p;
    p.x=3,p.y=1,p.z=2;
    v[2][2]=p;
    p.x=3,p.y=1,p.z=1;
    v[2][3]=p;
    p.x=5,p.y=1,p.z=1;
    v[2][4]=p;
    p.x=5,p.y=2,p.z=1;
    v[2][5]=p;
    p.x=5,p.y=3,p.z=1;
    v[2][6]=p;
    p.x=4,p.y=3,p.z=1;
    v[2][7]=p;
    p.x=4,p.y=3,p.z=2;
    v[2][8]=p;
    p.x=4,p.y=3,p.z=3;
    v[2][9]=p;
    p.x=6,p.y=3,p.z=3;
    v[2][10]=p;
    p.x=6,p.y=2,p.z=3;
    v[2][11]=p;
    p.x=6,p.y=1,p.z=3;
    v[2][12]=p;
    p.x=2,p.y=1,p.z=3;
    v[3][1]=p;
    p.x=2,p.y=1,p.z=2;
    v[3][2]=p;
    p.x=2,p.y=1,p.z=1;
    v[3][3]=p;
    p.x=6,p.y=1,p.z=3;
    v[3][4]=p;
    p.x=6,p.y=1,p.z=2;
    v[3][5]=p;
    p.x=6,p.y=1,p.z=1;
    v[3][6]=p;
    p.x=1,p.y=1,p.z=3;
    v[3][7]=p;
    p.x=1,p.y=1,p.z=2;
    v[3][8]=p;
    p.x=1,p.y=1,p.z=1;
    v[3][9]=p;
    p.x=5,p.y=1,p.z=3;
    v[3][10]=p;
    p.x=5,p.y=1,p.z=2;
    v[3][11]=p;
    p.x=5,p.y=1,p.z=1;
    v[3][12]=p;
    p.x=2,p.y=3,p.z=1;
    v[4][1]=p;
    p.x=2,p.y=3,p.z=2;
    v[4][2]=p;
    p.x=2,p.y=3,p.z=3;
    v[4][3]=p;
    p.x=5,p.y=3,p.z=1;
    v[4][4]=p;
    p.x=5,p.y=3,p.z=2;
    v[4][5]=p;
    p.x=5,p.y=3,p.z=3;
    v[4][6]=p;
    p.x=1,p.y=3,p.z=1;
    v[4][7]=p;
    p.x=1,p.y=3,p.z=2;
    v[4][8]=p;
    p.x=1,p.y=3,p.z=3;
    v[4][9]=p;
    p.x=6,p.y=3,p.z=1;
    v[4][10]=p;
    p.x=6,p.y=3,p.z=2;
    v[4][11]=p;
    p.x=6,p.y=3,p.z=3;
    v[4][12]=p;
    p.x=2,p.y=3,p.z=3;
    v[5][1]=p;
    p.x=2,p.y=2,p.z=3;
    v[5][2]=p;
    p.x=2,p.y=1,p.z=3;
    v[5][3]=p;
    p.x=3,p.y=1,p.z=1;
    v[5][4]=p;
    p.x=3,p.y=2,p.z=1;
    v[5][5]=p;
    p.x=3,p.y=3,p.z=1;
    v[5][6]=p;
    p.x=1,p.y=1,p.z=1;
    v[5][7]=p;
    p.x=1,p.y=2,p.z=1;
    v[5][8]=p;
    p.x=1,p.y=3,p.z=1;
    v[5][9]=p;
    p.x=4,p.y=1,p.z=1;
    v[5][10]=p;
    p.x=4,p.y=2,p.z=1;
    v[5][11]=p;
    p.x=4,p.y=3,p.z=1;
    v[5][12]=p;
    p.x=2,p.y=1,p.z=1;
    v[6][1]=p;
    p.x=2,p.y=2,p.z=1;
    v[6][2]=p;
    p.x=2,p.y=3,p.z=1;
    v[6][3]=p;
    p.x=4,p.y=3,p.z=3;
    v[6][4]=p;
    p.x=4,p.y=2,p.z=3;
    v[6][5]=p;
    p.x=4,p.y=1,p.z=3;
    v[6][6]=p;
    p.x=1,p.y=3,p.z=3;
    v[6][7]=p;
    p.x=1,p.y=2,p.z=3;
    v[6][8]=p;
    p.x=1,p.y=1,p.z=3;
    v[6][9]=p;
    p.x=3,p.y=3,p.z=3;
    v[6][10]=p;
    p.x=3,p.y=2,p.z=3;
    v[6][11]=p;
    p.x=3,p.y=1,p.z=3;
    v[6][12]=p;
    rez();
    afis();
    return 0;
}
