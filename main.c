#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
//#include "getch.h"
#include <string.h>
#include <stddef.h>

#define pf printf
#define sf scanf
#define MAX_STU 100
#define MAX_TEA 50

typedef struct Student
{
	char name[20];
	char sex;
	char id[20];
	char passwd[20];
	short chinese;
	short english;
	short math;
	short time;
	short birth;
	short exist;
}Student;

typedef struct Teacher
{
	char name[20];
	char sex;
	char id[20];
	char passwd[20];
	short time;
	short birth;
	short exist;
}Teacher;

typedef struct Admin
{
	char id[20];
	char passwd[20];
	short birth;
}Admin;

// 声明全局变量
Student* STU;
Teacher* TEA;
Admin* ADM;

// 下标
int temp = 0;
int pos = 0;
int i = 0;

// 系统初始化
void sams_init(void);
// 系统开始运行
void sams_start(void);
// 系统结束
void sams_exit(void);

// 管理子系统菜单
void admin_menu(void);
// 管理员添加老师
void admin_add_tea(void);
// 管理员删除老师
void admin_del_tea(void);
// 管理员重置老师
void admin_reset_tea(void);
// 管理员显示在职教师列表
void admin_list_tea(void);
// 管理员显示离职教师列表
void admin_list_ubtea(void);
// 管理员修改密码
void admin_change_pw(void);
// 管理员登录
bool admin_login(void);
// 运行管理员子系统
void admin_start(void);

// 学生子系统菜单
void student_menu(void);
// 学生查询成绩
void student_find_score(void);
// 学生查询成绩
void student_find_score(void);
// 学生修改密码
void student_ch_pw(void);
// 学生查询个人信息
void student_find_info(void);
// 学生登录
int student_login(void);
// 运行学生子系统
void student_start(void);

// 老师子系统菜单
void teacher_menu(void);
// 老师添加学生
void teacher_add_stu(void);
// 老师删除学生
void teacher_del_stu(void);
// 老师查询学生
void teacher_find_stu(void);
// 老师修改学生信息
void teacher_ch_stu_info(void);
// 老师添加学生成绩
void teacher_add_stu_score(void);
// 老师重置学生密码
void teacher_reset_stu_pw(void);
// 老师显示在校学生列表
void teacher_list_stu(void);
// 老师显示退学学生列表
void teacher_list_ubstu(void);
// 老师修改密码
void teacher_ch_pw(void);
// 老师登录
int teacher_login(void);
// 老师登录
int teacher_login(void);
// 运行老师子系统
void teacher_start(void);

// 获取字符串
char* get_str(char* str,size_t len);
// 清理缓冲区
void clear_stdin(void);
// 获取性别
char get_sex(void);
// 获取键盘指令
char get_cmd(char start,char end);
// 获取密码
char* get_pw(char* passwd,bool is_show,size_t size);

// 主函数
int main()
{
	sams_init();
	
	sams_start();

	sams_exit();
}

// 主菜单
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
	for(i=0; i<100; i++)
	{
		int num = 0;
		num = fscanf(sfrp,"%s %c %s %s %hd %hd %hd %hd %hd %hd",STU[i].name,&STU[i].sex,STU[i].id,STU[i].passwd,&STU[i].chinese,&STU[i].english,&STU[i].math,&STU[i].time,&STU[i].birth,&STU[i].exist);
	}

	FILE* tfrp = fopen("tea.txt","r");
	for(i=0; i<50; i++)
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
	for(i=0; i<100; i++)
	{
		int num = 0;
		if(STU[i].sex != 0)
		{
			num = fprintf(sfwp,"%s %c %s %s %hd %hd %hd %hd %hd %hd\n",STU[i].name,STU[i].sex,STU[i].id,STU[i].passwd,STU[i].chinese,STU[i].english,STU[i].math,STU[i].time,STU[i].birth,STU[i].exist);
		}
	}

	FILE* tfwp = fopen("tea.txt","w");
	for(i=0; i<50; i++)
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

