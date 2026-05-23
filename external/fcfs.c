#include <stdio.h>
#include <stdlib.h>


int main(){
  int n;
  
  printf("Enter Number of Processes: ");
  scanf("%d",&n);

  int at[20],bt[20],ct[20],wt[20],tat[20];

  float avg_wt=0,avg_tat=0;

  for(int i=0;i<n;i++){
    printf("Enter Arrival Time of Process %d :",i+1);
    scanf("%d",&at[i]);
    printf("Enter Burst Time of Process %d ",i+1);
    scanf("%d",&bt[i]);
  }

  ct[0]=at[0]+bt[0];

  for(int i=1;i<n;i++){
    if(at[i]>ct[i-1]){
      ct[i]=at[i]+bt[i];
    }
    else{
      ct[i]=ct[i-1]+bt[i];
    }
  }

  //CT = AT + BT 
  /*TAT=CT - AT 
   * WT = TAT - BT
   */

  for(int i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    
    avg_wt+=wt[i];
    avg_tat+=tat[i];

  }

  printf("\nProcess\tAT\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
  }

  printf("Avg TAT : %.2f\n",(avg_tat/n));
  printf("Avg WT : %.2f\n",(avg_wt/n));

  return 0;

}
