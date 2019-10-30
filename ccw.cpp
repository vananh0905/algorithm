double  e= 1e-15
int     CCW(point p1,point p2,point p3)
{
            double a1,a2,b1,b2,t;
            a1= p2.x -p1.x;
            b1= p2.y -p1.y;
            a2 =p3.x -p2.x;
            b2 =p3.y- p2.y;
            t= a1*b2 - a2*b1;
            if (abs (t) <e) return 0;
            if (t<0) return -1;
            return 1;
}
