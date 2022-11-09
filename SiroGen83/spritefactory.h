#pragma once

class SpriteFactory {

public:
	SpriteFactory(const SpriteFactory&) = delete;

	static SpriteFactory* GetInstance()
	{
		if (!_instance)
		{
			_instance = new SpriteFactory();
		}
		return _instance;
	}

private:
	SpriteFactory();
	static SpriteFactory* _instance;
};

