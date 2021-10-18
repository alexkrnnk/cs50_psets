#include <stdio.h>

int mx_sqrt(int x);

int main() {
    printf("%d", mx_sqrt(4));
    return 0;
}


int mx_sqrt(int x){
    int y = x / 2;
    for (int i = 0; i < x; i++){
        y = (y + x / y) / 2;
    }
    int step = y * y;
    if(step == x){
        return y;
    }
    else{
        return 0;
    }
}
