#include <stdio.h>
#include <sys/resource.h>

int funcionRecursiva(unsigned long a){
	int vector[1024];

	printf ("LLAMADO: %ld\n",a);

	funcionRecursiva(a+1);
}

int main(){
	//Codigo para incrementar el stack
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }


	struct rlimit limit;

	getrlimit (RLIMIT_STACK, &limit);
	printf ("\nStack Limit = %ld and %ld max\n", limit.rlim_cur, limit.rlim_max);
	funcionRecursiva(0);
	return 0;
}
