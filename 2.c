//fcfs cu scheduling
#include <stdio.h>

#define MAX 100

int main() {
    int Arrival_time[MAX], Burst_time[MAX], Completion_time[MAX],
        Turn_Around_time[MAX], Waiting_time[MAX], j;
    float Average_Turn_Around_time = 0, Average_Waiting_time = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &j);

    // Input arrival time and burst time for each process
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < j; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &Arrival_time[i], &Burst_time[i]);
    }

    // Calculate completion time for each process
    Completion_time[0] = Burst_time[0];
    for (int i = 1; i < j; i++) {
        Completion_time[i] = Completion_time[i - 1] + Burst_time[i];
    }

    // Calculate turn around time and waiting time for each process
    for (int i = 0; i < j; i++) {
        Turn_Around_time[i] = Completion_time[i] - Arrival_time[i];
        Waiting_time[i] = Turn_Around_time[i] - Burst_time[i];
        Average_Waiting_time += Waiting_time[i];
        Average_Turn_Around_time += Turn_Around_time[i];
    }

    // Output process details and calculated times
    printf("\nProcess Arrival(T) Burst(T) Completion(T) TurnAround(T) Waiting(T)\n");
    for (int i = 0; i < j; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1,
               Arrival_time[i], Burst_time[i], Completion_time[i],
               Turn_Around_time[i], Waiting_time[i]);
    }

    // Calculate and output average turn around time and average waiting time
    if (j > 0) {
        Average_Turn_Around_time /= j;
        Average_Waiting_time /= j;
    }
    printf("\nAverage Turn Around Time: %.2f\n", Average_Turn_Around_time);
    printf("Average Waiting Time: %.2f\n", Average_Waiting_time);

    return 0;
}
