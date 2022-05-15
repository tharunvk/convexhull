#include <bits/stdc++.h>
using namespace std;

struct dot
{
	int x, y;
};
typedef struct dot dot;


//return if angle wrt next point is clockwise, anticlockwise or collinear
int check_angle(dot a, dot b, dot c)
{
	// this is equivalent to finding the dot product of the vectors
	int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

	if (val == 0) 
	  return 0; // collinear - since vector dot product is zero

	else if (val>0) // clockwise - since vector dot product is positive
		return 1;

	else       // anticlockwise - since vector dot product is -ve
	  return 2; 
}

void find_best_hull(dot dots[], int total_dots)
{

	if (total_dots < 3) return;

	vector<dot> my_hull;


//finding leftmost
	int first_point = 0;
	for (int i = 1; i < total_dots; i++)
		if (dots[i].x < dots[first_point].x)
			first_point = i;

	int next_point = first_point, interim_point;
	// continue until the initial point is met again
	do
	{
		my_hull.push_back(dots[next_point]);

		interim_point = (next_point+1)%total_dots;
		for (int i = 0; i < total_dots; i++)
		{

		// check if it is anti clockwise, only then move ahead
		if (check_angle(dots[next_point], dots[i], dots[interim_point]) == 2)
			interim_point = i;
		}

		next_point = interim_point;

	} while (next_point != first_point);

//print hull edges
	for (int i = 0; i < my_hull.size(); i++)
		cout <<my_hull[i].x << ", "<< my_hull[i].y <<endl;
}

int main()
{
	dot dots[] = {{1,1},{2, 2},{4,5}, {5,2},{1,5}, {0, 0}, {3, 3}, {5,1}};
	int total_dots = sizeof(dots)/sizeof(dots[0]);
	find_best_hull(dots, total_dots);
	return 0;
}
