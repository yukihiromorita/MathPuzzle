#include <iostream>

int main(int argc, const char * argv[]) {
    int num[100] = {};
    
//    //my answer
//    for(int i=2; i<=100; i++){
//        for(int k=1; k<100./(float)i; k++){
//            num[i*k-1] = 1 - num[i*k-1];
//        }
//    }
//    for(int i=0; i<100; i++){
//        if(num[i] == 0) std::cout << i+1 << " ";
//    }
    
//    ideal answer
    for(int i=2; i<=100; i++){
        int j = i - 1;
        while(j < 100){
            num[j] = 1 - num[j];
            j += i;
        }
    }
    for(int i=0; i<100; i++){
        if(num[i] == 0) std::cout << i+1 << " ";
    }
        
    return 0;
}
