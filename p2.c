#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  struct node
{
char name[50],file[50][50];
int fileCount, dirCount;
struct node *directory[50];

} *root = NULL;

struct node* createNode(char name[50])
{
struct node *temp = NULL;
temp = (struct node *)malloc( sizeof(struct node) );
strcpy( temp -> name, name );
temp -> fileCount = 0;
temp -> dirCount = 0;
return temp;
}

int InsertDirectory(struct node *start, char dname[50], char pname[50] )
{
int i;
if(strcmp( root -> name, pname ) == 0)
{
root -> directory[root -> dirCount] = createNode(dname);
root -> dirCount++;
printf("%d",root -> dirCount);
return 1;
}

for(i = 0;i < start->dirCount;i++)
{
if( strcmp( start -> directory[i] -> name, pname ) == 0 )
{
start -> directory[i] -> directory[start -> directory[i] -> dirCount] = createNode(dname);
start -> directory[i] -> dirCount++;
return 1;
}
else if( InsertDirectory( start->directory[i], dname, pname ) )
return 1;
}
return 0;
}


int InsertFile(struct node *start, char fname[50], char pname[50] )
{
int i;

if(strcmp( root -> name, pname ) == 0)
{

strcpy( root -> file[root -> fileCount], fname );
root -> fileCount++;
return 1;
}

for(i = 0;i < start->dirCount;i++)
{
if( strcmp( start -> directory[i] -> name, pname ) == 0 )
{
strcpy( start -> directory[i] -> file[start -> directory[i] -> fileCount], fname );
start -> directory [i] -> fileCount++;
return 1;
}
else if(InsertFile( start->directory[i], fname, pname ))
return 1;
}

return 0;
}

int Search(struct node *start, char name[50] )
{
int i, flag;

for(i = 0;i < start->fileCount;i++)
if( strcmp( start -> file[i] , name ) == 0 )
return 2;

for(i = 0;i < start->dirCount;i++)
{
if( strcmp( start -> directory[i] -> name, name ) == 0 )
return 1;
else
if( ( flag = Search(start -> directory[i], name ) ) != 0 )
return flag;
}

return 0;
}


int Delete(struct node *start, char name[50])
{
int i, j, flag;

for(i = 0;i < start -> fileCount;i++)
if( strcmp( start -> file[i] , name ) == 0 )
{

for (j = i; j < start-> fileCount - 1; j++)
strcpy( start -> file[j], start -> file[j+1] );

start->fileCount--;
return 2;
}

for(i = 0;i < start -> dirCount;i++)
{
if( strcmp( start -> directory[i] -> name, name ) == 0 )
{
for (j = i; j < start -> dirCount - 1; j++)
start -> directory[j] = start -> directory[j+1];
start -> dirCount--;
free(start -> directory[j]);
return 1;
}
else
if( ( flag = Delete(start -> directory[i], name ) ) != 0 )
return flag;
}
return 0;
}

