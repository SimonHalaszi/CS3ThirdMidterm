/*

PATTERNS
- parallel algorithms: the concept, execution policies, sort(), reduce()

NOTES:

* parallel algorithms: the concept, execution policies, sort(), reduce()

    Parallel Algorithms Support

    - C++17 added support for parallel algorithms

    - To gain performance advantage need three parts:
        - Compiler that implements C++17 for example: g++ v9
        or higher

        - Parallelizer: for example a thread library such
        as Intel's threads build blocks (tbb)

        - Computer with multiple processors or cores

    Parallel STL Algorithms

    - Most STL algorithms have execution policy as their first parameter
        - defined in #include <execution>

    - Policies
        - std::execution::seq - sequential, unspecified order
            - One thread at a time, works on one element at a time
            to do algorithm
            
            - The default

        - std::execution::par - parallel seperate threads
            - Multiple threads work together at same to do algorithm

        - std::execution::unseq - seperate or same thread (vectorized)
        or migrate between threads
            - One thread at a time, works on many elements at a time
            to do algorithm

        - std::execution::par_unseq - same as unseq plus parallel
            - Many threads work on algorithm at different times or
            at the same time

    - New algorithms
        - reduce() - same as accumulate but arbitrary order of operations,
        may potentially run in parallel.
*/