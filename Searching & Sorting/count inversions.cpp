
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
public:
    long long merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        long long inv = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int p = 0; p < k; p++)
            arr[left + p] = temp[p];

        return inv;
    }

    long long mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long inv = 0;

        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);

        return inv;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
