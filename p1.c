#include<stdio.h>
#include<stdlib.h>

int tar[10],tar1[10],tar2[10],tar3[10];
int o=7,n,i,t[10],w[10],ta[10],c[10],p[10],lp,j=0,temp,pd[10],td[10],op[10];
int count,j,n,time,remain,flag=0,time_quantum;
int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
float awt=0,ata=0,tm;

void fcfs();
void rr();
void sjf();
void pri();

void main()
{

    while(o!=0)
    {
        printf("\n\n 1: FCFS  2: SJF  3: RR  4: PRIORITY 0: Exit\nENTER CHOICE: ");
        scanf("%d",&o);
       
        switch(o)
        {
            case 0: exit(0);
            case 1: fcfs(); break;
            case 2: sjf(); break;
            case 3: rr(); break;
            case 4: pri(); break;
        }

    }


}


void fcfs()
{
    printf("\nEnter the no of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&t[i]);
    }
   
    w[0]=0;
    for(i=0;i<n-1;i++)
    {
         w[i+1]=w[i]+t[i];
    }
    for(i=0;i<n;i++)
    {
        c[i]=w[i]+t[i];
    }
    for(i=0;i<n;i++)
    {
        ta[i]=c[i];
    }
    printf("\nProcess\t\tWaiting time\tturn around time");
    printf("\n-----------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
       
        printf("\nP%d\t\t%d\t\t%d",i+1,w[i],ta[i]);
    }
    for(i=0;i<n;i++)
    {
        awt=awt+w[i];
        ata=ata+ta[i];
    }
    awt=awt/n;
    ata=ata/n;
    printf("\n\nAvg waiting time = %f , Avg TA time = %f",awt,ata);
    printf("\n-----------------------------------------------------------------------");
}

void pri()
{
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&t[i]);
        td[i]=t[i];
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the priority of P%d : ",i+1);
        scanf("%d",&p[i]);
        pd[i]=p[i];
    }
    lp=p[0];


    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(p[i]>p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
    w[0]=0;
    for(i=0;i<n-1;i++)
    {
        w[i+1]=w[i]+t[i];
    }
    for(i=0;i<n;i++)
    {
        c[i]=w[i]+t[i];
    }
    for(i=0;i<n;i++)
    {
        ta[i]=c[i];
    }
    printf("\nPROCESS\t  BURST\t\tPRIORITY\tWAITING TIME\tTURNAROUND TIME");
    printf("\n-----------------------------------------------------------------------");
   
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(pd[i]==p[j])
            {
                printf("\nP%d\t  %d\t\t%d\t\t%d\t\t%d",i+1,t[j],pd[i],w[j],ta[j]);
            }
        }
    }

    awt=0;ata=0;

    for(i=0;i<n;i++)
    {
        awt=awt+w[i];
        ata=ata+ta[i];
    }
    awt=awt/n;
    ata=ata/n;

    printf("\n\nAVERAGE WAITING TIME = %f AVERAGE  TURNAROUND = %f",awt,ata);
    printf("\n-----------------------------------------------------------------------");
}

 void sjf()
 {
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        op[i]=i;
    }
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time of P%d : ",i+1);
        scanf("%d",&t[i]);
        td[i]=t[i];
    }

    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(td[i]>td[j])
            {
                temp=td[i];
                td[i]=td[j];
                td[j]=temp;

                temp=op[i];
                op[i]=op[j];
                op[j]=temp;
            }
        }
    }
    /* for(i=0;i<n;i++)
    {printf("\nop : %d ",op[i]);
    }*/
    for(i=0;i<n-1;i++)
    {
         w[i+1]=w[i]+td[i];
    }
    for(i=0;i<n;i++)
    {
         c[i]=w[i]+td[i];
    }
    for(i=0;i<n;i++)
    {
      ta[i]=c[i];
    }
    printf("\nPROCESS\t  BURST TIME\tWAITING TIME\tTURN AROUND TIME");
    printf("\n-----------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(op[j]==i)
            {
                printf("\nP%d\t  %d\t\t%d\t\t%d",i+1,t[i],w[j],ta[j]);
            }
        }
    }

    awt=0;ata=0;

    for(i=0;i<n;i++)
    {
        awt=awt+w[i];
        ata=ata+ta[i];
    }
    //printf("\nawt = %d , ata = %d ",awt,ata);
    awt=awt/n;
    ata=ata/n;

    printf("\n\nAAVERAGE WAITING TIME = %f ,AVERAGE WAITING TIME = %f",awt,ata);
    printf("\n-----------------------------------------------------------------------");
 }

void rr()
{
    printf("Enter Total no of Processes:\t ");
    scanf("%d",&n);
    remain=n;
    for(count=0;count<n;count++)
    {
        printf("Enter Arrival Time of P%d : ",count+1);
        scanf("%d",&at[count]);
        printf("Enter burst time  of P%d : ",count+1);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&time_quantum);
    // printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    i=0;
    for(time=0,count=0;remain!=0;)
    {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0)
        {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
            remain--;
            //printf("P[%d]\t\t%d\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            tar[i]=count+1;
            tar2[i]=time-at[count];
            tar3[i]=time-at[count]-bt[count];
            i++;
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(at[count+1]<=time)
            count++;
        else
            count=0;
    }
    for(i=0;i<n;i++)
    {
        td[i]=tar[i];
    }

    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(td[i]>td[j])
            {
                temp=td[i];
                td[i]=td[j];
                td[j]=temp;
            }
        }
    }

    printf("\nPROCESS\t\tTURNAROUND TIME\t\tWAITING TIME");
    printf("\n-----------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+1==tar[j])
            {
                printf("\nP%d\t\t%d\t\t        %d",tar[j],tar2[j],tar3[j]);
            }
        }
    }


    printf("\n\nAVERAGE WAITING TIME = %f\n",wait_time*1.0/n);
    printf("AVERAGE TURNAROUND TIME = %f",turnaround_time*1.0/n);
    printf("\n-----------------------------------------------------------------------");

}