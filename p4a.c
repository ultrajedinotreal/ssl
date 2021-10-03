#include<stdio.h>
void main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("Enter the max size of disk : ");
            scanf("%d",&max);
            printf("Enter the size of queue : ");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read: \n");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            printf("Enter the initial head position : ");
            scanf("%d",&head);
            queue[0]=head;
            printf("\nThe order is : ");
            printf("%d",head);


            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("\t%d ",queue[j+1]);
            }
            printf("\n\n");
            printf("Total seek time is : %d\n\n",seek);
            avg=seek/(float)n;
            //printf("Average seek time is %f\n",avg);

}
