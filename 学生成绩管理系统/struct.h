#ifndef STRUCT_H
#define STRUCT_H

//char admin_pw[20];

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

extern Student* STU;
extern Teacher* TEA;
extern Admin* ADM;

#endif//STRUCT_H
