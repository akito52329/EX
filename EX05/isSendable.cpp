#include "getVolumeSurface.h"

bool isSendable(BOX* box)
{
	const int MAX_COUNT = 8;
	int sizeCeiteria[] = { 200,180,160,140,120,100,80,60 };//ƒTƒCƒY‚ÌŠî€
	int size;
	int overSize = 201;
	size = box->x + box->y + box->z;

	box->packSize = overSize;
	for (int i = 0; i < MAX_COUNT; i++)
	{
		
		if (size <= sizeCeiteria[i])
		{
			box->packSize = sizeCeiteria[i];
		}
	}

	return box->packSize <= sizeCeiteria[0];
}