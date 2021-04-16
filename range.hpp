#ifndef __RANGE_HPP__
#define __RANGE_HPP__

template<int N>
struct Range {
    int arr[N];
    
    constexpr Range() : arr() {
        for (auto i = 0; i < N; ++i)
            arr[i] = i;
    }

    constexpr const int* begin() const {
        return arr;
    }

    constexpr const int* end() const {
        return arr + N;
    }

};

#endif // __RANGE_HPP__
