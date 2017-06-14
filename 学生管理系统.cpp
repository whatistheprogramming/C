/***************************************************
	文件名称：学生管理系统
	文件描述:对学生信息的管理 ，第一次使用先添加学生 
	编译环境：devc
	最后修改：2017年2月12日
***************************************************/ 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;
struct student{
	char name[20];
	char no[20];//序号 
	double math;
	double english;
	double c;
	double ave;
}stu[1000];
void menu();
void Continue();
void add();
void display();
void modify();
void Delete();
void sort();
void empty();
void search();
void read(int number);
void input(int number);

bool cmp(student a,student b)
{
	return a.ave>b.ave;
}

int main()
{
	system("color 9F");//修改控制台颜色
	menu();
	printf("如果第一次使用，请先选择功能1添加学生\n");
	int n;
	printf("请输入序号：");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 0:exit(0);
			case 1:add();break;
			case 2:display();break;
			case 3:modify();break;
			case 4:Delete();break;
			case 5:sort();break;
			case 6:search();break;
			case 7:empty();break;
			default:
				printf("输入错误，请重新输入！\n");
				system("pause");
				system("cls");
				menu();
				printf("请输入序号：");
				break;
		}
	}
	return 0;
}

void menu()
{
	printf("\t\t\t*******************************************************************\n"); 
	printf("\t\t\t************************学 生 管 理 系 统**************************\n");
	printf("\t\t\t*******************************************************************\n\n"); 
	printf("\t\t\t***************************【0】 退出程序**************************\n");
	printf("\t\t\t***************************【1】 添加学生**************************\n");
	printf("\t\t\t***************************【2】 显示学生**************************\n");
	printf("\t\t\t***************************【3】 修改学生**************************\n");
	printf("\t\t\t***************************【4】 删除学生**************************\n");
	printf("\t\t\t***************************【5】 成绩排序**************************\n");
	printf("\t\t\t***************************【6】 查找学生**************************\n");
	printf("\t\t\t***************************【7】 清空数据**************************\n");
}

void Continue()
{
	system("pause"); 
	system("cls");
	menu();
	printf("请输入序号:"); 
}

void read(int number)//把文件中的学生信息读到数组中 
{
	FILE *fp;
	fp=fopen("d:\\学生信息.txt","r+");
	for(int i=1;i<=number;i++)
	{
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%s",stu[i].no);
		fscanf(fp,"%lf",&stu[i].math);
		fscanf(fp,"%lf",&stu[i].english);
		fscanf(fp,"%lf",&stu[i].c);
	}
	fclose(fp);
} 

void input(int number)//把数组的学生信息清空，重新写入到文件 
{
	FILE *fp;
	fp=fopen("d:\\学生信息.txt","w");
	for(int i=1;i<=number;i++)
	{
		fprintf(fp,"%20s",stu[i].name);
		fprintf(fp,"%20s",stu[i].no);
		fprintf(fp,"%15.0lf",stu[i].math);
		fprintf(fp,"%15.0lf",stu[i].english);
		fprintf(fp,"%15.0lf\n",stu[i].c);
	}
	fclose(fp);
}
void add()//添加学生 
{
	system("cls");
	FILE *fp,*pa;
	int i=0,number,n=1;
	while(n==1)
	{
		printf("请输入学生姓名：\n");
		scanf("%s",stu[i].name);
		printf("请输入学生学号: \n");
		scanf("%s",stu[i].no);
		printf("请输入学生的高数成绩：\n");
		scanf("%lf",&stu[i].math);
		printf("请输入学生的英语成绩：\n");
		scanf("%lf",&stu[i].english);
		printf("请输入学生的C语言成绩：\n");
		scanf("%lf",&stu[i].c);
		
	if((pa=fopen("d:\\人数.txt","r"))==NULL)	//如果人数文件不存在
	{
		pa=fopen("d:\\人数.txt","w");				//创建学生信息文件
		number=0;									//人数置0
	}
	else   //若文件存在                         
	{
		fscanf(pa,"%d",&number);					//则先读出人数
	}
		fclose(pa);
		
		fp=fopen("d:\\学生信息.txt","a+");

		//把添加的学生写入文件 
		fprintf(fp,"%20s",stu[i].name);
		fprintf(fp,"%20s",stu[i].no);
		fprintf(fp,"%15.0lf",stu[i].math);
		fprintf(fp,"%15.0lf",stu[i].english);
		fprintf(fp,"%15.0lf\n",stu[i].c);
		fclose(fp);
	
		i++;
		number++;
		pa=fopen("d:\\人数.txt","w");//打开时把原来的人数清空，重新写入 
		fprintf(pa,"%d",number);
		fclose(pa);
		
		printf("如果要继续输入请按1，结束输入请按0：");
		scanf("%d",&n);
		if(n==0)   //结束输入 
		{
			fclose(fp);
			system("cls"); 
			menu();
			printf("请输入序号：");
		}
	}
}

