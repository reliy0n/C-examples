#include <stdio.h>

struct student{
  double number;
  double fmark;
  double mark;
  char name[20];
  char surname[20];
};

  int main(){
    struct student client = {0.0,0.0,0.0,"",""};
    FILE *fPtr;
    int i , offset = 0;
    fPtr = fopen("a.dat","wb+");
    for(i = 0 ; i < 5 ; i++){
      scanf("%lf %19s %19s %lf %lf",&client.number,client.name,client.surname,&client.mark,&client.fmark);
      fwrite(&client,sizeof(struct student), 1,fPtr);
    }
     fseek(fPtr, SEEK_SET, 0);
      while(fread(&client, sizeof(struct student), 1 , fPtr)){
        offset += 1;
        if(offset == 3){printf("Third entry is: %.2f %19s %19s %.2f %.2f\n",client.number,client.name,client.surname,client.mark,client.fmark);}
      }

      fclose(fPtr);

  }
