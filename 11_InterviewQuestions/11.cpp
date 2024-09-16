/*
Given N and M , find the minimum mumbers of primes required to make N

you can use the first M primes to do so

eg.1
Input :
N =10
M=1
output: 5
[2+2+2+2+2]

eg.2
Input :
N =11
M=3
output: 3
[3+3+5]
*/

#include<iostream>
#include<vector>
using namespace std;


std::vector<int> generatePrimes(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    // make false for divisible of 2,3,5,7,9
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
bool minPrimeRequired(const std::vector<int>& primes,int N,int M,std::vector<int>& combination,int start)
{
    if(M==0)
    {
        return N==0;
    }

    for(int i=start;(i<primes.size() && primes[i]<=N);i++)
    {
        combination.push_back(primes[i]);
        if(minPrimeRequired(primes,N-primes[i],M-1,combination,i))
        {
            return true;
        }
        combination.pop_back();
    }
    
}
int main()
{
   int limit = 100;
   int N=16;
   int M=4;
    std::vector<int> primes = generatePrimes(limit);

    std::vector<int> combination;
    if (minPrimeRequired(primes, N, M, combination, 0)) {
        std::cout << "A combination of " << M << " primes that sum up to " << N << " is: ";
        for (int prime : combination) {
            std::cout << prime << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No combination of " << M << " primes sums up to " << N << std::endl;
    }
    return 0;
}