#include "Camera.h"

class PhinholeCamera : public Camera
{
public:
	void Print() override {
		std::cout << "this is phinhole camera" << std::endl;
	}
};
GY_IMPLEMENTATION_DEF(Camera, PhinholeCamera, "phinhole");