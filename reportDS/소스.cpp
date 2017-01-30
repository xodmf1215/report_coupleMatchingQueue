#include <stdio.h>
#include <string.h>

struct Queue{
	char waitList[10][10];
	int num=0;
	int front=0;
	int rear=0;
}; //ť�� ���� ����ü�� �����Ѵ�.

void insertQ(Queue*, char *); //�ť�� ����� ��������
char* deleteQ(Queue*); //�ť�� front���� �����ð���
int isFull(Queue*); //�ť�� �����ִ���
int isEmpty(Queue*); //�ť�� ����ִ���

void main()
{
	Queue mq;
	Queue gq; //ť�� ���ڿ� ť�� ���ڿ� ť �ΰ����� �ִ�.
	char name[10];
	int cnt;
	printf("���� �ּ� ���α׷��Դϴ�\n");
	while (1) {
		printf("�� �̸� : ");
		cnt = 0;
		char gender;
		while (1) { //���̸��� �Է¹޴� while��
			scanf("%c", &name[cnt]);
			if (name[cnt] == '\n' || cnt > 8) //�̸��� 9char�� �Ѱų� ����Ű�� �ԷµǸ� �ι��ڷ� ������
			{
				name[cnt] = '\0';
				break;
			}
			cnt++;
		}
		printf("������ �Է��ϼ���(f or m) : ");
		scanf("%c", &gender);
		getchar();
		if (gender != 'f' && gender != 'm') break; //�����Է¶����� �̻��� ���� ������ �����ϵ��� �Ѵ�.
		if (gender == 'm') //�����ϰ��� ������ ��� �ť�� �˻��ϴ����� �ٸ��� ������ �Ȱ���.
		{
			if (isEmpty(&gq) == 0) //���ڰ� �ԷµǾ����� ����ť�� ������� ����� �ִ��� �˻��Ѵ�. ���� ������� ������
			{
				char nametmp[10];
				char *nt=nametmp;
				strcpy(nt,deleteQ(&gq)); // ���ڸ� �������� Ŀ��ź�� �޽����� ����Ѵ�.
				printf("Ŀ���� ź���Ͽ����ϴ�! %s ��%s\n", nt, name);
			}
			else //����ť�� ������� ����� ������ ���ڸ� ť�� �־�� �Ѵ�. �� ������
			{
				if (isFull(&mq) == 1) // ����ť�� ���� ��������
				{
					printf("��� �ο��� ���� á���ϴ�.\n"); //��� �ο��� �������� ����������.
				}
				else
				{
					insertQ(&mq, name); //����ť�� ��������� ����ť�� ����� �ְ�
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ּ���\n"); // ����ť�� ����ִٴ� �޽����� ����Ѵ�.
				}
			}
		}
		if (gender == 'f')//���ڰ� �ԷµǾ����� ����ť�� ������� ����� �ִ��� �˻��Ѵ�. ���� ������� ������
		{
			if (isEmpty(&mq) == 0)
			{
				char nametmp[10];
				char *nt = nametmp;
				strcpy(nt,deleteQ(&mq));//����ť���� front�� �ϳ� ��������
				printf("Ŀ���� ź���Ͽ����ϴ�! %s ��%s\n", nametmp, name);//Ŀ�� ź�� �޽����� ����Ѵ�.
			}
			else //����ť�� ��������� ���ڸ� ����ť�� �ְ� ����ť�� ����ִٴ� �޽����� ����ؾ��Ѵ�. �� ������
			{
				if (isFull(&gq) == 1) //�켱 ����ť�� ���ڸ� ���� �� ������ ���ٰ� ����ϰ�
				{
					printf("��� �ο��� ���� á���ϴ�.\n");
				}
				else //���� ����ť�� ���ڸ� ���� �� ������
				{
					insertQ(&gq, name);
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ּ���\n"); //����ť�� ����ִٴ� �޽����� ����ؾ��Ѵ�.
				}
			}
		}
	}
}
void insertQ(Queue *ps, char *name) {
	//ps->waitList[ps->rear] = name;
	strcpy(ps->waitList[ps->rear], name);
	ps->rear++;
}
char* deleteQ(Queue *ps) {
	ps->front++;
	return ps->waitList[(ps->front) - 1];
}
int isFull(Queue *ps) {
	return (ps->rear == 9); //������ �ִ�ũ���� 9�̸� ��������.
}
int isEmpty(Queue *ps) {
	return (ps->front == ps->rear); //���۰� ���� ������ ���.
}