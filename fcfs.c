#include<stdio.h>
struct p
{
    int id,AT,BT,CT,WT,TT;
}p[10];
void fcfs(struct p p[],int n)
{
    int total_WT=0;
    int total_TT=0;
    int CT=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].AT>p[j+1].AT)
            {
                struct p temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if (CT < p[i].AT)
            CT = p[i].AT;
        CT+=p[i].BT;
        p[i].CT=CT;

        p[i].TT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TT-p[i].BT;

        total_WT+=p[i].WT;
        total_TT+=p[i].TT;
    }

    printf("\n__Gantt Chart__\n");
    for(int i=0;i<n;i++)
    {
        printf("| P%d ",p[i].id);
    }
    printf("\n");
    printf("0\t");
    for(int i=0;i<n;i++)
        printf("%d\t",p[i].CT);
    printf("\nProcess\tAT\tBT\tCT\tTT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TT,p[i].WT);
    }
    printf("\nAverage Waiting Time : %.2f",(float)total_WT/n);
    printf("\nAverage Turnaround Time : %.2f",(float)total_TT/n);
}
int main()
{
    int n,i,j,AT[10],BT[10];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    printf("\nEnter the Arrival Time and Burst Time for each process : \n");
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        printf("P%d : ",p[i].id);
        scanf("%d%d",&p[i].AT,&p[i].BT);
    }
    
    fcfs(p,n);
    
    return 0;

}
/* Sample output
Enter the number of process : 4

Enter the Arrival Time and Burst Time for each process : 
P1 : 1 2
P2 : 3 4
P3 : 2 5
P4 : 4 7

__Gantt Chart__
| P1 | P3 | P2 | P4 
0	3	8	12	19	
Process	AT	BT	CT	TT	WT
P1	1	2	3	2	0
P3	2	5	8	6	1
P2	3	4	12	9	5
P4	4	7	19	15	8

Average Waiting Time : 3.50
Average Turnaround Time : 8.00 */
