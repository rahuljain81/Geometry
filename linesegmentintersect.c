// http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// A C++ program to check if two given line segments intersect
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define true	1
#define false	0

typedef struct
{
	int x;
	int y;
}Point;

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
int onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// See http://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
int doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	printf ("[p1,q1,p2]=%d\n", o1);
	int o2 = orientation(p1, q1, q2);
	printf ("[p1,q1,q2]=%d\n", o2);
	int o3 = orientation(p2, q2, p1);
	printf ("[p2,q2,p1]=%d\n", o3);
	int o4 = orientation(p2, q2, q1);
	printf ("[p2,q2,p2]=%d\n", o4);

	// General case
	if (o1 != o2 && o3 != o4)
	{
		printf ("Criss Cross Orientation\n");
		return true;
	}

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}

// Driver program to test above functions
int main()
{
#if 0
	Point p1 = {1, 1}, q1 = {10, 1};
	Point p2 = {1, 2}, q2 = {10, 2};

	if (doIntersect(p1, q1, p2, q2))
		printf ("Yes\n");
	else
		printf ("No\n");
#else 
	Point p1 = {10, 0}, q1 = {0, 10};
	Point p2 = {0, 0}, q2 = {10, 10};
	if (doIntersect(p1, q1, p2, q2))
		printf ("Yes\n");
	else
		printf ("No\n");
#endif
#if 1 
	Point pp1 = {-5, -5}, pq1 = {0, 0};
	Point pp2 = {0, 0}, pq2 = {2,2};
	if (doIntersect(pp1, pq1, pp2, pq2))
		printf ("Yes\n");
	else
		printf ("No\n");
#endif
	return 0;
}
