#include "Student.h"

/*
��������
��ʾ������ҳ��ѭ����ʾ�˵���
��ȡ�û�ѡ������Ӧ��������
*/
int main()
{
	int n = 0, m = 0;   //ѧ���������γ���Ŀ 
	int i, j, flag = 0; //�ж��Ƿ�������ܷ֣�����δ�����ܷ־����� 
	char filename[100];
	STU *head = NULL;   //����ͷ�ڵ�
	while (1)
	{
		system("cls"); 
		i = Menu();

		switch (i)
		{
		case 1:
			system("cls");  //����
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<1000):");  //����ѧ����  
			scanf("%d", &n);
			m = 3; 
			printf("\t\t\tInput student's ID, name and course score");
			printf("(");
			for(j = 0; j < m; j++)
			{
				printf(" %s", courseName[j]);
			}
			printf(" )\n");
			head = Creat(n, m);
			printf("¼�����ݳɹ�!�����������......");
			getche(); 
			system("cls");  
			break;
		case 2:
			system("cls");  
			AverSumofEveryCourse(head, n, m);
			print1(m); 
			printf("���ݼ������!�����������......");
			getche(); 
			break;
		case 3:
			system("cls");  
			AverSumofEveryStudent(head, n, m);
			flag = 1; 
			printf("���ݼ������!�����������......");
			getche(); 
			break;
		case 4:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			if(flag)
			{
				head = SortbyScore(head, n);
				Print(head, n, m);
				printf("�����������!�����������......");
			}
			else                  //δ�����ܷ֣��޷��������� 
			{
				printf("δ�����ܷ�,�޷����򣬰����������......");
			}
			getche(); 
			break;
		case 5:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low by number:\n");
			head = SortbyNumber1(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 6:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from low to high by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 7:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Chinese:\n");
			head = SortbyChinese(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 8:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Maths:\n");
			head = SortbyMaths(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 9:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by English:\n");
			head = SortbyEnglish(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 10:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Aver:\n");
			head = SortbyAver(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;

		case 11:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);     //����󷵻�ͷָ��    
			Print(head, n, m);				//��ӡ  ͷָ��ָ������� 
			printf("�����������!�����������......");
			getche();
			break;
		case 12:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			printf("�����������......");
			getche();	
			break;
		case 13:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			printf("�����������......");
			getche();
			break;
		case 14:
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			head = deleteStu(head, &n, m);    //ֻ��Ҫ����ͷָ��    ������ϸ���� deleteStu()��ʵ�� 
			printf("�����������......");
			getche();
			break;
		case 15:
			system("cls");  
			printf("\n\n\n");
			addStu(head, &n, m);
			printf("��ӳɹ��������������......");
			getche();
			break;
		case 16:
			system("cls");
			printf("\n\n\n");
			Modify(head, n, m);
			printf("�����������......");
			getche();
			break;
		case 17:
			system("cls");  
			printf("\n\n\n");
			topStu(head, m);
			printf("�����������......");
			getche();
			break;
		case 18:
			system("cls");  
			printf("\n\n\n");
			failStu(head, m);
			printf("�����������......");
			getche();
			break;
		case 19:
			system("cls");  
			printf("\n\n\n");
			Print(head, n, m);
			printf("�����������......");
			getche();
			break;
		case 20:
			system("cls");
			printf("\t\t\t����ִ����Ӧ��������󱣴�����Ӧ�ļ��У����㡢������޷��ٽ���ԭʼ���ݱ���\n");
			printf("\t\t\t��ʾ��������ʾ���ļ�������\n");
			printf("\t\t\tplease input file name(RawData.xls StatisticalData.xls ComprehensiveScoresOfStudents.xls  or .txt): ");
			fflush(stdin);
			gets(filename);
			WritetoFile(head, filename, n, m);
			printf("�����������......");
			getche();
			break;
		case 21:
			system("cls");
			head = ReadfromFile(head, &n, &m);
			printf("�����������......");
			getche();
			break;
		case 0:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tEnd of program!\n");
			printf("\t\t\t******************************************************************************\n");
			return 0;
		default:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");

		}

	}
	return 0;
}


/*
�������ܣ���ʾ�˵� 
�������� 
����ֵ���û�ѡ��Ĳ˵����
ע�⣺  ��ʹ�� 1 ����� �������ʹ�� 1 ���Ḳ��֮ǰ������  
        �¼ӵļ�¼��ʹ��   11 
*/
int   Menu(void)
{
	int i;
	system("title ѧ���ɼ�����ϵͳ");
	printf("\t\t\t                      ******  *****  *       *   ******                          \n");
	printf("\t\t\t                      *         *    * *   * *   *                               \n");
	printf("\t\t\t                      ******    *    *   *   *   ******                          \n");
	printf("\t\t\t                           *    *    *   *   *        *                          \n");
	printf("\t\t\t                      ******  *****  *       *   ******                          \n");
	printf("\t\t\t                                ѧ���ɼ�����ϵͳ\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t|     -------->> 1.  Input record ��Once��  (Can be overrided)               |\n");
	printf("\t\t\t|       ------>> 2.  Caculate each section and average score of every course |\n");
	printf("\t\t\t|       ------>> 3.  Caculate total and average score of every student       |\n");
	printf("\t\t\t|       ------>> 4.  Sort in descending order by  total score                |\n");
	printf("\t\t\t|                5.  Sort form high to low by number(DESC)                   |\n");
	printf("\t\t\t|                6.  Sort from low to high by number(ASC)                    |\n");
	printf("\t\t\t|                7.  Sort from high to low by Chinese(DESC)                  |\n");
	printf("\t\t\t|                8.  Sort from high to low by Maths(DESC)                    |\n");
	printf("\t\t\t|                9.  Sort from high to low by English(DESC)                  |\n");
	printf("\t\t\t|               10.  Sort from high to low by Aver(DESC)                     |\n");
	printf("\t\t\t|               11.  Sort in dictionary order by name                        |\n");
	printf("\t\t\t|               12.  Search by number                                        |\n");
	printf("\t\t\t|               13.  Search by name                                          |\n");
	printf("\t\t\t|               14.  Delete student by number                                |\n");
	printf("\t\t\t|      ------->>15.  Add student(s)                                          |\n");
	printf("\t\t\t|               16.  Modify student informaton                               |\n");
	printf("\t\t\t|         ---->>17.  search and save top student(s)                          |\n");
	printf("\t\t\t|         ---->>18.  search and save student(s) failling subject             |\n");
	printf("\t\t\t|               19.  print link-lists                                        |\n");
	printf("\t\t\t|           -->>20.  Write to a file                                         |\n");
	printf("\t\t\t|               21.  Read From file                                          |\n");
	printf("\t\t\t|                0.  Exit                                                    |\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d", &i);
	return i;

}

/*
�������ܣ���������       ������Ӽ�¼ 
������ѧ���������γ���Ŀ 
����ֵ������ͷ��� 
*/
STU *Creat(int n, int m) {
	STU *head = NULL;
	STU *p1, *p2;
	int i, j, flag;
	// system("cls");
	for (i = 1; i<n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		printf("\t\t\t");
		scanf("%lld", &p1->num);
		flag = CheckNum(NULL,p1->num);
		while(flag != 0)
		{
			printf("\t\t\tInput error!!!\n");
			printf("\t\t\t");
			scanf("%lld", &p1->num);
			flag = CheckNum(NULL,p1->num);
		}
		printf("\t\t\t");
		scanf("%s",p1->name);
		for (j = 0; j<m; j++)
		{
			printf("\t\t\t");
			scanf("%f", &p1->score[j]);
			flag = CheckNum(NULL,p1->score[j]);
			while(flag != 0)
			{
				printf("\t\t\tInput error!!!\n");
				printf("\t\t\t");
				scanf("%f", &p1->score[j]);
				flag = CheckNum(NULL,p1->score[j]);
			}
		}
		p1->rankNum = 0;
		p1->aver = 0;
		p1->sum = 0;
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return (head);
}

/*
�������ܣ�����������   ���ڶ�ȡ�ļ� 
������ѧ���������γ���Ŀ 
����ֵ������ͷ��� 
*/
STU *CreatEmpty(int n, int m)
{
	STU *head;
	STU *p1, *p2;
	int i, j;

	for (i = 1; i<n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}



/*
�������ܣ�����ÿ�ſγ�ƽ���֡��ܷ� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void  AverSumofEveryCourse(STU *head, int n, int m)
{
	STU *p;
	int i;
	char ch;
	float sum;
	
	memset(Course, 0, sizeof(Course));                  //��ʼ������Course 
	p = head;
	if (head != NULL)									/*��ֹû������ѧ����Ϣhead=NULLʱ������head->next�������*/
	{
		for (i = 0; i<m; i++)
		{
			p = head;
			sum = 0.0;
			do {
				sum += p->score[i];
				if(p->score[i] < 60)
				{
					Course[i].sectionNum[0]++;
				}
				if(p->score[i] >= 60 && p->score[i] < 70)
				{
					Course[i].sectionNum[1]++;
				}
				if(p->score[i] >= 70 && p->score[i] < 80)
				{
					Course[i].sectionNum[2]++;
				}
				if(p->score[i] >= 80 && p->score[i] < 90)
				{
					Course[i].sectionNum[3]++;
				}
				if(p->score[i] >= 90)
				{
					Course[i].sectionNum[4]++;
				}
				p = p->next;
			} while (p != NULL);
			Course[i].avescore = sum / n;
			Course[i].sumscore = sum;
		}
	}
	else
	{
		printf("Please input student information before doing this\n!!!\n");
	} 
}
/*
�������ܣ�����ÿ��ѧ���ܷ֡�ƽ���� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void  AverSumofEveryStudent(STU *head, int n, int m)
{
	STU *p;
	int i, j;
	p = head;
	if (head != NULL)
	{
		printf("\t\t\t******************************************************************************\n");
		for (i = 0; i<n; i++)
		{
			p->sum = 0.0;
			for (j = 0; j<m; j++)
			{
				p->sum += p->score[j];
			}
			p->aver = p->sum / m;
			printf("\t\t\tstudent %s: sum=%.1f,aver=%.1f\n", p->name, p->sum, p->aver);
			p = p->next;
		}
		printf("\t\t\t******************************************************************************\n");
	}
	else
	{
		printf("Please input student information before doing this!!!\n");
	} 
}
/*
�������ܣ���ѧ���ִܷӸߵ������� 
����������ͷ��㡢ѧ������ 
����ֵ������ͷ��� 
*/
STU  *SortbyScore(STU *head, int n)   //ð������ 
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;
	int data = -1, ranknum = 0;//��ѧ���������м���� 
	
	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p) 
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)//���һ�ζ�û��������Ȼp = head�����Ѿ��ź�������ѭ������ֹ 
		{
			if (p1->next->sum < p1->next->next->sum)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;			//		��������p1->a->b->c->......										 
				p1->next->next = p2->next;		//		�Ȱ�b���浽p2����p2 =  p1->next->next							
				p2->next = p1->next;			//		����a��һ��ָ��c,a->c��b��һ��ָ��a��b->a��						
				p1->next = p2;					//		����p1ָ��p2����p1ָ��b��p1->b									
				p = p1->next->next;				//		�ۺ����漴�ɵó���p1->b->a->c; 									
			}									//		p = a? �����涼û�ٽ�������Ȼ����a->c->......���涼�Ѿ��ź�����	 
		}										//		����һ��ѭ���Ƚ�ʱֻ����a�ڵ�֮ǰ����������� 
	}
	
	p1 = head;               //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);                //�ͷ�p1
	
	//�ִܷӸߵ�����������ÿ��ͬѧ��������ͬ�ܷ����β��� 
	for(p = head; p; p = p->next)
	{
		if(p->sum == data)
		{
			p->rankNum = ranknum;
		}
		else
		{
			ranknum++;
			p->rankNum = ranknum;
			data = p->sum;
		}
	}

	return head;
}
/*
�������ܣ���ѧ��ѧ�ŴӴ�С���� 
����������ͷ��㡢ѧ������
����ֵ������ͷ��� 
*/
STU  *SortbyNumber1(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num < p1->next->next->num)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}
/*
�������ܣ���ѧ��ѧ�Ŵ�С�������� 
����������ͷ���
����ֵ������ͷ��� 
*/
STU *SortbyNum(STU *head)    //���뷨���� 
{
	STU *first;    //Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��
	STU *t;        //��ʱָ�����������ڵ�
	STU *p, *q;     //��ʱָ�����,q��Ϊ���������ͷ,p����ǰһ���ڵ� 

	if(head == NULL)
	{
		return head;
	}
	first = head->next;      //ԭ����ʣ������ֱ�Ӳ�������Ľڵ�����
	head->next = NULL;       //����һ���ڵ���Ϊ��һ����������

	while (first != NULL)        //����ʣ�����������
	{
		//ע�⣺����for����������ֱ�Ӳ�������˼��ĵط�
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //����������������ڵ��������������Ҳ����λ��

		first = first->next; //���������еĽڵ��뿪���Ա������뵽����������

		if (q == head)      //���ڵ�һ���ڵ�֮ǰ
		{
			head = t;
		}
		else            //p��q��ǰ��
		{
			p->next = t;
		}
		t->next = q;     //��ɲ��붯��
						 //first = first->next;
	}
	return head;
}

