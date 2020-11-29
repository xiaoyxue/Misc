#pragma once
#include "common/Interface.h"

class IProductA
{
public:
	virtual void Process() = 0;
};

GY_INTERFACE_DEF(IProductA);



class IProductB
{
public:
	virtual void Process() = 0;
};
GY_INTERFACE_DEF(IProductB);



class IProductC
{
public:
	virtual void Process() = 0;
};
GY_INTERFACE_DEF(IProductC);