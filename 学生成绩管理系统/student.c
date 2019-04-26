#include "student.h"
#include "tools.h"
#include "struct.h"

Student* STU;

int temp = 0;

static void student_menu(void)
{
	pf("进入学生子系统...\n");
	pf("1、查询成绩\n");
	pf("2、修改密码\n");
	pf("3、查看个人信息\n");
	pf("4、返回上一级\n");
	pf("---------------\n");
}

void student_find_score(void)
{
	pf("成绩查询\n");
	pf("语文：%hd ,英语: %hd ,数学: %hd\n",STU[temp].chinese,STU[temp].english,STU[temp].math);
}
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
void student_find_info(void)
{
	pf("个人信息\n");
	pf("姓名：%s ,性别：%c ,学号: %s\n",STU[temp].name,STU[temp].sex,STU[temp].id);
}

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
	for(int i=0; i<100; i++)
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