void display()//显示学生
{
	system("cls");
	char ch;
	FILE *fp;
	if((fp=fopen("d:\\学生信息.txt","r+"))==NULL)
	{
		printf("文件打开错误！无学生信息！\n请先添加学生！\n");
		Continue(); 
		return;
	}
	int number=0;
	printf("学生信息如下：\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s\n","姓名","学号","高数","英语","C语言");
	while((ch=fgetc(fp))!=EOF)
		putchar(ch); 
	fclose(fp);
	fp=fopen("d:\\人数.txt","r");
	fscanf(fp,"%d",&number);
	printf("-----------------------------------------------------------------------------\n");
	printf("学生总数为: %d\n",number);
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
	
} 

void modify()//修改信息 
{
	system("cls");
	FILE *fp;
	int i,number,flag;
	char str[20],name[20],no[20];
	double math,english,c; 
	fp=fopen("d:\\人数.txt","r+");
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number);//从文件读入学生信息
	while(1)
	{
		flag=0;
		printf("请输入要修改的学生姓名或学号（按0结束）:\n");
		scanf("%s",str);
		if(strcmp(str,"0")==0)  break;//按0退出 
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))
		    {
		    	flag=1;
		    	printf("找到以下学生信息：\n");
		    	printf("-----------------------------------------------------------------------------\n");
				printf("%20s%20s%15s%15s%15s\n","姓名","学号","高数成绩","英语成绩","C语言成绩");
				printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c);
				printf("-----------------------------------------------------------------------------\n");
				break;
			}	
		}
		if(!flag)//没有找到要修改学生
			{
				printf("您输入的数据有误！文件中没有此学生的信息！\n");
				printf("-----------------------------------------------------------------------------\n");
				continue;
			} 
		else
		{
			printf("请输入修改后学生的姓名：\n");
			scanf("%s",name);
			printf("请输入修改后学生的序号：\n");
			scanf("%s",no);
			printf("请输入修改后学生的高数成绩：\n");
			scanf("%lf",&math);
			printf("请输入修改后学生的英语成绩：\n");
			scanf("%lf",&english);
			printf("请输入修改后学生的C语言成绩：\n");
			scanf("%lf",&c);
			
			strcpy(stu[i].name,name);
			strcpy(stu[i].no,no);
			stu[i].math=math;
			stu[i].english=english;
			stu[i].c=c;
			
			input(number);
		}	
	}
	if(flag)//修改成功	
	{ 
		printf("-----------------------------------------------------------------------------\n");
		printf("\t学生信息修改成功\n");
	} 
	printf("-----------------------------------------------------------------------------\n");
	Continue();
}  

