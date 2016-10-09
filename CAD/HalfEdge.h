#pragma once
#include <memory>

class Solid;
class Face;
class Loop;
class HalfEdge;
class Edge;
class Vertex;

using pS = std::shared_ptr<Solid>;
using pF = std::shared_ptr<Face>;
using pL = std::shared_ptr<Loop>;
using pH = std::shared_ptr<HalfEdge>;
using pE = std::shared_ptr<Edge>;
using pV = std::shared_ptr<Vertex>;

class Solid
{
public:
	pF face;
	pS prev, next;
	pE edge;
};

class Face
{
public:
	pS solid;
	pL loop;
	pF prev, next;
};

class Loop
{
public:
	pF face;
	pH halfEdge;
	pL prev, next;
};

class HalfEdge
{
public:
	pL loop;
	pH prev, next;
	pV vertex;
	pE edge;
};

class Edge
{
public:
	pH halfEdge;
	pE prev, next;
};

class Vertex
{
public:
	pV prev, next;
	double position[3];

	Vertex(double d1, double d2, double d3);
};

/**
 * \brief 
 * \return 
 */
pS mvfs(pV, pF)
{
	auto s = std::make_shared<Solid>();
	auto f = std::make_shared<Face>();
	auto l = std::make_shared<Loop>();

	s->face = f;
	f->solid = s;

	f->loop = l;
	l->face = f;

	return s;
}