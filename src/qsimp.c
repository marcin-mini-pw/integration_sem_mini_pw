#define EPS 1.0e-5
#define JMAX 20

float qsimp(float (*func)(float), float a, float b) {
    int j;
    float s,st,ost=0.0,os=0.0;

    for (j=1;j<=JMAX;j++){
        st=trapzd(func,a,b,j);
        s=(4.0*st-ost)/3.0;
        if (j > 5)
            if (fabs(s-os) < EPS*fabs(os) ||
                (s == 0.0 && os == 0.0)) return s;
        os=s;
        ost=st;
    }
    error("Too many steps in routine qsimp", 10);
}
