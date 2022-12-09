#include <stdio.h>
int checkout(int a,int no,int arr[])
{
    int decido=0;
    for(int x=0;x<no;x++)
    {
        if(arr[x]==a)
        {
            decido=1;
            break;
        }
    }
    return decido;
}
int main()
{
    printf("Welcome Sir ! \n");
    FILE* ptr = fopen("filledseats.txt", "r");
    int buf[100];
    int x=0;
    int array[100];
    while (fscanf(ptr,"%d",buf)== 1)
    {
        array[x]=buf[0];
        x+=1;
    }
    int seat_no=0;
    for(int q=0;q<3;q++)
    {
        printf("----------------------------------------------------------------------\n");
        for(int p=1;p<11;p++)
        {
            seat_no+=1;
            int decide=checkout(seat_no,x,array);
            if(decide==1)
            {
                printf("  0C  |",seat_no);
            }
            else
            {
                printf("  %02d  |",seat_no);
            }
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------------\n");
    printf("which seat you need : ");
    int decseat=0;
    scanf("%d",&decseat);
    if(decseat>30 || decseat<0)
    {
        printf("Seat does not exist...");
    }
    else if (checkout(decseat,x,array)==1)
    {
        printf("Seat not available...");
    }
    else
    {
        printf("Booking Done...\n");
        FILE* ptr = fopen("filledseats.txt", "a");
        fprintf(ptr,"\n%d",decseat);
    }
    fclose(ptr);
    printf("Thanks for Coming...");
}