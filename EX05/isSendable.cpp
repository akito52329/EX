#include "getVolumeSurface.h"

bool isSendable(BOX* box)
{
	int sizeCeiteria[] = { 60,80,100,120,140,160,180,200 };//ƒTƒCƒY‚ÌŠî€
	int size;
	size = box->x + box->y + box->z;

	if (size <= sizeCeiteria[0])
	{
		box->packSize = sizeCeiteria[0];
	}
	else if (size <= sizeCeiteria[1])
	{
		box->packSize = sizeCeiteria[1];
	}	
	else if (size <= sizeCeiteria[2])
	{
		box->packSize = sizeCeiteria[2];
	}	
	else if (size <= sizeCeiteria[3])
	{
		box->packSize = sizeCeiteria[3];
	}
	else if (size <= sizeCeiteria[4])
	{
		box->packSize = sizeCeiteria[4];
	}
	else if (size <= sizeCeiteria[5])
	{
		box->packSize = sizeCeiteria[5];
	}
	else if (size <= sizeCeiteria[6])
	{
		box->packSize = sizeCeiteria[6];
	}
	else if (size <= sizeCeiteria[7])
	{
		box->packSize = sizeCeiteria[7];
	}
	else
	{
		box->packSize = 0;
	}

	return box->packSize <= sizeCeiteria[7];
}