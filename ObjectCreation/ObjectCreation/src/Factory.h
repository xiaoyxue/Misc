#pragma once
#include <string>
#include <map>

template<typename T>
class ICreator
{
public:
	virtual T* Create() = 0;
	virtual ~ICreator() {}
};

template<typename T>
class Factory
{
private:
	std::map<std::string, ICreator<T>*> mCreators;
public:
	Factory() = default;
	void AddCreator(std::string alias, ICreator<T>* pCreator)
	{
		mCreators[alias] = pCreator;
	}
	T* CreateInstance(std::string alias) 
	{
		if (mCreators.find(alias) != mCreators.end())
		{
			return mCreators[alias]->Create();
		}
		return nullptr;
	}
};
