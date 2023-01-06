#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
const int N=3;

int count1(int a[N][N],int val){
    int c,d,count2=0;
    for(c=0;c<N;c++){
        for(d=0;d<N;d++){
            if(val==a[c][d])
                count2++;
        }
    }
    return count2;
}

int main(){
    int ar[N][N],ar2[N][N],i,j,d,w,ix3,ix4,ch,ch2=0,h=0,k;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            ar[i][j]=-1;
            ar2[i][j]=0;
        }
    }
    do{
        system("cls");
        printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n\n");
        printf("Pick a position: ");
        scanf("%d",&d);

        int ix1,ix2;
        ix1=(d-1)/3;
        ix2=d-(3*ix1)-1;
        ar[ix1][ix2]+=2;
        ar2[ix1][ix2]=1;
        h++;
        system("cls");
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(ar[i][j]==1)
                    printf("X\t");
                else if(ar[i][j]==0)
                    printf("O\t");
                else
                    printf(" \t");
            }
            printf("\n");
        }
        printf("Enter any key to continue: ");
        getch();
        system("cls");
        ch=0;
        if((ar[0][0]==1&&ar[1][0]==1&&ar[2][0]==1)||(ar[0][0]==1&&ar[0][1]==1&&ar[0][2]==1)||(ar[0][0]==1&&ar[1][1]==1&&ar[2][2]==1)||(ar[0][1]==1&&ar[1][1]==1&&ar[2][1]==1)||(ar[0][2]==1&&ar[1][2]==1&&ar[2][2]==1)||(ar[1][0]==1&&ar[1][1]==1&&ar[1][2]==1)||(ar[2][0]==1&&ar[2][1]==1&&ar[2][2]==1)||(ar[0][2]==1&&ar[1][1]==1&&ar[2][0]==1)){
           ch2=1;
            k=1;
        }

        if(ch2==0){
            do{
                w=rand()%(10)+1;
                ix3=w/3;
                ix4=w-(3*ix3)-1;
                if(ar2[ix3][ix4]==1)
                    ch=0;
                else
                    ch=1;
            }while(ch==0);

            int jx1,jx2;
            jx1=w/3;
            jx2=w-(3*jx1)-1;
            ar[jx1][jx2]+=1;
            ar2[jx1][jx2]=1;
            printf("Computer's Turn: \n");
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    if(ar[i][j]==1)
                        printf("X\t");
                    else if(ar[i][j]==0)
                        printf("O\t");
                    else
                        printf(" \t");
                }
                printf("\n");
            }
            printf("\nPress any key to continue ");
            getch();
            h++;
        }

        if((ar[0][0]==0&&ar[1][0]==0&&ar[2][0]==0)||(ar[0][0]==0&&ar[0][1]==0&&ar[0][2]==0)||(ar[0][0]==0&&ar[1][1]==0&&ar[2][2]==0)||(ar[0][1]==0&&ar[1][1]==0&&ar[2][1]==0)||(ar[0][2]==0&&ar[1][2]==0&&ar[2][2]==0)||(ar[1][0]==0&&ar[1][1]==0&&ar[1][2]==0)||(ar[2][0]==0&&ar[2][1]==0&&ar[2][2]==0)||(ar[0][2]==0&&ar[1][1]==0&&ar[2][0]==0)){
            ch2=1;
            k=-1;
        }
        else if(h==9){
            ch2==1;
            k=0;
        }
    }
    system("cls");
    while(h<=9&&ch2==0);
    if(k==0)
        printf("Match Drawn!!");
    else if(k==1)
        printf("You Win!!Congrats!!!");
    else if(k==-1)
        printf("Computer wins!!!");
}
