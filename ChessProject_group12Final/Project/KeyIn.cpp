#include<conio.h>
#include"KeyIn.h"

namespace Chen_Yan_Yu_KeyIn
{
	using namespace std;
	char KeyIn::readKey()
	{
		key = _getch();
		return key;
	}
	bool KeyIn::getSelected()
	{
		return selected;
	}
	bool KeyIn::getEsc()
	{
		return escTable;
	}
	void KeyIn::setSelected(bool b)
	{
		selected = b;
	}
	void KeyIn::setEsc(bool b)
	{
		escTable = b;
	}
}

/*
	char KeyIn::readKey()
	{
		key = _getch();

		switch (key)
		{
		case 0x0D://enter
			if (escTable == true)
			{
				//����Ӱʧ@
			}
			else
			{
				if (selected == true)//��Ѥl��b�Ӵ�Ц�m
				{
					//�P�_�i���i�H��,�Ϊ̦bmanager�P�_
				}
				else//��Ѫ��禡
				{

				}
			}
			break;
		case 0x1B://esc
			if (escTable == true)
			{
				//�����D���
				escTable = false;
			}
			else
			{
				//���X�D���
				escTable = true;
			}
			break;
		case 0x48://up
			//��в��ʨ�W���@��
			break;
		case 0x50://down
			//��в��ʨ�U���@��
			break;
		case 0x4D://right
			//��в��ʨ�k��@��
			break;
		case 0x4B://left
			//��в��ʨ쥪��@��
			break;
		}
		return key;
	}

*/