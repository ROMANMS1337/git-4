#include "pch.h"
#include "sort.h"

TEST(PointerSortTests, SortsUnorderedArray) {
    int arr[] = { 10, 2, 8, 4, 6 };
    int expected[] = { 2, 4, 6, 8, 10 };
    pointerSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], expected[i]);
    }
}