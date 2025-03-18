#include <stdio.h>
#include <math.h>
#include <windows.h>

double f(double x){
    double fx;

    /* Insert your function here: */
    fx=x*x-x-1;
    
    return fx;
}

int main(){
    double a,fin,rang;

    puts("put your domain [start;finish]=D you want to find the value at which f(x) may = 0\nStarting value:");
    scanf("%lf",&a);
    puts("Finishing value:");
    scanf("%lf",&fin);
    puts("The subdomain range [x;x+rang] c D (depending on how complicated your function is):");
    scanf("%lf",&rang);
    while(rang>1 || rang<0.1){
        puts("range is unpractical");
        scanf("%lf",&rang);
    }

    double b=a+rang;
    double A=a,B=b,rangmain=b-a;
    while(B<=fin){
        for(int i=0;i<100;i++){
            rangmain=b-a;
            if (f(a)==0){
                printf("%0.4lf\n",a);
                break;
            }
            else if(f(b)==0){
                printf("%0.4lf\n",b);
                break;
            }
            if(f(a+rangmain/2)*f(b)<0) a=a+(double)rangmain/2;
            else if(f(a+rangmain/2)*f(a)<0) b=a+(double)rangmain/2;
        }
        if(f((a+b)/2)<=0.0000001 && f((a+b)/2)>=-0.0000001) printf("%0.5lf\n",(a+b)/2);
        A+=rang;
        B+=rang;
        a=A;
        b=B;
        Sleep(100);
    }

    return 0;
}
