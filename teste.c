#include <stdio.h>
#include <sys\timeb.h> 

int main() { 
    struct timeb start, end;
    int diff;
    int i = 0;
    ftime(&start);

    while(i++ < 9999) {
        /*gastando tempo*/
        printf(".");    
    }

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff);
    scanf("%d",i);
    return 0;
}