//#include<window.h>
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Node {
	int id;//学号 
	char name[50];//姓名 
	char sex[10];//性别 
	int ch, ma, en;//语数英成绩 
	int sum;//总分 

	struct Node* next;//指针域 

}node;

typedef struct Nodd {
	char name[50];//课程名字
	char teacher[50];//课程老师
	char lo[50];//上课地点
	char time[10];//上课时间

	struct Nodd* next;
	// 0 代表当前时段没有课
}nodd;

struct Nodf {
	int id;//学号
	char name[50];//姓名
	char sex[10];//性别
	Nodd* p[10];//指针数组，指向所选的课
   // struct Nodf *next;
}student[150], nodf;

int cnt = 0;//


/*
char lesson[5][4][50] = {
"高等数学 1"  "线性代数 2"  "军事理论 3"  "思想政治 4"
"体育 5"  "c语言 6"  "大学物理 7"  "概率论 8"
"物联网 9"  "历史 10"  "电影鉴赏 11"  "国学文化12"
"离散数学 13"  "群论 14"  "单片机 15"   "微机原理 16"
"大学语文 17"  "大学生物 18"  "大学英语 19"  "大学化学 20"
"走进科学 21"  "探索发现 22"  "环球记录 23"  "综艺文化 24"
}*/


void delay(int k) {
	for (int i = 0; i < k; i++)
		for (int j = 0; j < i; j++);
}

node List_score;//成绩链表 

nodd List_lesson;//课程链表

//nodf List_class;//选课链表

void STU();
void TEACHER();
void ADMINER();

