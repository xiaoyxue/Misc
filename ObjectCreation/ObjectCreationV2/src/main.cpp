#include <iostream>
#include "common/Interface.h"
#include "products/IProduct.h"
#include "products/Camera.h"

int main()
{
	IProductA* productA1 = CreateInstanceRawPtr<IProductA>("Product1");
	productA1->Process();

	IProductB* productB1 = CreateInstanceRawPtr<IProductB>("Product1");
	productB1->Process();

	IProductC* productC = CreateInstanceRawPtr<IProductC>("ProductC");
	productC->Process();

	Camera* pRawcamera = CreateInstanceRawPtr<Camera>("pinhole");
	pRawcamera->Print();

	auto pSharedCamera = CreateInstanceSharedPtr<Camera>("pinhole");
	pSharedCamera->Print();

	auto pUniqueCamera = CreateInstanceUniquePtr<Camera>("pinhole");
	pUniqueCamera->Print();


	return 0;
}