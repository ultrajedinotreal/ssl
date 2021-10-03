#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int c, i, req[SIZE], head, st, n;
int hd;

void scan();


void main() {
        int x;

        printf("Enter total number of cylinders: ");
        scanf("%d", &c);

        scan();




}

void scan() {

        int i, st = 0, p, temp, j;

        printf("Enter number of requests: ");
        scanf("%d", &n);

        printf("Enter disk request queue:\n ");
        for (i = 0; i < n; i++) {
                 scanf("%d", &req[i]);
        }

        for (i = 0; i < n-1; i++) {
                for (j = i+1; j < n; j++) {
                        if (req[j] < req[i]) {
                                temp = req[j];
                                req[j] = req[i];
                                req[i] = temp;
                        }
                }
        }

        printf("Enter initial head position:  ");
        scanf("%d", &head);
        hd=head;
        for (i = 0; i < n; i++) {
                if (head < req[i]) {
                        p = i;
                        break;
                }
        }

        printf("\nOrder : ");
        printf("%d ",hd);
        for (i = p-1; i>=0; i--){
                st += (head - req[i]);
                head = req[i];
                printf("%d ", head);
        }

        st += head;
        head = 0;
        printf("%d ", head);

        for (i = p; i < n; i++) {
                st += (req[i] - head);
                head = req[i];
                printf("%d ", head);
        }

        printf("\nTotal seek time is %d", st);
}

