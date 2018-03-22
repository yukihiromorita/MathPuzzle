#include <iostream>
#include <vector>
using namespace std;

//桁を判定
float calcFigure(int num,int n){//数、進数
    int i = 1;
    while(true){
        num /= float(n);
        
        if(num < 1){
            return i;
            break;
        }
        i++;
    }
}

bool isPalindrome(int num,int figure,int n){//数 桁 進数
    bool isP = true;
    vector<int> fig; //n進数を配列表記
    int tmp = num;
    for(int i=0; i<figure;i++) {
        fig.push_back(tmp % n);
        tmp = tmp / n;
    }
//    for(int i=0; i<figure;i++) cout<<fig[i];
//    cout<<endl;
    
    if(figure % 2 == 0){
        for(int i=0; i<figure / 2; i++){
            if( fig[0+i] == fig[fig.size()-1-i] ){
                
            }else{
//                cout<< "false when " << n<<endl;
                isP = false;
                break;
            }
        }
    }else{
        for(int i=0; i<figure / 2; i++){
            if( fig[0+i] == fig[fig.size()-1-i] ){
                
            }else{
                isP = false;
                break;
            }
        }
    }
    
    return isP;
}

int main(int argc, const char * argv[]) {
    
    int i = 10;
    
    while(i < 1000){
        float figure2 = calcFigure(i, 2);
        float figure8 = calcFigure(i, 8);
        float figure10 = calcFigure(i, 10);
//        cout<< figure2 <<" "<< figure8 <<" "<< figure10 << endl;
        
        bool found2 = isPalindrome(i, figure2, 2);
        bool found8 = isPalindrome(i, figure8, 8);
        bool found10 = isPalindrome(i, figure10, 10);
        if(found2 == true && found8 == true && found10 == true ) {
            cout <<"answer is "<< i << endl;
            break;
        }
        i++;
    }
    
}
