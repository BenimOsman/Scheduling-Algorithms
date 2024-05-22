// WAP in C to implement SRTF Scheduling Algorithm.

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process
{
    int pid, at, bt, ct, wt, tat, rt, start_time;
};

int main()
{
    int n, current_time = 0, completed = 0;
    float bt_remaining[100];
    bool is_completed[100] = {false}, is_first_process = {true};
    float total_wt=0, total_tat=0, total_rt=0;
    printf("Enter Number of Processes : ");
    scanf("%d", &n);
    struct process ps[n];
    for (int i = 0; i < n; i++)
    {
        struct process *ptr = ps + i;
        ptr->pid = i + 1;
        printf("Process [%d]\nEnter Arrival Time : ", ptr->pid);
        scanf("%d", &ptr->at);
        printf("Enter Burst Time : ");
        scanf("%d", &ptr->bt);
        bt_remaining[i] = ptr->bt;
    }

    while (completed != n)                                                  // Find process with minimum burst time in ready queue at current time.
    {
        int min_index = -1; 
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (bt_remaining[i] < minimum)
                {
                    minimum = bt_remaining[i];
                    min_index = i;
                }
                if (bt_remaining[i] == minimum)
                {
                    if (ps[i].at < ps[min_index].at)
                    {
                        minimum = bt_remaining[i];
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            if (bt_remaining[min_index] == ps[min_index].bt)
            {
                ps[min_index].start_time = current_time;
            }
            bt_remaining[min_index] -= 1;
            current_time++;
            if (bt_remaining[min_index] == 0)
            {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
                ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;

                total_tat +=ps[min_index].tat;
                total_wt += ps[min_index].wt;
                total_rt += ps[min_index].rt;
                completed++;
                is_completed[min_index] = true;
            }
        }
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++)

    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    printf("\n");
    printf("\nAverage Turn Around Time = %f ",(float)total_tat/n);
    printf("\nAverage Waiting Time = %f ",(float)total_wt/n);
    printf("\nAverage Response Time= %f ",(float)total_rt/n);
    return 0;
}