// 管理子系统菜单
void admin_menu(void)
{
	pf("\n进入管理子系统...\n");
	pf("1、添加教师\n");
	pf("2、删除教师\n");
	pf("3、重置并解锁教师密码\n");
	pf("4、显示在职教师\n");
	pf("5、显示已离职教师\n");
	pf("6、修改自己密码\n");
	pf("7、返回上一级\n");
	pf("-----------------\n");
}

// 管理员添加老师
void admin_add_tea(void)
{
	pf("添加教师\n");
	char Cteacher_name[20];
	char Cteacher_sex;
	char Cteacher_id[20];
	char Cteacher_pw[20];
	pf("请输入教师姓名：");
	get_str(Cteacher_name,20);
	pf("请输入教师性别：");
	Cteacher_sex = get_sex();
	pf("请输入教师工号：");
	get_str(Cteacher_id,20);
	pf("请输入教师密码：");
	get_str(Cteacher_pw,20);
	int pos = -1; //插入的位置
	pf("id:%s。\n",TEA[0].id);
	for(i=0; i<50; i++)
	{
		if(TEA[i].sex == '\0' && pos == -1)
		{
			pf("pos已定位\n");
			pos = i;
		}
		if(strcmp(TEA[i].id,Cteacher_id)==0)
		{
			pf("工号重复，请重新输入！\n");
			break;
		}
		if(i==49)
		{
			strcpy(TEA[pos].name,Cteacher_name);
			TEA[pos].sex = Cteacher_sex;
			strcpy(TEA[pos].id,Cteacher_id);
			strcpy(TEA[pos].passwd,Cteacher_pw);
			pf("添加成功。\n");
		}
	}
	pf("id:%s。\n",TEA[0].id);
}

// 管理员删除老师
void admin_del_tea(void)
{
	pf("删除教师\n");
	pf("请输入教师工号:");
	char Cteacher_id[20]={};	
	get_str(Cteacher_id,20);
	for(i=0; i<50; i++)
	{
		if(strcmp(Cteacher_id,TEA[i].id)==0)
		{
			TEA[i].exist = 1;
			pf("删除成功！\n");			
			break;
		}
		if(i==49)
		{
			pf("无此工号！\n");
		}
	}
	
}

// 管理员重置老师
void admin_reset_tea(void)
{
	pf("重置密码\n");
	pf("请输入教师工号：");
	char Cteacher_id[20]={};
	get_str(Cteacher_id,20);
	char Cteacher_pw[20] = "123";
	for(i=0; i<50; i++)
	{
		if(strcmp(TEA[i].id,Cteacher_id)==0)
		{
			TEA[i].time = 0;
			TEA[i].birth = 0;
			TEA[i].exist = 0;
			strcpy(TEA[i].passwd,Cteacher_pw); 
			pf("重置成功！\n");
			break;
		}
		if(i==49)
		{
			pf("无此工号.\n");	
		}	
	}

}

// 管理员显示在职教师列表
void admin_list_tea(void)
{
	pf("显示在职教师");
	for(i=0; i<50; i++)
	{
		if(TEA[i].sex != '\0')
		{
			if(TEA[i].exist != 1)
			{
				pf("\n姓名:%s 性别：%c 工号：%s",TEA[i].name,TEA[i].sex,TEA[i].id);
			}
		}
		else
		{
			break;
		}
	}
}

// 管理员显示离职教师列表
void admin_list_ubtea(void)
{
	pf("显示离职教师");
	for(i=0; i<50; i++)
	{
		if(TEA[i].sex != '\0')
		{
			if(TEA[i].exist == 1)
			{
				pf("\n姓名:%s 性别：%c 工号：%s",TEA[i].name,TEA[i].sex,TEA[i].id);
			}
		}
		else
		{
			break;
		}
	}
}

//char admin_pw[20]="123";
//strcpy(admin_pw,admin_passwd);

