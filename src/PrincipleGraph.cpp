#include<stdio.h>
#include<pointset.h>

double myiterate(const point_set & X, point_set & c0){
	double err = 0;
	// Computing W
	// get knn for each point in c0
	// build graph
	// compute MST prim

	// Computing P
	// soft assignment

	// compute C
	// matrix operations

	return err;
}

int main(int argc, char *argv[]){
	if (argc < 2)
	{
		fprintf(stdout,"Usage: %s datapath\n",argv[0]);
		return 1;
	}

	point_set densitypoints;
	densitypoints.fromfile(argv[1]);

	point_set c0(densitypoints);

	// iterate, exit when err change less than e or max iteration reached.
	myiterate(densitypoints, c0);

	return 0;
}
