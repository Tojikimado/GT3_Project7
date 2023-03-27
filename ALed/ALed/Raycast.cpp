#include "Raycast.h"

void Raycast::SingleRayCast(int x, int y)
{
	for (float f = 5.f; f < 500.f; f = f + step)
	{
		D3DXVECTOR3* pointPos = new D3DXVECTOR3(x, y, f);
		
		//check toute les collisions / break si y'en a une 
		


	}

}
