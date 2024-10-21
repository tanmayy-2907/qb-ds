#include<stdio.h>

#define m 10

typedef struct{

  int key;
  int value;
}hash_table;

void initiliaze(hash_table table[], int key, int value);
void insert(hash_table table[], int key, int value);
void display(hash_table table[]);


int main()
{
  int i,key,value,n;
  hash_table table[m];
  
  initiliaze(table,key,value);
  display(table);

    printf("\nEnter No. Of Elements \n");
    scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter Key \n");
    scanf("%d",&key);
    
    printf("\nEnter Value \n");
    scanf("%d",&value);
    
    insert(table,key,value);
  }
  display(table);
  return 0;
}

void initiliaze(hash_table table[], int key, int value)
{
  int i;

  for(i=0;i<m;i++)
  {
      table[i].key=-1;
      table[i].value=0;
  }
}

void display(hash_table table[])
{
  int i;

  printf("------------------------------------------------------");
  printf("\n INDEX                 KEY                VALUE");
  printf("\n------------------------------------------------------");
  for(i=0;i<m;i++)
  {
    printf("\n%5d%20d%20d",i,table[i].key,table[i].value);
  }

}

int hash(int key)
{
  return (key%m);
}

void insert(hash_table table[], int key, int value)
{
  int orgind,ind,i=0;
  orgind=hash(key);
  ind=orgind;

  while(table[ind].key!=-1)
  {
    if(table[ind].key==key)
    {
      printf("\nDuplicate Key Is Not Allowed\n");
      return;
    }

    i++;
    ind=(orgind + i*i)%m;

    if(orgind==ind)
    {
      printf("\n The Table Is Full\n");
      return;
    }
  }
    printf("\n No. of Times Collision Occured For Key %d :%d",key,i);
    table[ind].key=key;
    table[ind].value=value;
}


