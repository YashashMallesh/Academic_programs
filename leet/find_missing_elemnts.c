/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min=nums[0], max=nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i]<min)
            min = nums[i];
        if(nums[i]>max)
            max = nums[i];    
    }

    int range=max-min+1;
    char* v = (char*)calloc(range, sizeof(char));
    for(int i=0;i<numsSize;i++)
        v[nums[i]-min] = 1;

    int* ans = (int*)malloc(range * sizeof(int));
    int cnt = 0;
    for (int i = min + 1; i < max; i++) {
        if (!v[i - min]) {
            ans[cnt++] = i;
        }
    }

    free(v);
    *returnSize = cnt;
    return ans;
}
