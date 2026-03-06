#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10]; //이름
	char number[14]; //전화번호
	char memo[5]; //직장, 친구 등 간단한 메모
}phone;

phone list[40];

int main(void) {
	printf("\t\t**전화번호부 작성하기**");
	int i;
	int num = 0;
	do {
		printf("\n\n\t\t1: 전화번호부 추가 2: 전화번호부 출력 3: 전화번호부 삭제 4: 전화번호부 검색 5: 전화번호부 종료");
		scanf("%d", &i); //i가 1이면 전화번호부에 추가
;		switch (i) {
		case 1:
			printf("\n\n\t\t전화번호부 추가 : ");
			scanf("%s", list[num].name);
			scanf("%s", list[num].number);
			scanf("%s", list[num].memo);
			num++;
			break;
		case 2:
			printf("\n\n\t\t전화번호부 출력 : ");
			for (int p = 0; p < num; p++) {
				printf("\n\n\t\t이름:%s 전화번호:%s 메모:%s", list[p].name, list[p].number, list[p].memo);
			}
			break;
		case 3:
			printf("\n\n\t\t전화번호부 삭제\n\t\t몇 번을 삭제할까요? ");
			int delete;
			scanf("%d", &delete);
			if (delete > num || delete <= 0) {
				printf("\n\n\t\t잘못된 입력값입니다.");
				break;
			}
			for (int p = delete; p < num; p++) {
				list[p - 1] = list[p];
			}
			num--;
			break;
		case 4:
			printf("\n\n\t\t전화번호부 검색 : ");
			char name[10];
			int flag = 0;
			scanf("%s", name);
			for (int p = 0; p < num; p++) {
				if (strcmp(list[p].name, name) == 0) {
					printf("\n\n\t\t이름:%s 전화번호:%s 메모:%s", list[p].name, list[p].number, list[p].memo);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				printf("\n\n\t\t찾으시는 이름이 없습니다.");
			break;
		case 5:
			printf("\n\n\t\t전화번호부 종료 ");
			break;
		} 
	} while (num < 40 && i != 5);
}