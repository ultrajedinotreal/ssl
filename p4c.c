#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int c, i, req[SIZE], head, st, n;
int hd;

void cscan();

void main() {


        printf("Enter total number of cylinders ");
        scanf("%d", &c);

        cscan();

}



void cscan() {

        int i, st = 0, p, temp, j;

        printf("Enter number of requests ");
        scanf("%d", &n);

        printf("Enter disk request queue ");
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
        printf("Enter initial position of head ");
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
        for (i = p-1; i>=0; i--) {
                st += (head - req[i]);
                head = req[i];
                printf("%d ", head);
        }

        st += head;
        head = 0;
        printf("%d ", head);

        head = c-1;
        printf("%d ", head);

        for (i = n-1; i >= p; i--) {
                st += (head - req[i]);
                head = req[i];
                printf("%d ", head);
        }

        printf("\nTotal seek time = %d", st);
}