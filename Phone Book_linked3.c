#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone {
	char name[10]; //이름
	char number[14]; //전화번호
	char memo[10]; //직장, 친구 등 간단한 메모
	struct phone* next;
}phone;

phone* addPerson(phone* head) // 알파벳 순으로 저장하기
{

	phone* new = (phone*)malloc(sizeof(phone));
	if (new == NULL) {
		printf("\n\n\t\t메모리가 부족합니다.");
		return head;
	}
	scanf("%s %s %s", new->name, new->number, new->memo);
	new->next = NULL;

	if (head == NULL) { // 첫 번째 노드 추가
		head = new;
	}
	else {
		int flag = 0;
		phone* temp = head;
		phone* back = NULL;
		while (temp != NULL && strcmp(temp->name, new->name) < 0) {
			back = temp;
			temp = temp->next;
			flag = 1;
		}
		if (flag == 0) {
			new->next = head;
			head = new;
		}
		else {
			back->next = new;
			new->next = temp;
		}
	}
	return head;
}

void print(phone* head)
{
	phone* tmp = head;
	if (tmp == NULL) {
		printf("\n\n\t\t저장된 사람이 없습니다.");
		return;
	}
	while (tmp != NULL) {
		printf("\n\n\t\t이름: %s 전화번호: %s 메모: %s", tmp->name, tmp->number, tmp->memo);
		tmp = tmp->next;
	}
}

phone* delPerson(phone* head, int delete, int max)
{
	phone* delPerson = head;
	phone* tmp = NULL;

	if (head == NULL || delete <= 0 || delete > max) {
		printf("\n\n\t\t삭제할 수 없습니다.");
		return head;
	}
	else {
		if (delete != 1) {
			for (int i = 1; i < delete; i++) {
				tmp = delPerson;
				delPerson = delPerson->next;
			}
			tmp->next = delPerson->next;
			free(delPerson);
			return head;
		}
		else {
			phone* del = head;
			head = del->next;
			free(del);
			return head;
		}
	}
}

phone* searchPerson(phone* head, char name[10])
{
	if (head == NULL) {
		printf("\n\n\t\t저장된 번호가 0개입니다.");
		return head;
	}
	phone* tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

phone* delPerson_byName(phone* head, char name[10])
{
	if (head == NULL)
		return head;
	else {
		phone* del = head;
		phone* tmp = NULL;
		while (del != NULL) {
			if (strcmp(del->name, name) == 0 && tmp != NULL) {
				tmp->next = del->next;
				free(del);
				return head;
			}
			if (strcmp(del->name, name) == 0) {
				head = head->next;
				free(del);
				return head;
			}
			tmp = del;
			del = del->next;
		}
		return head;
	}
}

int checkNum(phone* head)
{
	int count = 1;
	if (head == NULL)
		return 0;
	if (head->next == NULL)
		return 1;
	phone* tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		count++;
	}
	return count;
}

phone* freePhone(phone* head) // head를 NULL로 만들기
{
	if (head == NULL)
		return head;
	phone* tmp = head;
	while (head != NULL) {
		head = head->next;
		free(tmp);
		tmp = head;
	}
	return head;
}

int main(void) {
	printf("\t\t**전화번호부 작성하기**");
	int i, num = 0;
	phone* head = NULL;

	printf("\n\n\t\t1: 전화번호부 추가 2: 전화번호부 출력 3: 전화번호부 삭제_1 4: 전화번호부 검색 5: 전화번호부 삭제_2 6: 전화번호부 비우기 7: 전화번호부 종료");
	scanf("%d", &i); //i가 1이면 전화번호부에 추가

	while (i != 7) {
		switch (i) {
		case 1:
			printf("\n\n\t\t전화번호부 추가 : ");
			head = addPerson(head);
			num++;
			break;
		case 2:
			printf("\n\n\t\t전화번호부 출력 : ");
			print(head);
			break;
		case 3:
			printf("\n\n\t\t전화번호부 삭제\n\t\t몇 번을 삭제할까요? - by Index ");
			int delete;
			scanf("%d", &delete);
			head = delPerson(head, delete, num);
			num = checkNum(head);
			break;
		case 4:
			printf("\n\n\t\t전화번호부 검색 by Name: ");
			char name[10];
			scanf("%s", name);

			phone* tmp = searchPerson(head, name);
			if (tmp == NULL)
				printf("\n\n\t\t찾으시는 사람은 전화번호부에 없습니다.");
			else
				printf("\n\n\t\t이름: %s 전화번호: %s 메모: %s", tmp->name, tmp->number, tmp->memo);
			break;
		case 5:
			printf("\n\n\t\t전화번호부 삭제 by Name: ");
			char name2[10];
			scanf("%s", name2);
			head = delPerson_byName(head, name2);
			num = checkNum(head);
			break;
		case 6:
			printf("\n\n\t\t전화번호부 종료 ");
			head = freePhone(head);
			num = 0;
			break;
		}
		printf("\n\n\t\t1: 전화번호부 추가 2: 전화번호부 출력 3: 전화번호부 삭제_1 4: 전화번호부 검색 5: 전화번호부 삭제_2 6: 전화번호부 비우기 7: 전화번호부 종료");
		scanf("%d", &i); //i가 1이면 전화번호부에 추가
	}
}