// 管理员修改密码
void admin_change_pw(void)
{
	char old_pw[20]={};
	char new_pw[20]={};
	char new_two_pw[20]={};
	pf("请输入原密码：");
	get_pw(old_pw,true,20);
	printf("\n");
	pf("请输入新密码：");
	get_pw(new_pw,true,20);
	printf("\n");
	pf("请再次输入新密码：");
	get_pw(new_two_pw,true,20);
	printf("\n");
	if(strcmp(old_pw,ADM[0].passwd)==0)
	{
		if(strcmp(new_pw,new_two_pw)==0)
		{
			pf("修改密码成功\n");
			if(ADM[0].birth==0)
			{
				ADM[0].birth = 1;
			}
			strcpy(ADM[0].passwd,new_pw);
		}
		else
		{
			pf("两次密码不一致\n");
		}
	}
	else
	{
		pf("原密码错误。\n");
	}
}

// 管理员登录
bool admin_login(void)
{
	//char admin_id[20] = "admin";
	char Cadmin_id[20]={};
	char Cadmin_pw[20]={};
	pf("请输入用户名:");
	get_str(Cadmin_id,20);
	if(Cadmin_id[0]=='\0')
	{
		pf("用户名不能为空！\n");
		return false;
	}
	//pf("*%s*\n",Cadmin_id);
	pf("请输入密码:");
	get_pw(Cadmin_pw,true,20);
	//printf("\n*%s*",Cadmin_pw);
	printf("\n");
	if(strcmp(Cadmin_id,ADM[0].id)==0 && strcmp(Cadmin_pw,ADM[0].passwd)==0)
	{
		//printf("正确\n");
		return true;
	}
	else
	{
		return false;
	}
}

// 运行管理员子系统
void admin_start(void)
{
	if(!admin_login())
	{
		pf("登录失败!\n");
		return;
	}
	while(true)
	{
		if(ADM[0].birth==0)
		{
			admin_change_pw();
		}
		else
		{
			admin_menu();
			switch(get_cmd('1','7'))
			{
				case '1': admin_add_tea(); break;
				case '2': admin_del_tea(); break;
				case '3': admin_reset_tea(); break;
				case '4': admin_list_tea(); break;
				case '5': admin_list_ubtea(); break;
				case '6': admin_change_pw(); break;
				case '7': return;
			}
		}
	}
}


// 学生子系统菜单
void student_menu(void)
{
	pf("进入学生子系统...\n");
	pf("1、查询成绩\n");
	pf("2、修改密码\n");
	pf("3、查看个人信息\n");
	pf("4、返回上一级\n");
	pf("---------------\n");
}

// 学生查询成绩
void student_find_score(void)
{
	pf("成绩查询\n");
	pf("语文：%hd ,英语: %hd ,数学: %hd\n",STU[temp].chinese,STU[temp].english,STU[temp].math);
}

// 学生修改密码
void student_ch_pw(void)
{
	char old_stu_pw[20]={};
	char new_stu_pw[20]={};
	char new_stu_two_pw[20]={};
	pf("请输入原密码：");
	get_pw(old_stu_pw,true,20);
	printf("\n");
	pf("请输入新密码：");
	get_pw(new_stu_pw,true,20);
	printf("\n");
	pf("请再次输入新密码：");
	get_pw(new_stu_two_pw,true,20);
	printf("\n");
	if(strcmp(old_stu_pw,STU[temp].passwd)==0)
	{
		if(strcmp(new_stu_pw,new_stu_two_pw)==0)
		{
			pf("修改密码成功\n");
			if(STU[temp].birth==0)
			{
				STU[temp].birth = 1;
			}
			strcpy(STU[temp].passwd,new_stu_pw);
		}
		else
		{
			pf("两次密码不一致\n");
		}
	}
	else
	{
		pf("原密码错误。\n");
	}
}

// 学生查询个人信息
void student_find_info(void)
{
	pf("个人信息\n");
	pf("姓名：%s ,性别：%c ,学号: %s\n",STU[temp].name,STU[temp].sex,STU[temp].id);
}

