#include <stdio.h>

static count = 0; // 하노이의 탑의 옮긴 횟수를 저장하기 위한 변수입니다. 함수 내에서 count의 변수에 접근할 수 있게 전역변수로 설정했습니다.

/* -- 하노이의 탑(재귀함수로 구현) --
* 게임 규칙 1. 게임 승리 조건 : 최소한의 움직임으로 3개의 기둥 중 목표 기둥에 모든 원반을 옮겨놓아야 합니다.
*           2. 한 번에 하나의 원반만 이동시킬 수 있습니다.
*           3. 큰 원반은 작은 원반 위에 올려놓을 수 없습니다.
*           4. 기둥은 3개입니다.
*
* 하노이의 탑을 재귀함수로 푸는 이유 :
* for문과 if문으로 하노이의 탑을 구현하면 매우 복잡해지지만
* 재귀함수로 구현할 경우, 아래처럼 짧은 코드만으로 구현이 가능해지고 가독성이 좋아집니다.
*
* 종료 조건 : num == 1일 때 종료(0의 원반은 존재하지 않으므로)
* 문제 정의 : 1. num개의 원반을 옮기기 위해서는 num-1개의 원반이 중간 기둥에 옮겨져 있어야 합니다.
*             2. 가장 큰 원반이 목적 기둥으로 옮겨져야 합니다.
*             3. 중간 기중에서 n-1개의 원반을 목적 기둥으로 모두 옮깁니다.
*/
void Towers_of_Hanoi(int num, int start, int goal) // num : 원반의 개수 / start : 시작 기둥 위치 / goal : 목표 기둥 위치
{
	if (num > 1) { // 하노이의 탑 탈출 재귀함수 탈출 조건은 num이 2보다 작을 때입니다. 즉 num은 1일 경우, 아래의 printf문을 출력하고 탈출합니다.
		Towers_of_Hanoi(num - 1, start, 6 - start - goal); // 6-start-goal은 시작 기둥과 목표 기둥이 어떤 기둥이 되었든 중간 기둥을 나타냅니다.
	}                                                      // 바닥 원반을 제외한 나머지의 원반들을 하나의 덩어리로 보고 시작 기둥에서 중간 기둥으로 옮깁니다.
	count++;// 출력한 후 count의 값을 1씩 증가시킵니다.
	printf("%d. 크기가 %d인 원반을 %d번 기둥에서 %d번 기둥으로 옮겼습니다.\n", count, num, start, goal);
	if (num > 1) {
		Towers_of_Hanoi(num - 1, 6 - start - goal, goal); // 바닥 원반을 제외한 나머지 원반 덩어리를 중간 기둥에서 목표 기둥으로 옮깁니다.
	}
}

/* -- 문자 입력을 제한하는 함수 --
* 숫자가 아닌 문자가 입력되었을 경우, 입력버퍼를 비워서 무한루프에 빠지는 것을 방지합니다.
*/
int IntScanf(void)
{
	int x;
	if (scanf_s("%d", &x) == 0) { // 문자가 입력되었을 경우, 입력버퍼를 비우고, -1을 반환합니다.
		rewind(stdin);
		return -1;
	}
	else // 문자 입력 외의 값이 입력된 경우, 입력되었던 값을 반환합니다.
		return x;
}


// -- main --
int main(void)
{
	int num;   // 기둥의 개수
	int start; // 시작 기둥의 위치
	int goal;  // 목표 기둥의 위치
	
	while (1) {
		printf("\n--재귀함수로 구현한 하노이탑--\n\n원반 개수를 입력하세요 : ");
		if ((num = IntScanf()) == -1) {
			puts("\a정수를 입력해 주세요!!");
			continue;
		}
		else if (num <= 0) {
			puts("\a\n원반의 개수는 1보다 작을 수 없습니다.");
			continue;
		}
		else if (num > 63) {
			puts("하노이의 탑은 \"64개의 황금 원반을 3개의 기둥 사이에서 바꿔 옮기는 작업을 완료하면 세계의 종말이 찾아온다.\"라는 고대 인도의 신화에서 유래했습니다!\n");
			break;
		}
		else {
			printf("원반의 개수는 %d개 입니다.\n", num);
			break;
		}
	}
	
	
	while (1) {
		// -- 시작 기둥 입력 --
		printf("\n1. 시작할 때 원반들이 위치할 기둥은 몇 번째 기둥입니까?(기둥은 1~3번 까지 있음) : ");
		if ((start = IntScanf()) == -1) {
			puts("\a정수를 입력해 주세요!!");
			continue;
		}
		else if (start <= 0 || start > 3) {
			puts("\a기둥의 번호는 1번에서 3번까지만 유효합니다.");
			continue;
		}

		// -- 목표 기둥 입력 --
		printf("\n2. 원반들의 목표 기둥은 몇 번째 기둥입니까?(기둥은 1~3번 까지 있음) : ");
		if ((goal = IntScanf()) == -1) {
			puts("\a정수를 입력해 주세요!!");
			continue;
		}
		else if (goal <= 0 || goal > 3) {
			puts("\a기둥의 번호는 1번에서 3번까지만 유효합니다.");
			continue;
		}
		else if (start == goal) {
			puts("\a시작 기둥과 목표 기둥은 같은 번호에서 시작할 수 없습니다.");
			continue;
		}
		else {
			Towers_of_Hanoi(num, start, goal);   // 재귀함수 호출
			printf("옮긴 횟수 : %d회\n", count); // 옮긴 횟수 출력
			puts("\n성공적으로 게임을 끝마쳤습니다.\n");
			break;
		}
	}

	return 0;
}