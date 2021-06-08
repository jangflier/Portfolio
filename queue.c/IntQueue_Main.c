#include <stdio.h>
#include "IntQueue.h"

/* C언어를 이용한 Int형 큐 자료구조를 구현했습니다.
*  Int형 타입만 사용할 수 있습니다.
*  함수에 대한 자세한 설명은 IntQueue_Function.c 소스파일에 있습니다.
*/

// --- main ---
int main(void)
{
	IntQueue queue; // 데이터 타입이 IntQueue인 queue변수를 생성합니다.
	int size;

	// -- 큐 크기 입력 --
	while (1) {
		printf("\n큐의 크기를 입력해 주세요 : ");
		if ((size = IntScanf()) == -1) {
			puts("\a정수를 입력해 주세요!!");
			continue;
		}
		else if (size <= 0) {                       // 0과 같거나 작은 수를 입력하면 재입력을 요구합니다.
			puts("\a0보다 큰 정수를 입력해 주세요!!");
			continue;
		}
		else if (Initialize(&queue, size) == -1) {  // 임의로 배열 크기를 5로 정하고, 초기화 함수로 큐 구조체를 초기화합니다.
			puts("\a큐 생성에 실패했습니다.");      // 큐 생성에 실패할 경우, 1을 반환합니다.
			return 1;
		}
		else                                        // 위의 두 조건이 아닌 조건일 경우, 무한루프에서 빠져나옵니다.
			break;
	}
	// -----

	// -- 메뉴 출력 및 선택 --
	while (1) {
		int menu, x; // menu : 메뉴 선택 시 사용되는 변수이며, x ; 함수의 입력값을 저장하는 용도로 사용됩니다.
		int index;   // search함수의 반환값을 저장할 용도로 사용합니다. 함수를 여러 번 호출하는 것을 막아 성능을 향상시킵니다.

		// -- 메뉴 출력 및 선택 --
		printf("\n현재 데이터 수 : %d / %d\n", Size(&queue), Capacity(&queue));
		printf("1.인큐   2.디큐   3.피크  4.큐 비우기  5.데이터 검색  6.출력 0.종료\n");
		printf("번호를 해주세요 : ");
		if ((menu = IntScanf()) == -1) { // 문자를 입력했을 경우, 메뉴를 다시 호출합니다.
			puts("\a정수를 입력해 주세요!!");
			continue;
		}


		// -- 함수 실행 --
		if (menu == 0) break; // 번호 0을 입력했을 경우, while문을 빠져 나와서, terminate함수를 실행 후 프로그램 종료합니다.
		else if (menu < 0 || menu>6) { // 메뉴에 있는 0에서 6번 사이의 값이 아닌 경우, continue문으로 메뉴를 다시 호출합니다.
			puts("\a번호를 잘못 입력 했습니다! 0부터 6사이의 번호를 선택해 주세요.");
			continue;
		}
		switch (menu) // 입력된 번호에 따라 case를 실행합니다.
		{
		case 1: // ENQUEUE
			printf("ENQUEUE할 데이터의 값을 입력해 주세요 : ");
			if ((x = IntScanf()) == -1) {
				puts("\a정수를 입력해 주세요!!");
				break;
			}
			else if (Enqueue(&queue, x) == -1)
				puts("\aERROR : ENQUEUE에 실패했습니다!(-1)");
			break;

		case 2: // DEQUEUE
			if (Dequeue(&queue, &x) == -1)
				puts("\aERROR : DEQUEUE에 실패했습니다!(-1)");
			else
				printf("DEQUEUE데이터 : %d\n", x);
			break;

		case 3: // PEEK
			if (Peek(&queue, &x) == -1)
				puts("\aERROR : 피크에 실패했습니다.(-1)");
			else
				printf("PEEK데이터 : %d\n", x);
			break;

		case 4: // CLEAR
			Clear(&queue);
			puts("큐를 비웠습니다.\n");
			break;

		case 5: // SEARCH
			printf("큐 내에서 검색할 값을 입력해 주세요 : ");
			if ((x = IntScanf()) == -1) {
				puts("\a정수를 입력해 주세요!!");
				break;
			}
			else if ((index = Search(&queue, x)) == -1) // 함수가 여러 번 호출되어 성능이 저하되는 것을 막기 위해서 index변수에 반환 값을 대입합니다.
				puts("\a원하는 값을 찾지 못했습니다.(-1)");
			else
				printf("queue[%d]에서 %d값을 찾았습니다.\n", index, x);
			break;

		case 6: // PRINT
			puts("큐 내의 모든 데이터 출력(front부터 rear까지)");
			Print(&queue);
			break;
		} // switch문 끝
	} // while문 끝

	Terminate(&queue); // 무한루프가 종료되면 자동으로 Terminate함수를 실행하여 큐를 해제해 줍니다.
	return 0;
}