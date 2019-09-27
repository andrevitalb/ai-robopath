#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int n, axis, dir, tempX, tempY, bots[10000][2], movs[10000][10000][2], winners[10000][2], wins;
bool killBot;

// Function for printing the board & the robot movements
void printBoard(int num, int x, int y){
	system("CLS");

	cout << "Robot #" << num + 1 << ":" << endl << endl;

	printf("Robot's actual position: [%d][%d]\n\n", x, y);

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			if(i == x && j == y) printf("[  X ]");
			else if(i == 1 && j == 1) printf("[0000]");
			else if(i == 3 && j == 2) printf("[  1 ]");
			else if(i == 3 && j == 1) printf("[ -1 ]");
			else printf("[    ]");
		}
		cout << endl;
	}
}

// Initialize the game (Reset the values of all robots)
void startGame(){
	for(int i = 0; i < n; i++){
		bots[i][0] = 0;
		bots[i][1] = 0;
	}
}

// Function for generating the robot movements (It generates them & stores them in temporal variables)
void moveBot(int num){
	axis = rand() % 2;
	dir = rand() % 2;

	switch(dir){
		case 0: dir = -1; break;
		case 1: dir = 1; break;
	}

	switch(axis){
		case 0:
			tempY = bots[num][0] + dir;
			tempX = bots[num][1];
		break;
		case 1:
			tempY = bots[num][0];
			tempX = bots[num][1] + dir;
		break;
	}
}

// Function for corroborating the robot movements 
// It verifies the movement is within the board and that it's not the blocked cell
bool checkMove(){
    if(tempX == 1 && tempY == 1) return false;
	if(tempX > -1 && tempX < 3 && tempY > -1 && tempY < 4) return true;
	return false;
}

// Function for indicating if the robot has either won or lost (depending on it's current cell)
int checkWin(int n){
	if(bots[n][0] == 3 && bots[n][1] == 2) return 1;
	if(bots[n][0] == 3 && bots[n][1] == 1) return -1;
	return 0;
}

int main (){
	srand (time(NULL));

	printf("Give me the number of desired robots: ");
	scanf("%d", &n);

	startGame();

	for(int i = 0; i < n; i++){
		killBot = false;
		for(int j = 0; !killBot; j++){
			do {
				moveBot(i);
			} while(!checkMove());

			bots[i][axis] += dir;
			movs[i][j][0] = bots[i][0];
			movs[i][j][1] = bots[i][1];

			printBoard(i, bots[i][0], bots[i][1]);
			Sleep(200);

			if(checkWin(i) == 1) {
				printf("\nRobot #%d wins\n", i + 1);
				Sleep(900);
				winners[wins][0] = i;
				winners[wins++][1] = j;
				killBot++;
			}
			else if(checkWin(i) == -1) {
				printf("\nRobot #%d looses\n", i + 1);
				Sleep(900);
				killBot++;
			}
		}
	}

	printf("\n%d robots lost and %d won.\n", (n - wins), wins);

	if(wins) printf("Paths used by the winners: \n\n");

	for(int i = 0; i < wins; i++){
        printf("Robot %d:\n", winners[i][0] + 1);
		for(int j = 0; j <= winners[i][1]; j++){
			printf("\t[%d][%d]\n", movs[winners[i][0]][j][0], movs[winners[i][0]][j][1]);
		}
        cout << endl;
	}
	system("PAUSE");
}
