// WAP in C to implement SJF CPU Scheduling Algorithm.

#include<stdio.h>

struct PCB
{
    int pid, bt, tat, wt;
};

void main()
{
    struct PCB A[10], temp;
    int n, i, j = 1, sum = 0, tat_total = 0, wt_total = 0;
    float avg_tat = 0, avg_wt = 0;

    printf("\n SJF Algorithm \n");
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P[%d] : ", i + 1);
        scanf("%d", &A[i].bt);
        A[i].pid = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (A[j].bt > A[j + 1].bt)
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        A[i].wt = sum;
        sum = sum + A[i].bt;
        A[i].tat = sum;
    }

    printf("\nPID \t BT \t TAT \t WT\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t %d\t %d\t %d \n", A[i].pid, A[i].bt, A[i].tat, A[i].wt);
        tat_total += A[i].tat;
        wt_total += A[i].wt;
    }
    avg_tat = tat_total / (float)n;
    avg_tat = wt_total / (float)n;

    printf("\n Total Turnaround Time : %d\n", tat_total);
    printf("\\n Total Waiting Time : %d\n", wt_total);

    printf("\nAverage Turnaround Time : %.3f\n", avg_tat);
    printf("Average Waiting Time : %.3f\n", avg_wt);
}