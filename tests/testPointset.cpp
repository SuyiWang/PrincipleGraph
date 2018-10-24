#include<stdio.h>
#include<pointset.h>
#include<math.h>
#include<cstdlib>
#include<time.h>

void printpoint(point p){
	printf("Point: %f %f %f", p.get<0>(), p.get<1>(), p.get<2>());
}

void printvector(std::vector<value> result_knn){
	for(auto p:result_knn){
		printpoint(p.first);
		printf("  %d\n", p.second);
	}
}


double distance(point p1, point p2){
	double d1 = p1.get<0>()-p2.get<0>();
	double d2 = p1.get<1>()-p2.get<1>();
	double d3 = p1.get<2>()-p2.get<2>();
	return sqrt(d1*d1 + d2*d2 + d3*d3);
}


void printdistance(point p, std::vector<value> result_knn){
	for(auto resp:result_knn){
		printf("%f ", distance(p, resp.first));
	}
	printf("\n");
}


void show_result(point p, std::vector<value> result_knn){
	printpoint(p);
	printf("\n");
	//printvector(result_knn);
	printdistance(p, result_knn);
}


int testknn(point_set dp){
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		std::vector<value> result_knn;
		point p;
		dp.at_idx(rand()%dp.size(), p);
		result_knn = dp.knn(p, 20);
		show_result(p, result_knn);
	}
}


int testtime(point_set dp){
	srand(time(NULL));
	for (int i = 0; i < dp.size(); i++){
		std::vector<value> result_knn;
		point p;
		dp.at_idx(i, p);
		result_knn = dp.knn(p, 20);
	}
	printf("Time test done\n");
}


int main(int argc, char *argv[]){
	if (argc < 2)
	{
		fprintf(stdout,"Usage: %s datapath\n",argv[0]);
		return 1;
	}

	point_set densitypoints;
	densitypoints.fromfile(argv[1]);
	densitypoints.build_Rtree();

	testknn(densitypoints);
	testtime(densitypoints);
	return 0;
}