void welcome()//总菜单 
{
	system("cls");
	printf("*****************************\n");
	printf("---------------------------------------教务管理系统-------------------------------------------------------\n");
	printf("----------------------------------made by FHR (SDU)----------------------------------------------------\n");
	printf("**                    **\n");
	printf("**   进入学生端 ----1 **\n");
	printf("**   进入教师端 ----2 **\n");
	printf("**   进入管理端 ----3 **\n");
	printf("**  退出管理系统 ---4 **\n");
	printf("**                      **\n");
	printf("**  请输入对应的功能键（数字） **\n");
}
void welcome_teacher()//教师端菜单 
{
	system("cls");
	printf("*****************************\n");
	printf("**   教务管理系统(教师端)    **\n");
	printf("**                      **\n");
	printf("**   增加学生信息 ----1 **\n");
	printf("**   查询学生信息 ----2 **\n");
	printf("**   输出学生信息 ----3 **\n");
	printf("**   返回上一级   ----4 **\n");
	printf("**                      **\n");
	printf("**  请输入对应的功能键（数字） **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}

void welcome_stu()//学生端菜单 
{
	system("cls");
	printf("*****************************\n");
	printf("**   教务管理系统（学生端）    **\n");
	printf("**                    **\n");
	printf("**   查询学生成绩 ----1 **\n");
	printf("**   选择课程     ----2 **\n");
	printf("**   退选课程     ----3 **\n");
	printf("**   生成个人课表 ----4 **\n");
	printf("**   退出学生端管理系统 --- 5**\n");
	printf("**                      **\n");
	printf("** 	请输入对应的功能键（数字） **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}
void welcome_adminer()//管理员端菜单
{
	system("cls");
	printf("*****************************\n");
	printf("**   教务管理系统(管理员端)    **\n");
	printf("**                      **\n");
	printf("**   删除学生信息 ----1 **\n");
	printf("**   修改学生信息 ----2 **\n");
	printf("**   打印总课表   ----3 **\n");
	printf("**   增加课程信息 ----4 **\n");
	printf("**   删除课程信息 ----5 **\n");
	printf("**   修改课程信息 ----6 **\n");
	printf("**   退出管理员端管理系统 --- 7**\n");
	printf("**                      **\n");
	printf("** 	请输入对应的功能键（数字） **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}


int readfile_score(node* L) {
	FILE* fpr = fopen("stuinfo.txt", "r");

	node now;
	node* s;
	node* t = L;//尾指针 

	if (fpr == NULL) return 0;
	else {
		while (fscanf(fpr, "%d %s %s %d %d %d %d", &now.id, &now.name, &now.sex, &now.ch, &now.ma, &now.en, &now.sum) != EOF)
		{
			s = (node*)malloc(sizeof(node));  //s 指向新开辟的空间
			//printf("%d %s %s %d %d %d %d\n",now.id,now.name,now.sex,now.ch,now.ma,now.en,now.sum);
			*s = now;

			t->next = s;
			t = s;
			t->next = NULL;

		}

	}
	return 1;
}

int savefile_score(node* L)//保存文件 成功返回1 不成功返回0 
{
	FILE* fpw = fopen("stuinfo.txt", "w");
	if (fpw == NULL) return 0;

	node* p = L->next;

	while (p != NULL) {
		fprintf(fpw, "%d %s %s %d %d %d %d\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		p = p->next;
	}
	return 1;
}


int readfile_lesson(nodd* L) {
	FILE* fpr = fopen("lessoninfo.txt", "r");

	nodd now;
	nodd* s;
	nodd* t = L;//尾指针 

	if (fpr == NULL) return 0;
	else {
		while (fscanf(fpr, "%s %s %s %s", &now.name, &now.teacher, &now.lo, &now.time) != EOF)
		{
			s = (nodd*)malloc(sizeof(nodd));  //s 指向新开辟的空间
			//printf("%d %s %s %d %d %d %d\n",now.id,now.name,now.sex,now.ch,now.ma,now.en,now.sum);
			*s = now;

			t->next = s;
			t = s;
			t->next = NULL;

		}

	}
	return 1;
}

int savefile_lesson(nodd* L)//保存文件 成功返回1 不成功返回0 
{
	FILE* fpw = fopen("lessoninfo.txt", "w");
	if (fpw == NULL) return 0;

	nodd* p = L->next;

	while (p != NULL) {
		fprintf(fpw, "%s %s %s %s \n", p->name, p->teacher, p->lo, p->time);
		p = p->next;
	}
	return 1;
}

/*
int savefile_class(nodf *L){
	FILE *fpw = fopen("classinfo.txt","w");
	if(fpw == NULL) return 0;

	nodf *p = L->next;
	while(p != NULL){
		fprintf(fpw,"%d %s %s ",p->id,p->name,p->sex);
		//int cnt = 0;
		for(int i = 0 ; i <= 9 ; i++){
			if(p->p[i] == NULL)
			continue;
		fprintf(fpw,"%s %s %s %s",*(p->p[i]).name,*(p.p[i]).teacher,*(p.p[i]).lo,*(p.p[i]).time);
		}
		printf("\n");
		p = p->next;
	}
	return 1;
}

int readfile_class(nodf *L){
	FILE *fpr = fopen("classinfo.txt","r");

	nodf now;
	nodf *s;
	nodf *t = L;//尾指针

	if(fpr == NULL) return 0;
	else {
		while(fscanf(fpr,"%d %s %s ",&now.id,&now.name,&now.sex)!= EOF)
		{
			//printf("%d %s %s %d %d %d %d\n",now.id,now.name,now.sex,now.ch,now.ma,now.en,now.sum);
				for(int i = 0 ; i <= 9 ; i++){
			if(now.p[i] == NULL)
			continue;
		 fscanf(fpw,"%s %s %s %s",*(now->p[i]).name,*(p->p[i]).teacher,*(p->p[i]).lo,*(p->p[i]).time);
		}

			 *s = now;
			t->next = s;
			t = s;
			t->next = NULL;

		}

	}
	return 1;
}
*/ //失败的链表选课系统
void insertstu(node* L, node e)//功能 建链表 
{
	node* h = L;
	node* s = (node*)malloc(sizeof(node));
	*s = e;

	s->next = h->next;
	h->next = s;

	savefile_score(L);
}

void insertlesson(nodd* L, nodd e)//功能 建链表 
{
	nodd* h = L;
	nodd* s = (nodd*)malloc(sizeof(nodd));
	*s = e;

	s->next = h->next;
	h->next = s;

	savefile_lesson(L);
}

node* searchstuid(int id, node* L)//按学号查找某人，返回的是指向某人的指针 
{
	node* p = L;

	while (p != NULL) {
		if (p->id == id)
			return p;
		p = p->next;
	}
	return NULL; //没有这个人，返回空指针 
}
/*
node * search_classid(int id , nodf *L)//按学号查找某人，返回的是指向某人的指针
{
	nodf *p = L;

	while(p != NULL){
		if(p->id == id)
		return p;
		p = p->next;
	}
	return NULL; //没有这个人，返回空指针
}
*/ //失败的链表选课系统
nodd* searchlesson(char a[], nodd* L)//按学号查找某人，返回的是指向某人的指针 
{
	nodd* p = L;

	while (p != NULL) {
		if (!strcmp(p->name, a))
			return p;
		p = p->next;
	}
	return NULL; //没有这个人，返回空指针 
}

node* searchstuid_last(int id, node* L)//按学号查找某人，返回的是指向某人的上一个人的指针 ，为删除操作做准备
{
	node* p = L;

	while (p->next != NULL) {
		if (p->next->id == id)
			return p;
		p = p->next;
	}
	return NULL;
}

nodd* searchlesson_last(char a[], nodd* L)//按名字查找某课，返回的是指向某人的上一个课的指针，为删除操作做准备 
{
	nodd* p = L;

	while (p->next != NULL) {
		if (!strcmp(p->next->name, a))
			return p;
		p = p->next;
	}
	return NULL;
}

int max(int a, int b) { if (a > b) return a; else return b; }

int min(int a, int b) { if (a < b) return a; else return b; }

int findstumax(node* L, int mod)//查找成绩最高分 语文 0 数学 1 英语 2 总分 3
{
	node* p = L->next;

	if (p != NULL) {
		int maxa[4] = { -1,-1,-1,-1 };
		while (p != NULL) {
			maxa[0] = max(p->ch, maxa[0]);
			maxa[1] = max(p->ma, maxa[1]);
			maxa[2] = max(p->en, maxa[2]);
			maxa[3] = max(p->sum, maxa[3]);

			p = p->next;
		}
		return maxa[mod];
	}
	return 1;
}

int findstumin(node* L, int mod)//查找成绩最低分 语文 0 数学 1 英语 2 总分 3
{
	node* p = L->next;

	if (p != NULL) {
		int mina[4] = { 0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f };
		while (p != NULL) {
			mina[0] = min(p->ch, mina[0]);
			mina[1] = min(p->ma, mina[1]);
			mina[2] = min(p->en, mina[2]);
			mina[3] = min(p->sum, mina[3]);

			p = p->next;
		}
		return mina[mod];
	}
	return 1;
}

bool cmp(node a, node b, int mod) //比较函数 默认从高到低 语文 0  数学 1  英语 2  总分  3 
{
	switch (mod) {
	case 0:
		return a.ch > b.ch;
	case 1:
		return a.ma > b.ma;
	case 2:
		return a.en > b.en;
	case 3:
		return a.sum > b.sum;
	default:
		printf("输入有误，请重新输入！\n");
		break;
	}
	return 0;
}

void stusort(node* L, int mod) {

	for (node* p = L->next; p != NULL; p = p->next) {

		for (node* q = p; q != NULL; q = q->next) {
			if (!cmp(*p, *q, mod)) //交换 数据和指针 
			{
				node t = *p;
				*p = *q;
				*q = t;

				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
}
void addstu()//添加信息 
{
	system("cls");
	printf("请输入新增学生相关信息\n");
	node now;
	printf("学号:"); scanf("%d", &now.id);
	node* now1 = searchstuid_last(now.id, &List_score); 
	if (now1 != NULL)
	{
		printf("您输入的学号已被登记！ 请重新输入或进入管理端修改学生信息！\n");
		delay(5000);
		return;
	}

	printf("姓名:"); scanf("%s", now.name);
	printf("性别:"); scanf("%s", now.sex);
	printf("语文成绩:"); scanf("%d", &now.ch);
	printf("数学成绩:"); scanf("%d", &now.ma);
	printf("英语成绩:"); scanf("%d", &now.en);    now.sum = now.ch + now.en + now.ma;

	insertstu(&List_score, now);
}

void addlesson()//添加信息 
{
	system("cls");
	printf("请输入新增课程相关信息 （同名课程请在后用123加以表示，否则会覆盖已有信息!)\n");
	nodd now;
	printf("课程名字:"); scanf("%s", now.name);
	printf("任课老师:"); scanf("%s", now.teacher);
	printf("上课地点:"); scanf("%s", now.lo);
	printf("上课时间:"); scanf("%s", now.time);


	insertlesson(&List_lesson, now);
}


void delestu()//删除学生信息
{
	system("cls");
	int id, choice;
	while (1) {
		printf("请输入要删除信息的学生的学号：");
		scanf("%d", &id);
		node* kkk = searchstuid(id, &List_score);
		if (kkk == NULL) {
			printf("查无此人！\n");
			return;
		}
		node* now = searchstuid_last(id, &List_score);//返回的是这一个人的上一个人的指针 
		node* p = now->next;
		
		printf("----------------------------------------------------------------------\n");
		printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		printf("----------------------------------------------------------------------\n");


		node* now1 = now->next;
		now->next = now1->next;
		now1->next = NULL;
		free(now1);

		savefile_score(&List_score);
		printf("是否继续删除信息？ （yes -- 1  no -- 0） ：");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}
}

void deletlesson()//删除课程信息
{
	system("cls");
	int id, choice;
	char a[50];
	while (1) {
		printf("请输入要删除信息的课程的名字：");
		scanf("%s", a);
		nodd* kkk =  searchlesson(a, &List_lesson);
		if (kkk == NULL) {
			printf("查无此课！\n");
			return;
		}
		nodd* now = searchlesson_last(a, &List_lesson);//返回的是这一个ke的上一个ke的指针 
		nodd* p = now->next;
		
		printf("|课程名字\t|任课教师\t|上课地点\t|上课时间\t\n");
		printf("%s\t|%s\t\t|%s\t|%s\t|\n", p->name, p->teacher, p->lo, p->time);
		printf("----------------------------------------------------------------------\n");
		

		nodd* now1 = now->next;
		now->next = now1->next;
		now1->next = NULL;
		free(now1);

		savefile_lesson(&List_lesson); //保存删除后结果
		printf("是否继续删除信息？ （yes -- 1  no -- 0） ：");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}
}

void fixstu(node* L) {
	system("cls");
	int id, choice;
	while (1) {
		printf("请输入要修改学生的学号：");
		scanf("%d", &id);
		node* now = searchstuid(id, L);
		if (now == NULL) {
			printf("查无此人！\n");
			return;
		}

		node* p = now;
		printf("----------------------------------------------------------------------\n");
		printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		printf("----------------------------------------------------------------------\n");


		printf("修改姓名--------1\n");
		printf("修改性别--------2\n");
		printf("修改语文成绩----3\n");
		printf("修改数学成绩----4\n");
		printf("修改英语成绩----5\n");
		printf("请选择要修改的信息：");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			printf("输入要修改后的信息：");
			scanf("%s", now->name);
			break;
		case 2:
			printf("输入要修改后的信息：");
			scanf("%s", now->sex);
			break;
		case 3:
			printf("输入要修改后的信息：");
			scanf("%d", &now->ch);
			break;
		case 4:
			printf("输入要修改后的信息：");
			scanf("%d", &now->ma);
			break;
		case 5:
			printf("输入要修改后的信息：");
			scanf("%d", &now->en);
			break;
		default : 
			printf("输入有误，请重新输入！\n");
			break;
		}
		now->sum = now->ch + now->en + now->ma;
		printf("是否继续修改信息？ （yes -- 1  no -- 0） ：");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}

	savefile_score(L);
}

void fixlesson(nodd* L) {
	system("cls");
	int id, choice;
	char a[50];
	while (1) {
		printf("请输入要修改课程的名字：");
		scanf("%s", a);
		nodd* now = searchlesson(a, L);
		if (now == NULL) {
			printf("查无此课！\n");
			return ;
		}

		nodd* p = now;

		printf("|课程名字\t|任课教师\t|上课地点\t|上课时间\t\n");
		printf("%s\t|%s\t\t|%s\t|%s\t|\n", p->name, p->teacher, p->lo, p->time);
		printf("----------------------------------------------------------------------\n");


		printf("修改课程名字--------1\n");
		printf("修改任课教师--------2\n");
		printf("修改上课地点--------3\n");
		printf("修改上课时间--------4\n");
		printf("请选择要修改的信息：");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			printf("输入要修改后的信息：");
			scanf("%s", now->name);
			break;
		case 2:
			printf("输入要修改后的信息：");
			scanf("%s", now->teacher);
			break;
		case 3:
			printf("输入要修改后的信息：");
			scanf("%d", &now->lo);
			break;
		case 4:
			printf("输入要修改后的信息：");
			scanf("%d", &now->time);
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		printf("是否继续修改信息？ （yes -- 1  no -- 0） ：");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}

	savefile_lesson(L);//保存修改后的信息 
}

void searchstu(node* L) {
	system("cls");

	int id;
	node* now;

	printf("现在仅支持按学号查询，请输入要查询的学号：");
	scanf("%d", &id);
	now = searchstuid(id, L);

	if (now == NULL)
		printf("查无此人！\n");
	else {
		printf("----------------------------------------------------------------------\n");
		printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
		node* p = now;
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		printf("----------------------------------------------------------------------\n");
	}
}
/*
void search_class(nodf *L,int id){
	system("cls");

	int id;
	nodf *now;

	//printf("现在仅支持按学号查询，请输入要查询的学号：");
	//scanf("%d",&id);
	now =  searchclassid(id,L);

	if(now == NULL)
	   printf("您还没有选课！\n");
	else {
		printf("----------------------------------------------------------------------\n");
		printf("|学号\t|姓名\t|性别\t|\n");
		nodf *p = now;
		printf("%d|%s\t|%s\t|\n",p->id,p->name,p->sex);
		printf("----------------------------------------------------------------------\n");
		printf("您目前的选课情况为： \n");
		for(int i = 0 ; i <= 9 ; i++){
			if(p->p[i] != NULL)
		printf("%s\t%s\t%s\t%s\t\n",*(p->p[i]).name,*(p->p[i]).teacher,*(p->p[i]).lo,*(p->p[i]).time);
		 }
	}
}*/ //失败的链表选课系统

void printstu(node* L) {
	system("cls");
	node* p = L->next;
	printf("----------------------------------------------------------------------\n");
	printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
	if (p != NULL) {
		while (p != NULL) {
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			printf("----------------------------------------------------------------------\n");
			p = p->next;
		}
	}
	printf("***** 下方是成绩最高分 ******\n");
	printf("语文成绩最高分 ： %d\n", findstumax(&List_score, 0));
	printf("数学成绩最高分 ： %d\n", findstumax(&List_score, 1));
	printf("英语成绩最高分 ： %d\n", findstumax(&List_score, 2));
	printf("总分成绩最高分 ： %d\n", findstumax(&List_score, 3));
	printf("------------------------------------\n");
	printf("***** 下方是成绩最低分 ******\n");
	printf("语文成绩最低分 ： %d\n", findstumin(&List_score, 0));
	printf("数学成绩最低分 ： %d\n", findstumin(&List_score, 1));
	printf("英语成绩最低分 ： %d\n", findstumin(&List_score, 2));
	printf("总分成绩最低分 ： %d\n", findstumin(&List_score, 3));

	printf("可对学生成绩排序(默认从高到低)，语文请按0，数学请按1，英语请按2，总分请按3, 退出请按4\n");
	int c = 0;
	scanf("%d", &c);
	switch (c) {
	case 0:
		stusort(&List_score, c);
		printstu(&List_score);
		break;
	case 1:
		stusort(&List_score, c);
		printstu(&List_score);
		break;
	case 2:
		stusort(&List_score, c);
		printstu(&List_score);
		break;
	case 3:
		stusort(&List_score, c);
		printstu(&List_score);
		break;
	case 4:
		break;
	default:
		printf("输入有误，请重新输入！\n");
		break;
	}
}

void end() {
	printf("** 感谢您的使用，期待下次再见！ **");
	exit(0);
}

void printlesson(nodd* L) {
	system("cls");
	nodd* p = L->next;
	printf("----------------------------------------------------------------------\n");
	printf("|课程名字\t|任课教师\t|上课地点\t|上课时间\t\n");
	if (p != NULL) {
		while (p != NULL) {
			printf("%s\t|%s\t\t|%s\t|%s\t|\n", p->name, p->teacher, p->lo, p->time);
			printf("----------------------------------------------------------------------\n");
			p = p->next;
		}
	}
}

int searchclass(int idd) {
	for (int i = 0; i < 150; i++)
		if (student[i].id == idd)
			return i;
	return -1;
}

void printclass(int idd) {
	system("cls");
	int k = searchclass(idd);
	printf("|学号\t|姓名\t|性别\t|\n");
	printf("%d|%s\t|%s\t|\n", student[k].id, student[k].name, student[k].sex);
	printf("----------------------------------------------------------------------\n");
	//p = p->next; 

	printf("----------------------------------------------------------------------\n");
	printf("|课程名字\t|任课教师\t|上课地点\t|上课时间\t\n");

	for (int i = 0; i <= 9; i++)
		if (student[k].p[i] != NULL) {
			nodd* p1 = student[k].p[i];
			printf("%s\t|%s\t\t|%s\t|%s\t|\n", p1->name, p1->teacher, p1->lo, p1->time);
			printf("----------------------------------------------------------------------\n");

		}
}

nodd* check(int id, nodd* L) {
	for (int i = 0; i <= 9; i++) {
		nodd* now = student[id].p[i];
		if (now == NULL)
			continue;
		if (strcmp(now->name, L->name) == 0 || strcmp(now->time, L->time) == 0)
			return now;
	}
	return NULL;
}

int check_left(int id) //查找最多可选多少门课
{
	int cnt = 0;
	for (int i = 0; i <= 9; i++) {
		nodd* now = student[id].p[i];
		if (now == NULL) //还没有选课
			cnt++;
	}

	return cnt;
}


void class_choice(nodd* L)//选课函数
{
	system("cls");


	int ccnt = 0;//所选课的个数


	printf("**             欢迎来到选课界面!            **\n");
	printf("**        请注意！ 每人最多可选10门课！             **\n");
	int c;
	printf("请输入您的学号：");
	scanf("%d", &c);

	int stu_number = searchclass(c);

	int limit = check_left(stu_number);//选课上限

	if (stu_number == -1)//没有选课
	{
		printf("您还没有选课\n");
		printf("请输入您的姓名：");
		scanf("%s", student[cnt].name);
		printf("请输入您的性别：");
		scanf("%s", student[cnt].sex);
		student[cnt].id = c;
		stu_number = cnt;
		limit = 10;
		cnt++;
	}
	else
		printclass(c);

	while (1) {

		printlesson(&List_lesson);
		printf("\n");
		printf("----------------------开始选课-----------------\n");

		char a[50];
		printf("请输入所选课的名字：");
		scanf("%s", a);
		nodd* now = searchlesson(a, L);//now 为所选课的地址;
		if (now == NULL)
		{
			printf("------------------查无此课！ 请重新选择！-----------------\n");
			delay(100000);//延迟函数
			continue;
		}
		nodd* now1 = check(stu_number, now);//查找是否与已选的课冲突
		if (now1 == NULL) //此课未被选择，且与其他课无冲突
		{
			printf("------------------选课成功！-----------------\n");
			student[stu_number].p[ccnt] = now;//课已被选
			ccnt++;
			if (ccnt == limit)
			{
				printf("选课已达上限！ 无法选课！ \n");
				break;
			} //达到选课上限

		}
		else {
			printf("------------------选课失败！-----------------\n");
			printf("此课已被选 或 此课与 %s 有冲突！", now1->name);
		}

		//查询是否被选择，或者有冲突

		printf("是否继续选课？ yes 1  no 0 :");
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
	}
}

void class_delet(nodd* L) {
	system("cls");
	int c;
	printf("请输入您的学号：");
	scanf("%d", &c);

	int stu_number = searchclass(c);//输出学生的结构体编号，判断是否有课可以退

	if (stu_number == -1) {
		printf("您还没有选课，无法退课！\n");
		return;
	}

	int limit = 10 - check_left(stu_number);//退课上限

	while (1) {
		printf("您目前的课表为：\n");
		printclass(c);
		char a[50];
		printf("请输入要退课的名字：");
		scanf("%s", a);

		int i;
		for (i = 0; i <= 9; i++) {
			nodd* now = student[stu_number].p[i];
			if (now != NULL) {
				if (!strcmp(now->name, a)) {
					student[stu_number].p[i] = NULL;
					printf("------------------退课成功！-----------------\n");
					limit--;
					if (limit == 0)//无课可退
					{
						printf("您没有课可以退了！\n");
						return;
					}
					break;
				}
				else {
					if (i == 9) //没有找到要退的课
						printf("退课失败！ 请检查你输入的课程名字！ \n");
				}

			}
		}

        printf("是否继续退课？ yes 1  no 0 : ");
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
	}

}

void class_print()//打印课表
{
	system("cls");
	int c;
	printf("请输入您的学号：");
	scanf("%d", &c);
	if (int stu_number = searchclass(c) == -1)
		printf("您输入的学号有误，请重新输入！\n");
	else
	printclass(c);

}


int main() {
	int choice = 0;
	readfile_score(&List_score);
	readfile_lesson(&List_lesson);
	//scanf("%d",&choice);
	while (1) {
		welcome();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			STU();
			break;
		case 2:
			TEACHER();
			break;
		case 3:
			ADMINER();
			break;
		case 4:
			end();
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	}
	return 0;
}



void STU() {
	while (1) {
		welcome_stu();
		int c = 0;
		scanf("%d", &c);
		switch (c) {
		case 1://查询成绩 
			searchstu(&List_score);
			break;
		case 2://选课 
			class_choice(&List_lesson);
			break;
		case 3://退课 
			class_delet(&List_lesson);
			break;
		case 4://生成课表 
			class_print();
			break;
		case 5://返回上一级菜单 
			return;
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		printf("是否需要继续操作? (yes : 1   no : 0 ) : ");
		scanf("%d", &c);
		if (c == 0)
			break;
	}
	return;
}

void ADMINER() {
	while (1) {
		welcome_adminer();
		int c = 0;
		scanf("%d", &c);
		switch (c) {
		case 1://删除学生信息
			delestu();
			break;
		case 2://修改学生信息
			fixstu(&List_score);
			break;
		case 3://打印总课表
			printlesson(&List_lesson);
			break;
		case 4://增加课程
			addlesson();
			break;
		case 5://删除课程
			deletlesson();
			break;
		case 6://修改课程
			fixlesson(&List_lesson);
			break;
		case 7://返回上一级菜单 
			return;
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		printf("是否需要继续操作? (yes : 1   no : 0 ) : ");
		scanf("%d", &c);
		if (c == 0)
			break;
	}

	return;
}
void TEACHER() {
	while (1) {
		welcome_teacher();
		int c = 0;
		scanf("%d", &c);
		switch (c) {
		case 1://增加学生信息
			addstu();
			break;
		case 2://查询学生信息 
			searchstu(&List_score);
			break;
		case 3://输出学生信息 
			printstu(&List_score);
			break;
		case 0://退出程序 
			end();
			break;
		case 4://返回上一级菜单 
			return;
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		printf("是否需要继续操作? (yes : 1   no : 0 ) : ");
		scanf("%d", &c);
		if (c == 0)
			break;
	}
	return;
}

