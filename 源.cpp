//#include<window.h>
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Node {
	int id;//ѧ�� 
	char name[50];//���� 
	char sex[10];//�Ա� 
	int ch, ma, en;//����Ӣ�ɼ� 
	int sum;//�ܷ� 

	struct Node* next;//ָ���� 

}node;

typedef struct Nodd {
	char name[50];//�γ�����
	char teacher[50];//�γ���ʦ
	char lo[50];//�Ͽεص�
	char time[10];//�Ͽ�ʱ��

	struct Nodd* next;
	// 0 ����ǰʱ��û�п�
}nodd;

struct Nodf {
	int id;//ѧ��
	char name[50];//����
	char sex[10];//�Ա�
	Nodd* p[10];//ָ�����飬ָ����ѡ�Ŀ�
   // struct Nodf *next;
}student[150], nodf;

int cnt = 0;//


/*
char lesson[5][4][50] = {
"�ߵ���ѧ 1"  "���Դ��� 2"  "�������� 3"  "˼������ 4"
"���� 5"  "c���� 6"  "��ѧ���� 7"  "������ 8"
"������ 9"  "��ʷ 10"  "��Ӱ���� 11"  "��ѧ�Ļ�12"
"��ɢ��ѧ 13"  "Ⱥ�� 14"  "��Ƭ�� 15"   "΢��ԭ�� 16"
"��ѧ���� 17"  "��ѧ���� 18"  "��ѧӢ�� 19"  "��ѧ��ѧ 20"
"�߽���ѧ 21"  "̽������ 22"  "�����¼ 23"  "�����Ļ� 24"
}*/


void delay(int k) {
	for (int i = 0; i < k; i++)
		for (int j = 0; j < i; j++);
}

node List_score;//�ɼ����� 

nodd List_lesson;//�γ�����

//nodf List_class;//ѡ������

void STU();
void TEACHER();
void ADMINER();

