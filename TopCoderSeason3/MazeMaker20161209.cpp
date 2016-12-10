#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXY 7
#define MAXX 7
int matrix[MAXY][MAXX];

class MazeMaker {
public:
	int longestPath(vector<string> maze, int startRow, int startCol,
		vector<int> moveRow, vector<int> moveCol) {
		int result = 0, x, y, nextX, nextY;
		queue<int> qx, qy;

		// initiate matrix
		for (int i=0; i<MAXY; i++) {
			for (int j=0; j<MAXX; j++) {
				matrix[i][j] = -1;
			}
		}

		// count step 0 in start point of matrix 0
		matrix[startRow][startCol] = 0;

		// insert queue
		qy.push(startRow); qx.push(startCol);

		// repeat
		while (qy.size() > 0) {
			// pop in queue
			y = qy.front(); x = qx.front();
			qy.pop(); qx.pop();

			// insert posible point and count next step
			for (int j=0; j<moveRow.size(); j++) {
				nextY = y + moveRow[j];
				nextX = x + moveCol[j];
				if(nextY >= 0 && nextY < maze.size() && nextX >= 0 && nextX < maze[0].length()
					&& maze[nextY][nextX] == '.' && matrix[nextY][nextX] == -1) {
					qy.push(nextY); qx.push(nextX);
					matrix[nextY][nextX] = matrix[y][x]+1;
				}
			}
		}

		// if there is '.' in maze and -1 in matrix return -1
		for (int i=0; i<maze.size(); i++) {
			for (int j=0; j<maze[0].length(); j++) {
				if (maze[i][j] == '.' && matrix[i][j] == -1) {
					return -1;
				}
				result = max(result, matrix[i][j]);
			}
		}
	
		// or return the max value of matrix
		return result;
	}

};

int main(void) {
	MazeMaker mm;
	vector<string> maze;
	int startRow, startCol;
	vector<int> moveRow, moveCol;

	/*
	maze.push_back("...");
	maze.push_back("...");
	maze.push_back("...");
	startRow = 0, startCol = 1;
	moveRow.push_back(1); moveRow.push_back(0); moveRow.push_back(-1); moveRow.push_back(0);
	moveRow.push_back(1); moveRow.push_back(1); moveRow.push_back(-1); moveRow.push_back(-1);
	moveCol.push_back(0); moveCol.push_back(1); moveCol.push_back(0); moveCol.push_back(-1);
	moveCol.push_back(1); moveCol.push_back(-1); moveCol.push_back(1); moveCol.push_back(-1);
	*/
	/*
	maze.push_back("X.X");
	maze.push_back("...");
	maze.push_back("XXX");
	maze.push_back("X.X");
	startRow = 0, startCol = 1;
	moveRow.push_back(1); moveRow.push_back(0); moveRow.push_back(-1); moveRow.push_back(0);
	moveCol.push_back(0); moveCol.push_back(1); moveCol.push_back(0); moveCol.push_back(-1);
	*/
	/*
	maze.push_back(".......");
	maze.push_back("X.X.X..");
	maze.push_back("XXX...X");
	maze.push_back("....X..");
	maze.push_back("X....X.");
	maze.push_back(".......");
	startRow = 5, startCol = 0;
	moveRow.push_back(1); moveRow.push_back(0); moveRow.push_back(-1);
	moveRow.push_back(0); moveRow.push_back(-2); moveRow.push_back(1);
	moveCol.push_back(0); moveCol.push_back(-1); moveCol.push_back(0);
	moveCol.push_back(1); moveCol.push_back(3); moveCol.push_back(0);
	*/
	/*
	maze.push_back(".......");
	startRow = 0, startCol = 0;
	moveRow.push_back(1); moveRow.push_back(0); moveRow.push_back(1);
	moveRow.push_back(0); moveRow.push_back(1); moveRow.push_back(0);
	moveCol.push_back(0); moveCol.push_back(1); moveCol.push_back(0);
	moveCol.push_back(1); moveCol.push_back(0); moveCol.push_back(1);
	*/

	maze.push_back("..X.X.X.X.X.X.");
	startRow = 0, startCol = 0;
	moveRow.push_back(2); moveRow.push_back(0); moveRow.push_back(-2); moveRow.push_back(0);
	moveCol.push_back(0); moveCol.push_back(2); moveCol.push_back(0); moveCol.push_back(-2);


	cout << mm.longestPath(maze, startRow, startCol, moveRow, moveCol) << endl;
	
	return 0;
}