#include <stdio.h>
#include <stdlib.h>


int main(){
  
  int blocks[20],process[20],allocated[20];
  int block_size,process_size;
  int total_memory=0,allocated_memory=0;


  printf("Enter the number of blocks: ");
  scanf("%d",&block_size);
  
  printf("Enter the size of %d blocks:",block_size);
  for(int i=0;i<block_size;i++){
     scanf("%d",&blocks[i]);
     total_memory+=blocks[i];
  }

  printf("\nEnter the number of processes:");
  scanf("%d",&process_size);
  
  printf("Enter the size of %d processes:",process_size);
  for(int i=0;i<process_size;i++){
    scanf("%d",&process[i]);
    allocated[i]=-1;
  }

  for(int i=0;i<process_size;i++){
    for(int j=0;j<block_size;j++){
      if(blocks[j]>=process[i]){
        allocated[i]=j;
        allocated_memory+=process[i];
        blocks[j]-=process[i];
        break;
      }
    }
  }
  
  printf("\nProcess\tProcess Size\tAllocated\n");
  for(int i=0;i<process_size;i++){
    if(allocated[i]!=-1){
      printf("P%d\t%d\t\t%d\n",i+1,process[i],allocated[i]);
    }
    else {
      printf("P%d\t%d\t\tNot Allocated\n",i+1,process[i]);
    }
  }


  printf("total_memory:%d\n",total_memory);
  printf("allocated_memory:%d\n",allocated_memory);
  

}
