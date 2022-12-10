#include <stdio.h>
#include <stdlib.h>
void player1();
void checkaro();
void display();
void win(char op);
void player2();
void isend();
char xo[3][3]={{'.','.','.'},{'.','.','.'},{'.','.','.'}};
void win(char op)
{
    if(op=='X')
    {
        printf("Player 1 as won the game");
        exit(0);
    }
    else if(op=='O')
    {
        printf("Player 2 as won the game");
        exit(0);
    }
}
void isend()
{
    if(xo[0][0]==xo[0][1] && xo[0][0]==xo[0][2])
    {
        win(xo[0][0]);
    }
    else if(xo[0][0]==xo[1][0] && xo[2][0]==xo[0][0])
    {
        win(xo[0][0]);
    }
    else if(xo[2][0]==xo[2][1] && xo[2][0]==xo[2][2])
    {
        win(xo[2][0]);
    }
    else if(xo[2][2]==xo[1][2] && xo[2][2]==xo[0][2])
    {
        win(xo[2][2]);
    }
    else if(xo[0][0]==xo[1][1] && xo[1][1]==xo[2][2])
    {
        win(xo[0][0]);
    }
    else if(xo[2][0]==xo[1][1] && xo[1][1]==xo[0][2])
    {
        win(xo[2][0]);
    }
}
void checkaro(int desc)
{
    if(desc==1)
    {
        player1();
    }
    else if(desc==2)
    {
        player2();
    }
}
int plot(int a,int b,char t,int i)
{
    if(xo[a][b]=='.')
    {
        xo[a][b]=t;
        display();
        isend();
        if(i==1)
        {
            checkaro(2);
        }
        else
        {
            checkaro(1);
        }
    }
    else
    {
        printf("Its already occupied\n");
        checkaro(i);
    }
}
void display()
{
    for(int x=0;x<3;x++)
    {
        printf("---------------\n");
        for(int y=0;y<3;y++)
        {
            printf("  %c |",xo[x][y]);
        }
        printf("\n");
    }
    printf("--------------\n");   
}
void player1()
{
    printf("Player 1's Turn : ");
    printf("x , y : ");
    int x=0,y=0;
    scanf("%d %d",&x,&y);
    plot(x,y,'X',1);
}
void player2()
{
    printf("Player 2's Turn : ");
    printf("x , y : ");
    int x=0,y=0;
    scanf("%d %d",&x,&y);
    plot(x,y,'O',2);
}
int main()
{
    for(int x=0;x<3;x++)
    {
        printf("---------------\n");
        for(int y=0;y<3;y++)
        {
            printf("  %c |",xo[x][y]);
        }
        printf("\n");
    }
    printf("--------------\n");
    player1();
}
