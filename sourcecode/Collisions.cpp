#include"Collisions.h"
bool IsCollisionRect(D3DXVECTOR2 p1, D3DXVECTOR2 p2, RECT r1, RECT r2)
{
	RECT r;
	r1.left += p1.x;
	r1.right += p1.x;
	r1.top += p1.y;
	r1.bottom += p1.y;

	r2.left += p2.x;
	r2.right += p2.x;
	r2.top += p2.y;
	r2.bottom += p2.y;

	return IntersectRect(&r, &r1, &r2);
}
void Collision(D3DXVECTOR2 collider, RECT colliderRect, Player * player)
{
	if (IsCollisionRect(collider, (*player).pos, colliderRect, (*player).rect))
	{
		(*player).pos.y -= (*player).dy;
		(*player).pos.x -= (*player).dx;
	}
}


bool IsPointInRect(D3DXVECTOR2 p, RECT r, D3DXVECTOR2 pt)
{
	r.left += p.x;
	r.right += p.x;
	r.top += p.y;
	r.bottom += p.y;

	return (pt.x > r.left && pt.x<r.right && pt.y>r.top && pt.y < r.bottom);

}