#include<iostream>

using namespace std;

//�̷� ����
int maze[11][8] = {
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,0,1},
	{1,1,0,0,0,0,1,1},
	{1,0,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,0,1},
	{1,1,0,0,0,0,1,1},
	{1,0,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1}
};


//������ ����
#define EXIT_ROW 9
#define EXIT_COL 6

//���� ������ ��� ����
int mark[11][8];

//�̵� ������ ����
class Offset {
public:
	int ver;
	int hor;

	Offset(int ver, int hor) {
		this->ver = ver;
		this->hor = hor;
	}
};

//���� ��ġ ����
class Element {
public:
	int row;
	int col;
	int dir;
};

//��ġ�� �����ϴ� ���� ���� 
Element stack[100];
int top = -1;

//���� ��ġ�� �����ϴ� push �Լ�
void push(Element position) {
	stack[top].col = position.col;
	stack[top].row = position.row;
	stack[top++].dir = position.dir;
}

//���� ��ġ�� pop�ϴ� �Լ�
Element pop() {
	return stack[top--];
}


//����
int main() {
	//�̵��� �� �ִ� ��� ����
	Offset move[8] = {
						Offset(-1,0),//N����
						Offset(-1,1),//NE����
						Offset(0,1),//E����
						Offset(1,1),//SE����
						Offset(1,0),//S����
						Offset(1,-1),//SW����
						Offset(0,-1),//W����
						Offset(-1,-1) //NW����
	};

	//���� ����
	int row, col;
	int nextRow, nextCol;
	int dir;
	bool found = false;
	Element position;

	//���ÿ� ���� ��ġ�� ����
	top = 0;
	stack[0].row = 1; 
	stack[0].col = 1;
	stack[0].dir = 1;

	mark[1][1] = 1; //���� ��ġ�� ���� ��ġ�� �Է�

	cout << "========�̷�  ã��=========\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n��� ��ġ\n";
	cout << "(" << stack[0].row << "," << stack[0].col << ")\n";
	cout << "\n���Ա� ��ġ\n";
	cout << "(" << EXIT_ROW << "," << EXIT_COL << ")\n";
	cout << "================================\n";

	//�̷�ã�� �˰���
	while (top > -1 && !found) {
		//������ ��� pop
		position = pop();
		//pop�� ��ġ ����
		row = position.row;
		col = position.col;
		dir = position.dir;

		//dir�� 8���� �۰�, �������� �߰��Ҷ����� ����
		while (dir < 8 && !found) {
			//���� ��ġ �Է�
			nextRow = row + move[dir].ver;
			nextCol = col + move[dir].hor;

			//���� ��ġ�� �������� ����������
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
				found = true;
			}
			//���� ��ġ�� 1�� �ƴϰų� ���� �ʾҴ� ��ġ �϶�
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;	//���� ��ġ�� ���
				position.col = col;
				position.row = row;
				position.dir = ++dir;
				push(position);	//���� ��ġ�� ���ÿ� ����
				row = nextRow; //������ġ�� row�� ����
				col = nextCol;	//���� ��ġ�� col�� ����
				dir = 0;	//���� �ʱ�ȭ
			}
			else ++dir;	//���� �ٲ�
		}

	}
	//��θ� �߰� ���� ��
	if (found) {
		cout << "�̷� ��� ��δ�:\n";
		for (int i = 0; i < top; i++) {
			cout << "(" << stack[i].row << "," << stack[i].col << ") ";

		}
		cout << "(" << row << "," << col << ") ";
		cout << "(" << nextRow << "," << nextCol << ") ";
	}
	//��θ� �߰����� ������ ��
	else cout << "��ΰ� �������� �ʽ��ϴ�.\n";

}

