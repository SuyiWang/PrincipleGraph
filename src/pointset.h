#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

#include<string>
#include<vector>

#define Debug true

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

typedef bg::model::point<float, 3, bg::cs::cartesian> point;
typedef std::pair<point, unsigned> value;

// Ref: https://www.boost.org/doc/libs/1_68_0/libs/geometry/doc/html/geometry/spatial_indexes/rtree_quickstart.html
// knn uses r-tree

class point_set{
private:
	std::vector<point> pts;
	bgi::rtree< value, bgi::quadratic<16> > rtree;

public:
	point_set();
	point_set(const point_set &p);

	// public methods
	int fromfile(std::string);
	int writefile(std::string);
	int build_Rtree();
	std::vector<value> knn(point, unsigned int);
	
	// member methods
	bool at_idx(int n, point& p);
	int size();
	std::vector<point> get_pts() const;
};
