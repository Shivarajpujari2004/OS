#include <stdio.h>

void main() {
    int n, m, i, j;
    printf("Enter the number of processes and number of types of resources:\n");
    scanf("%d %d", &n, &m);

    int max[n][m], need[n][m], all[n][m], ava[m], finish[n], dead[n];
    int flag = 1, c;

    // Initializing finish array to 0
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    printf("Enter the maximum number of each type of resource needed by each process:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated number of each type of resource for each process:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter the available number of each type of resource:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &ava[j]);
    }

    // Calculating the need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                c = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] <= ava[j]) {
                        c++;
                    }
                }
                if (c == m) { // If all resources for this process can be allocated
                    for (j = 0; j < m; j++) {
                        ava[j] += all[i][j];
                    }
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
    }

    int deadlock = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            dead[deadlock] = i;
            deadlock++;
        }
    }

    if (deadlock > 0) {
        printf("Deadlock has occurred:\n");
        printf("The deadlocked processes are:\n");
        for (i = 0; i < deadlock; i++) {
            printf("P%d ", dead[i]);
        }
        printf("\n");
    } else {
        printf("No deadlock has occurred!\n");
    }
}
