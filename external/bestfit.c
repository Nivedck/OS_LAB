#include <stdio.h>
#include <stdlib.h>

int main(){

  int block_size[20], process_size[20],allocated[20];
  int block_count,process_count;
  int total_memory=0,allocated_memory=0,totalFree=0;

  printf("Enter number of blocks:");
  scanf("%d",&block_count);

  for(int i=0;i<block_count;i++){
    printf("\nEnter size of block %d:",i+1);
    scanf("%d",&block_size[i]);
    total_memory+=block_size[i];
    allocated[i]=-1;
  }

  printf("Enter the number of process requests:");
  scanf("%d",&process_count);

  for(int i=0;i<process_count;i++){
    printf("Enter size of process %d : ",i+1);
    scanf("%d",&process_size[i]);
  }

  for(int i=0;i<process_count;i++){
    int best_index = -1;
    
    for(int j=0;j<block_count;j++){
      if(block_size[j]>=process_size[i]){
        if(best_index==-1 || block_size[j]<block_size[best_index]){
          best_index=j;
        }
      }
    }
    
    if(best_index!=-1){ 
      allocated[i]=best_index;
      block_size[best_index]-=process_size[i];
      allocated_memory+=process_size[i];
    }
  }

   printf("\nProcess\tProcess Size\tAllocated\n");
  for(int i=0;i<process_count;i++){
    if(allocated[i]!=-1){
      printf("P%d\t%d\t\t%d\n",i+1,process_size[i],allocated[i]+1);
    }
    else {
      printf("P%d\t%d\t\tNot Allocated\n",i+1,process_size[i]);
    }
  }


  printf("total_memory:%d\n",total_memory);
  printf("allocated_memory:%d\n",allocated_memory);
   

}
