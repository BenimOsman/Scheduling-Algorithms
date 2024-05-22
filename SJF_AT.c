// WAP in C to implement SJF with Arrival Time CPU Scheduling Algorithm 

#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid,at,bt,ct,wt,tat;
};

int main()
{
    int n, current_time = 0;
    float avg_TAT=0, avg_WT=0;
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);
    struct process A[n];

    for (int i=0; i<n; i++)
    {
        struct process *ptr = A + i;
        ptr -> pid = i + 1;
        printf("For Process P [%d] :-\nEnter Arrival Time : ", ptr->pid);
        scanf("%d", &ptr->at);
        printf("Enter Burst Time : ");
        scanf("%d", &ptr->bt);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i].bt > A[j].bt && A[i].at >= A[j].at)
            {
                struct process temp = A[i];
                A[i] = A[j];
                A[j] = temp; 
            }
    
    for (int i=0; i<n; i++)
    {
        struct process *ptr = A + i;
        if (ptr->at > current_time && current_time==0)
            current_time += ptr->at;
        else if (ptr->at > current_time)
            current_time += current_time-ptr->at;
        current_time += ptr->bt;

        ptr->ct = current_time;
        ptr->tat = ptr->ct - ptr->at;
        ptr->wt = ptr->tat - ptr->bt;
        avg_TAT+=ptr->tat;
        avg_WT+=ptr->wt;
    }

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0; i<n; i++)
    {
        struct process *ptr = A + i;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", ptr->pid, ptr->bt, ptr->ct, ptr->tat, ptr->wt);
    }
}