void Display(struct node *start, int level)
{
int i;
char space[50] = "";

for(i = 0; i < level * 5; i++)
strcat(space," ");

for (i = 0; i < start -> dirCount; i++)
{
printf("\n %s%s ( Directory ) ", space, start -> directory[i] -> name);
Display(start -> directory[i], level+1);
}

for (i = 0; i < start -> fileCount; i++)
printf("\n %s%s ( File )", space, start->file[i]);
}

  struct dirNode{
char name[50],file[50][50];
int fileCount;
  }dir[10];
  void main(){
          char file[50][50],file1[50],dname[50], fname[50],fdname[50], pname[50];
          int i,j,k,fos,con,op,n,total=0,f,flag,dirCount = 0;

            root = (struct node *)malloc( sizeof(struct node) );
            strcpy( root -> name, "root" );
            root -> fileCount = 0;
            root -> dirCount = 0;

          do{
                  printf("**********FILE ORGANIZATION STRATEGIES*******\n1.Single level Directory\n2.Two Level Directory\n3.Hierarchical\n4.Exit\nEnter option:" );
                  scanf("%d",&fos);

                  switch(fos){
                          case 1:
                                  do{
                                          printf("\n*******MENU*******\n1.Create File\n2.Delete File\n3.search file\n4.Display\nEnter option: ");
                                          scanf("%d",&op);
                                          switch(op){
                                                  case 1:
                                                          printf("\nEnter the number of files to be created:");
                                                          scanf("%d",&n);
                                                          for(i=0;i<n;i++){
                                                                  printf("File %d :",i+1);
                                                                  scanf("%s",file[total + i]);
                                                          }
                                                          total += n;
                                                          break;
                                                  case 2:
                                                          f = 0;
                                                          printf("Enter the file to be deleted :");
                                                          scanf("%s",file1);
                                                          for(i=0;i<total;i++){
                                                                  if(strcmp(file[i],file1)==0){
                                                                          f = 1;
                                                                          for(j=i;j<total;j++){
                                                                                  strcpy(file[j],file[j+1]);
                                                                          }
                                                                  total--;
                                                                  }
                                                          }
                                                          if(f == 0)
                                                                  printf("File not found!\n");
                                                          else
                                                                  printf("file %s is deleted\n",file1);
                                                          break;
                                                  case 3:
                                                          f=0;
                                                          printf("enter the file to be searched :");
                                                          scanf("%s",file1);
                                                          for(i=0;i<total;i++){
                                                                  if(strcmp(file[i],file1)==0){
                                                                          f = 1;
                                                                  }
                                                          }
                                                          if(f == 0)
                                                                  printf("file not found!\n");
                                                          else
                                                                  printf("file %s  found at root/%s \n",file1,file1);
                                                          break;
                                                  case 4:
                                                          printf("Files present in the root directory:\n");
                                                          for(i=0;i<total;i++){
                                                                  printf("%s\n",file[i]);
                                                          }
                                                          break;
                                                  default:printf("\ninvalid option!");
                                          }
                                          printf("continue(1/0)?");
                                          scanf("%d",&con);
                                  }while(con == 1);
                                  break;
                         case 2:
                                  do{
                                          printf("\n*******MENU*******\n1.Create directory\n2.Create File\n3.Search\n4.Delete\n5.Display\nEnter option: ");
                                          scanf("%d",&op);
                                          switch(op){
                                                case 1: printf("\n Enter the directory name : ");
                                                        scanf("%s", dname);
                                                        strcpy( dir[dirCount].name, dname );
                                                        dir[dirCount].fileCount = 0;
                                                        dirCount++;
                                                        printf("\n Directory '%s' has been created ", dname);
                                                        break;

                                                case 2: printf("\n Enter the directory name to insert file : ");
                                                        scanf("%s",dname);
                                                        flag = 0;
                                                        for(i = 0; i < dirCount; i++){
                                                            if( strcmp( dname, dir[i].name ) == 0 ){
                                                                flag = 1;
                                                                printf("\n Enter the file name : ");
                                                                scanf("%s", fname);
                                                                strcpy( dir[i].file[dir[i].fileCount], fname);
                                                                dir[i].fileCount++;
                                                                printf("\n File '%s' has been created ", fname);
                                                            }
                                                        }
                                                        if(!flag)
                                                        printf("\n Directory '%s' Doesn't Exist !!! ", dname);
                                                        break;

                                                case 3: printf("\n Enter the file / directory name to search : ");
                                                        scanf("%s", dname );
                                                        flag = 0;
                                                        for(i = 0; i < dirCount; i++){
                                                            if( strcmp( dname, dir[i].name ) == 0){
                                                                flag = 1;
                                                                printf("\n Directory '%s' found at 'root' directory ", dname);
                                                        }
                                                        for(j = 0; j < dir[i].fileCount; j++)
                                                        {
                                                            if( strcmp( dname, dir[i].file[j] ) == 0)
                                                            {
                                                                flag = 1;
                                                                printf("\n file '%s' found at 'root/%s' directory ", dname, dir[i].name);
                                                            }
                                                        }

                                                        }
                                                        if(!flag)
                                                            printf("\n Directory / File '%s' Doesn't Exist !!! ", dname);

                                                        break;

                                                    case 4: printf("\n Enter file / directory to be deleted : ");
                                                        scanf("%s", dname);
                                                        flag = 0;
                                                        for(i = 0; i < dirCount; i++)
                                                        {
                                                            if( strcmp( dname, dir[i].name ) == 0)
                                                            {
                                                                flag = 1;
                                                                dirCount--;
                                                                for(j = 0; j < dirCount; j++)
                                                                    dir[j] = dir[j+1];
                                                                printf("\n Directory '%s' Has Been Deleted !!! ", dname);
                                                                i--;
                                                                continue;
                                                            }

                                                            for(j = 0; j < dir[i].fileCount;j++)
                                                            {
                                                                if( strcmp( dname, dir[i].file[j] ) == 0)
                                                                {
                                                                    flag = 1;
                                                                    dir[i].fileCount--;
                                                                    for(k = 0; k < dir[i].fileCount; k++)
                                                                        strcpy( dir[i].file[k], dir[i].file[k+1] );

                                                                    printf("\n File '%s' Has Been Deleted !!! ", dir[i].file[j] );
                                                                }
                                                            }
                                                        }
                                                        if(!flag)
                                                            printf("\n Directory / File '%s' Doesn't Exist !!! ", dname);

                                                        break;

                                                    case 5: printf("\n FILE SYSTEM STRUCTURE \n");
                                                        printf("\n --------------------- \n\n");
                                                        for(i = 0; i < dirCount; i++)
                                                        {
                                                            printf("\n %s (dir) ", dir[i].name);
                                                            for(j = 0; j < dir[i].fileCount; j++)
                                                                printf("\n\t %s (file) ",dir[i].file[j] );
                                                        }
                                                        printf("\n");
                                                        break;

                                                  default:printf("\ninvalid option!");
                                          }
                                          printf("continue(1/0)?");
                                          scanf("%d",&con);
                                  }while(con == 1);
                                  break;
                          case 3:
                                  do{
                                          printf("\n*******MENU*******\n1.Create directory\n2.Create File\n3.Search\n4.Delete\n5.Display\nEnter option: ");
                                          scanf("%d",&op);
                                          switch(op){
                                              case 1: printf("\n Enter directory name : ");
                                                        scanf("%s", fdname);
                                                        printf("\n Enter the parent directory : ");
                                                        scanf("%s", pname);
                                                        if( InsertDirectory(root, fdname, pname) )
                                                            printf("\n Directory Successfully Created \n");
                                                        else
                                                            printf("\n Parent Directory Not Found");
                                                        break;

                                            case 2: printf("\n Enter file name : ");
                                                    scanf("%s", fdname);
                                                    printf("\n Enter the parent directory : ");
                                                    scanf("%s", pname);
                                                    if( InsertFile(root, fdname, pname) )
                                                        printf("\n File Successfully Created \n");
                                                    else
                                                        printf("\n Parent Directory Not Found");
                                                    break;

                                            case 3: printf("\n Enter directory / file to search : ");
                                                    scanf("%s", fdname);
                                                    flag = Search(root, fdname);
                                                    if( flag == 1 )
                                                        printf("\n Directory '%s' Exist In The File System ", fdname);
                                                    else if( flag == 2 )
                                                        printf("\n File '%s' Exist In The File System ", fdname);
                                                    else
                                                            printf("\n Directory / File '%s' Doesn't Exist In The File System ", fdname);
                                                    break;

                                            case 4: printf("\n Enter the Directory / File to delete : ");
                                                    scanf("%s", fdname);
                                                    flag = Delete(root, fdname);
                                                    if( flag == 1 )
                                                        printf("\n Directory '%s' Deleted From The File System ", fdname);
                                                    else if( flag == 2 )
                                                        printf("\n File '%s' Deleted From The File System ", fdname);
                                                    else
                                                        printf("\n Directory / File '%s' Doesn't Exist In The File System ", fdname);
                                                    break;

                                            case 5: printf("\n\n FILE SYSTEM STRUCTURE \n\n");
                                                    printf("\n ROOT ");
                                                    Display(root, 1);
                                                    break;

                                            default:printf("\ninvalid option!");
                                          }
                                          printf("continue(1/0)?");
                                          scanf("%d",&con);
                                  }while(con == 1);
                                  break;
                          case 4:exit(0);
                          default:printf("\nInvalid option!!");
                  }
          }while(1);
  }  