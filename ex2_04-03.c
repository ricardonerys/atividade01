#include <stdio.h>
#include <math.h>


int main() {
     int v1[10]={2,7,1,4,4,1,7,2,0,0 };
     int v2[10]={8,7,3,8,8,3,7,8,0,0 };
     int v3[9];

     for(int i=0;i<10;i++){
        
        v3[i]=v1[i]+v2[i];
        printf("%d\t",v3[i]);
     }
     

    return 0;
}