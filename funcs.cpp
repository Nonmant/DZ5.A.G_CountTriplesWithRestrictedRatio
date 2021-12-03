//https://contest.yandex.ru/contest/27794/problems/G/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    long long n, k;
    input >> n >> k;

    //! @brief number, times
    std::map<long long , long long> numbers;
    long long number;
    for(int i = 0; i<n; ++i){
        input >> number;
        ++numbers[number];
    }
    auto numsSize = numbers.size();
    std::vector<std::pair<long long,long long>> numVect(numsSize);
    std::copy_n(numbers.begin(), numsSize, numVect.begin());

    long long count = 0, duplicates = 0;
    auto right = numVect.begin();
    for(auto left = numVect.begin(); left!=numVect.end(); ++left){
        long long rightMax = left->first*k;
        while (right!=numVect.end() && rightMax>=right->first){
            if(right->second>1)
                ++duplicates;
            ++right;
        }
        long long rangeLen = std::distance(left,right);
        if(left->second>=3)// 1,1,1
            ++count;
        if(left->second>=2){// 1,1,* | 1,*,1 | *,1,1
            count+=3*(rangeLen-1);
            --duplicates;
        }

        count+=duplicates*3;//each duplicate > left generates 3 variants

        //Variants with unique numbers
        count+=std::max((rangeLen-1)*(rangeLen-2)*3,(long long)(0));
    }

    output << count;
}
