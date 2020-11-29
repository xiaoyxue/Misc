#pragma once

class IProduct
{
public:
	virtual ~IProduct() {}
	virtual void Process() {}
};

class IProduct1
{
public:
	virtual ~IProduct1() {}
	virtual void Process() {}
};

class IProduct2
{
public:
	virtual ~IProduct2() {}
	virtual void Process() = 0;
};


class IProduct3
{
public:
	virtual ~IProduct3() {}
	virtual void Process() = 0;
};