#include<iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {

    vector <int> indekset;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums.at(i) + nums.at(j) == target) {
                indekset.push_back(i);
                indekset.push_back(j);
                break;
            }
        }
    }
    return indekset;
}
void write_vector(vector<int>& V)
{
    cout << "[";
    for (int i = 0; i < V.size(); i++) {
        if(i!=V.size()-1)
            cout << V[i] << " , ";
        
        else cout << V[i]<<"]"<<endl;
    }
}

int main() {
    int input, n,target;
    vector<int> V;

    cout << "How many numbers do you want to enter:";
    cin >> n;
    cout << "Enter your numbers " << endl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        V.push_back(input);
    }
    cout << "Enter your target:";
    cin >> target;

    cout << "The numbers in the vector are: " << endl;
    write_vector(V);
   
    V = twoSum(V, target);
    cout << "Indixes of the numbers that give you the target are:" << endl;
    
    write_vector(V);

}