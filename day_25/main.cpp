#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count = 0;
    cin >> count;

    while(count-- > 0)
    {
        long num = 0;

        cin >> num;
        //cout << "try number : " << num <<endl;
        if (num <= 1)
        {
            cout << "Not prime" <<endl;
            continue;
        }
        bool is_prime = true;
        long max = sqrt(num);
        for(long i = 2; i <= max; i++)
        {
            if(num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        cout << num << "  -> " ;
        if(is_prime)
        {
            cout << "Prime" <<endl;
        }
        else {
            cout << "Not prime" <<endl;
        }
    }
    return 0;
}
