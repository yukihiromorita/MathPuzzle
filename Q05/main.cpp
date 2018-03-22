#include <iostream>
using namespace std;


void exchange(int* count,int a, int b,int c,int d){//2 0 0
//    static int count = 0;//num of way to exchange
    int num = a+b+c+d;
//    *count += 1;
//    while(num <= 15){
        num = a+b+c+d;
        *count += 1;
        
        //50 -> 10
        if(c > 0 && num <= 11){
            c -= 1;
            d += 5;
            exchange(count,a,b,c,d);
        }
        
        //100->50
        if(b > 0 && num <= 14){
            b -= 1;
            c += 2;
            exchange(count,a,b,c,d);
        }
        
        //500 -> 100
        if(a > 0 && num <= 11){
            a -= 1;
            b += 5;
            exchange(count,a,b,c,d);
        }
//        else break;
//        *count += 1; //500 500など、両替可能だが枚数を満たすもの
//    }
//    *count += 1;
//    if(num == 15) *count += 1;
//    if(num > 15) cout<< "exception";
    
}


int main(int argc, const char * argv[]) {
    int cnt = 0;
    exchange(&cnt,2,0,0,0);
    cout << cnt;
}

