#include <iostream>
using namespace std;

void collatz(int* num){
//    int next;
//    if(num % 2 == 0){
//        next = num/2;
//    }else {
//        next = num * 3 + 1;
//    }
//    return next;
    
    (*num % 2 == 0) ? *num /= 2 : *num = *num*3+1;
}

int main(int argc, const char * argv[]) {
    int count = 0;
    for(int i=2; i<= 10000; i += 2){
        int init = i;
        int cur = i * 3 + 1;
        while(cur != 1) {
            collatz(&cur);
//            cout << cur << " ";
            if(cur == init){
                count++;
                cout << cur << endl;
                break;
            }
        }
    }
    cout << count;
    return 0;
}

