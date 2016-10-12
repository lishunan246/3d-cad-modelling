// CAD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{	
	auto v1 = std::make_shared<Vertex>(1.0, 0.0, 0.0);
	auto v2 = std::make_shared<Vertex>(0.0, 1.0, 0.0);
	auto v3 = std::make_shared<Vertex>(0.0, 0.0, 0.0);
	auto v4 = std::make_shared<Vertex>(0.0, 0.0, 1.0);
	auto solid = mvfs(v1);
	mev(v1,v2)

    return 0;
}

