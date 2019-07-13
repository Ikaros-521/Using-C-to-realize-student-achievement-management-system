#include "admin.h"
#include "tools.h"
#include "struct.h"

Admin* ADM;

static void admin_menu(void)
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

static void admin_add_tea(void)
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
	for(int i=0; i<50; i++)
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

static void admin_del_tea(void)
{
	pf("删除教师\n");
	pf("请输入教师工号:");
	char Cteacher_id[20]={};	
	get_str(Cteacher_id,20);
	for(int i=0; i<50; i++)
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

static void admin_reset_tea(void)
{
	pf("重置密码\n");
	pf("请输入教师工号：");
	char Cteacher_id[20]={};
	get_str(Cteacher_id,20);
	char Cteacher_pw[20] = "123";
	for(int i=0; i<50; i++)
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

static void admin_list_tea(void)
{
	pf("显示在职教师");
	for(int i=0; i<50; i++)
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

static void admin_list_ubtea(void)
{
	pf("显示离职教师");
	for(int i=0; i<50; i++)
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

