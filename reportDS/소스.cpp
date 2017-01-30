#include <stdio.h>
#include <string.h>

struct Queue{
	char waitList[10][10];
	int num=0;
	int front=0;
	int rear=0;
}; //큐를 위한 구조체를 선언한다.

void insertQ(Queue*, char *); //어떤큐에 어떤값을 넣을건지
char* deleteQ(Queue*); //어떤큐의 front값을 가져올건지
int isFull(Queue*); //어떤큐가 꽉차있는지
int isEmpty(Queue*); //어떤큐가 비어있는지

void main()
{
	Queue mq;
	Queue gq; //큐는 여자용 큐랑 남자용 큐 두가지가 있다.
	char name[10];
	int cnt;
	printf("미팅 주선 프로그램입니다\n");
	while (1) {
		printf("고객 이름 : ");
		cnt = 0;
		char gender;
		while (1) { //고객이름을 입력받는 while문
			scanf("%c", &name[cnt]);
			if (name[cnt] == '\n' || cnt > 8) //이름이 9char가 넘거나 엔터키가 입력되면 널문자로 마무리
			{
				name[cnt] = '\0';
				break;
			}
			cnt++;
		}
		printf("성별을 입력하세요(f or m) : ");
		scanf("%c", &gender);
		getchar();
		if (gender != 'f' && gender != 'm') break; //성별입력란에서 이상한 값이 들어오면 종료하도록 한다.
		if (gender == 'm') //남자일경우랑 여자일 경우 어떤큐를 검사하는지만 다르고 과정은 똑같다.
		{
			if (isEmpty(&gq) == 0) //남자가 입력되었으니 여자큐에 대기중인 사람이 있는지 검사한다. 만약 비어있지 않으면
			{
				char nametmp[10];
				char *nt=nametmp;
				strcpy(nt,deleteQ(&gq)); // 여자를 꺼내오고 커플탄생 메시지를 출력한다.
				printf("커플이 탄생하였습니다! %s 와%s\n", nt, name);
			}
			else //여자큐에 대기중인 사람이 없으면 남자를 큐에 넣어야 한다. 그 과정은
			{
				if (isFull(&mq) == 1) // 남자큐가 가득 차있으면
				{
					printf("대기 인원이 가득 찼습니다.\n"); //대기 인원이 가득차서 넣을수없다.
				}
				else
				{
					insertQ(&mq, name); //남자큐가 비어있으면 남자큐에 대상을 넣고
					printf("아직 대상자가 없습니다. 기다려주세요\n"); // 여자큐가 비어있다는 메시지를 출력한다.
				}
			}
		}
		if (gender == 'f')//여자가 입력되었으니 남자큐에 대기중인 사람이 있는지 검사한다. 만약 비어있지 않으면
		{
			if (isEmpty(&mq) == 0)
			{
				char nametmp[10];
				char *nt = nametmp;
				strcpy(nt,deleteQ(&mq));//남자큐에서 front를 하나 가져오고
				printf("커플이 탄생하였습니다! %s 와%s\n", nametmp, name);//커플 탄생 메시지를 출력한다.
			}
			else //남자큐가 비어있으면 여자를 여자큐에 넣고 남자큐가 비어있다는 메시지를 출력해야한다. 그 과정은
			{
				if (isFull(&gq) == 1) //우선 여자큐에 여자를 넣을 수 없으면 없다고 출력하고
				{
					printf("대기 인원이 가득 찼습니다.\n");
				}
				else //만약 여자큐에 여자를 넣을 수 있으면
				{
					insertQ(&gq, name);
					printf("아직 대상자가 없습니다. 기다려주세요\n"); //남자큐가 비어있다는 메시지를 출력해야한다.
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
	return (ps->rear == 9); //끝값이 최대크기인 9이면 가득찬것.
}
int isEmpty(Queue *ps) {
	return (ps->front == ps->rear); //시작과 끝이 같으면 빈것.
}