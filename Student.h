#ifndef __STUDENT__
#define __STUDENT__

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

#define   MAX_LEN  10                	   /* �ַ�����󳤶� */
#define   STU_NUM 1000                     /* ����ѧ������ */
#define   COURSE_NUM 3                    /* ���Ŀ��Կ�Ŀ�� */
#define   LEN sizeof(struct Student)	   /*�ṹ�������ֽڳ���*/ 

typedef struct Student
{
	long long num;	                    /* ÿ��ѧ����ѧ�� */
	char name[MAX_LEN];            	/* ÿ��ѧ�������� */
	float score[COURSE_NUM];	    /* ÿ��ѧ��COURSE_NUM�Ź��εĳɼ� */
	float sum;                      /* ÿ��ѧ�����ܳɼ� */
	float aver;					    /* ÿ��ѧ����ƽ���ɼ� */
	int rankNum;				    /* ÿ��ѧ������       */
	struct Student *next;
}STU;

struct {
	float avescore, sumscore;
	int sectionNum[5];
} Course[COURSE_NUM];

char *courseName[COURSE_NUM] ={"����","��ѧ","Ӣ��"};                  //����γ����� 

int   Menu(void);                                      //�����˵�
void  Print(STU *head, int n, int m);                  //��ӡѧ����Ϣ 
void print1(int courseNum);                             //��ӡ�γ���Ϣ 
void  AverSumofEveryStudent(STU *head, int n, int m);  //����ÿ�ſγ̵��ֺܷ�ƽ����
void  AverSumofEveryCourse(STU *head, int n, int m);   //����ÿ��ѧ�����ֺܷ�ƽ����
STU  *SortbyScore(STU *head, int n);				   //��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
STU  *Creat(int n, int m);   							//����������¼����Ϣ
STU *CreatEmpty(int n, int m);                          //���������� 
STU  *SortbyNumber1(STU *head, int n);                  //��ѧ���ɸߵ����ų��ɼ���
STU  *SortbyNum(STU *head);                            //��ѧ���ɵ͵����ų��ɼ���
STU  *SortbyChinese(STU *head, int n);					//�����ĳɼ��ɸߵ����ų��ɼ���
STU  *SortbyMaths(STU *head, int n);					//����ѧ�ɼ��ɸߵ����ų��ɼ���
STU  *SortbyEnglish(STU *head, int n);					//��Ӣ��ɼ��ɸߵ����ų��ɼ���
STU  *SortbyAver(STU *head, int n);                     //��ƽ���ɼ��ɸߵ����ų��ɼ���
STU  *SortbyName(STU *head, int n);                    //���������ֵ�˳���ų��ɼ���
void  SearchbyNum(STU *head, int n, int m);            //��ѧ�Ų�ѯѧ���������俼�Գɼ�
void  SearchbyName(STU *head, int n, int m);           //��������ѯѧ���������俼�Գɼ�
STU* deleteStu(STU *head, int *n, int m);			   //��ѧ��ɾ��ѧ����Ϣ
void addStu(STU *head, int *stuNum, int m);			   //����ѧ����Ϣ 
void Modify(STU *head, int n, int m);				   //�޸�ѧ����Ϣ 
void topStu(STU *head, int n);						   //�����ŵ������������ļ� 
void failStu(STU *head, int n);						   //����ѧ���������Ŀ���������ļ� 
void  WritetoFile(STU *head, char filename[100], int n, int m); //��ÿ��ѧ���ļ�¼��Ϣд���ļ�
STU *ReadfromFile(STU *head, int *n, int *m);                   //���ļ���ȡÿ��ѧ���ļ�¼��Ϣ 
int CheckNum(STU *head,  long long number); 


#endif