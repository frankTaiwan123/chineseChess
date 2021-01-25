#include<vector>

#ifndef CHESSBASE_H
#define CHESSBASE_H

using std::vector;

class chess
{
public:
	chess();//We do not use it.
	chess(int row, int column);//constructor, for derived class
	virtual void eatMove(vector<int> v);
	vector<int> getPosition();
	virtual vector<vector<int> > canMove() = 0;
	virtual void setStatus(int row, int column, char camp, bool die) = 0;
	bool getDead();
	void setDead(bool b);
protected:
	bool dead = true;//���Ѥl�O�_�w�Q�Y
	char color;//���Ѥl���}��
	int rowPos = 100;//�H�K�]����
	int colPos = 100;//�H�K�]����
};


#endif