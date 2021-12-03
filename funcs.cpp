//https://contest.yandex.ru/contest/27794/problems/G/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    int n, k;
    input >> n >> k;

    //! @brief number, times
    std::map<int, int> numbers;
    int number;
    for(int i = 0; i<n; ++i){
        input >> number;
        ++numbers[number];
    }
    auto numsSize = numbers.size();
    std::vector<std::pair<int,int>> numVect(numsSize);
    std::copy_n(numbers.begin(), numsSize, numVect.begin());

    unsigned long long count = 0, duplicates = 0;
    auto right = numVect.begin();
    for(auto left = numVect.begin(); left!=numVect.end(); ++left){
        unsigned long long rightMax = left->first*k;
        while (right!=numVect.end() && rightMax>=right->first){
            if(right->second>1)
                ++duplicates;
            ++right;
        }
        int rangeLen = std::distance(left,right);
        if(left->second>=3)// 1,1,1
            ++count;
        if(left->second>=2){// 1,1,* | 1,*,1 | *,1,1
            count+=3*(rangeLen-1);
            --duplicates;
        }

        count+=duplicates*3;//each duplicate > left generates 3 variants

        //Variants with unique numbers
        count+=(rangeLen-1)*(rangeLen-2)*3;//>=0
    }

    output << count;
}
