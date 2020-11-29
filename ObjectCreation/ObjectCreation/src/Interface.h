#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <map>

template<typename T>
T* CreateInstance(std::string alias);

template<typename T>
class AbstractFactory
{
public:
	typedef std::function<T* ()> CreateMethod;
public:
	virtual ~AbstractFactory() {}
	virtual void Test() = 0;
	virtual void RegisterCreateMethod(std::string alias, CreateMethod createMethod) = 0;
	static AbstractFactory<T>* GetFactoryPtr() { return mpFactory; }
	virtual T* CreateInstance(std::string alias) = 0;
	virtual void SetFactoryPtr(AbstractFactory<T>* ptr) { mpFactory = ptr; }
public:
	static AbstractFactory<T>* mpFactory;
};

class FactoryHolder
{
private:
	
public:

};




#define DEFINE_INTERFACE_FACTORY_NAME(T) Factory_##T
#define DEFINE_INTERFACE_FACTORY_INSTANCE_NAME(T) Factory_##T##_Instance
#define DEFINE_INTERFACE_FACTORY_INSTANCE_PTR_NAME(T) Factory_##T##_Instance_Ptr

#define TO_STRING(T) #T


#define SPECLIALIZE_CREATE_INSTANCE(BaseClassName)														\
template<>																								\
BaseClassName* CreateInstance<BaseClassName>(std::string alias)											\
{																										\
	return DEFINE_INTERFACE_FACTORY_INSTANCE_NAME(BaseClassName).GetFactoryPtr()->CreateInstance(alias);\
}

#define DEFINE_INTERFACE_FACTORY(T)																\
class DEFINE_INTERFACE_FACTORY_NAME(T) : public AbstractFactory<T>								\
{																								\
private:																						\
	std::map<std::string, CreateMethod> mCreateMethods;											\
public:																							\
	void RegisterCreateMethod(std::string alias, CreateMethod createMethod)	override			\
	{																							\
		mCreateMethods[alias] = createMethod;													\
	}																							\
	T* CreateInstance(std::string alias) override												\
	{																							\
		if (mCreateMethods.find(alias) != mCreateMethods.end())									\
		{																						\
			return mCreateMethods[alias]();														\
		}																						\
		return nullptr;																			\
	}																							\
	void Test()	override																		\
	{																							\
		std::cout << TO_STRING(Factory_##T) << std::endl;										\
	}																							\
} DEFINE_INTERFACE_FACTORY_INSTANCE_NAME(T);													\
AbstractFactory<T>* AbstractFactory<T>::mpFactory = &DEFINE_INTERFACE_FACTORY_INSTANCE_NAME(T);	\
SPECLIALIZE_CREATE_INSTANCE(T)


#define IMPLEMENTATION(BaseClassName, ClassName, alias)													\
extern AbstractFactory<BaseClassName>* DEFINE_INTERFACE_FACTORY_INSTANCE_PTR_NAME(BaseClassName);		\
class Implementation_##BaseClassName##_##ClassName														\
{																										\
typedef std::function<BaseClassName*()> CreateMethod;													\
public:																									\
	Implementation_##BaseClassName##_##ClassName()														\
	{																									\
		CreateMethod createMethod = []()->BaseClassName*{return new ClassName();};						\
		AbstractFactory<BaseClassName>::GetFactoryPtr()->Test();										\
		AbstractFactory<BaseClassName>::GetFactoryPtr()->RegisterCreateMethod(alias, createMethod);		\
	}																									\
} Implementation_##BaseClassName##_##ClassName##_Instance;												\



