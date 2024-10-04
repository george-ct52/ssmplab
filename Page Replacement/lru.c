 #include<stdio.h>

int main()
{
    int i,j,k,l,m,n,p=15,c=0;
    int a[20],b[20],q,min=50;
    printf("enter no. of reference string: ");
    scanf("%d",&n);
    printf("enter size of frame: ");
    scanf("%d",&m);
    printf("enter the elements of ref. string: \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(j=0; j<m; j++)
        b[j]=-1; //initialize all frame elements with -1
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i]==b[j]) //check if element already present in frame,if true then no page fault.
                break;
            else
                continue;
        }
        if(j==m)
        {
            for(k=0; k<m; k++)
                if(b[k]==-1)
                {
                    b[k]=a[i];//replace the initial value by string value
                    break;
                }
            if(k==m)
            {
                min=50;
                for(j=0; j<m; j++)
                {
                    l=i-1;
                    while(l>=0)
                    {
                        if(a[l]==b[j])
                        {
                            if(l<min)
                            {
                                min=l;
                                p=j;
                            }
                            break;
                        }
                        l--;
                    }
                }
            }
            b[p]=a[i];
            c++;
        }
        printf("\n\n");
        for(k=0; k<m; k++)
            if(b[k]==-1)
                printf(" ");
             else   
            printf(" %d",b[k]);
    }
    printf("\n No of page fault is:%d\n",c);
    printf("\n No of page Hit is:%d\n",n-c);
    printf("\n Page Hit ratio is:%f\n",(float)(n-c)/n);
    printf("\n Page fault ratio is:%f\n",(float)c/n);

}
