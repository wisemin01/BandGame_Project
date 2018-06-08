#include "DXUT.h"
#include "cImageManager.h"


// texture


void texture::Render(float x, float y, float size)
{
	IMAGEMANAGER->Render(this, x, y, size);
}

void texture::CenterRender(float x, float y, float size)
{
	IMAGEMANAGER->CenterRender(this, x, y, size);
}

void texture::Render(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, color);
}

void texture::CenterRender(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, color);
}

void texture::RectRender(float x, float y, const RECT * rc, float size)
{
	IMAGEMANAGER->RectRender(this, x, y, rc, size);
}



// =================================================================================



cImageManager::cImageManager()
{
	D3DXCreateSprite(g_device, &m_sprite);

	D3DXCreateFont(g_device, 25, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font25);
	D3DXCreateFont(g_device, 35, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font35);
	D3DXCreateFont(g_device, 50, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font50);
	D3DXCreateFont(g_device, 70, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font70);
	D3DXCreateFont(g_device, 100, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font100);
	D3DXCreateFont(g_device, 150, 0, 10, 1, FALSE, HANGUL_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &m_Font150);
}


cImageManager::~cImageManager()
{
	for (auto iter : m_images) {
		SAFE_RELEASE(iter.second->texturePtr);
		SAFE_DELETE(iter.second);
	}

	m_images.clear();

	SAFE_RELEASE(m_Font25);
	SAFE_RELEASE(m_Font35);
	SAFE_RELEASE(m_Font50);
	SAFE_RELEASE(m_Font70);
	SAFE_RELEASE(m_Font100);
	SAFE_RELEASE(m_Font150);

	SAFE_RELEASE(m_sprite);
}

void cImageManager::Render(texture * texturePtr, float x, float y, float size)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat,size,0,0,&D3DXVECTOR2(x,y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void cImageManager::CenterRender(texture * texturePtr, float x, float y, float size)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, 0, 0,
			&D3DXVECTOR2(x - (texturePtr->info.Width / 2.f), y - (texturePtr->info.Height / 2.f)));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void cImageManager::Render(texture * texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, &D3DXVECTOR2(x + texturePtr->info.Width/2.f,y + texturePtr->info.Height / 2.f), rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void cImageManager::CenterRender(texture * texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, &D3DXVECTOR2(x, y), rot,
			&D3DXVECTOR2(x - (texturePtr->info.Width / 2.f), y - (texturePtr->info.Height / 2.f)));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void cImageManager::RectRender(texture * texturePtr, float x, float y, const RECT *rc, float size)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		D3DXMatrixAffineTransformation2D(&mat, size, 0, 0, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

texture * cImageManager::AddImage(const string & key, const string & path)
{
	auto find = m_images.find(key);

	if (find != m_images.end())
		return find->second;

	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texturePtr;

	if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK) {
		texture *text = new texture(texturePtr, info);
		m_images.insert(make_pair(key, text));
		return text;
	}

	DEBUG_LOG("[IMAGE LOADING FAILED]");
	DEBUG_LOG(key);
	DEBUG_LOG(path);
	return nullptr;
}

texture * cImageManager::FindImage(const string & key)
{
	auto find = m_images.find(key);

	if (find == m_images.end()) {
		DEBUG_LOG(key + " IMAGE FIND FAILED");
		return nullptr;
	}

	return find->second;
}

bool cImageManager::AddListImage(const string & key, const string & path, int StartNum, int EndNum, const string &fomat)
{
	for (int i = StartNum; i <= EndNum; i++) {
		string rPath = path + to_string(i) + fomat;
		string rKey = key + to_string(i);

		auto ptr = AddImage(rKey, rPath);
		if (ptr == nullptr) return false;
	}
	return true;
}


void cImageManager::sDrawText(float x, float y, const string & str, int size, D3DXCOLOR color)
{
	D3DXMATRIX mat;
	RECT rc = { 0 };
	D3DXMatrixTranslation(&mat, x, y, 0);

	m_sprite->SetTransform(&mat);

	switch (size) {
	case 25:
		m_Font25->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	case 35:
		m_Font35->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	case 50:
		m_Font50->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	case 70:
		m_Font70->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	case 100:
		m_Font100->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	case 150:
		m_Font150->DrawTextA(m_sprite, str.c_str(), str.size(), &rc, DT_NOCLIP, color);
		break;
	default:
		DEBUG_LOG("지원하는 텍스트 크기가 없습니다 . 50, 70, 100, 150 의 값중 하나를 고르세요");
		break;
	}
	return;
}


