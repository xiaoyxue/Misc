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

	Camera* pRawcamera = CreateInstanceRawPtr<Camera>("phinhole");
	pRawcamera->Print();

	auto pSharedCamera = CreateInstanceSharedPtr<Camera>("phinhole");
	pSharedCamera->Print();

	auto pUniqueCamera = CreateInstanceUniquePtr<Camera>("phinhole");
	pUniqueCamera->Print();
	return 0;
}