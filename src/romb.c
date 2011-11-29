#define MAX 6
double romb(float (*func)(float), float a, float b) {
    double s[MAX];
    int m,n;
    double var;
    for (m = 0; m < MAX; m++) s[m] = 1; 
    for (n = 0; n < MAX; n++) {
        for (m = 0; m <= n; m++) {
            if (m==0) {
                var = s[m];
                s[m] = trapzd(func, a, b, n);
            } else {
                s[n]= ( pow(4 , m-1) * s[m-1] - var ) 
                    / (pow(4, m-1) - 1); 
                var = s[m]; s[m]= s[n];  
            }
        } 
    } 
    return s[MAX-1];
}
