#include "Student.h"

/*
主函数：
显示程序首页，循环显示菜单，
获取用户选项并完成相应处理流程
*/
int main()
{
	int n = 0, m = 0;   //学生人数、课程数目 
	int i, j, flag = 0; //判断是否计算了总分，以免未计算总分就排名 
	char filename[100];
	STU *head = NULL;   //定义头节点
	while (1)
	{
		system("cls"); 
		i = Menu();

		switch (i)
		{
		case 1:
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<1000):");  //输入学生数  
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
			printf("录入数据成功!按任意键继续......");
			getche(); 
			system("cls");  
			break;
		case 2:
			system("cls");  
			AverSumofEveryCourse(head, n, m);
			print1(m); 
			printf("数据计算完毕!按任意键继续......");
			getche(); 
			break;
		case 3:
			system("cls");  
			AverSumofEveryStudent(head, n, m);
			flag = 1; 
			printf("数据计算完毕!按任意键继续......");
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
				printf("数据排序完毕!按任意键继续......");
			}
			else                  //未计算总分，无法计算排名 
			{
				printf("未计算总分,无法排序，按任意键继续......");
			}
			getche(); 
			break;
		case 5:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low by number:\n");
			head = SortbyNumber1(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 6:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from low to high by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 7:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Chinese:\n");
			head = SortbyChinese(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 8:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Maths:\n");
			head = SortbyMaths(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 9:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by English:\n");
			head = SortbyEnglish(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 10:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by Aver:\n");
			head = SortbyAver(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;

		case 11:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);     //排序后返回头指针    
			Print(head, n, m);				//打印  头指针指向的内容 
			printf("数据排序完毕!按任意键继续......");
			getche();
			break;
		case 12:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			printf("按任意键继续......");
			getche();	
			break;
		case 13:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 14:
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			head = deleteStu(head, &n, m);    //只需要返回头指针    其他的细节在 deleteStu()中实现 
			printf("按任意键继续......");
			getche();
			break;
		case 15:
			system("cls");  
			printf("\n\n\n");
			addStu(head, &n, m);
			printf("添加成功！按任意键继续......");
			getche();
			break;
		case 16:
			system("cls");
			printf("\n\n\n");
			Modify(head, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 17:
			system("cls");  
			printf("\n\n\n");
			topStu(head, m);
			printf("按任意键继续......");
			getche();
			break;
		case 18:
			system("cls");  
			printf("\n\n\n");
			failStu(head, m);
			printf("按任意键继续......");
			getche();
			break;
		case 19:
			system("cls");  
			printf("\n\n\n");
			Print(head, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 20:
			system("cls");
			printf("\t\t\t请在执行相应计算操作后保存至相应文件中，计算、排序后将无法再进行原始数据保存\n");
			printf("\t\t\t提示：按照提示的文件名保存\n");
			printf("\t\t\tplease input file name(RawData.xls StatisticalData.xls ComprehensiveScoresOfStudents.xls  or .txt): ");
			fflush(stdin);
			gets(filename);
			WritetoFile(head, filename, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 21:
			system("cls");
			head = ReadfromFile(head, &n, &m);
			printf("按任意键继续......");
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
函数功能：显示菜单 
参数：无 
返回值：用户选择的菜单序号
注意：  在使用 1 输入后 如果继续使用 1 ，会覆盖之前的内容  
        新加的记录请使用   11 
*/
int   Menu(void)
{
	int i;
	system("title 学生成绩管理系统");
	printf("\t\t\t                      ******  *****  *       *   ******                          \n");
	printf("\t\t\t                      *         *    * *   * *   *                               \n");
	printf("\t\t\t                      ******    *    *   *   *   ******                          \n");
	printf("\t\t\t                           *    *    *   *   *        *                          \n");
	printf("\t\t\t                      ******  *****  *       *   ******                          \n");
	printf("\t\t\t                                学生成绩管理系统\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t|     -------->> 1.  Input record （Once）  (Can be overrided)               |\n");
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
函数功能：创建链表       用于添加记录 
参数：学生人数、课程数目 
返回值：链表头结点 
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
函数功能：创建空链表   用于读取文件 
参数：学生人数、课程数目 
返回值：链表头结点 
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
函数功能：计算每门课程平均分、总分 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*/
void  AverSumofEveryCourse(STU *head, int n, int m)
{
	STU *p;
	int i;
	char ch;
	float sum;
	
	memset(Course, 0, sizeof(Course));                  //初始化数组Course 
	p = head;
	if (head != NULL)									/*防止没有输入学生信息head=NULL时而进行head->next错误操作*/
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
函数功能：计算每名学生总分、平均分 
参数：链表头结点、学生人数、课程数目 
返回值：无 
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
函数功能：按学生总分从高到底排名 
参数：链表头结点、学生人数 
返回值：链表头结点 
*/
STU  *SortbyScore(STU *head, int n)   //冒泡排序 
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;
	int data = -1, ranknum = 0;//给学生排名的中间变量 
	
	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p) 
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)//如果一次都没交换，显然p = head，即已经排好序，外面循环则终止 
		{
			if (p1->next->sum < p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;			//		例如链表p1->a->b->c->......										 
				p1->next->next = p2->next;		//		先把b保存到p2，即p2 =  p1->next->next							
				p2->next = p1->next;			//		再让a下一个指向c,a->c；b下一个指向a，b->a。						
				p1->next = p2;					//		再让p1指向p2，即p1指向b：p1->b									
				p = p1->next->next;				//		综合上面即可得出：p1->b->a->c; 									
			}									//		p = a? 若后面都没再交换，显然，从a->c->......后面都已经排好序了	 
		}										//		则下一次循环比较时只需检查a节点之前的排序情况了 
	}
	
	p1 = head;               //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);                //释放p1
	
	//总分从高到低排完序后给每个同学排名，相同总分名次并列 
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
函数功能：按学生学号从大到小排序 
参数：链表头结点、学生人数
返回值：链表头结点 
*/
STU  *SortbyNumber1(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num < p1->next->next->num)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}
/*
函数功能：按学生学号从小到大排序 
参数：链表头结点
返回值：链表头结点 
*/
STU *SortbyNum(STU *head)    //插入法排序 
{
	STU *first;    //为原链表剩下用于直接插入排序的节点头指针
	STU *t;        //临时指针变量：插入节点
	STU *p, *q;     //临时指针变量,q作为有序链表的头,p保存前一个节点 

	if(head == NULL)
	{
		return head;
	}
	first = head->next;      //原链表剩下用于直接插入排序的节点链表
	head->next = NULL;       //将第一个节点作为第一个有序链表

	while (first != NULL)        //遍历剩下无序的链表
	{
		//注意：这里for语句就是体现直接插入排序思想的地方
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //遍历有序链表，无序节点在有序链表中找插入的位置

		first = first->next; //无序链表中的节点离开，以便它插入到有序链表中

		if (q == head)      //插在第一个节点之前
		{
			head = t;
		}
		else            //p是q的前驱
		{
			p->next = t;
		}
		t->next = q;     //完成插入动作
						 //first = first->next;
	}
	return head;
}

/*
函数功能：按学生语文成绩由高到低排序 
参数：链表头结点
返回值：链表头结点 
*/
STU  *SortbyChinese(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[0] < p1->next->next->score[0])  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
	
} 

/*
函数功能：按学生数学成绩由高到低排序 
参数：链表头结点
返回值：链表头结点 
*/
STU  *SortbyMaths(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[1] < p1->next->next->score[1])  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
} 

/*
函数功能：按学生英语成绩由高到低排序 
参数：链表头结点
返回值：链表头结点 
*/
STU  *SortbyEnglish(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[2] < p1->next->next->score[2])  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}				

/*
函数功能：按学生平均分由高到低排序 
参数：链表头结点
返回值：链表头结点 
*/
STU  *SortbyAver(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->aver < p1->next->next->aver)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
} 

/*
函数功能：按学生名字的字母顺序排序 
参数：链表头结点、学生人数
返回值：链表头结点 
*/
STU  *SortbyName(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name)>0)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;     //结合第4点理解
				p = p1->next->next;   //结合第6点理解
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}

