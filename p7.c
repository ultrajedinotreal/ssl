#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int n;
int state[SIZE];
int mutex;

/*void wait(int s) {
        s--;;
}

void signal(int s) {
        s++;
}
*/




void display() {
        int i;
        printf("\n");
        for (i = 0; i < n; i++) {
                printf("Philosopher %d : ", i+1);
                if (state[i] == 0)
                        printf("Eating");
                else if (state[i] == 1)
                        printf("Thinking");
                /*else if (state[i] == 2)
                        printf("Hungry"); */
                printf("\n");
        }
}

void init() {
        int i;
        for (i = 0; i < n; i++)
                state[i] = 1;
}

/*
void philosopher(int x) {
        take_forks(x);
        state[x] = 0;
}

void take_forks(int x) {
        wait(mutex);
        test(x);
        signal(mutex);
}
*/

void test(int x) {
        if (state[(x+n-1)%n] != 0 && state[(x+1)%n] != 0)
                state[x] = 0;
}

void main() {

        int r, j, k, i;
        printf("Number of philosophers : ");
        scanf("%d", &n);

        for (i = 0; i < 5; i++) {
                printf("\nITERATION %d", i+1);

                init();
                r = rand();
                r = r%n;
                printf("(Random number : %d)", r+1);
                test(r);

                for (j = r-1; j >= 0; j--)
                        test(j);
                for (k = n-1; k > r; k--)
                        test(k);
                display();
        }

}