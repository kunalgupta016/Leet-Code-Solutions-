// Recursive approach
#include <stdio.h>


void toh(int x,char src,char aux,char des){
    if(x==1){
        printf("\nDisk %d move from %c to %c ",x,src,des);
    }
    else{
        toh(x-1,'a','c','b');
        printf("\n Disk %d move from %c to %c",x,src,des);
        toh(x-1,'b','a','c');
    }

}

int main() {

    toh(3,'a','b','c');


    return 0;
}