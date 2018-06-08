#pragma once
#include "singleton.h"

// �ؽ����� ������ ��� ����ü 
// ����ü�� Ŭ������ ���� ������, �ı��ڸ� ��� �����ϸ� �ɹ� �Լ��� ������ �ִ�.

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

	// map �ڷ����� Ű�� ������ �̷������ Ű�� �̿��� ���� ���� ã������ �ִ�.
	// ���⼭ string�� Ű�� ���ڿ��� ����ϰڴٴ� �ǹ�.
	// texture�� �����Ͱ� ������ �����Ǿ��ִ�.

	map<string, texture*> m_images;

public:

	cImageManager();
	virtual ~cImageManager();

	void Render(texture* texturePtr, float x, float y, float size = 1.0);
	void CenterRender(texture* texturePtr, float x, float y, float size = 1.0);

	void Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	void RectRender(texture* texturePtr, float x, float y,const RECT *rc, float size = 1.0);

	// �̹��� �߰� key : �̹��� �̸� , path : �̹����� ã�� �ε��� ���.
	texture* AddImage(const string &key, const string &path);
	texture* FindImage(const string &key);

	bool AddListImage(const string &key, const string &path, int StartNum, int EndNum, const string &fomat = ".png");

	// sprite ó�� �κ�
	void Begin() { if (m_sprite) m_sprite->Begin(D3DXSPRITE_ALPHABLEND); }
	void End() { if (m_sprite) m_sprite->End(); }
	void OnResetDevice() { if(m_sprite) m_sprite->OnResetDevice(); }
	void OnLostDevice() { if (m_sprite) m_sprite->OnLostDevice(); }

	// ================================================

	// ��Ʈ�� sprite�� ����ؾ� �ϱ� ������
	// ImageManagerŬ������ ���ƴ�.


private:

	LPD3DXFONT m_Font25;
	LPD3DXFONT m_Font35;
	LPD3DXFONT m_Font50;
	LPD3DXFONT m_Font70;
	LPD3DXFONT m_Font100;
	LPD3DXFONT m_Font150;

public:

	// ������� ������ 25, 40, 50, 70, 100, 150 �� �ϳ���.
	// ���ڿ� ��� �Լ�
	void sDrawText(float x, float y, const string & str, int size, D3DXCOLOR color = D3DCOLOR_XRGB(255,255,255));
};

#define IMAGEMANAGER cImageManager::GetInstance()

// �� �Ŵ����� Font ��� ��� Ŭ����
#define FONTMANAGER cImageManager::GetInstance()