// 学生登录
int student_login(void)
{
	char Cstudent_id[20]={};
	char Cstudent_pw[20]={};
	pf("请输入用户名:");
	get_str(Cstudent_id,20);
	if(Cstudent_id[0]=='\0')
	{
		pf("用户名不能为空！\n");
		return -1;
	}
	//pf("*%s*\n",Cstudent_id);
	pf("请输入密码:");
	get_pw(Cstudent_pw,true,20);
	//printf("\n*%s*",Cstudent_passwd);
	printf("\n");
	for(i=0; i<100; i++)
	{
		if(strcmp(Cstudent_id,STU[i].id)==0)
		{
			if(STU[i].time==3)
			{
				pf("此学号已被锁定，请找教师解锁。\n");
				return -1;
			}
			if(STU[i].exist==1)
			{
				pf("此学生已退学。\n");
				return -1;
			}
			if(strcmp(Cstudent_pw,STU[i].passwd)==0)
			{
				return i;
			}
			else
			{	
				STU[i].time++;
				pf("密码错误.\n");
				return -1;
			}
		}
	}
	pf("不存在此学生。\n");
	return -1;
}

// 运行学生子系统
void student_start(void)
{
	temp = student_login();
	if(temp==-1)
	{
		pf("登录失败!\n");
		return;
	}
	while(true)
	{
		if(STU[temp].birth==0)
		{
			student_ch_pw();
		}
		else
		{
			student_menu();
			switch(get_cmd('1','4'))
			{
				case '1': student_find_score(); break;
				case '2': student_ch_pw(); break;
				case '3': student_find_info(); break;		
				case '4': return;
			}		
		}	
	}
}


// 老师子系统菜单
void teacher_menu(void)
{
	pf("\n进入教师子系统...\n");
	pf("1、添加学生\n");
	pf("2、删除学生\n");
	pf("3、查找学生\n");
	pf("4、修改学生信息\n");
	pf("5、录入学生成绩\n");
	pf("6、重置学生密码\n");
	pf("7、显示所有在校学生信息\n");
	pf("8、显示所有退学学生信息\n");
	pf("9、修改自己密码\n");
	pf("0、返回上一级\n");
	pf("-----------------\n");
}

// 老师添加学生
void teacher_add_stu(void)
{
	pf("添加学生\n");
	char Cstudent_name[20];
	char Cstudent_sex;
	char Cstudent_id[20];
	char Cstudent_pw[20];
	pf("请输入学生姓名：");
	get_str(Cstudent_name,20);
	pf("请输入学生性别：");
	Cstudent_sex = get_sex();
	pf("请输入学生工号：");
	get_str(Cstudent_id,20);
	pf("请输入学生密码：");
	get_str(Cstudent_pw,20);
	int pos = -1; //插入的位置
	pf("id:%s。\n",STU[0].id);
	for(i=0; i<100; i++)
	{
		if(STU[i].sex == '\0' && pos == -1)
		{
			pf("pos已定位\n");
			pos = i;
		}
		if(strcmp(STU[i].id,Cstudent_id)==1)
		{
			pf("学号重复，请重新输入！\n");
			break;
		}
		if(i==99)
		{
			strcpy(STU[pos].name,Cstudent_name);
			STU[pos].sex = Cstudent_sex;
			strcpy(STU[pos].id,Cstudent_id);
			strcpy(STU[pos].passwd,Cstudent_pw);
			pf("添加成功。\n");
		}
	}
	pf("id:%s。\n",STU[0].id);
}

// 老师删除学生
void teacher_del_stu(void)
{
	pf("删除学生\n");
	pf("请输入学生学号:");
	char Cstudent_id[20]={};	
	get_str(Cstudent_id,20);
	for(i=0; i<100; i++)
	{
		if(strcmp(Cstudent_id,STU[i].id)==0)
		{
			STU[i].exist = 1;
			pf("删除成功！\n");			
			break;
		}
		if(i==99)
		{
			pf("无此学号！\n");
		}
	}
	
}

// 老师查询学生
void teacher_find_stu(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(i=0; i<100; i++)
	{
		if(strcmp(Cstudent_id,STU[i].id)==0)
		{
			pf("姓名：%s 性别：%c 学号：%s\n",STU[i].name,STU[i].sex,STU[i].id);
			break;
		}
		else if(i==99)
		{
			pf("无此学号。\n");
		}
	}
}

