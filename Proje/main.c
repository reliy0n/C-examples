#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

/* Struct for student data */
struct data{
  int unsigned id;
  int unsigned exam;
  char name[SIZE];
  char surname[SIZE];

}ogrenci,ata;

/* input: string, output : lower character string */
  const char * golower(char text[SIZE]){
    int i;
    for(i = 0; i < 10 ; i++){
      text[i] = tolower(text[i]);
    }
    return text;
  }
  /* input: id and struct , output : if find 1, notfound 0*/
  int find(struct data ogrenci,int id){
    int find = 0;
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
      fseek(fPtr, SEEK_SET, 0);
      while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
        if(ogrenci.id == id ){
        find = 1;
        }
      }
      fclose(fPtr);
      return find;
  }
  /* input: struct , output : add new user*/
  void add(struct data ogrenci){
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
    fwrite(&ogrenci,sizeof(ogrenci),1,fPtr);
    fclose(fPtr);
  }
  /* input: struct , output : all user */
  void listAll(struct data ogrenci){
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
      fseek(fPtr, SEEK_SET, 0);
      while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
        printf("%d\t%9s\t%9s\t%d\n", ogrenci.id, ogrenci.name,ogrenci.surname,ogrenci.exam );
      }
      fclose(fPtr);
  }
  /* input: struct and search student id, output : user which have searching id */
  void search_id(struct data ogrenci,int id){
    int find = 0;
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
      fseek(fPtr, SEEK_SET, 0);
      while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
        if(ogrenci.id == id ){
        printf("%d %9s %9s %d\n",ogrenci.id, ogrenci.name,ogrenci.surname,ogrenci.exam );
        find = 1;
        }
      }
      fclose(fPtr);
      if(find == 0){printf("Doesn't any match.\n");}
  }
  /* input: struct and student name, output : users which have searching name */
  void search_name(struct data ogrenci,char name[SIZE]){
    int find = 0;
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
    fseek(fPtr,SEEK_SET,0);
    while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
      if(strcmp(golower(name),golower(ogrenci.name)) == 0){
        find = 1;
        printf("%d %9s %9s %d\n",ogrenci.id, ogrenci.name,ogrenci.surname,ogrenci.exam );
      }
    }
    fclose(fPtr);
    if(find == 0){printf("Doesn't any match.\n");}
  }
  /* input: struct and student surname, output : users which have searching surname */
  void search_surname(struct data ogrenci,char surname[SIZE]){
    int find = 0;
    FILE *fPtr;
    fPtr = fopen("data.data","ab+");
    fseek(fPtr,SEEK_SET,0);
    while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
      if(strcmp(golower(surname),golower(ogrenci.surname)) == 0){
        find = 1;
        printf("%d %9s %9s %d\n",ogrenci.id, ogrenci.name,ogrenci.surname,ogrenci.exam );
      }
    }
    fclose(fPtr);
    if(find == 0){printf("Doesn't any match.\n");}
  }
  /* input: struct and id , output : update user */
  void update(struct data ogrenci,int id){
    int find = 0;
    int count = 0;
    FILE *fPtr;
    fPtr = fopen("data.data","rb+");
      fseek(fPtr, 0 , SEEK_SET);
      while(fread(&ata,sizeof(struct data),1,fPtr)){
        count += 1;
          if(ata.id == id ){
            fseek( fPtr , (sizeof(struct data) * count) - sizeof(struct data),SEEK_SET );
            fwrite(&ogrenci,sizeof(ogrenci),1,fPtr);
            find = 1;
            break;
          }
      }
      fclose(fPtr);
      if(find == 0){printf("Doesn't any match.\n");}
      else{printf("user %d updated\n",id);}
  }
  /* input: struct and id , output : delete id */
  void delete(struct data ogrenci,int id){
    int find = 0;
    FILE *fPtr;
    FILE *cPtr;
    fPtr = fopen("data.data","ab+");
    cPtr = fopen("clean.data","wb");
      fseek(fPtr, 0, SEEK_SET);
      while(fread(&ogrenci,sizeof(struct data),1,fPtr)){
          if(ogrenci.id == id ){
            find = 1;
          }
          else{
            fwrite(&ogrenci, sizeof(ogrenci),1,cPtr);
          }
      }
      fclose(fPtr);
      fclose(cPtr);
      remove("data.data");
      rename("clean.data","data.data");
      if(find == 0){printf("There is no user with this id.\n");}
      else{printf("Deleted %d.\n",id);}
  }

int main ()
{

    int i;
    int decition;
    int id;
    int third;
    char third_name[SIZE];
    char third_surname[SIZE];
    int fifth;


    /* Menu and decition part*/
    while(decition != 7){
      printf("\033[32m1-) a new register with Student Name-Surname, Student ID Number and Exam\n2-) search a student by students id number.\n3-) search a student by students name/surname.\n4-)update an existing register.\n5-)delete one or more of the registers.\n6-)print all the registers (id number, name-surname, exam grade) in a neat\n7-)exit the program\n\033[0m" );
      printf("\033[31mSelect your process\n\033[0m");
      scanf("%d",&decition);

      switch (decition) {
        case 1:
            printf("Enter student id:");
            scanf("%d",&ogrenci.id);
            printf("Enter student name:");
            scanf("%9s",ogrenci.name);
            printf("Enter student surname:");
            scanf("%9s",ogrenci.surname);
            printf("Enter student exam:");
            scanf("%d",&ogrenci.exam);
            if(find(ogrenci,ogrenci.id) == 0){add(ogrenci);printf("   >>Student added! \n");}
            else{printf("  >>This id exist if you want to add, first delete id!\n");}
        break;

        case 2:
            printf("Enter student id which you want to search:");
            scanf("%d",&id);
            search_id(ogrenci,id);
        break;

        case 3:
            printf("Select your porgress\n 1-) Seach wih name \n 2-) Search with surname\n");
            scanf("%d",&third);
              if(third == 1){
                  printf("Enter student name:");
                  scanf("%9s",third_name);
                  search_name(ogrenci,third_name);
              }
              else if(third == 2){
                printf("Enter student surname:");
                scanf("%9s",third_surname);
                search_surname(ogrenci,third_surname);
              }
              else{printf("Wrong number. You are redirecting main page!\n");}
        break;

        case 4:
            printf("\n");
            listAll(ogrenci);
            printf("\x1b[34mSelect student id which update you want.\n\033[0m");
            scanf("%d",&id);
            ogrenci.id = id;
            printf("Enter student name:");
            scanf("%9s",ogrenci.name);
            printf("Enter student surname:");
            scanf("%9s",ogrenci.surname);
            printf("Enter student exam:");
            scanf("%d",&ogrenci.exam);
            update(ogrenci,id);

        break;

        case 5:
            printf("\n");
            listAll(ogrenci);
            printf("\x1b[34mHow much user delete you want ?.\n\033[0m");
            scanf("%d",&fifth);
              for(i = 0 ; i < fifth ; i++ ){
                printf("Enter %d id which you want to delete: ", i+1);
                  scanf("%d",&id);
                delete(ogrenci,id);
              }

        break;

        case 6:
        printf("\x1b[34mAll Student List\n\033[0m");
        listAll(ogrenci);
        break;

        case 7:
        printf("You exit successfully.\n");
        break;

        default:
          printf("Wrong chracter plase try again\n");
        break;
      }


}

}
