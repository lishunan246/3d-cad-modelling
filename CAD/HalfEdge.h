#ifndef __HALFEDGE_H__
#define __HALFEDGE_H__

#include <memory>
#include <vector>

namespace CAD
{
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
		std::vector<pV> vertexs;
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
		//pE edge;
		pL prev, next;
	};

	class HalfEdge
	{
	public:
		pL loop;
		pH prev, next, pair;
		pV start, end;
		pE edge;

		HalfEdge(pV s, pV e) :start(s), end(e) {}
	};

	class Edge
	{
	public:
		pH halfEdge1, halfEdge2;
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
	inline pS mvfs(pV v, pF face = nullptr) 
	{
		auto s = std::make_shared<Solid>();
		auto f = std::make_shared<Face>();
		auto l = std::make_shared<Loop>();

		s->face = f;
		f->solid = s;

		f->loop = l;
		l->face = f;

		s->vertexs.push_back(v);
		return s;
	}

	void kvsf(pV, pF);
	pH mev(pV v1, pV v2, pL loop);
	
	void kev(pE, pV);

	pL mef(pV v1, pV v2, pL loop);
	

	void kef(pE);
	void mekr(pV, pV, pE);
	void kemr(pE);
	void kfmrh(pF, pF);
	void mfkrh(pF, pF);
	void semv(pE, pV, pE);
	void jekv(pE, pE);
}
#endif // !__HALFEDGE_H__
