#include "DXUT.h"
#include "maingame.h"

// �� include 
#include "cLoadingScene.h"
#include "cIntroScene.h"
#include "cActionScene.h"
#include "cIngameScene.h"

void maingame::Init()
{
#if (FALSE)
	ZeroMemory(&devMode, sizeof(DEVMODE));

	devMode.dmSize = sizeof(DEVMODE);
	devMode.dmBitsPerPel = 32;
	devMode.dmPelsHeight = WINSIZEY;
	devMode.dmPelsWidth = WINSIZEX;
	devMode.dmFields = DM_BITSPERPEL | DM_PELSHEIGHT | DM_PELSWIDTH;
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
#endif
	// ���⼭ �� ������ ��� �߰�
	SCENEMANAGER->AddScene("loading", new cLoadingScene);
	SCENEMANAGER->AddScene("action", new cActionScene);
	SCENEMANAGER->AddScene("intro", new cIntroScene);
	SCENEMANAGER->AddScene("ingame", new cIngameScene);

	// ù��° �� ����
	SCENEMANAGER->ChangeScene("loading");
}

void maingame::Update()
{
	SOUNDMANAGER->Update();
	INPUTMANAGER->Update();
	SCENEMANAGER->Update();
}

void maingame::Render()
{
	// ���̷�Ʈ X �� �׷��� ó���� sprite��ü�� ó���Ǳ� ������
	// ���� �۾� �� Begin() �۾� �Ŀ� End() �Լ��� ȣ����

	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();

}

void maingame::Release()
{
	// maingame Ŭ������ ���� �ڵ� �߰� : 
	cImageManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cInputManager::ReleaseInstance();
	cSoundManager::ReleaseInstance();

#if (FALSE)
	ZeroMemory(&devMode, sizeof(DEVMODE));

	devMode.dmSize = sizeof(DEVMODE);
	devMode.dmBitsPerPel = 32;
	devMode.dmPelsHeight = defaultX;
	devMode.dmPelsWidth = defaultX;
	devMode.dmFields = DM_BITSPERPEL | DM_PELSHEIGHT | DM_PELSWIDTH;
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
#endif
}


void maingame::OnLostDevice()
{
	IMAGEMANAGER->OnLostDevice();
}

void maingame::OnResetDevice()
{
	IMAGEMANAGER->OnLostDevice();
}