/*
函数功能：打印链表（学生信息） 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*/
void Print(STU *head, int n, int m)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)        //只要不是空链表，就输出链表中所有节点
	{
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t%15s\t%s\t", "学号", "姓名"); 
		for(i = 0; i < m; i++)
		{
			printf("%s\t", courseName[i]);
		}
		printf("%s\t%s\t%s\n", "总分", "平均分", "排名"); 
		do
		{

			printf("\t\t\t%15lld\t%s\t", p->num, p->name);
			for (i = 0; i<m; i++)
			{
				printf("%.1f\t", p->score[i]);
			}
			printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;     //移到下一个节点
		} while (p != NULL);
		printf("\t\t\t******************************************************************************\n");
	}
}
/*
函数功能：打印每名课程信息 
参数：课程数目
返回值：无 
*/
void print1(int courseNum)
{
	int i;
	
	printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "course", "sum", "averscore","<60(不及格)", "[60,70)", "[70,80)", "[80,90)", ">=90","通过数");
	for(i = 0; i < courseNum; i++)
	{
		printf("\t\t\t%s\t%.1f\t%.1f\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", courseName[i], Course[i].sumscore, Course[i].avescore, Course[i].sectionNum[0],
										  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4],Course[i].sectionNum[1]+Course[i].sectionNum[2]+Course[i].sectionNum[3]+Course[i].sectionNum[4]);
	}
}


