/*
______________Algorithm____________

Input the number of processes and their AT and BT.

Initialize:

CT (Current time) = 0

completed = 0 (number of processes completed)

done flag in each process to mark completion

Repeat until all processes are completed:

Find all processes where AT <= CT and done == 0

From those, choose the one with the smallest BT

If multiple have same BT, pick the one with earlier AT

If no process is ready, increment CT++

Once a process is selected:

Calculate:

CT = current time + BT of selected process

TT = CT - AT

WT = TT - BT

Mark process as done = 1

Add process ID to Gantt chart

After all processes complete:

Print Gantt chart

Display CT, TT, WT for all processes

Calculate and display average WT and average TT
*/



#include<stdio.h>
struct process
{
    int AT,BT,CT,pid,done,WT,TT;
}p[10];

void sjfs(struct process p[],int n)
{
    int CT=0,completed=0,total_wt=0,total_tt=0;
    int complete[10];

    while(completed<n)
    {
        int idx=-1,min_bt=10000;
        for(int i=0;i<n;i++)
        {
            if(p[i].AT<=CT&&p[i].done==0)
            {
                if(p[i].BT<min_bt)
                {
                    min_bt=p[i].BT;
                    idx=i;
                }
                else if(p[i].BT==min_bt)
                {
                    if(p[i].AT>p[idx].AT)
                    {
                        idx=i;
                    }
                }
            }
            
        }
        if(idx!=-1)
            {
                CT+=p[idx].BT;
                p[idx].CT=CT;
                p[idx].TT=p[idx].CT-p[idx].AT;
                p[idx].WT=p[idx].TT-p[idx].BT;
                p[idx].done=1;
                complete[completed]=p[idx].pid;
                total_wt += p[idx].WT;
                total_tt += p[idx].TT;

                completed++;
            }
            else
            CT++;
        
       
    }
     printf("\n Gantt Chart \n");
        for(int i=0;i<n;i++)
        {
            printf("P%d\t|",complete[i]);
        }printf("\n");
        int time=0;
        printf("0\t");
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<n;j++)
             {
                 if(p[j].pid==complete[i])
                 {
                     
                    time += p[j].BT;
                    printf("%d\t", time);
                    break;

                 }
             }
        }

        printf("\nProcess\tAT\tBT\tCT\tTT\tWT\n");
        for (int i = 0; i < n; i++)
        {
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].CT, p[i].TT, p[i].WT);
        }
        
        printf("\nAverage Waiting Time : %.2f", (float)total_wt / n);
        printf("\nAverage Turnaround Time : %.2f", (float)total_tt / n);

}
int main()
{
    int n,i,j,AT[10],BT[10];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    printf("\nEnter the Arrival Time and Burst Time for each process : \n");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("P%d : ",p[i].pid);
        scanf("%d%d",&p[i].AT,&p[i].BT);
    }
    
    sjfs(p,n);
    
    return 0;

}
/*Sample Output

Enter the number of process : 4

Enter the Arrival Time and Burst Time for each process : 
P1 : 0 8
P2 : 1 4
P3 : 2 9
P4 : 3 5
 Gantt Chart 
P1	|P2	|P4	|P3	|
0	8	12	17	26	

Process	AT	BT	CT	TT	WT
P1	0	8	8	8	0
P2	1	4	12	11	7
P3	2	9	26	24	15
P4	3	5	17	14	9

Average Waiting Time : 7.75
Average Turnaround Time : 14.25
*/
