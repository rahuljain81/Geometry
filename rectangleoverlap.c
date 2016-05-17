//http://www.geeksforgeeks.org/find-two-rectangles-overlap/
//Two rectangles do not overlap if one of the following conditions is true.
// 1) One rectangle is above top edge of other rectangle.
// 2) One rectangle is on left side of left edge of other rectangle.

#include<stdio.h>
#define true	1
#define false	0
#define bool	int

typedef struct
{
	int x, y;
}Point;

// Returns true if two rectangles (l1, r1) and (l2, r2) overlap
bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
	// If one rectangle is on left side of other
	if (l1.x > r2.x || l2.x > r1.x)
	{
		printf ("left side of other\n");
		return false;
	}

	// If one rectangle is above other
	if (l1.y < r2.y || l2.y < r1.y)
	{
		printf ("above other \n");
		return false;
	}

	return true;
}

/* Driver program to test above function */
int main()
{
	Point l1 = {0, 10}, r1 = {10, 0};
	Point l2 = {5, 5}, r2 = {15, 0};
	if (doOverlap(l1, r1, l2, r2))
		printf("Rectangles Overlap\n");
	else
		printf("Rectangles Don't Overlap\n");
	return 0;
}
