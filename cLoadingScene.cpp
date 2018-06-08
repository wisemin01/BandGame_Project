#include "DXUT.h"
#include "cLoadingScene.h"


cLoadingScene::cLoadingScene()
{
}


cLoadingScene::~cLoadingScene()
{
}

void cLoadingScene::Init()
{
}

void cLoadingScene::Update()
{
	LoadingFunc();
	//if (GETKEY_DOWN(VK_LBUTTON))
	SCENEMANAGER->ChangeScene("action");
}

void cLoadingScene::Render()
{
}

void cLoadingScene::Release()
{

}

void cLoadingScene::LoadingFunc()
{
	// 이미지 로딩

	IMAGEMANAGER->AddImage("backGround1", "./image/ingameBackGround/ingameBG1.png");
	IMAGEMANAGER->AddImage("backGround2", "./image/ingameBackGround/ingameBG2.png");
	IMAGEMANAGER->AddImage("backGround3", "./image/ingameBackGround/ingameBG3.png");

	IMAGEMANAGER->AddListImage("pattern1", "./image/pattern1/", 1, 10);
	IMAGEMANAGER->AddListImage("pattern2", "./image/pattern2/", 1, 10);
	IMAGEMANAGER->AddListImage("pattern3", "./image/pattern3/", 1, 10);

	IMAGEMANAGER->AddImage("Credit", "./image/startScenes/Credit.png");
	IMAGEMANAGER->AddImage("Info", "./image/startScenes/Info.png");
	IMAGEMANAGER->AddImage("StartScene", "./image/startScenes/startScene.png");

	IMAGEMANAGER->AddListImage("CreditButton_", "./image/ui/Credit", 1, 3);
	IMAGEMANAGER->AddListImage("StartButton_", "./image/ui/Start", 1, 3);
	IMAGEMANAGER->AddListImage("UseButton_", "./image/ui/Use", 1, 3);
	
	IMAGEMANAGER->AddListImage("selectLED1", "./image/SelectLED/s1_", 1, 2);
	IMAGEMANAGER->AddListImage("selectLED2", "./image/SelectLED/s2_", 1, 2);
	IMAGEMANAGER->AddListImage("selectLED3", "./image/SelectLED/s3_", 1, 2);
	IMAGEMANAGER->AddListImage("selectLED4", "./image/SelectLED/s4_", 1, 2);
	IMAGEMANAGER->AddListImage("selectLED5", "./image/SelectLED/s5_", 1, 2);

	IMAGEMANAGER->AddListImage("ExitButton_", "./image/ingameUI/Exit", 1, 3);
	IMAGEMANAGER->AddListImage("GotoStartButton_", "./image/ingameUI/GotoStart", 1, 3);
	IMAGEMANAGER->AddListImage("LeftButton_", "./image/ingameUI/Left", 1, 3);
	IMAGEMANAGER->AddListImage("RightButton_", "./image/ingameUI/Right", 1, 3);
	IMAGEMANAGER->AddListImage("PlayButton_", "./image/ingameUI/Play", 1, 4);

	IMAGEMANAGER->AddListImage("progressBar", "./image/ingameUI/progressBar", 1, 2);

	IMAGEMANAGER->AddImage("Amorfati", "./image/SongName/Amorfati.png");
	IMAGEMANAGER->AddImage("Celeb", "./image/SongName/Celeb.png");
	IMAGEMANAGER->AddImage("Jinjin", "./image/SongName/Jinjin.png");
	IMAGEMANAGER->AddImage("Love", "./image/SongName/Love.png");
	IMAGEMANAGER->AddImage("SeeMe", "./image/SongName/SeeMe.png");

	IMAGEMANAGER->AddListImage("Light", "./image/light/", 1, 3);

	// Person

	IMAGEMANAGER->AddListImage("Corus", "./image/corus/", 1, 10);
	IMAGEMANAGER->AddListImage("Corus2", "./image/corus2/", 1, 10);
	IMAGEMANAGER->AddListImage("Fan", "./image/fan/", 1, 3);
	IMAGEMANAGER->AddListImage("Singer", "./image/singer/", 1, 10);
	IMAGEMANAGER->AddListImage("BackDancer", "./image/backDancer/", 1, 10);

	// idle

	IMAGEMANAGER->AddListImage("IDLE_Corus", "./image/idle/Corus/", 1, 5);
	IMAGEMANAGER->AddListImage("IDLE_Corus2", "./image/idle/Corus2/", 1, 5);
	IMAGEMANAGER->AddListImage("IDLE_BackDancer", "./image/idle/backDancer/", 1, 2);
	IMAGEMANAGER->AddListImage("IDLE_BackDancer2", "./image/idle/backDancer2/", 1, 8);
	IMAGEMANAGER->AddListImage("IDLE_Singer", "./image/idle/singer/", 1, 5);
	
	//IsEndLoading = true;

}
