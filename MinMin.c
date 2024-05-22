#include<stdio.h>
#include<limits.h>

int main() 
{
    int nT, nM;                                                 // Number of Tasks, Number of Machines
    printf("\nEnter Number of Machines and Tasks : \n");
    scanf("%d%d", &nM, &nT);

    int minMin[nM][nT];                                         // Declaring a 2-D Array of size nM n nT to store time required
    int tmp[nM][nT];                                            // Temporary Variable to store a copy of 'minMin'
    int makespan = 0;                                           
    printf("\nFill Data :\n");                                    // User prompts and stores them in the 'minMin' array
    for (int i = 0; i < nM; i++)
        for (int j = 0; j < nT; j++) 
        {
            scanf("%d", &minMin[i][j]);
            tmp[i][j] = minMin[i][j];
        }

    printf("\nOriginal Data : \n");
    for (int i = 0; i < nM; i++) {
        for (int j = 0; j < nT; j++)
            printf("%d ", minMin[i][j]);
        printf("\n");
    }

    int resultTask[nT];
    int resultMachine[nT];
    int resultTime[nT];

    int ptr = -1;                                               // Indicates if result set is full or not

    while (ptr < nT - 1) 
    {
        int time[nT], machine[nT];                              // Stores Minimum time w.r.t machine of each task
        for (int j = 0; j < nT; j++)                            // Finding Minimum Processing Time for each task
        {
            int minimum = INT_MAX;
            int pos = -1;
            for (int i = 0; i < nM; i++) 
            {
                if (minMin[i][j] < minimum) 
                {
                    minimum = minMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }

        int minimum = INT_MAX;
        int pos = -1;

        for (int j = 0; j < nT; j++)                            // Now we find the task with minimum time 
        {
            if (time[j] < minimum) 
            {
                minimum = time[j];
                pos = j;
            }
        }

        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (minimum > makespan)
            makespan = minimum;

        for (int i = 0; i < nM; i++)                            // Updating the state after scheduling the current task.
        {
            for (int j = 0; j < nT; j++) 
            {
                if (j == resultTask[ptr])
                    minMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && minMin[i][j] != INT_MAX)
                    minMin[i][j] += minimum;
                else
                    continue;
            }
        }
    }

    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < nT; i++) {
        printf("Task %d Runs on Machine %d with Time %d units.\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }
    printf("\nTotal Elapsed Time: %d units.\n", makespan);
    return 0;
}


/*
    Declare a 2d-array of size nM x nT
    Data should be in the following format:
    T1 T2 T3
    M1 | 140 | 20 | 60 |
    M2 | 100 | 100 | 70 |
*/

/*
Inside the while loop, it calculates the minimum processing time for each task on all machines and selects the task with the maximum minimum processing time.
    It updates the result arrays with the selected task, machine, and processing time.
    It updates the minMin array based on the task selected to schedule it.
*/