#include <stdio.h>

void main() {
    int p[20], bt[20], su[20], wt[20], tat[20], at[20], ct[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("Enter the number of processes --- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter the Arrival Time of Process %d --- ", i);
        scanf("%d", &at[i]);
        printf("Enter the Burst Time of Process %d --- ", i);
        scanf("%d", &bt[i]);
        printf("System/User Process (0/1) ? --- ");
        scanf("%d", &su[i]);
    }

    // Sort based on arrival time first, then by system/user process if arrival times are the same
    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            if(at[i] > at[k] || (at[i] == at[k] && su[i] > su[k])) {
                // Swap process ids
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap system/user identifiers
                temp = su[i];
                su[i] = su[k];
                su[k] = temp;

                // Swap arrival times
                temp = at[i];
                at[i] = at[k];
                at[k] = temp;
            }
        }
    }

    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        if (ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = ct[i] - at[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\t\tARRIVAL TIME\tSYSTEM/USER PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i = 0; i < n; i++) {
        printf("\n%d \t\t\t%d \t\t\t%d \t\t%d \t\t%d \t\t%d",p[i],at[i],su[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time is --- %f", wtavg/n);
    printf("\nAverage Turnaround Time is --- %f", tatavg/n);
}
