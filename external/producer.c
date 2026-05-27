#include <stdio.h>
#include <stdlib.h>


int mutex=1;
int full=0;
int empty;
int x;

int wait(int s){
  return(--s);
}

int signal(int s){
  return(++s);
}


void producer(){
  empty=wait(empty);
  mutex=wait(mutex);
  x++;
  printf("Producer produced %d!\n",x);
  mutex=signal(mutex);
  full=signal(full);
}


void consumer(){
  full=wait(full);
  mutex=wait(mutex);
  x--;
  printf("Consumer conusmed %d !:\n",x);
  mutex=signal(mutex);
  empty=signal(empty);
}

int main(){
  int choice;
  printf("Enter the size of buffer:");
  scanf("%d",&empty);

  while(1){
    printf("\n1.Produce\n2.Consume\n3.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        if(mutex==1 && empty!=0){
          producer();
        }else{
          printf("Buffer is Full!\n");
        
        }
        break;

      case 2:
        if(empty==1 && full!=0){
          consumer();
        }else{
          printf("Buffer is empty!\n");
        }
        break;

      case 3:
        exit(0);
      
      default:
        printf("Invalid choice!!\n");
    }
  }

  return 0;

}


