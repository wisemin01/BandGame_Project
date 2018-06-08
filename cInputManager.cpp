#include "DXUT.h"
#include "cInputManager.h"


cInputManager::cInputManager()
{
	Init();
}


cInputManager::~cInputManager()
{
	Release();
}

void cInputManager::Init()
{
	memset(keyMap, E_NONE, sizeof(keyMap));
	IsMouseOnTile = false;
}

void cInputManager::Update()
{
	memcpy(oldKey, curnKey, 256);
	memset(curnKey, E_NONE, sizeof(curnKey));

	GetKeyboardState(curnKey);

	for (int i = 0; i < 256; i++) {
		BYTE vkey = curnKey[i] & 0x80;
		curnKey[i] = (vkey) ? 1 : 0;

		INT nOld = oldKey[i];
		INT nCur = curnKey[i];

		if (nOld == 1 && nCur == 1) keyMap[i] = E_RETAIN;
		else if(nOld == 0 && nCur == 1) keyMap[i] = E_DOWN;
		else if (nOld == 1 && nCur == 0) keyMap[i] = E_UP;
		else keyMap[i] = E_NONE;
 	}

	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);

	MousePos = D3DXVECTOR2(pt.x, pt.y);
}


void cInputManager::Release()
{
}

BOOL cInputManager::GetKeyDown(INT key)
{
	return (keyMap[key] == E_DOWN);
}

BOOL cInputManager::GetKeyUp(INT key)
{
	return (keyMap[key] == E_UP);
}

BOOL cInputManager::GetKeyRetain(INT key)
{
	return (keyMap[key] == E_RETAIN);
}
