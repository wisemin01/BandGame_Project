#include "DXUT.h"
#include "cSoundManager.h"


cSoundManager::cSoundManager()
{
	AddSound("Amorfati", "./sound/Amorfati.mp3", 218); // default 218
	AddSound("Celeb", "./sound/Celeb.mp3", 149); // 3 : 10 - 25초
	AddSound("Jinjin", "./sound/Jinjin.mp3", 214); // 3 : 34
	AddSound("Love", "./sound/Love.mp3", 207); // 3 : 27
	AddSound("SeeMe", "./sound/SeeMe.mp3", 165); // 2 : 45

	soundState = E_NONE;
	soundProgress = 0;

	IsOnPlay = false;

	curnTime = g_nowTime;
}


cSoundManager::~cSoundManager()
{
	sounds.clear();
	soundSizes.clear();
}

void cSoundManager::Update()
{
	if (soundState == E_PAUSE)
		curnTime += deltaTime;
	else if (soundState == E_PLAY) {
		if (curnTime <= g_nowTime) {

			soundProgress++;

			if (soundProgress >= soundSizes.find(nowSound)->second)
				pStopSound();

			curnTime = g_nowTime + 1000;

		}
	}
}

void cSoundManager::AddSound(const string & key, const string & path, int soundSize)
{
	auto find = sounds.find(key);

	if (find != sounds.end()) {
		DEBUG_LOG(key + " SOUND ADD FAILED");
		return;
	}

	// 노래제목 , 노래 경로
	sounds.insert(make_pair(key, path));
	// 노래제목 , 노래 크기
	soundSizes.insert(make_pair(key, soundSize));
}

void cSoundManager::SelectSound(const string & key)
{
	auto find = sounds.find(key);

	if (find == sounds.end()) {
		DEBUG_LOG(key + " SOUND SELECT FAILED");
		return;
	}

	if (soundState == E_PAUSE)
		pStopSound();

	nowSound = find->first;
	nowSoundPath = find->second;
	soundProgress = 0;
}

bool cSoundManager::SelectSound(int soundNumber)
{
	if (soundState == E_PLAY)
		return false;

	switch (soundNumber) {
	case 0:
		SelectSound("Amorfati");
		break;
	case 1:
		SelectSound("Celeb");
		break;
	case 2:
		SelectSound("Jinjin");
		break;
	case 3:
		SelectSound("Love");
		break;
	case 4:
		SelectSound("SeeMe");
		break;
	default:
		DEBUG_LOG("SelectSound(INT) - Select Failed");
		break;
	}
	return true;
}

void cSoundManager::pPlaySound()
{
	IsOnPlay = true;
	soundState = E_PLAY;
	string buf = "play " + nowSoundPath;
	mciSendStringA(buf.c_str(), 0, 0, 0);
}

void cSoundManager::pPauseSound()
{
	IsOnPlay = false;
	soundState = E_PAUSE;

	string buf = "pause " + nowSoundPath;
	mciSendStringA(buf.c_str(), 0, 0, 0);
}

void cSoundManager::pStopSound()
{
	IsOnPlay = false;
	soundState = E_NONE;
	soundProgress = 0;

	string buf = "stop " + nowSoundPath;
	mciSendStringA(buf.c_str(), 0, 0, 0);
}

INT cSoundManager::GetSoundSize()
{
	auto find = soundSizes.find(nowSound);

	if (find == soundSizes.end())
		return 0;

	return find->second;
}

INT cSoundManager::GetNowSoundProgress()
{
	return soundProgress;
}

INT cSoundManager::GetSoundNumber()
{
	if (nowSound == "Amorfati")
		return 0;
	else if (nowSound == "Celeb")
		return 1;
	else if (nowSound == "Jinjin")
		return 2;
	else if (nowSound == "Love")
		return 3;
	else if (nowSound == "SeeMe")
		return 4;
	else {
		DEBUG_LOG("현재 재생 정보 오류");
		return -1;
	}
}
