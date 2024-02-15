// prime number checker
// number array from 2 to 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	int p = 0;
    int i = 0;
    
    int primes[50] = {0};
    int primeIndex = 2;
    
    bool isPrime = false;
    
    //hardcoding default primes
    primes[0] = 2;
    primes[1] = 3;
    
    // as 2,3 hardcoded. 4 is composite. 5 is starting prime int
    for (p = 5; p <= 100; p += 2) 
    {
        // making boolean true
        // doesn't serve any purpose till this point
        isPrime = true;
        
        // functional logic
        // if given prime number is greater than previous primes
        // or it's square root 
        // it's already a composite
        // reducing redundancy
        
        /*
            For instance we have 2 and 3 inside primes array
             * suppose 81 to check
             * division by 2 gives float reject
             * division by 3 gives 27 accept
             * stisfies the remainder criteria of 0
             * no need to further divide by any
             * condition satisfied, composite
             * bypass

        */
        for (i = 1; p/primes[i] >= primes[i]; ++i)
        {
                if (p % primes[i] == 0)
                    isPrime = false;
        }
        
        if (isPrime == true)
        {
                primes[primeIndex] = p;
                ++primeIndex;
        }
    }
    
    // because primeIndex is hardcoded to have a value as equal to array size
    // setting < sign and not <= because of the array size we set to 50
    // and all the values are 0 initially until we are assigning values to index in the loops
    // so this time setting <= there will result in 0 at the end
    // yes reducing the array size to exact equal to number of primes between 1 to 100 can be done to have <=
    // but reducing efforts 
    for (int r = 0; r < primeIndex; ++r){
            printf("%i  ", primes[r]);
    }
	return 0;
}