/*
函数功能：输入学号搜索学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
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
				printf("\t\t\t%s\t%s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "总分", "平均分", "排名");
				
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
函数功能：输入学生名字搜索学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
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
				printf("\t\t\t%s\t%s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "总分", "平均分", "排名");
				
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
函数功能：输入学号删除学生 
参数：链表头结点、学生人数、课程数目 
返回值：新的链表头结点 
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
				printf("\t\t\t%s\t%s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%s\t", courseName[i]);
				}
				printf("%s\t%s\t%s\n", "总分", "平均分", "排名");
				
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
					printf("删除成功！按任意键继续......");
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
函数功能：输入学号添加学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
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
		flag = CheckNum(head,p1->num);  //传递头指针 是检查是否重复 
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
			flag = CheckNum(NULL,p1->score[j]);  //检查是否大于 0  
			while(flag != 0)
			{
				printf("\t\t\tInput error!!!\n");
				printf("\t\t\t");
				scanf("%f", &p1->score[j]);
				flag = CheckNum(NULL,p1->score[j]);  //检查是否大于 0  
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
	//将新添加的学生链表连在原链表尾 
	p2 = head;
	while(p2->next)
	{
		p2 = p2->next;
	}
	p2->next = Nhead;
}
/*
函数功能：输入学号修改学生信息 
参数：链表头结点、学生人数、课程数目 
返回值：无 
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
					printf("\t\t\t%s\t\t%s\t", "学号", "姓名"); 
					for(i = 0; i < m; i++)
					{
						printf("%s\t", courseName[i]);
					}
					printf("%s\t%s\t%s\n", "总分", "平均分", "排名");
					
					printf("\t\t\t");
					printf("%lld\t%s\t", p->num, p->name);
					for (i = 0; i<m; i++)
					{
						printf("%.1f\t", p->score[i]);
					}
					printf("%.1f\t%.1f\t%d\n", p->sum, p->sum / m, p->rankNum);
					
					printf("\t\t\tplease input the modified information:\n");
					printf("\t\t\t%s\t\t%s\t", "学号", "姓名"); 
					for(i = 0; i < m; i++)
					{
						printf("%s\t", courseName[i]);
					}
					printf("\n\t\t\t");
					scanf("%lld", &p->num);
					flag = CheckNum(NULL,p->num);  //传递头指针 是检查是否重复 
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
						flag = CheckNum(NULL,p->score[i]);  //检查是否大于 0  
						while(flag != 0)
						{
							printf("\t\t\tInput error!!!\n");
							printf("\t\t\t");
							scanf("%f", &p->score[i]);
							flag = CheckNum(NULL,p->score[i]);  //检查是否大于 0  
						}
					}
					flag = 0;
					printf("修改成功！"); 
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
函数功能：保存至相应文件   使用不同的文件名 
参数：链表头结点、文件名、学生人数、课程数目 
返回值：无
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
		fprintf(fp,"%s\t%d\t%s\t%d\n","学生总数：",n,"课程数：",m);
		fprintf(fp, "%s\t%s\t", "学号", "姓名"); 
		for(i = 0; i < m; i++)
		{
			fprintf(fp, "%s\t", courseName[i]);
		}
		fprintf(fp, "%s\t%s\t%s\n", "总分", "平均分", "排名");
		
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
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "课程", "课程总分", "课程平均分", "<60(不及格)", "[60,70)", "[70,80)", "[80,90)", ">=90","通过数");
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
函数功能：筛选优等生 并保存至文件 
参数：链表头结点、学生人数
返回值：无 
*/
void topStu(STU *head, int n)
{
	STU *p = head;
	FILE *fp;
	int i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 1, count = 0;  //优等生三个条件 标志  
	
	if((fp = fopen("SuperiorStudent.xls", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		flag4 = 0;
	}
	fprintf(fp, "%s\t%s\n", "学号", "姓名"); 
	for(; p; p= p->next)
	{
		flag1 = 0;//初始化三个条件都不满足 
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
		if(flag1 || flag2 || flag3)   //满足一个就是优等生    此逻辑可以更改  
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
		printf("无优等生!");
		if(flag4)
		fprintf(fp, "无优等生"); 
	}
	else
	{
		printf("优等生共%d人\n", count);
		if(flag4)
		fprintf(fp, "\t优等生共%d人\n", count);
	}
	fclose(fp);
}
/*
函数功能：查找学生不及格科目信息并保存 
参数：链表头结点、学生人数
返回值：无 
*/
void failStu(STU *head, int n)
{
	STU *p = head;
	int i, flag1 = 0, flag2 = 1, flag3 = 1;
	FILE *fp;
	
	if((fp = fopen("FailingSubjects.xls", "w")) == NULL)
	{
		printf("打开文件失败\n");
		flag3 = 0;
	}
	
	fprintf(fp, "%s\t%s\t", "学号", "姓名"); 
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
						fprintf(fp,"%s\t","过关");
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
		printf("无不及格学生\n");
		if(flag3)
		{
			fprintf(fp, "无不及格学生\n");
		}
	}
	fclose(fp);
}


/*
Read records  from local file 

The file must be in special form
You can see it in example.txt and example.xls

Note：Can only read from *.txt and *.xls
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
	fscanf(fp,"%s\t%d\t%s\t%d\n",temp1,n,temp2,m);            //把头部读掉 
	fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);  //把头部读掉 
	head = CreatEmpty(*n, *m);         
	p = head;						//创建一个空链表 
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


