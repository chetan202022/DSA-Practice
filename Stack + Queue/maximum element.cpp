
// https://www.hackerrank.com/challenges/maximum-element/problem

vector<int> getMax(vector<string> operations) {
    stack<int> st, mx;
    vector<int> ans;

    for (string &op : operations) {
        stringstream ss(op);
        int type;
        ss >> type;

        if (type == 1) {
            int x;
            ss >> x;
            st.push(x);
            if (mx.empty() || x >= mx.top())
                mx.push(x);
        }
        else if (type == 2) {
            if (!st.empty()) {
                if (!mx.empty() && st.top() == mx.top())
                    mx.pop();
                st.pop();
            }
        }
        else if (type == 3) {
            if (!mx.empty())
                ans.push_back(mx.top());
        }
    }
    return ans;
}