// 老师修改学生信息
void teacher_ch_stu_info(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(i=0; i<100; i++)
	{
		if(strcmp(Cstudent_id,STU[i].id)==0)
		{
			char ch_name[20];
			char ch_sex;
			char ch_id[20];
			pf("原信息：姓名：%s 性别：%c 学号：%s\n",STU[i].name,STU[i].sex,STU[i].id);
			pf("请输入新姓名：");
			get_str(ch_name,20);
			pf("请输入新性别：");
			if(sf("%c",&ch_sex)==1)
			{
				getchar();
			}
			pf("请输入新学号：");
			get_str(ch_id,20);
			
			strcpy(STU[i].name,ch_name);
			STU[i].sex = ch_sex;
			strcpy(STU[i].id,ch_id);

			pf("信息修改成功。\n");
			break;
		}
		else if(i==99)
		{
			pf("无此学号。\n");
		}
	}
}

// 老师添加学生成绩
void teacher_add_stu_score(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(i=0; i<100; i++)
	{
		if(strcmp(Cstudent_id,STU[i].id)==0)
		{
			short chinese = 0;
			short english = 0;
			short math = 0;
			pf("原信息：语文：%hd 英语：%hd 数学：%hd\n",STU[i].chinese,STU[i].english,STU[i].math);
			pf("请输入新语文成绩：");
			if(sf("%hd",&chinese)==1)
			{
				getchar();
			}
			pf("请输入新英语成绩：");
			if(sf("%hd",&english)==1)
			{
				getchar();
			}
			pf("请输入新数学成绩：");
			if(sf("%hd",&math)==1)
			{
				getchar();
			}
			
			STU[i].chinese = chinese;
			STU[i].english = english;
			STU[i].math = math;

			pf("信息修改成功。\n");
			break;
		}
		else if(i==99)
		{
			pf("无此学号。\n");
		}
	}
}

// 老师重置学生密码
void teacher_reset_stu_pw(void)
{
	pf("重置密码\n");
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	char Cstudent_pw[20] = "123";
	for(i=0; i<100; i++)
	{
		if(strcmp(STU[i].id,Cstudent_id)==0)
		{
			STU[i].time = 0;
			STU[i].birth = 0;
			STU[i].exist = 0;
			strcpy(STU[i].passwd,Cstudent_pw); 
			pf("重置成功！\n");
			break;
		}
		if(i==99)
		{
			pf("无此学号.\n");	
		}	
	}
}

// 老师显示在校学生列表
void teacher_list_stu(void)
{
	pf("显示在校学生");
	for(i=0; i<100; i++)
	{
		if(STU[i].sex != '\0')
		{
			if(STU[i].exist != 1)
			{
				pf("\n姓名:%s 性别：%c 学号：%s",STU[i].name,STU[i].sex,STU[i].id);
			}
		}
		else
		{
			break;
		}
	}
}

// 老师显示退学学生列表
void teacher_list_ubstu(void)
{
	pf("显示退学学生");
	for(i=0; i<100; i++)
	{
		if(STU[i].sex != '\0')
		{
			if(STU[i].exist == 1)
			{
				pf("\n姓名:%s 性别：%c 工号：%s",STU[i].name,STU[i].sex,STU[i].id);
			}
		}
		else
		{
			break;
		}
	}
}

// 老师修改密码
void teacher_ch_pw(void)
{
	char old_pw[20]={};
	char new_pw[20]={};
	char new_two_pw[20]={};
	pf("请输入原密码：");
	get_pw(old_pw,true,20);
	printf("\n");
	pf("请输入新密码：");
	get_pw(new_pw,true,20);
	printf("\n");
	pf("请再次输入新密码：");
	get_pw(new_two_pw,true,20);
	printf("\n");
	if(strcmp(old_pw,TEA[pos].passwd)==0)
	{
		if(strcmp(new_pw,new_two_pw)==0)
		{
			pf("修改密码成功\n");
			if(TEA[pos].birth==0)
			{
				TEA[pos].birth = 1;
			}
			strcpy(TEA[pos].passwd,new_pw);
		}
		else
		{
			pf("两次密码不一致\n");
		}
	}
	else
	{
		pf("原密码错误。\n");
	}
}

