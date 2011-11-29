#define EPS 1.0e-5
#define JMAX 20

float qtrap(float (*func)(float), float a, float b)
{
    int j;
    float s,olds=0.0;

    for (j=1;j<=JMAX;j++) {
        s=trapzd(func,a,b,j);
        if (j > 5)
            if (fabs(s-olds) < EPS*fabs(olds) ||
                (s == 0.0 && olds == 0.0)) return s;
        olds=s;
    }
    error("Too many steps in routine qtrap");
}
