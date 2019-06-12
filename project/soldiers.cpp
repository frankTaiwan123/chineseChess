#include"soldiers.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using std::vector;
using namespace Chen_Yan_Yu_Board;

soldiers::soldiers()
{

}

soldiers::soldiers(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > soldiers::canMove()
{
	vector<vector<int> > valid;
	if (color == 'b' && getPosition()[0] >= 5)
	{
		crossRiver = true;
	}
	else if (color == 'r' && getPosition()[0] <= 4)
	{
		crossRiver = true;
	}
	if (crossRiver == true)
	{
		if (color == 'b')
		{
			if (rowPos + 1 <= 9 && board::checkColor(rowPos + 1, colPos) != 'b')//�h�U��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos + 1, colPos});
			}
			if (colPos - 1 >= 0 && board::checkColor(rowPos, colPos - 1) != 'b')//�h����i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos, colPos - 1});
			}
			if (colPos + 1 <= 8 && board::checkColor(rowPos, colPos + 1) != 'b')//�h�k��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos, colPos + 1});
			}
		}
		else
		{
			if (rowPos - 1 >= 0 && board::checkColor(rowPos - 1, colPos) != 'r')//�h�W��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos - 1, colPos});
			}
			if (colPos - 1 >= 0 && board::checkColor(rowPos, colPos - 1) != 'r')//�h����i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos, colPos - 1});
			}
			if (colPos + 1 <= 8 && board::checkColor(rowPos, colPos + 1) != 'r')//�h�k��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos, colPos + 1});
			}
		}
	}
	else//�|���L�e�A�u��V�e����or�Y
	{
		if (color == 'b')
		{
			if (rowPos + 1 <= 9 && board::checkColor(rowPos + 1, colPos) != 'b')//�h�U��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos + 1, colPos});
			}
		}
		else
		{
			if (rowPos - 1 >= 0 && board::checkColor(rowPos - 1, colPos) != 'r')//�h�W��i�H��or�Y
			{
				valid.push_back(vector<int>{rowPos - 1, colPos});
			}
		}
	}

	return valid;
}

void soldiers::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void soldiers::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}