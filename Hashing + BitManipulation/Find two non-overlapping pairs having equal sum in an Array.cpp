
// https://www.geeksforgeeks.org/dsa/find-two-non-overlapping-pairs-having-equal-sum-in-an-array/

void findPairs(int arr[], int n)
{
    // first create an empty map
    // key -> which is sum of a pair of
    // elements in the array
    // value -> vector storing index of
    // every pair having that sum
    unordered_map<int, vector<Pair> > map;

    // consider every pair (arr[i], arr[j])
    // and where (j > i)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            // calculate sum of current pair
            int sum = arr[i] + arr[j];

            // if sum is already present in the map
            if (map.find(sum) != map.end()) {

                // check every pair having equal sum
                for (auto pair : map.find(sum)->second) {
                    int m = pair.first, n = pair.second;

                    // if pairs don't overlap,
                    // print them and return
                    if ((m != i && m != j) && (n != i && n != j)) {
                        cout << "Pair First(" << arr[i] << ", "
                             << arr[j] << ")\nPair Second ("
                             << arr[m] << ", " << arr[n] << ")";
                        return;
                    }
                }
            }

            // Insert current pair into the map
            map[sum].push_back({ i, j });
        }
    }

    // If no such pair found
    cout << "No such non-overlapping pairs present";
}
}
