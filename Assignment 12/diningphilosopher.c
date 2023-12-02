#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#define N 5  
void philosopher(int id, int* chopsticks) {
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        printf("Philosopher %d is thinking.\n", id+1);
        sleep(1);  
        while (chopsticks[left] == 0) {
            sleep(1);
        }
        chopsticks[left] = 0;
        printf("Philosopher %d picks up left chopstick %d.\n", id+1, left+1);
        while (chopsticks[right] == 0) {
            sleep(1);
        }
        chopsticks[right] = 0;
        printf("Philosopher %d picks up right chopstick %d and starts eating.\n", id+1, right+1);

        sleep(1); 
        chopsticks[left] = 1;
        printf("Philosopher %d releases left chopstick %d.\n", id+1, left+1);

        chopsticks[right] = 1;
        printf("Philosopher %d releases right chopstick %d.\n", id+1, right+1);
    }
}

int main() {
   

    int shmid = shmget(1122, 1024, IPC_CREAT | 0666);
    int* chopsticks = shmat(shmid, NULL, 0);
    for (int i = 0; i < N; i++) {
        chopsticks[i] = 1;  // 1 represents that the chopstick is available
    }

    // Create philosopher processes
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process (philosopher)
            philosopher(i, chopsticks);
            exit(0);
        } else if (pid < 0) {
            // Fork error
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all philosopher processes to finish (this will never happen in this simulation)
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    // Detach and remove shared memory
    shmdt(chopsticks);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
