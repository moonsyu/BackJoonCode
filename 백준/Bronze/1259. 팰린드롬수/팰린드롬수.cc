#include <stdio.h>

void result(int a, int b, int c, int d, int e){
    if(a > 0){
        if(a == e && b == d){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    else if(b > 0){
        if(b == e && c == d){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    else if(c > 0){
        if(c == e){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    else if(d > 0){
        if(d == e){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    else if(e > 0){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}

int main(){
    
    int a,b,c,d,e;
    int num;
    
    for( ; ; ){
        scanf("%d", &num);
        if(num == 0){
            break;
        }
        a = num/10000;
        b = num/1000 - a*10;
        c = num/100 - a*100 - b*10;
        d = num/10 - a*1000 - b*100 -c*10;
        e = num - a*10000 - b*1000 - c*100 - d*10;
        
        result(a,b,c,d,e);
    }
    return 0;
}
