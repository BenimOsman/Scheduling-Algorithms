#include<stdio.h>
int main()
{
    printf("FCFS\n");
    int n, p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0;
    float awt=0, atat=0;
    
    printf("Enter No. of Proccess : ");
    scanf("%d",&n);

    printf("Enter %d Process : ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Enter %d Arrival Time : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }

    printf("Enter %d Burst Time : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    
    for(i=0;i<n;i++)                        // Sorting AT, BT and Process according to AT
    {
        for(j=0;j<(n-i);j++)
        {
            if(at[j]>at[j+1])
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;
                temp=bt[j+1];
                bt[j+1]=bt[j];
                bt[j]=temp;
            }
        }
    }
    
    ct[0]=at[0]+bt[0];             // Calculating 1st CT
    for(i=1;i<n;i++)
    {  
        temp=0;
        if(ct[i-1]<at[i])
        {
            temp=at[i]-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }
    
    // Calculating TAT and BT 
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t %d\t %d\t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time : %f",atat);

    printf("\nAverage Wating Time : %f",awt);
    return 0;
}