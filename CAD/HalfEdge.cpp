#include "HalfEdge.h"

CAD::Vertex::Vertex(double d1, double d2, double d3)
{
	position[0] = d1;
	position[1] = d2;
	position[2] = d3;
}

CAD::pH CAD::mev(pV v1, pV v2, pL loop)
{
	auto he1 = std::make_shared<HalfEdge>(v1, v2);
	auto he2 = std::make_shared<HalfEdge>(v2, v1);

	auto edge = std::make_shared<Edge>();
	he1->edge = edge;
	he2->edge = edge;
	edge->halfEdge1 = he1;
	edge->halfEdge2 = he2;

	loop->face->solid->vertexs.push_back(v2);
	he1->pair = he2;
	he2->pair = he1;
	he1->loop = he2->loop = loop;

	if (!loop->halfEdge)
	{
		he1->prev = he2;
		he2->prev = he1;
		he1->next = he2;
		he2->next = he1;
		loop->halfEdge = he1;
	}
	else
	{
		auto halfedge = loop->halfEdge;
		while (halfedge->next->start != v1)
			halfedge = halfedge->next;

		he1->next = he2;
		he1->prev = halfedge;

		he2->prev = he1;
		he2->next = halfedge->next;

		halfedge->next->prev = he2;
		halfedge->next = he1;
	}

	return he1;
}

CAD::pL CAD::mef(pV v1, pV v2, pL loop)
{
	auto he1 = std::make_shared<HalfEdge>(v1, v2);
	auto he2 = std::make_shared<HalfEdge>(v2, v1);

	he1->pair = he2;
	he2->pair = he1;

	auto edge = std::make_shared<Edge>();
	he1->edge = edge;
	he2->edge = edge;
	edge->halfEdge1 = he1;
	edge->halfEdge2 = he2;

	auto the = loop->halfEdge;
	while (the->start != v1)
		the = the->next;

	auto t1 = the;

	while (the->start != v2)
	{
		the = the->next;
	}

	the = the->next;
	while (the->start != v2)
	{
		the = the->next;
	}

	auto t2 = the;

	he1->prev = t1->prev;
	he1->next = t2;
	he2->prev = t2->prev;
	he2->next = t1;

	t1->prev->next = he1;
	t1->prev = he2;

	t2->prev->next = he2;
	t2->prev = he1;



	auto newloop = std::make_shared<Loop>();
	loop->halfEdge = he2;
	newloop->halfEdge = he1;

	auto newface = std::make_shared<Face>();
	newface->loop = newloop;
	newloop->face = newface;

	auto solid = loop->face->solid;
	newface->solid = solid;
	auto tf = solid->face;
	while (tf->next)
	{
		tf = tf->next;
	}

	tf->next = newface;
	newface->prev = tf;

	auto e = solid->edge;
	while (e&&e->next)
	{
		e = e->next;
	}

	if (!e)
		solid->edge = e;
	else
	{
		e->next = edge;
		edge->prev = e;
	}

	return loop;
}
