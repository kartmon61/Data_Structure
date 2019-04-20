#include<iostream>

using namespace std;

//미로 생성
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


//목적지 설정
#define EXIT_ROW 9
#define EXIT_COL 6

//내가 움직인 경로 생성
int mark[11][8];

//이동 가능한 방향
class Offset {
public:
	int ver;
	int hor;

	Offset(int ver, int hor) {
		this->ver = ver;
		this->hor = hor;
	}
};

//현재 위치 저장
class Element {
public:
	int row;
	int col;
	int dir;
};

//위치를 저장하는 스택 생성 
Element stack[100];
int top = -1;

//현재 위치를 저장하는 push 함수
void push(Element position) {
	stack[top].col = position.col;
	stack[top].row = position.row;
	stack[top++].dir = position.dir;
}

//현재 위치를 pop하는 함수
Element pop() {
	return stack[top--];
}


//메인
int main() {
	//이동할 수 있는 경로 지정
	Offset move[8] = {
						Offset(-1,0),//N방향
						Offset(-1,1),//NE방향
						Offset(0,1),//E방향
						Offset(1,1),//SE방향
						Offset(1,0),//S방향
						Offset(1,-1),//SW방향
						Offset(0,-1),//W방향
						Offset(-1,-1) //NW방향
	};

	//변수 생성
	int row, col;
	int nextRow, nextCol;
	int dir;
	bool found = false;
	Element position;

	//스택에 시작 위치를 저장
	top = 0;
	stack[0].row = 1; 
	stack[0].col = 1;
	stack[0].dir = 1;

	mark[1][1] = 1; //시작 위치를 갔던 위치에 입력

	cout << "========미로  찾기=========\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n출발 위치\n";
	cout << "(" << stack[0].row << "," << stack[0].col << ")\n";
	cout << "\n출입구 위치\n";
	cout << "(" << EXIT_ROW << "," << EXIT_COL << ")\n";
	cout << "================================\n";

	//미로찾기 알고리즘
	while (top > -1 && !found) {
		//마지막 경로 pop
		position = pop();
		//pop한 위치 저장
		row = position.row;
		col = position.col;
		dir = position.dir;

		//dir이 8보다 작고, 목적지를 발견할때까지 동작
		while (dir < 8 && !found) {
			//다음 위치 입력
			nextRow = row + move[dir].ver;
			nextCol = col + move[dir].hor;

			//다음 위치가 목적지에 도착했을때
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
				found = true;
			}
			//다음 위치가 1이 아니거나 가지 않았던 위치 일때
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;	//갔던 위치로 등록
				position.col = col;
				position.row = row;
				position.dir = ++dir;
				push(position);	//현재 위치를 스택에 저장
				row = nextRow; //다음위치를 row에 저장
				col = nextCol;	//다음 위치를 col에 저장
				dir = 0;	//방향 초기화
			}
			else ++dir;	//방향 바꿈
		}

	}
	//경로를 발견 했을 때
	if (found) {
		cout << "미로 통과 경로는:\n";
		for (int i = 0; i < top; i++) {
			cout << "(" << stack[i].row << "," << stack[i].col << ") ";

		}
		cout << "(" << row << "," << col << ") ";
		cout << "(" << nextRow << "," << nextCol << ") ";
	}
	//경로를 발견하지 못했을 때
	else cout << "경로가 존재하지 않습니다.\n";

}

