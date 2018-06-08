#pragma once

enum PERSON_STATE {
	EP_IDLE,
	EP_PLAY,
	EP_IDLE2
};

struct PersonsState {

	INT Corus;
	INT Corus2;
	INT Singer;
	INT backDancer;

	PersonsState() :
		Corus(EP_IDLE), Corus2(EP_IDLE), Singer(EP_IDLE), backDancer(EP_IDLE) {}
	PersonsState(PERSON_STATE corus, PERSON_STATE corus2, PERSON_STATE singer, PERSON_STATE backDancer) :
		Corus(corus), Corus2(corus2), Singer(singer), backDancer(backDancer) {}
	~PersonsState() {}

	inline void Initialize() {
		Corus = EP_IDLE; Corus2 = EP_IDLE; Singer = EP_IDLE; backDancer = EP_IDLE;
	}
};

class FrameAni;

class cPersonAdmin
{
private:

	FrameAni * corus[2];
	FrameAni * corus2[2];
	FrameAni * singer[3];
	FrameAni * backDancer[3];

	PersonsState * StateAdmin;

	map<INT, PersonsState*> StateList;
	INT frontTime;
	string frontSound;

	cSoundManager *soundManager;

public:
	cPersonAdmin();
	~cPersonAdmin();

	void Init();
	void Update();
	void Render();
	void Release();

	void UpdatePersonState();
	void UpdateSoundList();
};

