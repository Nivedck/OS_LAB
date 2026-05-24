#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int n;
  int at[20],bt[20],rt[20],tat[20],wt[20],ct[20];
  int time=0,tq,found,completed=0;
  float avg_tat=0,avg_wt=0;

  printf("Enter no of processes: ");
  scanf("%d",&n);

  printf("\nEnter Process Details\n");
  for(int i=0;i<n;i++){
    printf("Enter Arrival time and Burst Time of P%d:",i+1);
    scanf("%d %d",&at[i],&bt[i]);
    rt[i]=bt[i];
  }

  printf("\nEnter Time Quantum: ");
  scanf("%d",&tq);

  while(completed<n){
    found=0;
    for(int i=0;i<n;i++){
      if(at[i]<=time && rt[i]>0){
        found=1;
        if(rt[i]>tq){
          time+=tq;
          rt[i]-=tq;
        }
        else{
          time+=rt[i];
          ct[i]=time;
          rt[i]=0;
          completed++;
        }
      }
    }
    if(!found){
      time++;
    }
  }  

  for(int i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];

    avg_wt+=wt[i];
    avg_tat+=tat[i];
  }

  printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
  for(int i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
  }

  printf("Average TAT:%.2f\n",avg_tat/n);
  printf("Average WT:%.2f\n",avg_wt/n);

  return 0;

}
