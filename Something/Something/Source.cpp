#include <iostream>
#include <random>
#include <string>
#include <Windows.h>
#include <list>
#include <conio.h>
#include "Item.h"

/*
for (int xp = 0; xp < 10; xp++;)
{
	for (int yp = 0; yp < 10; yp++)
	{
		switch(board[xp][yp];)
		{
			case '*':
				enroom();
			case '.':
				//Nurp
			case '@':
				//NAW
		}
	}
}
*/
random_device rd;
vector<Item> listt;
vector<string> listtt;
string Jacob = "this message should not appear,\ntell me if it does\n";
Item i = Item("def", 1, 1, 1);
bool engenst = true;
bool nroom = false;
bool enmoving = true;
char input;
int sx;
int sy;
int selitem;
int facing;
int selection = 0;
int curSelect = 0;
int money = 5;
int xroom = 0;
int yroom = 0;
int tempxroom = xroom;
int tempyroom = yroom;
int aoen;
int engenx;
int engeny;
int outerbounds = rd() % 4;
int enroom = 0;
int x = 4;
int y = 4;

vector<string> itemnames =
{
	"Sword",
	"Food",
	" ",
	" ",
	" "
};

int itemstats[5][3] =
{
	1,3,1,
	5,0,1,
	0,0,0,
	0,0,0,
	0,0,0
};

char board[10][10] =  { '#','#','#','#','-','-','#','#','#','#',
						'#','.','.','.','.','.','.','.','.','#',
						'#','.','.','.','.','.','.','.','.','#',
						'#','.','.','.','.','.','.','.','.','#',
						'|','.','.','.','.','.','.','.','.','|',
						'|','.','.','.','.','.','.','.','.','|',
						'#','.','.','.','.','.','.','.','.','#',
						'#','.','.','.','.','.','.','.','.','#',
						'#','.','.','.','.','.','.','.','.','#',
						'#','#','#','#','-','-','#','#','#','#' };
char masterboard[10][10] =  { '#','#','#','#','-','-','#','#','#','#',
							  '#','.','.','.','.','.','.','.','.','#',
							  '#','.','.','.','.','.','.','.','.','#',
							  '#','.','.','.','.','.','.','.','.','#',
							  '|','.','.','.','.','.','.','.','.','|',
							  '|','.','.','.','.','.','.','.','.','|',
							  '#','.','.','.','.','.','.','.','.','#',
							  '#','.','.','.','.','.','.','.','.','#',
							  '#','.','.','.','.','.','.','.','.','#',
							  '#','#','#','#','-','-','#','#','#','#' };
