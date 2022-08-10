/*
 *  Concatenation_of_Array.c
 *
 *  Created on: Aug 10, 2022
 *      Author: KHLOUD MOHAMED
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    
    *returnSize = 2 * numsSize;
    
    int* ans = (int*)malloc((*returnSize)*sizeof(int));
    
    for(int i=0 ; i<numsSize ; i++)
    {
        ans[i + numsSize] = ans[i] = nums[i];
    }
    
    return ans;

}