struct BOX {	//���̒�`
	double x;	//��
	double y;	//����
	double z;	//���s
	double volume;	//�̐�
	double surface; //�\�ʐ�
	double packSize; //������}�ւ̃T�C�Y
};

bool isSendable(BOX* box);

void getVolumeSurface(BOX* box);