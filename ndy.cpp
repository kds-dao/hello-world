#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct student
{char no[10];
char name[20];
int score;
};

char filename[100]=“studd.txt"; /*设置文件名*/
FILE *fp;
void create(); /*创建函数声明*/
void append();    /*添加函数声明*/
void search();/*查找函数声明*/
void del();      /*删除函数声明*/
void modify();   /*修改函数声明*/
void output(); /*显示函数声明*/

int main(void)
{
    int num;
    while(1)
    {
        printf(" ***学生成绩系统***\n\n");
        printf("   1.创建记录      \n");
        printf("   2.添加记录      \n");
        printf("   3.查找记录      \n");
        printf("   4.修改记录      \n");
        printf("   5.删除记录      \n");
        printf("   6.显示记录      \n");
        printf("   0.退出系统      \n");
        printf("\n 选择序号0-6: "    )；
        scanf("%d",&num);
        if(num>=0&&num<=6)
        {
            switch(num)
            {case 1:create();break;
             case 2:append();break;
             case 3:search();break;
             case 4:modify();break;
             case 5:del();break;
             case 6:output();break;
            case 0:exit(1);
            }
            printf("\n\n操作完毕，请再次选择! \n");
        }
        else
            printf("\n\n选择错误，请再次选择! \n");
    }
    getch();
    return 0;
}

/*创建记录*/

void create()
{
    struct student stu;
    if((fp=fopen(filename,"w"))==NULL)
    {
      printf("Cannot Open File!\n");
      exit(0);
    }
    fprintf(fp,"%-10s%-20s%-50s\n","学号","姓名","成绩");
    printf("\n请输入学号,姓名及成绩(以0结束）\n");
    scanf("%s",stu.no);
    while(strcmp(stu.no,"0"))
    {
        scanf("%s%d",stu.name,&stu.score);
        fprintf(fp,"%-10s%-20s%-50d\n",stu.no,stu.name,stu.score);
        scanf("%s",stu.no)
    }
    fclose(fp);
}

/*添加记录*/

void append()
{
    struct student stu;
    if((fp=fopen(filename,"a"))==NULL)
    {
        printf("\nCannot Open File!");
        exit(0);
    }
    printf("\n请输入要添加的学号,姓名及成绩\n");
    scanf("%s%s%d",stu.no,stu.name,&stu.score);
    fprintf(fp,"%-10s%-20s%-50d\n",stu.no,stu.name,stu.score);
    fclose(fp);
}

/*查找记录*/

void search()
{
    int k=0;
    char nokey[10];
    struct student stu;
    printf("\n请输入学号:");
    scanf("%s",nokey);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("\nCannot Open File!");
        exit(0);
    }
    fseek(fp,1L*sizeof(struct student),0);
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d",stu.no,stu.name,$stu.score);
        if(strcmp(nokey.stu.no)==0)
        {
            printf("\n\n已查找到，该记录为:\n\n");
            printf("%-10s%-20s%-50s","学号","姓名","成绩");
            printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
            k=1;
        }
    }
    if(!k)
        printf("\n文件中无此人记录。");
    fclose(fp);
}

/*修改记录*/

void modify()
{
    int k=0;
    long position;
    char nokey[10];
    struct student stu;
    printf("\n 请输入学号:");
    scanf("%s",nokey);
    if((fp=fopen(filename,"r+"))==NULL)
    {
        printf("\nCannot Open File!");
        exit(0);
    }
    fseek(fp,1L*sizeof(struct student),0);
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d",stu.no,stu.name,&stu.score);
        if(strcmp(nokey,stu.no)==0)
        { position=ftell(fp);
          k=1;
          break;
        }
    }
    if(k)
    {
        printf("\n\n已查找到，该纪录为:\n\n");
        printf("%-10s%-20s%-50s","学号","姓名","成绩");
        printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
        printf("\n请输入新的学号,姓名及成绩:");
        scanf("%s%s%d",stu.no,stu.name,&stu.score);
        fseek(fp,position-1L*sizeof(struct student),SEEK_SET);
        fprintf(fp,"n%-10s%-20s%-50d",stu.no,stu.name,stu.score);
    }
    else
      printf("\n\n文件中无此人的记录。");
    fclose(fp);
}

/*删除记录*/

void del()
{
    int m,k=0;
    long position;
    char nokey[10];
    struct student stu;
    printf("\n请输入学号:");
    scanf("%s",nokey);
    if((fp=fopen(filename,"r+"))=NULL)
    {
        printf("\nCannot Open File");
        exit(0);
    }
    fseek(fp,1L*sizeof(struct student);0);
    while(!feof(fp))
    {
        fscanffp,(fp,"%s%s%d",stu.no,stu.name,&stu.score);
        if(strcmp(nokey,stu.no)==0)
        {
            position=ftell(fp);
            k=1;
            break;
        }
    }
    if(k)
    {
        printf("\n\n已查找到，该纪录为:\n\n");
        printf("%-10s%-20s%-50s","学号","姓名","成绩");
        printf("%-10s%-20s%-50s",stu.no,stu.name,stu.score);
        printf("\n确实要删除记录，请按1;不删除记录，请按0:");
        scanf("%d",&m);
        if(m)
        {
            fseek(fp,position-1L*sizeof(struct student),SEEK_SET);
            fprintf(fp,"%-10s%-20s%-50s",",",",");
        }
    }
    else
      printf("\n\文件中无此人记录。");
    fclose(fp);
}

/*显示记录*/

void output()
{
    struct student stu;
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("\nCannot Openn File!");
        exit(0);
    }
    printf("\n\n文件内容为: \n");
    fseek(fp,1L*sizeof(struct student),0);
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d\n",stu.no,stu.name,&stu.score);
        printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
    }
    fclose(fp);
}
