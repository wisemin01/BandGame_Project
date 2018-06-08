#include "DXUT.h"
#include "cDisplaySong.h"


cDisplaySong::cDisplaySong()
{
	songName[0] = IMAGEMANAGER->FindImage("Amorfati");
	songName[1] = IMAGEMANAGER->FindImage("Celeb");
	songName[2] = IMAGEMANAGER->FindImage("Jinjin");
	songName[3] = IMAGEMANAGER->FindImage("Love");
	songName[4] = IMAGEMANAGER->FindImage("SeeMe");
}


cDisplaySong::~cDisplaySong()
{

}

void cDisplaySong::Render()
{
	songName[SOUNDMANAGER->GetSoundNumber()]->CenterRender(WINSIZEX / 2 + 40, WINSIZEY / 2 - 225);
}
