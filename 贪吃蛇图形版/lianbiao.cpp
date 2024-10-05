#include<stdio.h>
#include<stdlib.h>
#include<lianbiao.h>


//typedef struct note
//{
//	int data;
//	struct note* next;
//}list;//����ṹ

list* create(int x)
{
	list* p = (list*)malloc(sizeof(list));
	if (p == NULL)
	{
		printf("����ʧ��\n");
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}//�����ڵ�

void printlist(list* p)
{

	if (p == 0)
	{
		printf("������\n");
		return;
	}
	else
	{
		printf("%d->", p->data);
	}
	if ((p != 0) && (p->next) != NULL)
	{
		printlist(p->next);
	}
	else
	{
		printf("��ӡ���\n");
	}

}//��ӡ����


 void  printlistall(list* p)//��ӡ�б�������Ϣ
{
	if (p == 0)
	{
		printf("������\n");
		return;
	}
	else
	{
		printf("data:%d,direction:%d,x:%d,y:%d\n", p->data, p->direction, p->x, p->y);
	}
	if ((p != 0) && (p->next) != NULL)
	{
		printlistall(p->next);
	}
	else
	{
		printf("��ӡ���\n");
	}

}

void last(list** pp, int x)//(&p,x)
{
	list* temp = *pp;
start:
	if ((temp)->next != NULL)
	{
		temp = (temp)->next;
		goto start;
	}

	(temp)->next = create(x);
}//��������ڵ�

void first(list** pp, int x)//(&p,x)
{
	list* newhead = create(x);
	if (*pp == NULL)
	{

		*pp = newhead;
	}
	else
	{
		newhead->next = *pp;
		*pp = newhead;
	}
}//����ǰ����ڵ�

void  changefirsttype(list** pp, int tp)//(&p,x)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		(*pp)->type = tp;		
	}

}//�޸ĵ�һ���ڵ�

void  defirst(list** pp)//(&p,x)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	else
	{
		list* temp = *pp;
		*pp = (*pp)->next;
		free(temp);
	}

}//ɾ����һ���ڵ�

void  delast(list** pp)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}

	list* current = *pp;
	list* previous = NULL;

	// �ҵ������ڶ����ڵ�
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	// �������ֻ��һ���ڵ�
	if (previous == NULL)
	{
		free(*pp);
		*pp = NULL;
	}
	else
	{
		free(current);
		previous->next = NULL;
	}
}//ɾ�����һ���ڵ�

void  changelasttype(list** pp, int tp)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->type = tp;
	}

}//�޸����һ���ڵ�����

void  changelastdirection(list** pp, int di)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->direction = di;
	}
}

void  changelastx(list** pp, int di)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->x = di;
	}
}

void  changelastdata(list** pp, int di)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->data = di;
	}
}

void  changelasty(list** pp, int di)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->y = di;
	}
}

int getlastdirection(list** pp)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return 0;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->direction;
	}
}


int getlastx(list** pp)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return 0;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->x;
	}
}

int getlasty(list** pp)
{
	if (*pp == NULL)
	{
		printf("����Ϊ�գ��޷��޸�\n");
		return 0;
	}
	else
	{
		list* temp = *pp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->y;
	}
}

list* lian(int x, int* arr)
{

	if (x <= 0)
	{
		printf("�޽ڵ㣬����Ϊ��\n");
		return NULL;
	}
	else
	{
		list* start = create(arr[0]);
		list* temp = start;
		int i = 1;
		for (i; i < x; i++)
		{
			start->next = create(0);
			start = start->next;
			start->data = arr[i];

		}
		return temp;
	}
}//��������

void freelian(list** p)//(&li)
{
	list* li = *p;
	if (*p == NULL)
		return;
	if (li->next != NULL)
	{
		freelian(&(li->next));
	}
	if (li->next == NULL)
	{
		free(li);
		li = NULL;
	}
	free(li);
	*p = NULL;
}//�ͷ�����

int delone(int x, list** pp)
{


	list* f = *pp;
	list* b = NULL;
	if (f->data == x)
	{
		defirst(pp);
		return 1;
	}
	else
	{
		while (f->next != NULL)
		{
			if (f->data == x)
			{
				b->next = f->next;
				free(f);
				return 1;
			}
			b = f;
			f = f->next;
		}
		//printf("δ�ҵ�%d\n", x);
		return 0;
	}
}//ɾ���׸�ָ���ڵ�

int  delall(int x, list** pp)
{
	int flag = 0;
start:
	if (delone(x, pp))
	{
		flag++;
		goto start;
	}
	return flag;
}//ɾ������ָ���ڵ�

void addlist(list** pp, int x, int* nump)
{
	if (pp == NULL)
	{
		*pp = lian(x, nump);
		printf("����Ϊ�գ��Ѵ���\n");
		return;
	}
	list* temp = *pp;
	if (temp == NULL)
	{
		*pp = lian(x, nump);
		printf("����Ϊ�գ��Ѵ���\n");
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = lian(x, nump);
	printf("�����\n");
	return;
}//β���������
//
//int main()
//{
//
//	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	list* lianbiao = NULL;
//	printlist(lianbiao);
//	addlist(&lianbiao, 6, arr2);
//	printlist(lianbiao);
//	defirst(&lianbiao);
//	printlist(lianbiao);
//	delast(&lianbiao);
//	printlist(lianbiao);
//	delall(3, &lianbiao);
//	printlist(lianbiao);
//	freelian(&lianbiao);
//	printlist(lianbiao);
//
//
//	return 0;
//}

