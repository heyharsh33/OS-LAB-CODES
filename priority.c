#include <stdio.h>  
int main() 
{ 
int i,j,n,tat[10],wt[10],bt[10],pid[10],pr[10],t,twt=0,ttat=0; 
float awt,atat; 
printf("\n-----------PRIORITY SCHEDULING--------------\n"); 
printf("Enter the No of Process: "); 
scanf("%d", &n); 
for(i=0;i<n;i++) 
{ 
    pid[i] = i; 
    printf("Enter the Burst time of Pid %d : ",i); 
    scanf("%d",&bt[i]); 
    printf("Enter the Priority   of Pid %d : ",i); 
    scanf ("%d",&pr[i]); 
} 
// Sorting start 
for(i=0;i<n;i++) 
    for(j=i+1;j<n;j++) 
    { 
        if (pr[i] > pr[j] ) 
        { 
            t = pr[i]; 
            pr[i] = pr[j]; 
            pr[j] = t; 
            t = bt[i]; 
            bt[i] = bt[j]; 
            bt[j] = t; 
            t = pid[i];  
            pid[i] = pid[j]; 
            pid[j] = t; 
        }   
    } 
// Sorting finished 
tat[0] = bt[0]; 
wt[0] = 0; 
for(i=1;i<n;i++) 
{ 
    wt[i] = wt[i-1] + bt[i-1]; 
    tat[i] = wt[i] + bt[i]; 
} 
printf("\n---------------------------------------------------------------\n"); 
printf("\nPid\t Priority\tBurst time\t WaitingTime\tTurnArroundTime\n"); 
printf("\n--------------------------------------------------------------\n"); 
for(i=0;i<n;i++) 
{ 
    printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",pid[i],pr[i],bt[i],wt[i],tat[i]); 
} 
for(i=0;i<n;i++) 
{ 
    ttat = ttat+tat[i]; 
    twt = twt + wt[i]; 
} 
awt = (float)twt / n; 
atat = (float)ttat / n; 
printf("\n\nAvg.Waiting Time: %.2f\nAvg.Turn Around Time: %.2f\n",awt,atat); 
return 0;
}

/*

output

-----------PRIORITY SCHEDULING--------------
Enter the No of Process: 4
Enter the Burst time of Pid 0 : 2
Enter the Priority   of Pid 0 : 3
Enter the Burst time of Pid 1 : 6
Enter the Priority   of Pid 1 : 2
Enter the Burst time of Pid 2 : 4
Enter the Priority   of Pid 2 : 1
Enter the Burst time of Pid 3 : 5
Enter the Priority   of Pid 3 : 7

---------------------------------------------------------------

Pid      Priority       Burst time       WaitingTime    TurnArroundTime

--------------------------------------------------------------

2       1               4               0               4
1       2               6               4               10
0       3               2               10              12
3       7               5               12              17

Avg.Waiting Time: 6.50
Avg.Turn Around Time: 10.75

*/