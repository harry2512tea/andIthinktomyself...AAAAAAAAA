

class SceneTime
{
public:
	static SceneTime* getInstance();
	void setDeltaTime(float value) { deltaTime = value; };
	float GetDeltaTime() { return deltaTime; };

private:
	static SceneTime* instance;
	float deltaTime;
};