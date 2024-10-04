#include <stdio.h>

void waittime(int at[10],int bt[10],int wt[10],int n)
{
        wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}

}

void swap(int* arr, int i, int j) 
{ 
    int temp = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp; 
}

 
void sortarrivaltime(int at[],int bt[],int p[], int n)
{
  for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
     {
       if (at[j] > at[j + 1]) 
         {
                swap(at, j, j + 1);
                swap(bt, j, j + 1);
                swap(p, j, j + 1); 
          }
     }
    }
}





int main()
{
int temp,ct[10],bt[10],at[10],wt[10],p[10],awt,tat[10],atat,n;
printf("Enter the number of processes :");
scanf("%d",&n);
atat=0,awt=0;

printf("enter %d process:",n);
    for(int i=0;i<n;i++)
    {
    scanf("%d",&p[i]);
    }
for (int i=0;i<n;i++)
{
 printf("Enter Arrival Time and Burst time :");
 scanf("%d%d",&at[i],&bt[i]);
}

sortarrivaltime(at,bt,p,n);

waittime(at,bt,wt,n);
ct[0]=at[0]+bt[0];
for(int i=1;i<n;i++)
 {  
      
   temp=0;
   if(ct[i-1]<at[i])
    {
        temp=at[i]-ct[i-1];
    }
   ct[i]=ct[i-1]+bt[i]+temp;
 }
for(int i=0;i<n;i++)
    {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    atat+=tat[i];
    awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;


printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
for(int i =0;i<n;i++)
{
  printf("\n%d\t %d\t %d\t %d\t %d\t%d ",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
 printf("\n Average Turnaround Time : %d",atat);
 printf("\n Average Waiting Time : %d",awt);
 return 0;
}
