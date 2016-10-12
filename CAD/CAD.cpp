// CAD.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"

using namespace CAD;
int main()
{	
	auto v1 = std::make_shared<Vertex>(1.0, 0.0, 0.0);
	auto v2 = std::make_shared<Vertex>(0.0, 1.0, 0.0);
	auto v3 = std::make_shared<Vertex>(0.0, 0.0, 0.0);
	auto v4 = std::make_shared<Vertex>(0.0, 0.0, 1.0);
	auto solid = mvfs(v1);
	mev(v1, v2, solid->face->loop);
	mev(v1, v3, solid->face->loop);

	mef(v2, v3, solid->face->loop);

	mev(v1, v4, solid->face->loop);
	mef(v2, v4, solid->face->loop);
	mef(v3, v4, solid->face->loop);
    return 0;
}

