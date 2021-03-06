
#include<stdio.h>
#include<mrg32k3a.h>

#define NN       100000000UL

int main(void){ 
   long i; unsigned int sum=0;
   mrg32k3a_state state; mrg32k3a_sse_state sse_state;
   mrg32k3a_init_(&state); mrg32k3a_get_sse_state_(&state,&sse_state);
   mrg32k3a_print_state_(&state);
   for(i=0;i<NN;i++) sum+=mrg32k3a_sse_generate_(&sse_state);
   printf("%ld MRG32K3A_SSE pseudorandom numbers generated.\n",NN);
   printf("Fractional part of the total sum of generated numbers: %f\n",sum/4294967296.);
   printf("Next output value: %f\n",mrg32k3a_sse_generate_(&sse_state)/4294967296.);
   return 0;
}
