#include "teacher.h"
#include "tools.h"
#include "struct.h"

Teacher* TEA;

int pos = 0;

static void teacher_menu(void)
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
	for(int i=0; i<100; i++)
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
void teacher_del_stu(void)
{
	pf("删除学生\n");
	pf("请输入学生学号:");
	char Cstudent_id[20]={};	
	get_str(Cstudent_id,20);
	for(int i=0; i<100; i++)
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

void teacher_find_stu(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(int i=0; i<100; i++)
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

void teacher_ch_stu_info(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(int i=0; i<100; i++)
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
void teacher_add_stu_score(void)
{
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	for(int i=0; i<100; i++)
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
void teacher_reset_stu_pw(void)
{
	pf("重置密码\n");
	pf("请输入学生学号：");
	char Cstudent_id[20]={};
	get_str(Cstudent_id,20);
	char Cstudent_pw[20] = "123";
	for(int i=0; i<100; i++)
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
void teacher_list_stu(void)
{
	pf("显示在校学生");
	for(int i=0; i<100; i++)
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
void teacher_list_ubstu(void)
{
	pf("显示退学学生");
	for(int i=0; i<100; i++)
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
	for(int i=0; i<50; i++)
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

