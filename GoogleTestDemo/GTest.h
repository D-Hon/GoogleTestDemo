#pragma once

#include <gtest/gtest.h>
#ifdef _DEBUG
#pragma comment(lib,"gtestd.lib")
#pragma comment(lib,"gtest_maind.lib")
#else
#pragma comment(lib,"gtest.lib")
#pragma comment(lib,"gtest_main.lib")
#endif


class CGT
	: public ::testing::Test
{
public:
	CGT()
	{
		printf("CGT\n");
	};

	~CGT()
	{
		printf("~CGT\n");
	};
	//奇数校验
	bool COdd(int nValue)
	{
		return (1 == (nValue % 2)) ? true : false;
	}
	//偶数校验
	bool CEven(int nValue)
	{
		return (0 == (nValue % 2)) ? true : false;
	}

	//每个测试[-][特例]开始前将会执行一次 Suite
	void SetUp()
	{
		printf("CGT SetUp\n");
	};
	//每个测试[-][特例]结束后将会执行一次 Suite
	void TearDown()
	{
		printf("CGT TearDown\n");
	};
	//每个测试[用例][-]开始前将会执行一次 Case
	static void SetUpTestCase()
	{
		printf("CGT SetUpTestCase\n");
	}
	//每个测试[用例][-]结束后将会执行一次 Case
	static void TearDownTestCase()
	{
		printf("CGT TearDownTestCase\n");
	}

};