void welcome()//�ܲ˵� 
{
	system("cls");
	printf("*****************************\n");
	printf("---------------------------------------�������ϵͳ-------------------------------------------------------\n");
	printf("----------------------------------made by FHR (SDU)----------------------------------------------------\n");
	printf("**                    **\n");
	printf("**   ����ѧ���� ----1 **\n");
	printf("**   �����ʦ�� ----2 **\n");
	printf("**   �������� ----3 **\n");
	printf("**  �˳�����ϵͳ ---4 **\n");
	printf("**                      **\n");
	printf("**  �������Ӧ�Ĺ��ܼ������֣� **\n");
}
void welcome_teacher()//��ʦ�˲˵� 
{
	system("cls");
	printf("*****************************\n");
	printf("**   �������ϵͳ(��ʦ��)    **\n");
	printf("**                      **\n");
	printf("**   ����ѧ����Ϣ ----1 **\n");
	printf("**   ��ѯѧ����Ϣ ----2 **\n");
	printf("**   ���ѧ����Ϣ ----3 **\n");
	printf("**   ������һ��   ----4 **\n");
	printf("**                      **\n");
	printf("**  �������Ӧ�Ĺ��ܼ������֣� **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}

void welcome_stu()//ѧ���˲˵� 
{
	system("cls");
	printf("*****************************\n");
	printf("**   �������ϵͳ��ѧ���ˣ�    **\n");
	printf("**                    **\n");
	printf("**   ��ѯѧ���ɼ� ----1 **\n");
	printf("**   ѡ��γ�     ----2 **\n");
	printf("**   ��ѡ�γ�     ----3 **\n");
	printf("**   ���ɸ��˿α� ----4 **\n");
	printf("**   �˳�ѧ���˹���ϵͳ --- 5**\n");
	printf("**                      **\n");
	printf("** 	�������Ӧ�Ĺ��ܼ������֣� **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}
void welcome_adminer()//����Ա�˲˵�
{
	system("cls");
	printf("*****************************\n");
	printf("**   �������ϵͳ(����Ա��)    **\n");
	printf("**                      **\n");
	printf("**   ɾ��ѧ����Ϣ ----1 **\n");
	printf("**   �޸�ѧ����Ϣ ----2 **\n");
	printf("**   ��ӡ�ܿα�   ----3 **\n");
	printf("**   ���ӿγ���Ϣ ----4 **\n");
	printf("**   ɾ���γ���Ϣ ----5 **\n");
	printf("**   �޸Ŀγ���Ϣ ----6 **\n");
	printf("**   �˳�����Ա�˹���ϵͳ --- 7**\n");
	printf("**                      **\n");
	printf("** 	�������Ӧ�Ĺ��ܼ������֣� **\n");
	//printf("**   **\n");
   // printf("**   **\n");
}


int readfile_score(node* L) {
	FILE* fpr = fopen("stuinfo.txt", "r");

	node now;
	node* s;
	node* t = L;//βָ�� 

	if (fpr == NULL) return 0;
	else {
		while (fscanf(fpr, "%d %s %s %d %d %d %d", &now.id, &now.name, &now.sex, &now.ch, &now.ma, &now.en, &now.sum) != EOF)
		{
			s = (node*)malloc(sizeof(node));  //s ָ���¿��ٵĿռ�
			//printf("%d %s %s %d %d %d %d\n",now.id,now.name,now.sex,now.ch,now.ma,now.en,now.sum);
			*s = now;

			t->next = s;
			t = s;
			t->next = NULL;

		}

	}
	return 1;
}

int savefile_score(node* L)//�����ļ� �ɹ�����1 ���ɹ�����0 
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
	nodd* t = L;//βָ�� 

	if (fpr == NULL) return 0;
	else {
		while (fscanf(fpr, "%s %s %s %s", &now.name, &now.teacher, &now.lo, &now.time) != EOF)
		{
			s = (nodd*)malloc(sizeof(nodd));  //s ָ���¿��ٵĿռ�
			//printf("%d %s %s %d %d %d %d\n",now.id,now.name,now.sex,now.ch,now.ma,now.en,now.sum);
			*s = now;

			t->next = s;
			t = s;
			t->next = NULL;

		}

	}
	return 1;
}

int savefile_lesson(nodd* L)//�����ļ� �ɹ�����1 ���ɹ�����0 
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
	nodf *t = L;//βָ��

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
*/ //ʧ�ܵ�����ѡ��ϵͳ
void insertstu(node* L, node e)//���� ������ 
{
	node* h = L;
	node* s = (node*)malloc(sizeof(node));
	*s = e;

	s->next = h->next;
	h->next = s;

	savefile_score(L);
}

void insertlesson(nodd* L, nodd e)//���� ������ 
{
	nodd* h = L;
	nodd* s = (nodd*)malloc(sizeof(nodd));
	*s = e;

	s->next = h->next;
	h->next = s;

	savefile_lesson(L);
}

node* searchstuid(int id, node* L)//��ѧ�Ų���ĳ�ˣ����ص���ָ��ĳ�˵�ָ�� 
{
	node* p = L;

	while (p != NULL) {
		if (p->id == id)
			return p;
		p = p->next;
	}
	return NULL; //û������ˣ����ؿ�ָ�� 
}
/*
node * search_classid(int id , nodf *L)//��ѧ�Ų���ĳ�ˣ����ص���ָ��ĳ�˵�ָ��
{
	nodf *p = L;

	while(p != NULL){
		if(p->id == id)
		return p;
		p = p->next;
	}
	return NULL; //û������ˣ����ؿ�ָ��
}
*/ //ʧ�ܵ�����ѡ��ϵͳ
nodd* searchlesson(char a[], nodd* L)//��ѧ�Ų���ĳ�ˣ����ص���ָ��ĳ�˵�ָ�� 
{
	nodd* p = L;

	while (p != NULL) {
		if (!strcmp(p->name, a))
			return p;
		p = p->next;
	}
	return NULL; //û������ˣ����ؿ�ָ�� 
}

node* searchstuid_last(int id, node* L)//��ѧ�Ų���ĳ�ˣ����ص���ָ��ĳ�˵���һ���˵�ָ�� ��Ϊɾ��������׼��
{
	node* p = L;

	while (p->next != NULL) {
		if (p->next->id == id)
			return p;
		p = p->next;
	}
	return NULL;
}

nodd* searchlesson_last(char a[], nodd* L)//�����ֲ���ĳ�Σ����ص���ָ��ĳ�˵���һ���ε�ָ�룬Ϊɾ��������׼�� 
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

int findstumax(node* L, int mod)//���ҳɼ���߷� ���� 0 ��ѧ 1 Ӣ�� 2 �ܷ� 3
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

int findstumin(node* L, int mod)//���ҳɼ���ͷ� ���� 0 ��ѧ 1 Ӣ�� 2 �ܷ� 3
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

bool cmp(node a, node b, int mod) //�ȽϺ��� Ĭ�ϴӸߵ��� ���� 0  ��ѧ 1  Ӣ�� 2  �ܷ�  3 
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
		printf("�����������������룡\n");
		break;
	}
	return 0;
}

void stusort(node* L, int mod) {

	for (node* p = L->next; p != NULL; p = p->next) {

		for (node* q = p; q != NULL; q = q->next) {
			if (!cmp(*p, *q, mod)) //���� ���ݺ�ָ�� 
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
void addstu()//�����Ϣ 
{
	system("cls");
	printf("����������ѧ�������Ϣ\n");
	node now;
	printf("ѧ��:"); scanf("%d", &now.id);
	node* now1 = searchstuid_last(now.id, &List_score); 
	if (now1 != NULL)
	{
		printf("�������ѧ���ѱ��Ǽǣ� �������������������޸�ѧ����Ϣ��\n");
		delay(5000);
		return;
	}

	printf("����:"); scanf("%s", now.name);
	printf("�Ա�:"); scanf("%s", now.sex);
	printf("���ĳɼ�:"); scanf("%d", &now.ch);
	printf("��ѧ�ɼ�:"); scanf("%d", &now.ma);
	printf("Ӣ��ɼ�:"); scanf("%d", &now.en);    now.sum = now.ch + now.en + now.ma;

	insertstu(&List_score, now);
}

void addlesson()//�����Ϣ 
{
	system("cls");
	printf("�����������γ������Ϣ ��ͬ���γ����ں���123���Ա�ʾ������Ḳ��������Ϣ!)\n");
	nodd now;
	printf("�γ�����:"); scanf("%s", now.name);
	printf("�ο���ʦ:"); scanf("%s", now.teacher);
	printf("�Ͽεص�:"); scanf("%s", now.lo);
	printf("�Ͽ�ʱ��:"); scanf("%s", now.time);


	insertlesson(&List_lesson, now);
}


void delestu()//ɾ��ѧ����Ϣ
{
	system("cls");
	int id, choice;
	while (1) {
		printf("������Ҫɾ����Ϣ��ѧ����ѧ�ţ�");
		scanf("%d", &id);
		node* kkk = searchstuid(id, &List_score);
		if (kkk == NULL) {
			printf("���޴��ˣ�\n");
			return;
		}
		node* now = searchstuid_last(id, &List_score);//���ص�����һ���˵���һ���˵�ָ�� 
		node* p = now->next;
		
		printf("----------------------------------------------------------------------\n");
		printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		printf("----------------------------------------------------------------------\n");


		node* now1 = now->next;
		now->next = now1->next;
		now1->next = NULL;
		free(now1);

		savefile_score(&List_score);
		printf("�Ƿ����ɾ����Ϣ�� ��yes -- 1  no -- 0�� ��");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}
}

void deletlesson()//ɾ���γ���Ϣ
{
	system("cls");
	int id, choice;
	char a[50];
	while (1) {
		printf("������Ҫɾ����Ϣ�Ŀγ̵����֣�");
		scanf("%s", a);
		nodd* kkk =  searchlesson(a, &List_lesson);
		if (kkk == NULL) {
			printf("���޴˿Σ�\n");
			return;
		}
		nodd* now = searchlesson_last(a, &List_lesson);//���ص�����һ��ke����һ��ke��ָ�� 
		nodd* p = now->next;
		
		printf("|�γ�����\t|�ον�ʦ\t|�Ͽεص�\t|�Ͽ�ʱ��\t\n");
		printf("%s\t|%s\t\t|%s\t|%s\t|\n", p->name, p->teacher, p->lo, p->time);
		printf("----------------------------------------------------------------------\n");
		

		nodd* now1 = now->next;
		now->next = now1->next;
		now1->next = NULL;
		free(now1);

		savefile_lesson(&List_lesson); //����ɾ������
		printf("�Ƿ����ɾ����Ϣ�� ��yes -- 1  no -- 0�� ��");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}
}

void fixstu(node* L) {
	system("cls");
	int id, choice;
	while (1) {
		printf("������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%d", &id);
		node* now = searchstuid(id, L);
		if (now == NULL) {
			printf("���޴��ˣ�\n");
			return;
		}

		node* p = now;
		printf("----------------------------------------------------------------------\n");
		printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
		printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
		printf("----------------------------------------------------------------------\n");


		printf("�޸�����--------1\n");
		printf("�޸��Ա�--------2\n");
		printf("�޸����ĳɼ�----3\n");
		printf("�޸���ѧ�ɼ�----4\n");
		printf("�޸�Ӣ��ɼ�----5\n");
		printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%s", now->name);
			break;
		case 2:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%s", now->sex);
			break;
		case 3:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%d", &now->ch);
			break;
		case 4:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%d", &now->ma);
			break;
		case 5:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%d", &now->en);
			break;
		default : 
			printf("�����������������룡\n");
			break;
		}
		now->sum = now->ch + now->en + now->ma;
		printf("�Ƿ�����޸���Ϣ�� ��yes -- 1  no -- 0�� ��");
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
		printf("������Ҫ�޸Ŀγ̵����֣�");
		scanf("%s", a);
		nodd* now = searchlesson(a, L);
		if (now == NULL) {
			printf("���޴˿Σ�\n");
			return ;
		}

		nodd* p = now;

		printf("|�γ�����\t|�ον�ʦ\t|�Ͽεص�\t|�Ͽ�ʱ��\t\n");
		printf("%s\t|%s\t\t|%s\t|%s\t|\n", p->name, p->teacher, p->lo, p->time);
		printf("----------------------------------------------------------------------\n");


		printf("�޸Ŀγ�����--------1\n");
		printf("�޸��ον�ʦ--------2\n");
		printf("�޸��Ͽεص�--------3\n");
		printf("�޸��Ͽ�ʱ��--------4\n");
		printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%s", now->name);
			break;
		case 2:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%s", now->teacher);
			break;
		case 3:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%d", &now->lo);
			break;
		case 4:
			printf("����Ҫ�޸ĺ����Ϣ��");
			scanf("%d", &now->time);
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
		printf("�Ƿ�����޸���Ϣ�� ��yes -- 1  no -- 0�� ��");
		scanf("%d", &choice);
		if (choice == 0)
			break;
	}

	savefile_lesson(L);//�����޸ĺ����Ϣ 
}

void searchstu(node* L) {
	system("cls");

	int id;
	node* now;

	printf("���ڽ�֧�ְ�ѧ�Ų�ѯ��������Ҫ��ѯ��ѧ�ţ�");
	scanf("%d", &id);
	now = searchstuid(id, L);

	if (now == NULL)
		printf("���޴��ˣ�\n");
	else {
		printf("----------------------------------------------------------------------\n");
		printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
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

	//printf("���ڽ�֧�ְ�ѧ�Ų�ѯ��������Ҫ��ѯ��ѧ�ţ�");
	//scanf("%d",&id);
	now =  searchclassid(id,L);

	if(now == NULL)
	   printf("����û��ѡ�Σ�\n");
	else {
		printf("----------------------------------------------------------------------\n");
		printf("|ѧ��\t|����\t|�Ա�\t|\n");
		nodf *p = now;
		printf("%d|%s\t|%s\t|\n",p->id,p->name,p->sex);
		printf("----------------------------------------------------------------------\n");
		printf("��Ŀǰ��ѡ�����Ϊ�� \n");
		for(int i = 0 ; i <= 9 ; i++){
			if(p->p[i] != NULL)
		printf("%s\t%s\t%s\t%s\t\n",*(p->p[i]).name,*(p->p[i]).teacher,*(p->p[i]).lo,*(p->p[i]).time);
		 }
	}
}*/ //ʧ�ܵ�����ѡ��ϵͳ

void printstu(node* L) {
	system("cls");
	node* p = L->next;
	printf("----------------------------------------------------------------------\n");
	printf("|ѧ��\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
	if (p != NULL) {
		while (p != NULL) {
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", p->id, p->name, p->sex, p->ch, p->ma, p->en, p->sum);
			printf("----------------------------------------------------------------------\n");
			p = p->next;
		}
	}
	printf("***** �·��ǳɼ���߷� ******\n");
	printf("���ĳɼ���߷� �� %d\n", findstumax(&List_score, 0));
	printf("��ѧ�ɼ���߷� �� %d\n", findstumax(&List_score, 1));
	printf("Ӣ��ɼ���߷� �� %d\n", findstumax(&List_score, 2));
	printf("�ֳܷɼ���߷� �� %d\n", findstumax(&List_score, 3));
	printf("------------------------------------\n");
	printf("***** �·��ǳɼ���ͷ� ******\n");
	printf("���ĳɼ���ͷ� �� %d\n", findstumin(&List_score, 0));
	printf("��ѧ�ɼ���ͷ� �� %d\n", findstumin(&List_score, 1));
	printf("Ӣ��ɼ���ͷ� �� %d\n", findstumin(&List_score, 2));
	printf("�ֳܷɼ���ͷ� �� %d\n", findstumin(&List_score, 3));

	printf("�ɶ�ѧ���ɼ�����(Ĭ�ϴӸߵ���)�������밴0����ѧ�밴1��Ӣ���밴2���ܷ��밴3, �˳��밴4\n");
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
		printf("�����������������룡\n");
		break;
	}
}

void end() {
	printf("** ��л����ʹ�ã��ڴ��´��ټ��� **");
	exit(0);
}

void printlesson(nodd* L) {
	system("cls");
	nodd* p = L->next;
	printf("----------------------------------------------------------------------\n");
	printf("|�γ�����\t|�ον�ʦ\t|�Ͽεص�\t|�Ͽ�ʱ��\t\n");
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
	printf("|ѧ��\t|����\t|�Ա�\t|\n");
	printf("%d|%s\t|%s\t|\n", student[k].id, student[k].name, student[k].sex);
	printf("----------------------------------------------------------------------\n");
	//p = p->next; 

	printf("----------------------------------------------------------------------\n");
	printf("|�γ�����\t|�ον�ʦ\t|�Ͽεص�\t|�Ͽ�ʱ��\t\n");

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

int check_left(int id) //��������ѡ�����ſ�
{
	int cnt = 0;
	for (int i = 0; i <= 9; i++) {
		nodd* now = student[id].p[i];
		if (now == NULL) //��û��ѡ��
			cnt++;
	}

	return cnt;
}


void class_choice(nodd* L)//ѡ�κ���
{
	system("cls");


	int ccnt = 0;//��ѡ�εĸ���


	printf("**             ��ӭ����ѡ�ν���!            **\n");
	printf("**        ��ע�⣡ ÿ������ѡ10�ſΣ�             **\n");
	int c;
	printf("����������ѧ�ţ�");
	scanf("%d", &c);

	int stu_number = searchclass(c);

	int limit = check_left(stu_number);//ѡ������

	if (stu_number == -1)//û��ѡ��
	{
		printf("����û��ѡ��\n");
		printf("����������������");
		scanf("%s", student[cnt].name);
		printf("�����������Ա�");
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
		printf("----------------------��ʼѡ��-----------------\n");

		char a[50];
		printf("��������ѡ�ε����֣�");
		scanf("%s", a);
		nodd* now = searchlesson(a, L);//now Ϊ��ѡ�εĵ�ַ;
		if (now == NULL)
		{
			printf("------------------���޴˿Σ� ������ѡ��-----------------\n");
			delay(100000);//�ӳٺ���
			continue;
		}
		nodd* now1 = check(stu_number, now);//�����Ƿ�����ѡ�Ŀγ�ͻ
		if (now1 == NULL) //�˿�δ��ѡ�������������޳�ͻ
		{
			printf("------------------ѡ�γɹ���-----------------\n");
			student[stu_number].p[ccnt] = now;//���ѱ�ѡ
			ccnt++;
			if (ccnt == limit)
			{
				printf("ѡ���Ѵ����ޣ� �޷�ѡ�Σ� \n");
				break;
			} //�ﵽѡ������

		}
		else {
			printf("------------------ѡ��ʧ�ܣ�-----------------\n");
			printf("�˿��ѱ�ѡ �� �˿��� %s �г�ͻ��", now1->name);
		}

		//��ѯ�Ƿ�ѡ�񣬻����г�ͻ

		printf("�Ƿ����ѡ�Σ� yes 1  no 0 :");
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
	}
}

void class_delet(nodd* L) {
	system("cls");
	int c;
	printf("����������ѧ�ţ�");
	scanf("%d", &c);

	int stu_number = searchclass(c);//���ѧ���Ľṹ���ţ��ж��Ƿ��пο�����

	if (stu_number == -1) {
		printf("����û��ѡ�Σ��޷��˿Σ�\n");
		return;
	}

	int limit = 10 - check_left(stu_number);//�˿�����

	while (1) {
		printf("��Ŀǰ�Ŀα�Ϊ��\n");
		printclass(c);
		char a[50];
		printf("������Ҫ�˿ε����֣�");
		scanf("%s", a);

		int i;
		for (i = 0; i <= 9; i++) {
			nodd* now = student[stu_number].p[i];
			if (now != NULL) {
				if (!strcmp(now->name, a)) {
					student[stu_number].p[i] = NULL;
					printf("------------------�˿γɹ���-----------------\n");
					limit--;
					if (limit == 0)//�޿ο���
					{
						printf("��û�пο������ˣ�\n");
						return;
					}
					break;
				}
				else {
					if (i == 9) //û���ҵ�Ҫ�˵Ŀ�
						printf("�˿�ʧ�ܣ� ����������Ŀγ����֣� \n");
				}

			}
		}

        printf("�Ƿ�����˿Σ� yes 1  no 0 : ");
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
	}

}

void class_print()//��ӡ�α�
{
	system("cls");
	int c;
	printf("����������ѧ�ţ�");
	scanf("%d", &c);
	if (int stu_number = searchclass(c) == -1)
		printf("�������ѧ���������������룡\n");
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
			printf("�����������������룡\n");
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
		case 1://��ѯ�ɼ� 
			searchstu(&List_score);
			break;
		case 2://ѡ�� 
			class_choice(&List_lesson);
			break;
		case 3://�˿� 
			class_delet(&List_lesson);
			break;
		case 4://���ɿα� 
			class_print();
			break;
		case 5://������һ���˵� 
			return;
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
		printf("�Ƿ���Ҫ��������? (yes : 1   no : 0 ) : ");
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
		case 1://ɾ��ѧ����Ϣ
			delestu();
			break;
		case 2://�޸�ѧ����Ϣ
			fixstu(&List_score);
			break;
		case 3://��ӡ�ܿα�
			printlesson(&List_lesson);
			break;
		case 4://���ӿγ�
			addlesson();
			break;
		case 5://ɾ���γ�
			deletlesson();
			break;
		case 6://�޸Ŀγ�
			fixlesson(&List_lesson);
			break;
		case 7://������һ���˵� 
			return;
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
		printf("�Ƿ���Ҫ��������? (yes : 1   no : 0 ) : ");
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
		case 1://����ѧ����Ϣ
			addstu();
			break;
		case 2://��ѯѧ����Ϣ 
			searchstu(&List_score);
			break;
		case 3://���ѧ����Ϣ 
			printstu(&List_score);
			break;
		case 0://�˳����� 
			end();
			break;
		case 4://������һ���˵� 
			return;
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
		printf("�Ƿ���Ҫ��������? (yes : 1   no : 0 ) : ");
		scanf("%d", &c);
		if (c == 0)
			break;
	}
	return;
}

