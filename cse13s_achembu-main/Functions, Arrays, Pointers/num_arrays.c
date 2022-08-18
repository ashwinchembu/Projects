
/*
 * All of your code goes in here. You need to finish these functions.
 */

#include <stdio.h>


/*
 * All of your code goes in here. You need to finish these functions.
 */

int maximum(int *nums, int len) {
    if (len < 0){
        return 0;
    }
    int i;
    int max = nums[0];
    for (i =0;i<len;++i){
        if (max < nums[i]){
           // printf("%i bigger than max",nums[i]);
            max = nums[i];
        }
        else{
           // printf("%i not bigger than max",nums[i]);
        }
    }
  return max;
}

int sum_positive(int *nums, int len) {
    if (len < 0){
        return 0;
    }
    int i;
    int sum = 0;
    for (i=0;i<len;++i){
        if (nums[i] > 0){
            sum+= nums[i];
        }
    }
  return sum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
    int it = 0;
    int value;
    if (initial> 0){
        value = initial;
    }
    else{
        value = 0;
    }
    int m;
    for (int m =0;m < len;++m){
        value = f(value,nums[m]);
    }
  return value;
}
int max2(int max, int val){
    if (val > max){
        max = val;
    }
    return max;
}
int maximum_with_reduce(int *nums, int size) {
   int n =  reduce(nums,size,max2,0);
  return n;
}

int pos(int sum,int val){
    if (val > 0){
        sum += val;
    }
    return sum;
}
int sum_positive_with_reduce(int *nums, int size) {
     int n =  reduce(nums,size,pos,0);
  return n;
}
int neg(int sum, int val){
    if (val < 0) {
        sum+=1;
    }
    return sum;
}
int count_negative_with_reduce(int *nums, int size) {
    int n =  reduce(nums,size,neg,0);
  return n;
}