void Delete()//删除学生
{
	system("cls");
	FILE *fp,*fa;
	int i,n=1,number,flag,del=0;
	char str[20];
	fa=fopen("d:\\人数.txt","r");//读取人数 
	fscanf(fa,"%d",&number);
	fclose(fa);
	
	read(number);
	while(n==1)
	{ 
		flag=-1;
		printf("请输入要删除的学生姓名或学号:\n");
		scanf("%s",str);
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))//如果找到 
			{
				flag=i;break;//找到则退出循环 
			}
			
		}
		if(flag==-1)//没有找到 
		{
			printf("您输入的数据有误！文件中没有此学生的信息！\n");
			printf("-----------------------------------------------------------------------------\n");
			break;
		} 			
		else
		{
			printf("您要删除的学生信息如下：\n");
			printf("%20s%20s%15s%15s%15s\n","姓名","学号","高数成绩","英语成绩","C语言成绩");
			printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[flag].name,stu[flag].no,stu[flag].math,stu[flag].english,stu[flag].c);
			del++;
			for(int j=flag;j<=number;j++)
			{
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j].no,stu[j+1].no);
				stu[i].math=stu[i+1].math;
				stu[i].english=stu[i+1].english;
				stu[i].c=stu[i+1].c;
			} 
			FILE *pb;
			pb=fopen("d:\\人数.txt","r");//先把学生数量写入number 
			fscanf(pb,"%d",&number);
			fclose(pb);
			number-=del;//删除后的学生人数 
			pb=fopen("d:\\人数.txt","w");//再次打开学生数量，原来的数据清空，重新写入 
			fprintf(pb,"%d",number);
			fclose(pb);
			
			input(number);//把修改后的信息重新写入文件 
		}	
		printf("如果要继续删除其他学生信息请按1，否则按0：");
		scanf("%d",&n);
	}
	if(flag!=-1)//如果删除成功	
	{ 
		printf("-----------------------------------------------------------------------------\n");
		printf("\t学生信息删除成功\n");
		printf("-----------------------------------------------------------------------------\n");
	} 
	system("pause"); 
	system("cls");
	menu();
	printf("请输入序号:"); 
} 

void sort()//学生排序 
{
	system("cls");
	FILE *fp;
	int number,i,j,k,t[1000]={0};
	fp=fopen("d:\\人数.txt","r+");
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number); 
	printf("排序前的成绩为：\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s%20s\n","姓名","学号","高数","英语","C语言","平均成绩");
	for(i=1;i<=number;i++)
	{
		t[i]=i;
		stu[i].ave=(stu[i].math+stu[i].english+stu[i].c)/3.0; 
		printf("%20s%20s%15.0lf%15.0lf%15.0lf%20.1lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c,stu[i].ave);
	}
	printf("-----------------------------------------------------------------------------\n");
	
	sort(stu+1,stu+number+1,cmp);//排序 

	printf("排序后的成绩为：\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s%20s\n","姓名","学号","高数","英语","C语言","平均成绩");
	for(i=1;i<=number;i++)
		printf("%20s%20s%15.0lf%15.0lf%15.0lf%20.1lf\n",stu[i].name,stu[i].no,stu[i].math,
											stu[i].english,stu[i].c,stu[i].ave);
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
}

void empty()//清空数据 
{
	char str[100];
	printf("-----------------------------------------------------------------------------\n");
	printf("您将清除所有学生信息！\n确认请输入 y,否则输入其他字符结束本次操作：");
	scanf("%s",str);
	if(strcmp(str,"y")==0)
	{
		FILE *fp;
		if((fp=fopen("d:\\学生信息.txt","w"))==NULL)
			printf("文件打开错误！\n");
		fclose(fp);
		
		if((fp=fopen("d:\\人数.txt","w"))==NULL)
			printf("文件打开错误！\n");
		fclose(fp);
		
		printf("-----------------------------------------------------------------------------\n");
		printf("删除完成！\n");	
	}
	else
	{
		printf("-----------------------------------------------------------------------------\n");
		printf("操作已结束，未进行格式化！\n");
	}
	Continue(); 
	
}

void search()
{
	FILE *fp;
	char str[20];
	int number,i,flag;
	fp=fopen("d:\\人数.txt","r+");//先读出学生人数number 
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number);
	while(1)
	{
		flag=0;
		printf("请输入要查找的学生姓名或学号（按0结束）:\n");
		scanf("%s",str);
		if(strcmp(str,"0")==0)  break;//按0退出 
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))//如果找到 
		    {
		    	flag=1;
		    	printf("找到以下学生信息：\n");
		    	printf("-----------------------------------------------------------------------------\n");
				printf("%20s%20s%15s%15s%15s\n","姓名","学号","高数","英语","C语言");
				printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c);
				printf("-----------------------------------------------------------------------------\n");
			}	
		}
		if(!flag)//没找到
		{	
			printf("未找到学生信息！\n");
			printf("-----------------------------------------------------------------------------\n");
			continue;
		} 
	}
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
}


