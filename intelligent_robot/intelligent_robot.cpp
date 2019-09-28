#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int n, axis, dir, tempX, tempY, bots[10000][2], movs[10000][10000][2], winners[10000], checks, dumb, dumbs[10000], dumbC;
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
	dir = 1;

	if(bots[num][1] == 0 && bots[num][0] == 3){
		dir = -1;
		axis = 0;
		tempY = bots[num][0] + dir;
		tempX = bots[num][1];
	}
	else {
		switch(axis){
			case 0:
				if((bots[num][0] < 2 && bots[num][1] != 1) || (bots[num][1] == 2 && bots[num][0] == 2) || (bots[num][1] == 0 && bots[num][0] == 2)){
					if(bots[num][1] == 0)
					tempY = bots[num][0] + dir;
					tempX = bots[num][1];
				}
				else{
					axis = 1;
					tempY = bots[num][0];
					tempX = bots[num][1] + dir;
				}
			break;
			case 1:
				if(bots[num][0] != 1 && bots[num][1] < 2){
					tempY = bots[num][0];
					tempX = bots[num][1] + dir;
				}
				else {
					axis = 0;
					tempY = bots[num][0] + dir;
					tempX = bots[num][1];
				}
			break;
		}
	}
}

// Function for indicating if the robot has won (depending on it's current cell)
bool checkWin(int n){
	return (bots[n][0] == 3 && bots[n][1] == 2);
}

int main (){
	srand (time(NULL));

	printf("Give me the number of desired robots: ");
	scanf("%d", &n);

	startGame();

	for(int i = 0; i < n; i++){
		killBot = false;
		printBoard(i, 0, 0);
		for(int j = 0; !killBot; j++){
			moveBot(i);

			bots[i][axis] += dir;
			movs[i][j][0] = bots[i][0];
			movs[i][j][1] = bots[i][1];

			printBoard(i, bots[i][0], bots[i][1]);
			Sleep(200);

			if(checkWin(i) == 1) {
				printf("\nRobot #%d got to the reward with %d steps\n", i + 1, j + 1);
				Sleep(900);
				winners[i] = j;
				if(j > dumb) {
					dumbC = 0;
					dumbs[dumbC] = i;
					dumb = j;
				}
				else if(j == dumb) dumbs[++dumbC] = i;
				killBot++;
			}
		}
	}

	system("CLS");

	if(dumbC == 0) printf("\nThe robot that took longer to get to the reward was Robot #%d, with %d steps\n", dumbs[0] + 1, dumb + 1);
	else{
		printf("\nThe robots that took longer to get to the reward were:\n");
		for(int i = 0; i <= dumbC; i++) printf("Robot #%d\n", dumbs[i]);
		printf("Those robots took %d steps\n", dumb + 1);
	}

	system("PAUSE");

	while(checks != -1){
		system("CLS");

		printf("Results:\n\n");
		for(int i = 0; i < n; i++) printf("Robot #%d: %d steps\n", i + 1, winners[i] + 1);

		printf("\nPath reviewer:\n\nEnter the number of the robot which you desire to review its path (1 - %d)\nor enter -1 to exit: ", n);
		scanf("%d", &checks);

		if(checks == -1) return 0;

		printf("Robot %d:\n", checks);
		checks--;

		for(int i = 0; i <= winners[checks]; i++) printf("\t[%d][%d]\n", movs[checks][i][0], movs[checks][i][1]);

		cout << endl;
		system("PAUSE");
	}

	cout << "Bye bye :)" << endl;
	system("PAUSE");
}
