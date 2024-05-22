// WAP in C to perform SJF CPU Scheduling Algorithm.

#include <stdio.h>
int main()
{
    int at[10]={0}, bt[10]={0}, tat[10]={0}, wt[10], ct[10]={0}; 
    int n,i,j,temp,pos;
    float totalWT=0,totalTAT=0;

    printf("Enter the Number of Processes : ");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d] : ",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
    }

    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        totalWT+=wt[i];
        totalTAT+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    totalWT/=i;
    totalTAT/=i;
    printf("\nAverage Turnaround Time : %.2f\n",totalTAT);
    printf("\n\nAverage Waiting Time : %.2f",totalWT);

    return 0;
}