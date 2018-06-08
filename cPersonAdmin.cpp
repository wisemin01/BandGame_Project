#include "DXUT.h"
#include "cPersonAdmin.h"
#include "FrameAni.h"

cPersonAdmin::cPersonAdmin() :
	soundManager(SOUNDMANAGER)
{
	Init();
}


cPersonAdmin::~cPersonAdmin()
{
	Release();
}

void cPersonAdmin::Init()
{
	corus[EP_PLAY] = new FrameAni("Corus", 150, 10, D3DXVECTOR2(WINSIZEX / 2 + 450, WINSIZEY / 2 + 30));
	corus2[EP_PLAY] = new FrameAni("Corus2", 150, 10, D3DXVECTOR2(WINSIZEX / 2 - 470, WINSIZEY / 2 + 20));
	singer[EP_PLAY] = new FrameAni("Singer", 150, 10, D3DXVECTOR2(WINSIZEX / 2 + 10, WINSIZEY / 2 + 30));
	backDancer[EP_PLAY] = new FrameAni("BackDancer", 150, 10, D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2 + 40));

	corus[EP_IDLE] = new FrameAni("IDLE_Corus", 300, 5, D3DXVECTOR2(WINSIZEX / 2 + 450, WINSIZEY / 2 + 30));
	corus2[EP_IDLE] = new FrameAni("IDLE_Corus2", 300, 5, D3DXVECTOR2(WINSIZEX / 2 - 470, WINSIZEY / 2 + 30));
	singer[EP_IDLE] = new FrameAni("IDLE_Singer", 300, 5, D3DXVECTOR2(WINSIZEX / 2 + 10, WINSIZEY / 2 + 30));
	singer[EP_IDLE2] = new FrameAni("IDLE_Singer", 1000, 1, D3DXVECTOR2(WINSIZEX / 2 + 10, WINSIZEY / 2 + 30));
	backDancer[EP_IDLE] = new FrameAni("IDLE_BackDancer", 300, 2, D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2 + 50));
	backDancer[EP_IDLE2] = new FrameAni("IDLE_BackDancer2", 300, 8, D3DXVECTOR2(WINSIZEX / 2, WINSIZEY / 2 + 40));

	frontSound = SOUNDMANAGER->nowSound;
	frontTime = 0;
	StateAdmin = new PersonsState(EP_IDLE, EP_IDLE, EP_IDLE, EP_IDLE);

	FILE *stream = nullptr;

	string path;
	path = "./animation_info/" + soundManager->nowSound + ".txt";
	stream = fopen(path.c_str(), "r");
	MAP_CLEAR(StateList);

	int size;
	fscanf(stream, "SIZE : %d", &size);

	for (int i = 0; i < size; i++) {
		PersonsState *sta = new PersonsState(EP_IDLE, EP_IDLE, EP_IDLE, EP_IDLE);
		INT t;
		fscanf(stream, "%d : %d %d %d %d", &t, &sta->Corus, &sta->Corus2, &sta->Singer, &sta->backDancer);

		StateList.insert(make_pair(t, sta));
	}
	fclose(stream);
}

void cPersonAdmin::Update()
{
	UpdateSoundList();
	UpdatePersonState();

	if (SOUNDMANAGER->soundState == E_PLAY) {
		corus[StateAdmin->Corus]->Update();
		corus2[StateAdmin->Corus2]->Update();
		backDancer[StateAdmin->backDancer]->Update();
		singer[StateAdmin->Singer]->Update();
	}
	else {
		corus[EP_IDLE]->Update();
		corus2[EP_IDLE]->Update();
		backDancer[EP_IDLE]->Update();
		singer[EP_IDLE]->Update();
	}
}

void cPersonAdmin::Render()
{
	if (SOUNDMANAGER->soundState == E_PLAY) {
		backDancer[StateAdmin->backDancer]->Render();
		corus[StateAdmin->Corus]->Render();
		corus2[StateAdmin->Corus2]->Render();
		singer[StateAdmin->Singer]->Render();
	}
	else {
		backDancer[EP_IDLE]->Render();
		corus[EP_IDLE]->Render();
		corus2[EP_IDLE]->Render();
		singer[EP_IDLE]->Render();
	}
}

void cPersonAdmin::Release()
{
	for (int i = EP_IDLE; i <= EP_PLAY; i++) {
		SAFE_DELETE(corus[i]);
		SAFE_DELETE(corus2[i]);
		SAFE_DELETE(singer[i]);
		SAFE_DELETE(backDancer[i]);
	}
	MAP_CLEAR(StateList);

	SAFE_DELETE(backDancer[EP_IDLE2]);
	SAFE_DELETE(singer[EP_IDLE2]);
	SAFE_DELETE(StateAdmin);

	frontSound.clear();
}

void cPersonAdmin::UpdatePersonState()
{
	if (frontTime != SOUNDMANAGER->GetNowSoundProgress())
	{
		// TODO
		auto find = StateList.find(SOUNDMANAGER->GetNowSoundProgress());

		if (find != StateList.end()) {
			SAFE_DELETE(StateAdmin);
			PersonsState *State = new PersonsState(*find->second);
			StateAdmin = State;
		}
	}

	frontTime = SOUNDMANAGER->GetNowSoundProgress();
}

void cPersonAdmin::UpdateSoundList()
{
	if (frontSound != soundManager->nowSound)
	{
		// TODO

		FILE *stream;
		string path = "./animation_info/" + soundManager->nowSound + ".txt";

		stream = fopen(path.c_str(), "r");
		for (auto iter : StateList) { SAFE_DELETE(iter.second); }
		StateList.clear();

		int size;
		fscanf(stream, "SIZE : %d", &size);

		for (int i = 0; i < size; i++) {
			PersonsState *sta = new PersonsState();
			INT t;
			fscanf(stream, "%d : %d %d %d %d", &t, &sta->Corus, &sta->Corus2, &sta->Singer, &sta->backDancer);

			StateList.insert(make_pair(t, sta));
		}
		fclose(stream);

		StateAdmin->Initialize();
		frontTime = 0;
	}

	frontSound = soundManager->nowSound;
}