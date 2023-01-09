#include<iostream>
#include<string>
#include <vector>
#include<unordered_map>
using namespace std;
struct StructureWithFunctions
{   //Two sum solution with vector
    vector<int> twoSum(vector<int>& nums, int target);
    //Two sum solution with hash tabel
    vector<int>twoSum(vector<int>& nums, double target);

};
void write_vector(vector<int>& V)
{
    cout << "[";
    for (int i = 0; i < V.size(); i++) {
        if (i != V.size() - 1)
            cout << V[i] << " , ";

        else cout << V[i] << "]" << endl;
    }
}
int main() {
    StructureWithFunctions smf;
    //Two sum using vector
    cout << "Solution of Two sum using vector" << endl;
    int target=9;
    vector<int> V={2,7,11,15};

    cout << "Numbers in the vector are: " << endl;
    write_vector(V);

    V=smf.twoSum(V, target);
    cout << "Indices of the two numbers such that they add up to target "<<target<<" are:" << endl;
    write_vector(V);
    cout << endl;

    //Two sum using hash tabel
    cout << "Solution of Two sum using hash tabel" << endl;
    target = 6;
    V = { 3,2,4};

    cout << "Numbers in the vector are: " << endl;
    write_vector(V);

    V = smf.twoSum(V, target);
    cout << "Indices of the two numbers such that they add up to target " << target << " are:" << endl;
    write_vector(V);

   
}
//Two sum - vector
vector<int>StructureWithFunctions::twoSum(vector<int>& nums, int target) {

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
};
//Two sum - hash tabel
vector<int> StructureWithFunctions::twoSum(vector<int>& nums, double target) {

    unordered_map<int, int> indekset;
    for (int i = 0; i < nums.size(); i++) {
        if (indekset.find(target - nums[i]) != indekset.end()) {
            return { indekset[target - nums[i]], i };
        }
        indekset[nums[i]] = i;
    }
    return {};
}

