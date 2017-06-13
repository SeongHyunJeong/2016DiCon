#pragma once
#include"player.h"
bool IsCollisionRect(D3DXVECTOR2 p1, D3DXVECTOR2 p2, RECT r1, RECT r2);
void Collision(D3DXVECTOR2 collider, RECT colliderRect, Player *);
bool IsPointInRect(D3DXVECTOR2 p, RECT r, D3DXVECTOR2 pt);