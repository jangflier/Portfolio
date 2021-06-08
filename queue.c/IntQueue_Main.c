#include <stdio.h>
#include "IntQueue.h"

/* C�� �̿��� Int�� ť �ڷᱸ���� �����߽��ϴ�.
*  Int�� Ÿ�Ը� ����� �� �ֽ��ϴ�.
*  �Լ��� ���� �ڼ��� ������ IntQueue_Function.c �ҽ����Ͽ� �ֽ��ϴ�.
*/

// --- main ---
int main(void)
{
	IntQueue queue; // ������ Ÿ���� IntQueue�� queue������ �����մϴ�.
	int size;

	// -- ť ũ�� �Է� --
	while (1) {
		printf("\nť�� ũ�⸦ �Է��� �ּ��� : ");
		if ((size = IntScanf()) == -1) {
			puts("\a������ �Է��� �ּ���!!");
			continue;
		}
		else if (size <= 0) {                       // 0�� ���ų� ���� ���� �Է��ϸ� ���Է��� �䱸�մϴ�.
			puts("\a0���� ū ������ �Է��� �ּ���!!");
			continue;
		}
		else if (Initialize(&queue, size) == -1) {  // ���Ƿ� �迭 ũ�⸦ 5�� ���ϰ�, �ʱ�ȭ �Լ��� ť ����ü�� �ʱ�ȭ�մϴ�.
			puts("\ať ������ �����߽��ϴ�.");      // ť ������ ������ ���, 1�� ��ȯ�մϴ�.
			return 1;
		}
		else                                        // ���� �� ������ �ƴ� ������ ���, ���ѷ������� �������ɴϴ�.
			break;
	}
	// -----

	// -- �޴� ��� �� ���� --
	while (1) {
		int menu, x; // menu : �޴� ���� �� ���Ǵ� �����̸�, x ; �Լ��� �Է°��� �����ϴ� �뵵�� ���˴ϴ�.
		int index;   // search�Լ��� ��ȯ���� ������ �뵵�� ����մϴ�. �Լ��� ���� �� ȣ���ϴ� ���� ���� ������ ����ŵ�ϴ�.

		// -- �޴� ��� �� ���� --
		printf("\n���� ������ �� : %d / %d\n", Size(&queue), Capacity(&queue));
		printf("1.��ť   2.��ť   3.��ũ  4.ť ����  5.������ �˻�  6.��� 0.����\n");
		printf("��ȣ�� ���ּ��� : ");
		if ((menu = IntScanf()) == -1) { // ���ڸ� �Է����� ���, �޴��� �ٽ� ȣ���մϴ�.
			puts("\a������ �Է��� �ּ���!!");
			continue;
		}


		// -- �Լ� ���� --
		if (menu == 0) break; // ��ȣ 0�� �Է����� ���, while���� ���� ���ͼ�, terminate�Լ��� ���� �� ���α׷� �����մϴ�.
		else if (menu < 0 || menu>6) { // �޴��� �ִ� 0���� 6�� ������ ���� �ƴ� ���, continue������ �޴��� �ٽ� ȣ���մϴ�.
			puts("\a��ȣ�� �߸� �Է� �߽��ϴ�! 0���� 6������ ��ȣ�� ������ �ּ���.");
			continue;
		}
		switch (menu) // �Էµ� ��ȣ�� ���� case�� �����մϴ�.
		{
		case 1: // ENQUEUE
			printf("ENQUEUE�� �������� ���� �Է��� �ּ��� : ");
			if ((x = IntScanf()) == -1) {
				puts("\a������ �Է��� �ּ���!!");
				break;
			}
			else if (Enqueue(&queue, x) == -1)
				puts("\aERROR : ENQUEUE�� �����߽��ϴ�!(-1)");
			break;

		case 2: // DEQUEUE
			if (Dequeue(&queue, &x) == -1)
				puts("\aERROR : DEQUEUE�� �����߽��ϴ�!(-1)");
			else
				printf("DEQUEUE������ : %d\n", x);
			break;

		case 3: // PEEK
			if (Peek(&queue, &x) == -1)
				puts("\aERROR : ��ũ�� �����߽��ϴ�.(-1)");
			else
				printf("PEEK������ : %d\n", x);
			break;

		case 4: // CLEAR
			Clear(&queue);
			puts("ť�� ������ϴ�.\n");
			break;

		case 5: // SEARCH
			printf("ť ������ �˻��� ���� �Է��� �ּ��� : ");
			if ((x = IntScanf()) == -1) {
				puts("\a������ �Է��� �ּ���!!");
				break;
			}
			else if ((index = Search(&queue, x)) == -1) // �Լ��� ���� �� ȣ��Ǿ� ������ ���ϵǴ� ���� ���� ���ؼ� index������ ��ȯ ���� �����մϴ�.
				puts("\a���ϴ� ���� ã�� ���߽��ϴ�.(-1)");
			else
				printf("queue[%d]���� %d���� ã�ҽ��ϴ�.\n", index, x);
			break;

		case 6: // PRINT
			puts("ť ���� ��� ������ ���(front���� rear����)");
			Print(&queue);
			break;
		} // switch�� ��
	} // while�� ��

	Terminate(&queue); // ���ѷ����� ����Ǹ� �ڵ����� Terminate�Լ��� �����Ͽ� ť�� ������ �ݴϴ�.
	return 0;
}