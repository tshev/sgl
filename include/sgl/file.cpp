#include <iostream>
#include <cassert>
#include <cstdint>
#include <vector>
#include <algorithm>

int median3(int x, int y, int z) { // [1,2,3] , [2,1,3], [3,1,2],[2,3,1][1,1,1], 
   if (x > y) {
     if (x > z) {
       if (y > z) {
          return y;
       }
       return z;
     } 

     return x;
   } else { // x <= y
     if (y > z) {
       if (x > z) {
          return x;
       }
       return z;    
     }
     
     return y;
   }
}




int main() {
    {
        int a[] = {1, 2, 3};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(median3(a[0], a[1], a[2]) == *b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }

    {
        int a[] = {1, 2, 2};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(median3(a[0], a[1], a[2]) == *b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }


    {
        int a[] = {1, 1, 2};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(median3(a[0], a[1], a[2]) == *b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }



    {
        int a[] = {2, 2, 2};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(median3(a[0], a[1], a[2]) == *b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }

    std::cout << (1 <=> 3) << std::endl; 

}
