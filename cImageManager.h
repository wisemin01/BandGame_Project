#pragma once
#include "singleton.h"

// 텍스쳐의 정보를 담는 구조체 
// 구조체도 클래스와 같이 생성자, 파괴자를 사용 가능하며 맴버 함수도 넣을수 있다.

struct texture {

	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		: texturePtr(texturePtr),info(info) {}

	void Render(float x, float y, float size = 1.0);
	void CenterRender(float x, float y, float size = 1.0);

	void Render(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void RectRender(float x, float y, const RECT *rc, float size = 1.0);
};

class cImageManager :
	public singleton<cImageManager>
{
private:
	LPD3DXSPRITE m_sprite;	

	// map 자료형은 키와 값으로 이루어지며 키를 이용해 넣은 값을 찾을수도 있다.
	// 여기서 string은 키로 문자열을 사용하겠다는 의미.
	// texture의 포인터가 값으로 지정되어있다.

	map<string, texture*> m_images;

public:

	cImageManager();
	virtual ~cImageManager();

	void Render(texture* texturePtr, float x, float y, float size = 1.0);
	void CenterRender(texture* texturePtr, float x, float y, float size = 1.0);

	void Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void RectRender(texture* texturePtr, float x, float y,const RECT *rc, float size = 1.0);

	// 이미지 추가 key : 이미지 이름 , path : 이미지를 찾아 로드할 경로.
	texture* AddImage(const string &key, const string &path);
	texture* FindImage(const string &key);

	bool AddListImage(const string &key, const string &path, int StartNum, int EndNum, const string &fomat = ".png");

	// sprite 처리 부분
	void Begin() { if (m_sprite) m_sprite->Begin(D3DXSPRITE_ALPHABLEND); }
	void End() { if (m_sprite) m_sprite->End(); }
	void OnResetDevice() { if(m_sprite) m_sprite->OnResetDevice(); }
	void OnLostDevice() { if (m_sprite) m_sprite->OnLostDevice(); }

	// ================================================

	// 폰트도 sprite를 사용해야 하기 때문에
	// ImageManager클래스에 합쳤다.


private:

	LPD3DXFONT m_Font25;
	LPD3DXFONT m_Font35;
	LPD3DXFONT m_Font50;
	LPD3DXFONT m_Font70;
	LPD3DXFONT m_Font100;
	LPD3DXFONT m_Font150;

public:

	// 사이즈는 무조건 25, 40, 50, 70, 100, 150 중 하나로.
	// 문자열 출력 함수
	void sDrawText(float x, float y, const string & str, int size, D3DXCOLOR color = D3DCOLOR_XRGB(255,255,255));
};

#define IMAGEMANAGER cImageManager::GetInstance()

// 이 매니저는 Font 출력 겸용 클래스
#define FONTMANAGER cImageManager::GetInstance()