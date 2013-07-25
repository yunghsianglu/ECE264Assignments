
typedef __uint128_t uint128;

#define SUCCESS 0
#define FAILURE -1

#define FALSE 0
#define TRUE 1

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

// Convert uint128 to/from strings
char * u128ToString(uint128 value);
uint128 alphaTou128(const char * str);

// Return TRUE or FALSE
int primalityTestParallel(uint128 value, int n_threads);




