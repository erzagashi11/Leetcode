#include <iostream>
#include <vector>
using namespace std;

void runningSum(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        count += nums[i];
        ans.push_back(count);
    }
    cout << "The numbers in the vector after running the sum are: " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
void write_vector(vector<int>& V)
{cout << "[";
    for (int i = 0; i < V.size(); i++) {
        if (i != V.size() - 1)
            cout << V[i] << " , ";

        else cout << V[i] << "]" << endl;
    }
}

int main() {

    int input, n;
    vector<int> V;
    cout << "How many numbers do you want to enter:";
    cin >> n;
    cout << "Enter your numbers " << endl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        V.push_back(input);
    }

    write_vector(V);
    cout << endl;
    runningSum(V);


}