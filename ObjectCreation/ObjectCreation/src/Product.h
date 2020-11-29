#pragma once
#include "IProduct.h"
#include "Factory.h"
#include <iostream>

class ProductA : public IProduct
{
public:
	ProductA() = default;
	virtual ~ProductA() {}
	void Process() override
	{
		std::cout << "ProductA" << std::endl;
	}
};


class ProductACreator : public ICreator<IProduct>
{
	IProduct* Create() override
	{
		return new ProductA;
	}
};


class ProductB : public IProduct
{
public:
	ProductB() = default;
	virtual ~ProductB() {}
	void Process() override
	{
		std::cout << "ProductB" << std::endl;
	}
};


class ProductBCreator : public ICreator<IProduct>
{
	IProduct* Create() override
	{
		return new ProductB;
	}
};


class ProductC : public IProduct
{
public:
	ProductC() = default;
	virtual ~ProductC() {}
	void Process() override
	{
		std::cout << "ProductC" << std::endl;
	}
};


class ProductCCreator : public ICreator<IProduct>
{
	IProduct* Create() override
	{
		return new ProductC;
	}
};