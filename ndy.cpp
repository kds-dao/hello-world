#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct student
{char no[10];
char name[20];
int score;
};

char filename[100]=��studd.txt"; /*�����ļ���*/
FILE *fp;
void create(); /*������������*/
void append();    /*��Ӻ�������*/
void search();/*���Һ�������*/
void del();      /*ɾ����������*/
void modify();   /*�޸ĺ�������*/
void output(); /*��ʾ��������*/

int main(void)
{
    int num;
    while(1)
    {
        printf(" ***ѧ���ɼ�ϵͳ***\n\n");
        printf("   1.������¼      \n");
        printf("   2.��Ӽ�¼      \n");
        printf("   3.���Ҽ�¼      \n");
        printf("   4.�޸ļ�¼      \n");
        printf("   5.ɾ����¼      \n");
        printf("   6.��ʾ��¼      \n");
        printf("   0.�˳�ϵͳ      \n");
        printf("\n ѡ�����0-6: "    )��
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
            printf("\n\n������ϣ����ٴ�ѡ��! \n");
        }
        else
            printf("\n\nѡ��������ٴ�ѡ��! \n");
    }
    getch();
    return 0;
}

/*������¼*/

void create()
{
    struct student stu;
    if((fp=fopen(filename,"w"))==NULL)
    {
      printf("Cannot Open File!\n");
      exit(0);
    }
    fprintf(fp,"%-10s%-20s%-50s\n","ѧ��","����","�ɼ�");
    printf("\n������ѧ��,�������ɼ�(��0������\n");
    scanf("%s",stu.no);
    while(strcmp(stu.no,"0"))
    {
        scanf("%s%d",stu.name,&stu.score);
        fprintf(fp,"%-10s%-20s%-50d\n",stu.no,stu.name,stu.score);
        scanf("%s",stu.no)
    }
    fclose(fp);
}

/*��Ӽ�¼*/

void append()
{
    struct student stu;
    if((fp=fopen(filename,"a"))==NULL)
    {
        printf("\nCannot Open File!");
        exit(0);
    }
    printf("\n������Ҫ��ӵ�ѧ��,�������ɼ�\n");
    scanf("%s%s%d",stu.no,stu.name,&stu.score);
    fprintf(fp,"%-10s%-20s%-50d\n",stu.no,stu.name,stu.score);
    fclose(fp);
}

/*���Ҽ�¼*/

void search()
{
    int k=0;
    char nokey[10];
    struct student stu;
    printf("\n������ѧ��:");
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
            printf("\n\n�Ѳ��ҵ����ü�¼Ϊ:\n\n");
            printf("%-10s%-20s%-50s","ѧ��","����","�ɼ�");
            printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
            k=1;
        }
    }
    if(!k)
        printf("\n�ļ����޴��˼�¼��");
    fclose(fp);
}

/*�޸ļ�¼*/

void modify()
{
    int k=0;
    long position;
    char nokey[10];
    struct student stu;
    printf("\n ������ѧ��:");
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
        printf("\n\n�Ѳ��ҵ����ü�¼Ϊ:\n\n");
        printf("%-10s%-20s%-50s","ѧ��","����","�ɼ�");
        printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
        printf("\n�������µ�ѧ��,�������ɼ�:");
        scanf("%s%s%d",stu.no,stu.name,&stu.score);
        fseek(fp,position-1L*sizeof(struct student),SEEK_SET);
        fprintf(fp,"n%-10s%-20s%-50d",stu.no,stu.name,stu.score);
    }
    else
      printf("\n\n�ļ����޴��˵ļ�¼��");
    fclose(fp);
}

/*ɾ����¼*/

void del()
{
    int m,k=0;
    long position;
    char nokey[10];
    struct student stu;
    printf("\n������ѧ��:");
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
        printf("\n\n�Ѳ��ҵ����ü�¼Ϊ:\n\n");
        printf("%-10s%-20s%-50s","ѧ��","����","�ɼ�");
        printf("%-10s%-20s%-50s",stu.no,stu.name,stu.score);
        printf("\nȷʵҪɾ����¼���밴1;��ɾ����¼���밴0:");
        scanf("%d",&m);
        if(m)
        {
            fseek(fp,position-1L*sizeof(struct student),SEEK_SET);
            fprintf(fp,"%-10s%-20s%-50s",",",",");
        }
    }
    else
      printf("\n\�ļ����޴��˼�¼��");
    fclose(fp);
}

/*��ʾ��¼*/

void output()
{
    struct student stu;
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("\nCannot Openn File!");
        exit(0);
    }
    printf("\n\n�ļ�����Ϊ: \n");
    fseek(fp,1L*sizeof(struct student),0);
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d\n",stu.no,stu.name,&stu.score);
        printf("%-10s%-20s%-50d",stu.no,stu.name,stu.score);
    }
    fclose(fp);
}
