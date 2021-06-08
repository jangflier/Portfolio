#include <stdio.h>
#include "IntStack.h"

/* C�� �̿��� Int�� ���� �ڷᱸ���� �����߽��ϴ�.
*  Int�� Ÿ�Ը� ����� �� �ֽ��ϴ�.
*  �Լ��� ���� �ڼ��� ������ IntStack_Function.c �ҽ����Ͽ� �ֽ��ϴ�.
*/

// --- main ---
int main(void)
{
	IntStack stack; // ������ Ÿ���� IntStack�� stack������ �����մϴ�.
	int size;       // ������ ũ�⸦ �����ϴ� �����Դϴ�.

	// -- ���� ũ�� �Է� --
	while (1) {		
		printf("\n������ ũ�⸦ �Է��� �ּ��� : ");
		if ((size = IntScanf()) == -1) {
			puts("\a������ �Է��� �ּ���!!");
			continue;
		}
		else if (size <= 0) {                       // 0�� ���ų� ���� ���� �Է��ϸ� ���Է��� �䱸�մϴ�.
			puts("\a0���� ū ������ �Է��� �ּ���!!");
			continue;
		}
		else if (Initialize(&stack, size) == -1) {  // ���Ƿ� �迭 ũ�⸦ 5�� ���ϰ�, �ʱ�ȭ �Լ��� ���� ����ü�� �ʱ�ȭ�մϴ�.
			puts("\a���� ������ �����߽��ϴ�.");    // ���û����� ������ ���, 1�� ��ȯ�մϴ�.
			return 1;
		}
		else                                        // ���� �� ������ �ƴ� ������ ���, ���ѷ������� �������ɴϴ�.
			break;
	}
	// -----

	// -- �޴� ��� �� ���� --
	while (1) {
		int menu, x; // menu�� �޴������� ���� �����̰�, x�� �Էµ� ���� �����ϴ� �뵵�� ���˴ϴ�.
		int index;   // search�Լ��� ��ȯ���� ������ �뵵�� ���˴ϴ�.

		printf("\n���� ������ �� : %d / %d\n", Size(&stack), Capacity(&stack));
		printf("1.Ǫ��   2.��   3.��ũ  4.���� ����  5.������ �˻�  6.��� 0.����\n");
		printf("��ȣ�� �Է��� �ּ��� : ");
		if ((menu = IntScanf()) == -1) { // ���ڸ� �Է����� ���, �޴��� �ٽ� ȣ���մϴ�.
			puts("\a������ �Է��� �ּ���!!");
			continue;
		}


		// -- �Լ� ���� --
		else if (menu == 0) break;            // ��ȣ 0�� �Է����� ���, while���� ���� ���ͼ�, terminate�Լ��� ���� �� ���α׷� �����մϴ�.
		else if (menu < 0 || menu>6) {   // �޴��� �ִ� 0���� 6�� ������ ���� �ƴ� ���, continue������ �޴��� �ٽ� ȣ���մϴ�.
			puts("\a��ȣ�� �߸� �Է� �߽��ϴ�! 0���� 6������ ��ȣ�� ������ �ּ���.");
			continue;
		}
		switch (menu) // �Էµ� ��ȣ�� ���� case�� �����մϴ�.
		{
		case 1: // PUSH
			printf("PUSH�� �������� ���� �Է��� �ּ��� : ");
			if ((x = IntScanf()) == -1) {
				puts("\a������ �Է��� �ּ���!!");
				break;
			}
			else if(Push(&stack, x) == -1)
				puts("\aERROR : PUSH�� �����߽��ϴ�!(-1)");
			break;

		case 2: // POP
			if (Pop(&stack, &x) == -1)
				puts("\aERROR : POP�� �����߽��ϴ�!(-1)");
			else
				printf("POP������ : %d\n", x);
			break;

		case 3: // PEEK
			if (Peek(&stack, &x) == -1)
				puts("\aERROR : ��ũ�� �����߽��ϴ�.(-1)");
			else
				printf("PEEK������ : %d\n", x);
			break;

		case 4: // CLEAR
			Clear(&stack);
			puts("������ ������ϴ�.\n");
			break;

		case 5: // SEARCH
			printf("���� ������ �˻��� ���� �Է��� �ּ��� : ");
			if ((x = IntScanf()) == -1) {
				puts("\a������ �Է��� �ּ���!!");
				break;
			}
			else if ((index = Search(&stack, x)) == -1)
				puts("\a���ϴ� ���� ã�� ���߽��ϴ�.(-1)");
			else
				printf("stack[%d]���� %d���� ã�ҽ��ϴ�.\n", index, x);
			break;

		case 6: // PRINT
			puts("���ó� ��� ������ ���(bottom���� top����)");
			Print(&stack);
			break;
		} // switch�� ��
	} // while�� ��

	Terminate(&stack); // ���ѷ����� ����Ǹ� �ڵ����� Terminate�Լ��� �����Ͽ� ������ ������ �ݴϴ�.
	return 0;
}