#include "sams.h"
#include "tools.h"
#include "struct.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"


void sams_menu(void)
{
	pf("***欢迎使用指针学生成绩管理系统***\n");
	pf("1、管理员子系统\n");
	pf("2、教师子系统\n");
	pf("3、学生子系统\n");
	pf("4、退出系统\n");
	pf("-----------------------------\n");
}

// 系统初始化
void sams_init(void)
{
	// 申请堆内存、加载数据
	STU = calloc(MAX_STU,sizeof(Student));
	TEA = calloc(MAX_TEA,sizeof(Teacher));
	ADM = calloc(1,sizeof(Admin));
	pf("系统初始化...\n");

	FILE* afrp = fopen("admin.txt","r");
	int num = 0;
	num = fscanf(afrp,"%s %s %hd",ADM[0].id,ADM[0].passwd,&ADM[0].birth);

	FILE* sfrp = fopen("stu.txt","r");
	for(int i=0; i<100; i++)
	{
		int num = 0;
		num = fscanf(sfrp,"%s %c %s %s %hd %hd %hd %hd %hd %hd",STU[i].name,&STU[i].sex,STU[i].id,STU[i].passwd,&STU[i].chinese,&STU[i].english,&STU[i].math,&STU[i].time,&STU[i].birth,&STU[i].exist);
	}

	FILE* tfrp = fopen("tea.txt","r");
	for(int i=0; i<50; i++)
	{
		int num = 0;
		num = fscanf(tfrp,"%s %c %s %s %hd %hd %hd",TEA[i].name,&TEA[i].sex,TEA[i].id,TEA[i].passwd,&TEA[i].time,&TEA[i].birth,&TEA[i].exist);
	}
}

// 系统开始运行
void sams_start(void)
{
	// 进入系统的业务流程控制
	pf("系统开始运行...\n");
	while(true)
	{
		sams_menu();
		switch(get_cmd('1','4'))
		{
			case '1': admin_start(); break;
			case '2': teacher_start(); break;
			case '3': student_start(); break;
			case '4': return;
		}
	}
}

// 系统结束
void sams_exit(void)
{
	FILE* afwp = fopen("admin.txt","w");	
	int num = 0;
	num = fprintf(afwp,"%s %s %hd",ADM[0].id,ADM[0].passwd,ADM[0].birth);

	FILE* sfwp = fopen("stu.txt","w");
	for(int i=0; i<100; i++)
	{
		int num = 0;
		if(STU[i].sex != 0)
		{
			num = fprintf(sfwp,"%s %c %s %s %hd %hd %hd %hd %hd %hd\n",STU[i].name,STU[i].sex,STU[i].id,STU[i].passwd,STU[i].chinese,STU[i].english,STU[i].math,STU[i].time,STU[i].birth,STU[i].exist);
		}
	}

	FILE* tfwp = fopen("tea.txt","w");
	for(int i=0; i<50; i++)
	{
		int num = 0;
		if(TEA[i].sex != 0)
		{
			num = fprintf(tfwp,"%s %c %s %s %hd %hd %hd\n",TEA[i].name,TEA[i].sex,TEA[i].id,TEA[i].passwd,TEA[i].time,TEA[i].birth,TEA[i].exist);
		}	
	}
	// 释放内存、保存数据
	free(STU);
	free(TEA);
	free(ADM);
	pf("系统退出...\n");
}
