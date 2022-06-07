typedef struct Solution{
    int numsSize;
    int *original;
    int *shuffled;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *sol = (Solution *)malloc(sizeof(Solution));
    sol->numsSize = numsSize;

		//int ori[numsSize];
		//sol->original = ori;

    sol->original = (int *)malloc(sizeof(int)*numsSize);
    sol->shuffled = (int *)malloc(sizeof(int)*numsSize);
    for (int i=0;i<numsSize;i++){
        sol->original[i]=nums[i];
        sol->shuffled[i]= nums[i];// please complete it
    }

		//等於上面的迴圈
    //memcpy(sol->original, nums, sizeof(int) * numsSize);
    //memcpy(sol->shuffled, nums, sizeof(int) * numsSize);

    return sol;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->numsSize;
    // copy original to shuffled
    memcpy(obj->shuffled, obj->original, sizeof(int) * obj->numsSize);
    return obj->shuffled;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
	// shuffling

    int random;//to store a random number
    // change the value for each index(means shuffle)
    for(int i = 0 ; i < obj->numsSize; i++){
        int temp = obj -> shuffled[i];//keep the value
        random = rand() % (obj->numsSize - i) + i;// have a random number
        obj -> shuffled[i] = obj->shuffled[random];//change the shuffled[i] number into random place number 
        obj->shuffled[random] = temp;// change the shuffled[random] value to shuffled[i]
    }
         

    *retSize = obj->numsSize;
    return obj->shuffled;  
}

void solutionFree(Solution* obj) {
    free(obj->original);
    free(obj->shuffled);
    free(obj);    
}