/*
�������ܣ���ѧ�����ĳɼ��ɸߵ������� 
����������ͷ���
����ֵ������ͷ��� 
*/
STU  *SortbyChinese(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[0] < p1->next->next->score[0])  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
	
} 

/*
�������ܣ���ѧ����ѧ�ɼ��ɸߵ������� 
����������ͷ���
����ֵ������ͷ��� 
*/
STU  *SortbyMaths(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[1] < p1->next->next->score[1])  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
} 

/*
�������ܣ���ѧ��Ӣ��ɼ��ɸߵ������� 
����������ͷ���
����ֵ������ͷ��� 
*/
STU  *SortbyEnglish(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[2] < p1->next->next->score[2])  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}				

/*
�������ܣ���ѧ��ƽ�����ɸߵ������� 
����������ͷ���
����ֵ������ͷ��� 
*/
STU  *SortbyAver(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->aver < p1->next->next->aver)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
} 

/*
�������ܣ���ѧ�����ֵ���ĸ˳������ 
����������ͷ��㡢ѧ������
����ֵ������ͷ��� 
*/
STU  *SortbyName(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name)>0)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;     //��ϵ�4�����
				p = p1->next->next;   //��ϵ�6�����
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}

/*
�������ܣ���ӡ����ѧ����Ϣ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void Print(STU *head, int n, int m)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)        //ֻҪ���ǿ�������������������нڵ�
	{
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t%15s\t%s\t", "ѧ��", "����"); 
		for(i = 0; i < m; i++)
		{
			printf("%s\t", courseName[i]);
		}
		printf("%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����"); 
		do
		{

			printf("\t\t\t%15lld\t%s\t", p->num, p->name);
			for (i = 0; i<m; i++)
			{
				printf("%.1f\t", p->score[i]);
			}
			printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;     //�Ƶ���һ���ڵ�
		} while (p != NULL);
		printf("\t\t\t******************************************************************************\n");
	}
}
/*
�������ܣ���ӡÿ���γ���Ϣ 
�������γ���Ŀ
����ֵ���� 
*/
void print1(int courseNum)
{
	int i;
	
	printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "course", "sum", "averscore","<60(������)", "[60,70)", "[70,80)", "[80,90)", ">=90","ͨ����");
	for(i = 0; i < courseNum; i++)
	{
		printf("\t\t\t%s\t%.1f\t%.1f\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", courseName[i], Course[i].sumscore, Course[i].avescore, Course[i].sectionNum[0],
										  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4],Course[i].sectionNum[1]+Course[i].sectionNum[2]+Course[i].sectionNum[3]+Course[i].sectionNum[4]);
	}
}


