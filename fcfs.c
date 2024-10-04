#include<stdio.h>
#include<stdlib.h>
void main(){
    int no_req,diff,seek=0,head_movs=0;;

    printf("Enter the number of block requests:");
    scanf("%d",&no_req);
    int seq[no_req+1];
    printf("Enter the sequence:");
    for (int i = 1; i <= no_req; i++)
    {
        scanf("%d",&seq[i]);
    }
    
    printf("Enter the initial head position:");
    scanf("%d",&seq[0]);

    for(int i=0;i<no_req;i++)
    {
        diff=abs(seq[i+1]-seq[i]);
        seek+=diff;
        head_movs++;
        printf("%d->",seq[i]);
    }
    printf("%d",seq[no_req]);
    printf("\nSeek Time=%d",seek);
    printf("\nTotal Head Movements=%d",head_movs);

}
