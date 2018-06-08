#include "DXUT.h"
#include "maingame.h"

// 씬 include 
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
	// 여기서 각 씬들을 모두 추가
	SCENEMANAGER->AddScene("loading", new cLoadingScene);
	SCENEMANAGER->AddScene("action", new cActionScene);
	SCENEMANAGER->AddScene("intro", new cIntroScene);
	SCENEMANAGER->AddScene("ingame", new cIngameScene);

	// 첫번째 씬 배정
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
	// 다이렉트 X 의 그래픽 처리는 sprite객체로 처리되기 때문에
	// 렌더 작업 전 Begin() 작업 후에 End() 함수를 호출함

	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();

}

void maingame::Release()
{
	// maingame 클래스의 해제 코드 추가 : 
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
