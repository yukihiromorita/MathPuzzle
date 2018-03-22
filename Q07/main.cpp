#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    for(int y = 1966; y <= 2020; y++){
        for(int m = 1; m<=12; m++){
            int d = day[m-1];
            if(m == 2 && ((d % 4 == 0 && d % 100 != 0) || d % 400 == 0)) d = 29;
            for(int day=1; day <= d; day++){
                int date = y * 10000 + m*100 + day;
                std::stringstream ss;
                ss << static_cast<std::bitset<25> >(date);
                
                string dateStr = ss.str();
                string reversedDate = ss.str();
                reverse(reversedDate.begin(),reversedDate.end());
                if(dateStr == reversedDate){
                    //                    cout << ss.str()  << endl;
                    cout << date << endl;
                }
            }
        }
    }
}
