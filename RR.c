// WAP in C to implement SRTF Scheduling Algorithm.

#include<stdio.h>

struct process 
{
    int pid, at, bt, ct, tat, wt, rt, remaining_bt;
};

int main()
{
    int n, quantum;
    int current_time = 0, completed = 0;
    float avg_TAT = 0, avg_WT = 0;

    printf("Enter the Number of Processes : ");
    scanf("%d", &n);
    printf("Enter Time Quantum : ");
    scanf("%d", &quantum);

    struct process ps[n];                                   // Creating an Array
    for (int i = 0; i < n; i++)
    {
        struct process *ptr = &ps[i];
        ptr -> pid = i + 1;
        printf("Process P[%d]\nEnter Arrival Time : ", ptr->pid);
        scanf("%d", &ptr->at);
        printf("Enter Burst Time : ");
        scanf("%d", &ptr->bt);
        ptr->remaining_bt = ptr->bt;
    }

    while (completed < n) 
    {
        int flag = 0;                                               // Added flag to break out of loop
        for (int i = 0; i < n; i++) 
        {
            struct process *ptr = &ps[i];
            if (ptr->at <= current_time && ptr->remaining_bt > 0) 
            {
                int min_time = (ptr->remaining_bt < quantum) ? ptr->remaining_bt : quantum;
                current_time += min_time;
                ptr->remaining_bt -= min_time;

                if (ptr->remaining_bt == 0) 
                {
                    completed++;
                    ptr->ct = current_time;
                    ptr->tat = ptr->ct - ptr->at;
                    ptr->wt = ptr->tat - ptr->bt;
                }
                flag = 1;                                           // Set flag to indicate a process was executed
            }
        }
        if (flag == 0) 
        {
            current_time++;                                         // Increment Time if no process was executed
        }
    }

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT \n");
    for (int i = 0; i < n; i++)
    {
        struct process *ptr = &ps[i];
        avg_TAT += ptr->tat;
        avg_WT += ptr->wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", ptr->pid, ptr->at, ptr->bt, ptr->ct, ptr->tat, ptr->wt);
    }
    printf("Average Turnaround Time (TAT): %.2f\n", avg_TAT / n);
    printf("Average Waiting Time (WT): %.2f\n", avg_WT / n);
    return 0;
}