void itemmove()
{
	bool check = true;
	int checknum = 0;
	while (check)
	{
		if (itemnames[checknum] != " ")
		{
			if (checknum > 0)
			{
				itemnames[checknum - 1] = itemnames[checknum];
				itemnames[checknum] = " ";
			}
		}
/*

FINISH THIS MODULE

*/
		checknum++;
		if (checknum > 4)
		{
			check = false;
		}
	}
}
void enMove()
{
	if (xroom != 0 && yroom != 0)
	{
		enmoving = true;
	}
	while (enmoving == true)
	{
		int testx = 1;
		int testy = 1;
		bool stop = false;
		int watway = /*rd() % 4*/0;
		watway++;
		switch (watway)
		{
		case 1:
			while (!stop)
			{
				if ((testx != 9) && (testy != 9))
				{
					testx++;
				}
				else if ((testx == 9) && (testy != 9))
				{
					testx = 1;
					testy++;
				}
				else if ((testx == 9) && (testy == 9))
				{
					stop = true;
				}
				if (board[testx][testy] == '*')
				{
					board[testx][testy] = '.';
					board[testx + 1][testy] = '*';
//					watway = rd() % 4
//					watway++;
				}
				else if (board[testx][testy] == '.')
				{
					//DO A BARREL ROLL
				}
			}
		case 2:

		case 3:

		case 4:

			break;
		}
	}
}
int optionList(string prompt, vector<string> list)
{
	curSelect = 0;
	for (;;) 
	{
		system("cls");
		if (prompt != "")
		{ 
			cout << prompt;
		}
		int index = 0;
		for (string s : list)
		{
			if (curSelect == index)
			{ cout << "> "; }
			else
			{
				cout << "  "; 
			}
			cout << s;
			if (curSelect == index)
			{
				cout << " <";
			}
			cout << "\n";
			index++;
		}
		char input = char(_getch());
		if (input == 'w')
		{
			curSelect--;
			if (curSelect < 0)
			{ 
				curSelect = (int)(list.size() - 1);
			}
		}
		else if (input == 's') 
		{
			curSelect++;
			if (curSelect > list.size() - 1) 
			{ 
				curSelect = 0; 
			}
		}
		else if (input == 'e') 
		{
			return curSelect;
		}
	}
}
Item inventory()
{
	listt = vector<Item>({ Item(itemnames[0],itemstats[0][0] , itemstats[0][1],itemstats[0][2]), Item(itemnames[1],itemstats[1][0],itemstats[1][1],itemstats[1][2]) });
	selection = optionList(Jacob, itemnames);
	selitem = selection;
	system("cls");
	return listt[selection];
}
string watchawannado()
{
	listtt = vector<string>({ string("Use"), string("Throw Away"), string("Back")});
	selection = optionList(Jacob, listtt);
	system("cls");
	return listtt[selection];
}
void engen()
{
	while (engenst == true)
	{
		if (nroom == true)
		{
			enroom = /*rd() % 5 */1;
			enroom++;
			aoen = enroom;
			nroom = false;
		}
		if ((enroom >= 1))
		{
			engenx = rd() % 8;
			engeny = rd() % 8;
			engenx++;
			engeny++;
			if (engenx != x && engeny != y)
			{
				board[engenx][engeny] = '*';
				enroom--;
			}
		}
		else if (enroom == 0)
		{
			engenst = false;
		}
	}
}
//Move down
void Md()
{
	x++;
	if (board[x][y] == '#')
	{
		x = x - 1;
	}
	else if (board[x][y] == '$')
	{
		money = money + 5;
		board[x - 1][y] = masterboard[x - 1][y];
	}
	else if ((x == 9) && (y == 4) || (x == 9) && (y == 5))
	{
		xroom = xroom - 1;
	}
	else
	{
		board[x - 1][y] = masterboard[x - 1][y];
	}
	board[sx][sy] = masterboard[sx][sy];
}
//Move up
void Mu()
{
	x = x - 1;
	if (board[x][y] == '#')
	{
		x++;
	}
	else if (board[x][y] == '$')
	{
		money = money + 5;
		board[x + 1][y] = masterboard[x + 1][y];
	}
	else if ((x == 0) && (y == 4) || (x == 0) && (y == 5))
	{
		xroom++;
	}
	else
	{
		board[x + 1][y] = masterboard[x + 1][y];
	}
	board[sx][sy] = masterboard[sx][sy];
}
//Move left
void Ml()
{
	y = y - 1;
	if (board[x][y] == '#')
	{
		y++;
	}
	else if (board[x][y] == '$')
	{
		money = money + 5;
		board[x][y + 1] = masterboard[x][y + 1];
	}
	else if ((x == 4) && (y == 0) || (x == 5) && (y == 0))
	{
		yroom++;
	}
	else
	{
		board[x][y + 1] = masterboard[x][y + 1];
	}
	board[sx][sy] = masterboard[sx][sy];
}
//Move right
void Mr()
{
	y++;
	if (board[x][y] == '#')
	{
		y = y - 1;
	}
	else if (board[x][y] == '$')
	{
		money = money + 5;
		board[x][y - 1] = masterboard[x][y - 1];
	}
	else if ((x == 4) && (y == 9) || (x == 5) && (y == 9))
	{
		yroom--;
	}
	else
	{
		board[x][y - 1] = masterboard[x][y - 1];
	}
	board[sx][sy] = masterboard[sx][sy];
}
//Attack Up
void Au()
{
	board[sx][sy] = masterboard[sx][sy];
	sx = x - 1;
	sy = y;
	board[sx][sy] = '|';
}
//Attack Down
void Ad()
{
	board[sx][sy] = masterboard[sx][sy];
	sx = x + 1;
	sy = y;
	board[sx][sy] = '|';
}
//Attack Left
void Al()
{
	board[sx][sy] = masterboard[sx][sy];
	sx = x;
	sy = y - 1;
	board[sx][sy] = '~';
}
//Attack Right
void Ar()
{
	board[sx][sy] = masterboard[sx][sy];
	sx = x;
	sy = y + 1;
	board[sx][sy] = '~';
}
int main()
{
	outerbounds++;
	while (true)
	{
		tempxroom = xroom;
		tempyroom = yroom;
		for (int xp = 0; xp < 10; xp++)
		{
			if (xroom == outerbounds)
			{
				board[0][4] = '#';
				board[0][5] = '#';
			}
			else
			{
				board[0][4] = '-';
				board[0][5] = '-';
			}
			if (xroom == -(outerbounds))
			{
				board[9][4] = '#';
				board[9][5] = '#';
			}
			else
			{
				board[9][4] = '-';
				board[9][5] = '-';
			}
			if (yroom == -(outerbounds))
			{
				board[4][9] = '#';
				board[5][9] = '#';
			}
			else
			{
				board[4][9] = '|';
				board[5][9] = '|';
			}
			if (yroom == outerbounds)
			{
				board[4][0] = '#';
				board[5][0] = '#';
			}
			else
			{
				board[4][0] = '|';
				board[5][0] = '|';
			}
			board[x][y] = '@';
			for (int yp = 0; yp < 10; yp++)
			{
				cout << board[xp][yp] << " ";
			}
			cout << endl;
		}
		input = char(_getch());
		switch (input)
		{
		case 'w':
			Mu();
			//enMove();
			break;
		case 's':
			Md();
			//enMove();
			break;
		case 'a':
			Ml();
			//enMove();
			break;
		case 'd':
			Mr();
			//enMove();
			break;
		case 'i':
			Au();
			break;
		case 'k':
			Ad();
			break;
		case 'j':
			Al();
			break;
		case 'l':
			Ar();
			break;
		case 'e':
			reinv:
			itemmove();
			i = inventory();
			switch (selection)
			{
			case 0:
				watchawannado();
				switch (selection)
				{
				case 0:

				case 1:
					itemnames[selitem] = " ";
					itemstats[0][selitem] = 0;
					itemstats[1][selitem] = 0;
					itemstats[2][selitem] = 0;
				case 2:
					goto reinv;
					break;
				}
			case 1:
				watchawannado();
				switch (selection)
				{
				case 0:

				case 1:
					itemnames[selitem] = " ";
					itemstats[0][selitem] = 0;
					itemstats[1][selitem] = 0;
					itemstats[2][selitem] = 0;
				case 2:
					goto reinv;
					break;
				}
			case 2:
				watchawannado();
				switch (selection)
				{
				case 0:

				case 1:
					itemnames[selitem] = " ";
					itemstats[0][selitem] = 0;
					itemstats[1][selitem] = 0;
					itemstats[2][selitem] = 0;
				case 2:
					goto reinv;
					break;
				}
			case 3:
				watchawannado();
				switch (selection)
				{
				case 0:

				case 1:
					itemnames[selitem] = " ";
					itemstats[0][selitem] = 0;
					itemstats[1][selitem] = 0;
					itemstats[2][selitem] = 0;
				case 2:
					goto reinv;
					break;
				}
			case 4:
								watchawannado();
				switch (selection)
				{
				case 0:

				case 1:
					itemnames[selitem] = " ";
					itemstats[0][selitem] = 0;
					itemstats[1][selitem] = 0;
					itemstats[2][selitem] = 0;
				case 2:
					goto reinv;
					break;
				}
				break;
			}
		}
		if (xroom != tempxroom || yroom != tempyroom)
		{
			nroom = true;
		}
		if (nroom == true)
		{
			engenst = true;
			engen();
		}
		if (yroom > tempyroom)
		{
			y = 8;
			board[4][1] = masterboard[4][1];
			board[5][1] = masterboard[5][1];
		}
		else if (yroom < tempyroom)
		{
			y = 1;
			board[4][8] = masterboard[4][8];
			board[5][8] = masterboard[5][8];
		}
		else if (xroom > tempxroom)
		{
			x = 8;
			board[1][4] = masterboard[1][4];
			board[1][5] = masterboard[1][5];
		}
		else if (xroom < tempxroom)
		{
			x = 1;
			board[8][4] = masterboard[8][4];
			board[8][5] = masterboard[8][5];
		}
		if (board[x][y] == '*')
		{
			goto death;
		}
		system("cls");
	}
	death:
	cout << "You've died and lost absolutely everything\n";
	system("pause");
	return 0;
}