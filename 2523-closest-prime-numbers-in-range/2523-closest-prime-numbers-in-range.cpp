class Solution
{
public:
    vector<int> primes;

    // fillPrimes function filles the vector given to it by all the prime numbers from 
    //                   "2 to high" 

    void fillPrimes(vector<int> &prime, int high)
    {
        bool ChalloManali[high + 1];
        memset(ChalloManali, true, sizeof(ChalloManali));
        ChalloManali[1] = false;
        ChalloManali[0] = false;
        for (int i = 2; (i * i) <= high; i++)
        {
            if (ChalloManali[i] == true)
            {
                for (int j = i * i; j <= sqrt(high); j = j + i)
                {
                    ChalloManali[j] = false;
                }
            }
        }
        for (int i = 2; i * i <= high; i++)
        {
            if (ChalloManali[i] == true)
            {
                prime.push_back(i);
            }
        }
    }
    // Using segmented sieve, we get all the primes between [low, high] filled in the vector called prime.
    // Our SegmentedSieve function requires another basis function- called fillPrimes. 
    void SegmentedSieve(int low, int high)
    {
        if (low < 2 and high >= 2)
        {
            low = 2;
        } 
        // Case when low = 1 as 1 is not a Prime Number

        bool primeTime[high - low + 1];
        // here primeTime[0] indicates whether low is prime or not similarly prime[1] indicates whether low+1 is prime or not
        memset(primeTime, true, sizeof(primeTime));

        vector<int> aphaPrimes;
        fillPrimes(aphaPrimes, high);
        // aphaPrimes has primes in range [2,sqrt(n)]
        //  we take primes from 2 to sqrt[n] because the multiples of all primes below high are marked by these
        // primes in range 2 to sqrt[n] for eg: for number 7 its multiples i.e 14 is marked by 2, 21 is marked by 3,
        // 28 is marked by 4, 35 is marked by 5, 42 is marked 6, so 49 will be first marked by 7 so all number before 49
        // are marked by primes in range [2,sqrt(49)]

        for (int i : aphaPrimes)
        {
            int lower = (low / i);
            // here lower means the first multiple of prime which is in range [low,high]
            // for eg: 3's first multiple in range [38,50] is 39
            if (lower <= 1)
            {
                lower = i + i;
            }
            else if (low % i)
            {
                lower = (lower * i) + i;
            }
            else
            {
                lower = (lower * i);
            }
            for (int j = lower; j <= high; j = j + i)
            {
                primeTime[j - low] = false;
            }
        }

        for (int i = low; i <= high; i++)
        {
            if (primeTime[i - low] == true)
            {
                primes.push_back(i);
            }
        }
    }

    vector<int> closestPrimes(int left, int right)
    {
        SegmentedSieve(left, right);
        vector<int> curr = {-1, -1};
        int diff = INT_MAX;
        for (int i = 1; i < primes.size(); i++)
        {
            int temp = primes[i] - primes[i - 1];
            if (temp < diff)
            {
                diff = temp;
                curr = {primes[i - 1], primes[i]};
            }
        }
        return curr;
    }
};