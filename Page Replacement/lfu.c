#include <stdio.h>

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
}

int totalAccessed(int arr[],int i,int a){
    int count = 0;
    for(int j=i;j>=0;j--){
        if(arr[j]==a)
            count++;
    }
    return count;
}

int recentAccess(int arr[],int i,int a){
    int count=0;
    for(int j=i;j>=0;j--){
        count++;
        if(arr[j]==a)
            return count;
    }
}

void lfu(int arr[],int n, int f[],int fno){
    int index=-1,count=0,p=0,i,j,x,k,lfuArr[fno][n];
    int m1,m2;
    int temp[fno][2];
    for( i=0;i<n;i++){
        if(pageIsFound(f,count,arr[i])){
            // Increase page hit count
            p++;
        }
        else{
            if(count == fno){
                int min = n;
                for(k=0;k<fno;k++){
                    temp[k][1]=totalAccessed(arr,i,f[k]);
                    temp[k][2]=recentAccess(arr,i,f[k]);
                    if(min>temp[k][1]){
                        min = temp[k][1];
                        index = k;
                    }
                    else if(min == temp[k][1]){
                        if(temp[k][2] > temp[index][2])
                            index = k;
                    }
                }
                f[index] = arr[i];
            }
            else{
                f[count++]=arr[i];
            }
        }
        for(j=0,k=0;j<fno;j++){
            if(k<count)
                lfuArr[k++][i] = f[j];
            else 
                lfuArr[k++][i] = -1;
        }
    }
    for(i=0;i<fno;i++){
        for(j=0;j<n;j++){
            if(lfuArr[i][j] != -1)
                printf("%d  ",lfuArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults = %d\n",p);
    printf("Page Hits= %d\n", n - p); 
    printf("Hit ratio=%f\n",(float)(n-p)/n);
    printf("Page fault ratio=%f",(float)(p)/n);// Displaying the number of page hits
}

void main(){
    printf("LFU Page Replacement Algorithm\n");
    int n,i,frameNum;
    printf("Enter the number of frames: ");
    scanf("%d",&frameNum);
    printf("Enter the number of page requests: ");
    scanf("%d",&n);
    printf("Enter the page string each separated by a space\n");
    int arr[n],F[frameNum];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nPages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    lfu(arr,n ,F,frameNum);
}
