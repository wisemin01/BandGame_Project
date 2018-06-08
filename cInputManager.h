#pragma once
#include "singleton.h"
class cInputManager :
	public singleton <cInputManager>
{
private:
	enum KEYSTATE {
		E_NONE,
		E_DOWN,
		E_UP,
		E_RETAIN
	};

	BYTE keyMap[256];

	BYTE curnKey[256];
	BYTE oldKey[256];

	D3DXVECTOR2 MousePos;
	D3DXVECTOR2 MouseTilePos;

	BOOL IsMouseOnTile;

public:
	cInputManager();
	~cInputManager();
	
	void Update();

	void Init();
	void Release();

	BOOL GetKeyDown(INT key);
	BOOL GetKeyUp(INT key);
	BOOL GetKeyRetain(INT key);

	VOID SetMouseTilePos(D3DXVECTOR2 pos) { MouseTilePos = pos;}
	D3DXVECTOR2 GetMouseTilePos() { return MouseTilePos; }
	D3DXVECTOR2 GetMousePos() { return MousePos; }

	BOOL GetIsMouseOnTile() { return IsMouseOnTile; }
	VOID SetIsMouseOnTile(BOOL flag) { IsMouseOnTile = flag; }
};

#define INPUTMANAGER cInputManager::GetInstance()

#define GETKEY_DOWN(key)	INPUTMANAGER->GetKeyDown(key)
#define GETKEY_UP(key)		INPUTMANAGER->GetKeyUp(key)
#define GETKEY_RETAIN(key)	INPUTMANAGER->GetKeyRetain(key)

#define GET_MOUSEPOS		INPUTMANAGER->GetMousePos()
#define GET_MOUSETILEPOS	INPUTMANAGER->GetMouseTilePos()