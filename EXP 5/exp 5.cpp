#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long totalPower = 0;
        for (int b : batteries) {
            totalPower += b;
        }

        
        sort(batteries.rbegin(), batteries.rend());

       
        for (int b : batteries) {
            if (b > totalPower / n) {
                totalPower -= b;
                n--;
            } else {
               
                break;
            }
        }

        
        return totalPower / n;
    }
};