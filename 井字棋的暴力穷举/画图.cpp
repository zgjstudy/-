#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Draw the current situation of Tic-Tac-Toe.
void draw(int* data);

// Draw o or x or blank.
string drawHelp(int data);

// dfs
void dfs(int n);

// Determine if the game is over.
bool isOver();

// Draw the branch
void drawBranch();

int d[15];		// Current state
int branch[15];	// Current state's chess order
int counter = 0;	// The number of states

int main()
{
	freopen("out.txt", "w", stdout);

	memset(d, 0, sizeof(d));
	memset(branch, 0, sizeof(branch));

	dfs(0);

	system("pause");
	return 0;
}

void draw(int* data)
{
	cout << "Count: " << ++counter << endl;
	cout << "| " << drawHelp(data[0]) << "  " << drawHelp(data[1]) << "  " << drawHelp(data[2]) << " |" << endl;
	cout << "| " << drawHelp(data[3]) << "  " << drawHelp(data[4]) << "  " << drawHelp(data[5]) << " |" << endl;
	cout << "| " << drawHelp(data[6]) << "  " << drawHelp(data[7]) << "  " << drawHelp(data[8]) << " |" << endl;
	drawBranch();
}

string drawHelp(int i)
{
	return (string)(i == 1 ? "o" : (i == -1 ? "x" : " "));
}

void drawBranch()
{
	cout << "Branch: ";
	for (int i = 0; branch[i] != 0; ++i)
	{
		if (i == 0)
			cout << branch[i];
		else
			cout << " - " << branch[i];
	}
	cout << endl << endl;
}

bool isOver()
{
	if (d[0] == d[1] && d[1] == d[2] && d[0] != 0 || d[3] == d[4] && d[4] == d[5] && d[4] != 0
		|| d[6] == d[7] && d[7] == d[8] && d[6] != 0 || d[0] == d[3] && d[3] == d[6] && d[0] != 0
		|| d[1] == d[4] && d[4] == d[7] && d[4] != 0 || d[2] == d[5] && d[5] == d[8] && d[5] != 0
		|| d[0] == d[4] && d[4] == d[8] && d[4] != 0 || d[2] == d[4] && d[4] == d[6] && d[4] != 0)
		return true;
	return false;
}

void dfs(int n)
{
	if (n >= 10) // If the map is full, then return
		return;
	
	draw(d);

	if (isOver()) // If the game is over, then return.
		return;

	int mark = n & 1 ? -1 : 1;

	for (int i = 0; i < 9; ++i)
	{
		if (d[i] == 0)
		{
			branch[n] = i + 1;
			d[i] = mark;
			dfs(n + 1);
			d[i] = 0;
			branch[n] = 0;
		}
	}
}
