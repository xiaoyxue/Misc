#pragma once
#include <iostream>
#include "common/Interface.h"

class Camera
{
public:
	virtual void Print() {
		std::cout << "this is abstract camera" << std::endl;
	}
};

GY_INTERFACE_DEF(Camera);



