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

  //Bestfit algorithm; 
  
  for(int i=0;i<process_count;i++){
    for(int j=0;j<block_count;j++){
      if(block_size[j]>=process_size[i]){
        allocated[i]=j;
        block_size[j]-=process_size[i];
        allocated_memory+=process_size[i]; 
        break;
      }
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock No.\n");
for(int i = 0; i < process_count; i++) {
printf("%d\t\t%d\t\t", i+1, process_size[i]);
if(allocated[i] != -1)
printf("%d\n", allocated[i] + 1);
else
printf("Not Allocated\n");
}
// Calculate remaining free memory
for(int i = 0; i < block_count; i++) {
totalFree += block_size[i];
}
printf("\nTotal Memory = %d", total_memory);
printf("\nTotal Allocated Memory = %d", allocated_memory);
printf("\nTotal Free Memory = %d\n", totalFree);

}
