//http://www.geeksforgeeks.org/orientation-3-ordered-points/
// A C++ program to find orientation of three points

#include <stdio.h>
 
typedef struct
{
    int x, y;
}Point;

#if 0
Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ < τ, the orientation is counterclockwise (left turn)
If  σ = τ, the orientation is collinear
If  σ > τ, the orientation is clockwise (right turn)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e., counterclockwise
Above expression is 0 when σ = τ, i.e., collinear
Above expression is positive when σ > τ, i.e., clockwise
#endif

 
// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p1, Point p2, Point p3)
{
#if 0
	P1 P2 P3
	Slope of p1 & p2 = S1 = (p2.y - p1.y)/(p2.x - p1.x)
	Slope of p2 & p3 = S2 = (p3.y - p2.y)/(p3.x - p2.x)
	S2-S1= (p3.y - p2.y)/(p3.x - p2.x) - (p2.y - p1.y)/(p2.x - p1.x)
	S2-S1 = (p3.y - p2.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p2.x)
#endif
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
 
    if (val == 0) 
		return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Driver program to test above functions
int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    
	if (o==0)         
		printf ( "Linear\n");
    else if (o == 1)  
		printf ("Clockwise\n");
    else              
		printf ("CounterClockwise\n");
    return 0;
}