// 老师登录
int teacher_login(void)
{
	char Cteacher_id[20]={};
	char Cteacher_pw[20]={};
	pf("请输入用户名:");
	get_str(Cteacher_id,20);
	if(Cteacher_id[0]=='\0')
	{
		pf("用户名不能为空！\n");
		return -1;
	}
	//pf("*%s*\n",Cteacher_id);
	pf("请输入密码:");
	get_pw(Cteacher_pw,true,20);
	//printf("\n*%s*",Cadmin_passwd);
	printf("\n");
	for(i=0; i<50; i++)
	{
		if(strcmp(Cteacher_id,TEA[i].id)==0)
		{
			if(TEA[i].time==3)
			{
				pf("此工号已被锁定，请找管理员解锁。\n");
				return -1;
			}
			if(TEA[i].exist==1)
			{
				pf("此教师已离职。\n");
				return -1;
			}
			if(strcmp(Cteacher_pw,TEA[i].passwd)==0)
			{
				return i;
			}
			else
			{	
				TEA[i].time++;
				pf("密码错误.\n");
				return -1;
			}
		}
	}
	pf("不存在此教师。\n");
	return -1;
}

// 运行老师子系统
void teacher_start(void)
{
	pos = teacher_login();
	if(pos==-1)
	{
		pf("登录失败!\n");
		return;
	}
	while(true)
	{
		if(TEA[pos].birth==0)
		{
			teacher_ch_pw();
			
		}
		else
		{
			teacher_menu();
			switch(get_cmd('0','9'))
			{
				case '1': teacher_add_stu(); break;
				case '2': teacher_del_stu(); break;
				case '3': teacher_find_stu(); break;
				case '4': teacher_ch_stu_info(); break;
				case '5': teacher_add_stu_score(); break;
				case '6': teacher_reset_stu_pw(); break;
				case '7': teacher_list_stu(); break;
				case '8': teacher_list_ubstu(); break;
				case '9': teacher_ch_pw(); break;		
				case '0': return;
			}		
		}
	}
}

/** tools **/
// 清理输入缓冲区
void clear_stdin(void)
{
	//stdin->_IO_read_ptr = stdin->_IO_read_end;//清理输入缓冲区
}

// 获取字符串
char* get_str(char* str,size_t len)
{
	if(NULL == str)
	{
		puts("empty ptr！");
		return NULL;
	}

	char *in=fgets(str,len,stdin);

	size_t cnt = strlen(str);
	if('\n' == str[cnt-1])
	{
		str[cnt-1] = '\0';
	}
	else
	{
		scanf("%*[^\n]");
		scanf("%*c");
	}
	
	clear_stdin();

	return str;
}

// 获取性别
char get_sex(void)
{
	printf("（m男，w女）：");
	while(true)
	{
		char sex = getch();
		if('w' == sex || 'm' == sex)
		{
			printf("%s\n",'w'==sex?"女":"男");
			return sex;
		}
	}
}

// 获取键盘指令
char get_cmd(char start,char end)
{
	clear_stdin();

	printf("请输入指令:");
	while(true)
	{
		char val = getch();
		if(val >= start && val <= end)
		{
			printf("%c\n",val);
			return val;
		}
	}
}

// 获取密码
char* get_pw(char* passwd,bool is_show,size_t size)
{
	if(NULL == passwd) return NULL;

	int count = 0;
	do{
		char val = getch();
		if(8 == val)
		{
			if(count > 0)
			{
				if(is_show)printf("\b \b");
				count--;
			}
			continue;
		}
		else if(13 == val)
		{
			break;
		}
		passwd[count++] = val;
		if(is_show) printf("*");
	}while(count < size -1);

	passwd[count] = '\0';
	return passwd;
}
