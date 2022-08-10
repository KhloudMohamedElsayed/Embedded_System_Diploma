/*
 *  Running_Sum_of_1d_Array.c
 *
 *  Created on: Aug 10, 2022
 *      Author: KHLOUD MOHAMED
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* runningSum(int* nums, int numsSize, int* returnSize){
    
    *returnSize = numsSize;
    
    int* ans = (int*)malloc((*returnSize)*sizeof(int));
    
    long SumArray = 0;
    
    for(int i=0 ; i<numsSize ; i++)
    {
         SumArray += nums[i];
         ans[i] = SumArray;
    }
    
   return ans;
}