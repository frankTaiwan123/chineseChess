#ifndef KEYIN
#define KEYIN

namespace Chen_Yan_Yu_KeyIn
{
	class KeyIn
	{
	public:
		char readKey();//manager�ΰj�餣���I�sreadKeyŪ��
		bool getSelected();
		bool getEsc();
		void setSelected(bool b);
		void setEsc(bool b);
	private:
		char key;
		bool selected = false;//�P�_�{�b��Ѥl�F�S
		bool escTable = false;//�P�_�ϥΪ̬O�_�s�X���
	};
}

#endif

