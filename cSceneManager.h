#pragma once
#include "singleton.h"

// ������ ���� , ���� ���� Update�� Render�� ���� ó�����ִ� Ŭ������
// cSceneManager�� �����ߴ�.

class cScene;
class cSceneManager :
	public singleton<cSceneManager>
{
private:

	// map �ڷ����� ���ڿ��� cScene�� �����͸� �����
	// ���ڿ��� ���� �߰�/ã�Ⱑ �����ϴ�.

	map<string, cScene*> m_scenes;

	cScene * nowScene;	// ���� ���� ������
	cScene * nextScene;	// ���� ���� ������

private:
	void Init();
	void Release();
public:
	cSceneManager() { Init(); }
	virtual ~cSceneManager() { Release(); }

	void Update();
	void Render();
	
	cScene* AddScene(const string &key, cScene* ptr);
	cScene* ChangeScene(const string &key);
};

#define SCENEMANAGER cSceneManager::GetInstance()