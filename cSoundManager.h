#pragma once
#include "singleton.h"

enum SOUND_STATE {
	E_NONE,
	E_PLAY,
	E_PAUSE,
	E_END
};

class cSoundManager :
	public singleton <cSoundManager>
{
private:
	// �뷡���� , �뷡 ���
	std::map<string, string> sounds;
	// �뷡���� , �뷡 ũ��
	std::map<string, int> soundSizes;
public:

	string nowSound;
	string nowSoundPath;

	DWORD curnTime;

	int soundState;
	int soundProgress;

	bool IsOnPlay;

public:
	cSoundManager();
	virtual ~cSoundManager();

	void Update();

	void AddSound(const string & key, const string & path, int soundSize = 0);
	void SelectSound(const string & key);
	bool SelectSound(int soundNumber);

	void pPlaySound();
	void pPauseSound();
	void pStopSound();

	INT GetSoundSize();

	INT GetNowSoundProgress();
	INT GetSoundNumber();
};

#define SOUNDMANAGER cSoundManager::GetInstance()