/*
�������ܣ�����ѧ������ѧ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void  SearchbyNum(STU *head, int n, int m)
{
	long long num;
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%lld", &num);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t\t%s\t%s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����");
				
				printf("\t\t\t");
				printf("%lld\t%s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%.1f\t", p->score[i]);
				}
				printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
				break;
			}
			p = p->next;

		} while (p != NULL);

	}
	if (flag)
	{
		printf("\t\t\t");
		printf("Not found!\n");
	}
	printf("\t\t\t******************************************************************************\n");

}
/*
�������ܣ�����ѧ����������ѧ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void  SearchbyName(STU *head, int n, int m)
{
	char name[MAX_LEN];
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%s", name);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (strcmp(name, p->name) == 0)
			{
				printf("\t\t\t%s\t%s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����");
				
				printf("\t\t\t");
				printf("%lld\t%s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%.1f\t", p->score[i]);
				}
				printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
			}
			p = p->next;

		} while (p != NULL);
		
	}
	if (flag)
	{
		printf("\t\t\t");
		printf("Not found!\n");
	}
	printf("\t\t\t******************************************************************************\n");

}
/*
�������ܣ�����ѧ��ɾ��ѧ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���µ�����ͷ��� 
*/
STU* deleteStu(STU *head, int *n, int m)
{
	long long num;
	int i;
	int flag = 1;
	char temp[5];
	
	printf("\t\t\tplease input number you want to delete\n");
	printf("\t\t\t");
	scanf("%lld", &num);
	STU *p, *q;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t\t%s\t%s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����");
				
				printf("\t\t\t");
				printf("%lld\t%s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%.1f\t", p->score[i]);
				}
				printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
				printf("\t\t\tAre you surn to delete?(yes/no):");
				scanf("%s", temp);
				if(strcmp(temp, "yes") == 0)
				{
					if(p == head)
					{
						head = p->next;
					}
					else
					{
						q->next = p->next;
					}
					free(p);
					*n = *n - 1;
					printf("ɾ���ɹ��������������......");
					getche();
				}
				break;
			}
			q = p;
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");
	
	return head;
}
/*
�������ܣ�����ѧ�����ѧ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void addStu(STU *head, int *stuNum, int m)
{
	STU *Nhead = NULL;
	STU *p1, *p2;
	int i, j, n;
	int flag;
	
	printf("please input student number you want to add:");
	scanf("%d", &n);
	*stuNum += n;
	printf("\t\t\tInput student's ID, name and course score");
	printf("(");
	for(j = 0; j < m; j++)
	{
		printf(" %s", courseName[j]);
	}
	printf(" )\n");
	
	// system("cls");
	for (i = 1; i<n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		printf("\t\t\t");
		scanf("%lld", &p1->num);
		flag = CheckNum(head,p1->num);  //����ͷָ�� �Ǽ���Ƿ��ظ� 
		while(flag != 0)
		{
			if(flag == 2) printf("\t\t\tInput erroor,may you input repeat number!!!\n");
			if(flag == 1) printf("\t\t\tInput error!!!\n");
			printf("\t\t\t");
			scanf("%lld", &p1->num);
			flag = CheckNum(head,p1->num);  
		}		
		printf("\t\t\t");
		scanf("%s",p1->name);
		for (j = 0; j<m; j++)
		{
			printf("\t\t\t");
			scanf("%f", &p1->score[j]);
			flag = CheckNum(NULL,p1->score[j]);  //����Ƿ���� 0  
			while(flag != 0)
			{
				printf("\t\t\tInput error!!!\n");
				printf("\t\t\t");
				scanf("%f", &p1->score[j]);
				flag = CheckNum(NULL,p1->score[j]);  //����Ƿ���� 0  
			}	
		}
		p1->rankNum = 0;
		p1->aver = 0;
		p1->sum = 0;
		p1->next = NULL;
		if (i == 1)
		{
			Nhead = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	//������ӵ�ѧ����������ԭ����β 
	p2 = head;
	while(p2->next)
	{
		p2 = p2->next;
	}
	p2->next = Nhead;
}
/*
�������ܣ�����ѧ���޸�ѧ����Ϣ 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*/
void Modify(STU *head, int n, int m)
{
	long long num;
	int i;
	int flag = 1;
	STU *p = head;
		
	printf("\t\t\tplease input number you want to modify\n");
	printf("\t\t\t");
	scanf("%lld", &num);
	if (head != NULL)
	{
		do {
				if (p->num == num)
				{
					printf("\t\t\t%s\t\t%s\t", "ѧ��", "����"); 
					for(i = 0; i < m; i++)
					{
						printf("%s\t", courseName[i]);
					}
					printf("%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����");
					
					printf("\t\t\t");
					printf("%lld\t%s\t", p->num, p->name);
					for (i = 0; i<m; i++)
					{
						printf("%.1f\t", p->score[i]);
					}
					printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
					
					printf("\t\t\tplease input the modified information:\n");
					printf("\t\t\t%s\t\t%s\t", "ѧ��", "����"); 
					for(i = 0; i < m; i++)
					{
						printf("%s\t", courseName[i]);
					}
					printf("\n\t\t\t");
					scanf("%lld", &p->num);
					flag = CheckNum(NULL,p->num);  //����ͷָ�� �Ǽ���Ƿ��ظ� 
					while(flag != 0)
					{
						if(flag == 1) printf("\t\t\tInput error!!!\n");
						printf("\t\t\t");
						scanf("%lld", &p->num);
						flag = CheckNum(NULL,p->num);  
					}		
					printf("\t\t\t");
					scanf("%s", p->name);
					for(i = 0; i < m; i++)
					{
						printf("\t\t\t");
						scanf("%f", &p->score[i]);
						flag = CheckNum(NULL,p->score[i]);  //����Ƿ���� 0  
						while(flag != 0)
						{
							printf("\t\t\tInput error!!!\n");
							printf("\t\t\t");
							scanf("%f", &p->score[i]);
							flag = CheckNum(NULL,p->score[i]);  //����Ƿ���� 0  
						}
					}
					flag = 0;
					printf("�޸ĳɹ���"); 
				}
				p = p->next;
		}while(p);
		
		if(flag)
		{
			printf("Not find!\n");
		}
	}
}

