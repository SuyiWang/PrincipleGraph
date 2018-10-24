#include"pointset.h"

point_set::point_set(){

}
point_set::point_set(const point_set &p){
	pts.clear();
	for (const auto item:p.get_pts())
		pts.push_back(item);
}

int point_set::fromfile(std::string filename){
	FILE* fp = fopen(filename.c_str(), "r");
	int x,y,z,w;

	int counter = 0; 
	while(fscanf(fp, "%d%d%d%d", &x, &y, &z, &w) != EOF){
		point p(x,y,z);
		pts.push_back(p);
		// example usage
		// printf("%f %f %f\n", p.get<0>(), p.get<1>(), p.get<2>());
		counter++;
	}

	#if Debug
		printf("%d lines read\n", counter);
	#endif

	fclose(fp);
	return 0;
}

int point_set::writefile(std::string filename){
	return 0;
}

int point_set::build_Rtree(){
	for(unsigned int i = 0; i < pts.size(); ++i){
		rtree.insert({pts[i], i});
	}
	return 0;
}

std::vector<value> point_set::knn(point p, unsigned int k){
	std::vector<value> result_n;
	rtree.query(bgi::nearest(p, k), std::back_inserter(result_n));
	return result_n;
}

bool point_set::at_idx(int n, point &p){
	if (n < pts.size() && n >=0){
		p = pts[n];
		return true;
	}else{
		return false;
	}
}

int point_set::size(){
	return pts.size();
}

std::vector<point> point_set::get_pts() const{
	return pts;
}
