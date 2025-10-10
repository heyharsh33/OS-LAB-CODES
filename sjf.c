#include <stdio.h>
int main() {
    int i, j, n, temp;
    int t[10], p[10], wt[10], tt[10];
    int twt = 0, ttat = 0;
    float awt, atat;
    printf("Enter number of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the Burst Time of Process %d: ", i + 1);
        scanf("%d", &t[i]);
        p[i] = i + 1;
    }
    // Sorting by Burst Time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (t[i] > t[j]) {
                temp = t[i]; t[i] = t[j]; t[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    // Calculating Waiting Time
    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + t[i - 1];
    // Calculating Turnaround Time
    for (i = 0; i < n; i++)
        tt[i] = t[i] + wt[i];
    // Printing results
    printf("\nSHORTEST JOB FIRST SCHEDULING ALGORITHM\n");
    printf("PROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], t[i], wt[i], tt[i]);
        twt += wt[i];
        ttat += tt[i];
    }
    awt = (float)twt / n;
    atat = (float)ttat / n;
    printf("\nAVERAGE WAITING TIME = %.2f", awt);
    printf("\nAVERAGE TURNAROUND TIME = %.2f\n", atat);
    return 0;
}
/*

output

Enter number of process: 3
Enter the Burst Time of Process 1: 04
Enter the Burst Time of Process 2: 13
Enter the Burst Time of Process 3: 25

SHORTEST JOB FIRST SCHEDULING ALGORITHM
PROCESS ID      BURST TIME      WAITING TIME    TURNAROUND TIME
1               4               0               4
2               13              4               17
3               25              17              42

AVERAGE WAITING TIME = 7.00
AVERAGE TURNAROUND TIME = 21.00

*/

//Another version of this code.

/*
#include<stdio.h> 
int main() 
{ 
int i,j,k,n,sum,wt[10],tt[10],twt,ttat; 
int t[10],p[10];
float awt,atat; 
printf("Enter number of process\n"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
    printf("\n Enter the Burst Time of Process %d: ",i); 
    scanf("\n %d",&t[i]); 
} 
for(i=0;i<n;i++) 
    p[i]=i; 
    for(i=0;i<n;i++) 
    { 
        for(k=i+1;k<n;k++) 
        { 
            if(t[i]>t[k]) 
            { 
                int temp; 
                temp=t[i]; 
                t[i]=t[k]; 
                t[k]=temp; 
                temp=p[i]; 
                p[i]=p[k]; 
                p[k]=temp; 
            }     
        } 
        printf("\n\n SHORTEST JOB FIRST SCHEDULING ALGORITHM");
        printf("\n PROCESS ID \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n\n"); 
        wt[0]=0; 
        for(i=0;i<n;i++) 
        { 
            sum=0; 
            for(k=0;k<i;k++) 
            { 
                wt[i]=sum+t[k]; 
                sum=wt[i]; 
            }     
        } 
        for(i=0;i<n;i++) 
        { 
            tt[i]=t[i]+wt[i]; 
        } 
        for(i=0;i<n;i++) 
        { 
            printf("%5d \t\t%d \t\t %5d \t\t %5d \n\n",p[i],t[i],wt[i],tt[i]); 
        } 
        twt=0; 
        ttat=t[0]; 
        for(i=1;i<n;i++) 
        { 
            twt=twt+wt[i]; 
            ttat=ttat+tt[i]; 
        } 
        awt=(float)twt/n;
        atat=(float)ttat/n; 
        printf("\n AVERAGE WAITING TIME %4.2f",awt); 
        printf("\n AVERAGE TURN AROUND TIME %4.2f",atat); 
    }
return 0;
}
*/