/*
�������ܣ���������Ӧ�ļ�   ʹ�ò�ͬ���ļ��� 
����������ͷ��㡢�ļ�����ѧ���������γ���Ŀ 
����ֵ����
*/
void  WritetoFile(STU *head, char filename[20], int n, int m)
{
	STU *p;
	p = head;
	FILE *fp;
	int i, j;
	printf("\n\n\n");
	printf("\t\t\t******************************************************************************\n");
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\tFail to open %s\n", filename);
		printf("\t\t\t******************************************************************************\n");
		return;
	}
	if(strcmp(filename, "RawData.xls") == 0 || strcmp(filename, "RawData.txt") == 0 || strcmp(filename, "ComprehensiveScoresOfStudents.xls") == 0 || strcmp(filename, "ComprehensiveScoresOfStudents.txt") == 0)
	{
		fprintf(fp,"%s\t%d\t%s\t%d\n","ѧ��������",n,"�γ�����",m);
		fprintf(fp, "%s\t%s\t", "ѧ��", "����"); 
		for(i = 0; i < m; i++)
		{
			fprintf(fp, "%s\t", courseName[i]);
		}
		fprintf(fp, "%s\t%s\t%s\n", "�ܷ�", "ƽ����", "����");
		
		for (i = 0; i<n; i++)
		{
			fprintf(fp, "%lld\t%s\t", p->num, p->name);
			for (j = 0; j<m; j++)
			{
				fprintf(fp, "%.1f\t", p->score[j]);
			}
			fprintf(fp, "%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;
		}
	}
	else
	{
		if(strcmp(filename, "StatisticalData.xls") == 0 || strcmp(filename, "StatisticalData.txt") == 0)   
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "�γ�", "�γ��ܷ�", "�γ�ƽ����", "<60(������)", "[60,70)", "[70,80)", "[80,90)", ">=90","ͨ����");
			for(i = 0; i < m; i++)
			{
				fprintf(fp, "%s\t%.1f\t%.1f\t%d\t%d\t%d\t%d\t%d\t%d\n", courseName[i], 100, Course[i].avescore, Course[i].sectionNum[0],
														  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4],Course[i].sectionNum[1]+Course[i].sectionNum[2]+Course[i].sectionNum[3]+Course[i].sectionNum[4]);
			}
		}
		else
		{
			printf("filename is wrong!\n");
			return ;
		}
	}
	
	printf("\t\t\tExport Successfully!\n");
	fclose(fp);
	printf("\t\t\t******************************************************************************\n");

}
/*
�������ܣ�ɸѡ�ŵ��� ���������ļ� 
����������ͷ��㡢ѧ������
����ֵ���� 
*/
void topStu(STU *head, int n)
{
	STU *p = head;
	FILE *fp;
	int i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 1, count = 0;  //�ŵ����������� ��־  
	
	if((fp = fopen("SuperiorStudent.xls", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		flag4 = 0;
	}
	fprintf(fp, "%s\t%s\n", "ѧ��", "����"); 
	for(; p; p= p->next)
	{
		flag1 = 0;//��ʼ������������������ 
		flag2 = 0;
		flag3 = 0;
		
		if(p->aver >= 80)
		{
			flag1 = 1;
		}
		if(p->aver >= 60 && p->aver <90)
		{
			for(i = 0; i < n; i++)
			{
				if(p->score[i] >= 90)
				{
					flag2 = 1;
					break;
				}
			}
		}
		if(p->aver < 60)
		{
			for(i = 0; i < n; i++)
			{
				if(p->score[i] == 100)
				{
					flag3 = 1;
					break;
				}
			}
		}
		if(flag1 || flag2 || flag3)   //����һ�������ŵ���    ���߼����Ը���  
		{
			count++;
			printf("%lld\t%s\n", p->num, p->name);
			if(flag4)
			{
				fprintf(fp, "%lld\t%s\n", p->num, p->name);
			}
		}
	}
	if(count == 0)
	{
		printf("���ŵ���!");
		if(flag4)
		fprintf(fp, "���ŵ���"); 
	}
	else
	{
		printf("�ŵ�����%d��\n", count);
		if(flag4)
		fprintf(fp, "\t�ŵ�����%d��\n", count);
	}
	fclose(fp);
}
/*
�������ܣ�����ѧ���������Ŀ��Ϣ������ 
����������ͷ��㡢ѧ������
����ֵ���� 
*/
void failStu(STU *head, int n)
{
	STU *p = head;
	int i, flag1 = 0, flag2 = 1, flag3 = 1;
	FILE *fp;
	
	if((fp = fopen("FailingSubjects.xls", "w")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		flag3 = 0;
	}
	
	fprintf(fp, "%s\t%s\t", "ѧ��", "����"); 
	for(i = 0; i < 3; i++)
	{
		fprintf(fp, "%s\t", courseName[i]);
	}
	fprintf(fp, "\n");
	
	for(; p; p = p->next)
	{
		flag1 = 0;
		for(i = 0; i < n; i++)
		{
		//	printf("flag1 = %d score[%d] = %.1f ", flag1, i, p->score[i]);
			if(p->score[i] < 60)
			{
				flag1 = 1;
				break;
			}
		}
		//printf("flag1 = %d\n", flag1);
		if(flag1)
		{
			flag2 = 0;
			printf("%lld\t%s\t", p->num, p->name);
			if(flag3)
			{
				fprintf(fp, "%lld\t%s\t", p->num, p->name);
			}
			for(i = 0; i < n; i++)
			{
				if(p->score[i] < 60)
				{
					printf("%s:%.1f\t", courseName[i], p->score[i]);
					if(flag3)
					{
						fprintf(fp, "%.1f\t", p->score[i]);
					}
				}
				else
				{
					if(flag3)
					{
						fprintf(fp,"%s\t","����");
					}
				}
					
			}
			printf("\n");
			if(flag3)
			fprintf(fp, "\n");
		}
	}
	if(flag2)
	{
		printf("�޲�����ѧ��\n");
		if(flag3)
		{
			fprintf(fp, "�޲�����ѧ��\n");
		}
	}
	fclose(fp);
}


/*
Read records  from local file 

The file must be in special form
You can see it in example.txt and example.xls

Note��Can only read from *.txt and *.xls
*/ 
STU *ReadfromFile(STU *head, int *n, int *m)
{  
	STU *p;
	FILE *fp;
	int i, j;
	char file_name[100];
	char temp1[100],temp2[100],temp3[100],temp4[100],temp5[100],temp6[100],temp7[100],temp8[100];
	printf("\t\t\tPlease input file name:\n\t\t\t");
	scanf("%s",file_name);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("\t\t\tFail to open %s\n",file_name);
		printf("\t\t\tTry RawData.xls ???\n");
		return NULL;
	}
	fscanf(fp,"%s\t%d\t%s\t%d\n",temp1,n,temp2,m);            //��ͷ������ 
	fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);  //��ͷ������ 
	head = CreatEmpty(*n, *m);         
	p = head;						//����һ�������� 
	for (i = 0; i<*n; i++)
	{
		fscanf(fp,"%lld\t%s\t", &p->num, &p->name);
		
		for (j = 0; j<*m; j++)
		{
			fscanf(fp, "%f\t", &p->score[j]);
		}
		fscanf(fp, "%f\t%f\t%d\n", &p->sum, &p->aver,&p->rankNum);

		p = p->next;

	}
	i = *n;
	j = *m;
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\tImport Successfully!\n");
	printf("\t\t\t******************************************************************************\n");	
	fclose(fp);
	Print(head, i, j);
	return(head);
}

int CheckNum(STU *head,  long long number)
{
	STU *p;
	p = head;
	if(number < 0)  
	{
		return 1;
	}
	
	while(p != NULL)
	{
		
		if(p->num == number)
		{
			 return 2;
		}
		p = p->next;
	}
	
	return 0;			
}


