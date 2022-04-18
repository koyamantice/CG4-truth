#include "SceneFactory.h"
#include "TitleScene.h"
#include "PlayScene.h"
//#include "BossScene.h"
//#include "GameoverScene.h"
//#include "ClearScene.h"


BaseScene* SceneFactory::CreateScene(const std::string& sceneName) {
	//éüÇÃÉVÅ[ÉìÇÃçÏê¨
	BaseScene* newScene = nullptr;
	if (sceneName=="TITLE") {
		newScene=new TitleScene();
	}
	else if (sceneName == "PlayScene") {
		newScene = new PlayScene();
	}
	//else if(sceneName == "BOSS"){
	//	newScene = new BossScene();
	//}
	//else if (sceneName == "GAMEOVER") {
	//	newScene = new GameoverScene();
	//}
	//else if (sceneName == "CLEAR") {
	//	newScene = new ClearScene();
	//}
	return newScene;
}
