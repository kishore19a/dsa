#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

int countDigits(int n)
{
    if (n == 0) return 1;

    int res{0};
    while(n != 0)
    {
        n /= 10;
        res++;
    }

    return res;
}

bool palindromeNumber(int n)
{
    int rev{0}, temp{n};

    while(temp != 0)
    {
        int r = temp % 10;
        rev = rev * 10 + r;
        temp /= 10;
    }
    
    return (rev == n);
}

double factorialOfNumber(double n)
{
    if(n < 0) return -1;

    int fact{1};
    for (int i = 2; i <= n; i++)
        fact *= i;
    
    return fact;
}

int trailingZerosInFactorial(int n)
{
    int numZeros{0};
    for(int i = 5; i <= n; i *= 5)
        numZeros += n/i;

    return numZeros;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}

bool checkForPrime(int n)
{
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }

    return true;
}

void primeFactors(int n)
{
    if(n <= 1) 
        std::cout << "No prime factors" << std::endl;

    while(n % 2 == 0)
    {
        std::cout << "2, ";
        n /= 2;
    }

    while(n % 3 == 0)
    {
        std::cout << "3, ";
        n /= 3;
    }

    for(int i = 5; i*i <= n; i+=6)
    {
        while(n % i == 0)
        {
            std::cout << i << ", ";
            n /= i;
        }

        while(n % (i+2) == 0)
        {
            std::cout << i+2 << ", ";
            n /= (i+2);
        }
    }

    if(n > 3)
        std::cout << n << ", ";

    std::cout << std::endl;
}

void allDivisors(int n)
{
    std::stack<int> s;
    std::queue<int> q;

    for (int i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            if(i != n/i)
            {
                q.push(i);
                s.push(n/i);
            }
            else
            {
                q.push(i);
            }
        }
    }

    while(!q.empty())
    {
        std::cout << q.front() << ", ";
        q.pop();
    }

    while(!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }

    std::cout << std::endl;  
}

void printAllPrimesFrom1ToN(int n)
{
    std::vector<bool> prime(n+1, true);

    for(int i = 2; i <= n; i++)
    {
        if(prime[i])
        {
            std::cout << i << ", ";
            for(int j = i*i; j <= n; j += i)
                prime[j] = false;
        }
    }

    std::cout << std::endl;
}

int powerOf(int x, int n)
{
    int res{1};
    while(n > 0)
    {
        if(n % 2 == 1)
            res *= x;

        x *= x;
        n /= 2;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n{0};
    std::cout << "Enter a number to do mathematical operations: ";
    std::cin >> n;

    std::cout << "Number of digits in " << n << " = " << countDigits(n) << std::endl;
    std::cout << "Is " << n << " palindrome ? " << (palindromeNumber(n)? "yes" : "no") << std::endl;
    std::cout << std::fixed << "Factorial of " << n << " = " << factorialOfNumber(n) << std::endl;
    std::cout << "Number of trailing zeros in factorial of " << n << " = " << trailingZerosInFactorial(n) << std::endl;
    std::cout << "Is " << n << " prime ? " << (checkForPrime(n)? "yes" : "no") << std::endl;
    
    std::cout << "Prime factors of " << n << ":" << std::endl;
    primeFactors(n);

    std::cout << "All divisors of " << n << ":" << std::endl;
    allDivisors(n);

    std::cout << "All prime numbers from 1 to " << n << ":" << std::endl;
    printAllPrimesFrom1ToN(n);

    int a, b;
    std::cout << "Enter 2 numbers to find GCD and LCM; Also calculating a^b : ";
    std::cin >> a >> b;

    std::cout << "GCD of " << a << " & " << b << " = " << gcd(a, b) << std::endl;
    std::cout << "LCM of " << a << " & " << b << " = " << lcm(a, b) << std::endl;
    std::cout << "Power of " << a << " raised to " << b << " = " << powerOf(a, b) << std::endl;

    return 0;
}
