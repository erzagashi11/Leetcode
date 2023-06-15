#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<stack>
#include<queue>
#include <unordered_map>
#include<string>
#include <vector>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode2 {
public:
    //1.Valid Parentheses
    //Time:O(n)
//Space:O(n)
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
    
        //2.First Unique Character in a String
    //Time: O(n) 
    //Space: O(n) 
    int firstUniqChar(string s) {
        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }

    //3. Implement Stack using Queues
        // Time: O(1) amortizum
        // space: O(1) amortizum


    class MyStack {
    private:
        vector<int> stack;

    public:
        void push(int x) {
            stack.push_back(x);
        }

        int pop() {
            if (!empty()) {
                int topElement = stack.back();
                stack.pop_back();
                return topElement;
            }
            return -1;
        }

        int top() {
            if (!empty()) {
                return stack.back();
            }
            return -1;
        }

        bool empty() {
            return stack.empty();
        }
    };
    // 4. Time Needed to Buy Tickets
   // Time: O(n)
   // space: O(n)

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;
        int time = 0;

        for (int i = 0; i < tickets.size(); i++)
        {
            queue.push(tickets[i]);
        }
        int target = k;

        while (true) {
            if (queue.front() != 0)
            {
                time++;
                if (target == 0)
                {
                    if (queue.front() == 1)
                    {
                        return time;
                    }
                    else
                        target = queue.size();
                }
                queue.push(queue.front() - 1);
                queue.pop();
            }
            else {
                queue.pop();
            }
            target--;
        }
    }
    
    //5.Missing Number
    //Time:O(n)
    //Space:O(1)


    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n
        int actualSum = accumulate(nums.begin(), nums.end(), 0); // Sum of numbers in the array
        return expectedSum - actualSum;
    }

    // 6. Find Target Indices After Sorting Array
    // Time: O(nlogn)
    // Space: O(n)

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == target)
                answer.push_back(i);
        }
        return answer;
    }
   
    // 7. Search in a Binary Search Tree
    // Time: O(n)
    // Space: O(n)

    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }

    // 8. Maximum Depth of Binary Tree
    // Time: O(n)
    // Space: O(n)

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
    
    // 9. Reverse Linked List
    // Time: O(n)
    // Space: O(1)

    ListNode* reverseList(ListNode* head) {
        ListNode* nextNode, * prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }


    //10. Baseball Game
    // Time complexity: O(n)
    // Space complexity: O(n)

    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                st.push(y);
                st.push(x);
                st.push(x + y);
            }
            else if (ops[i] == "C") {
                st.pop();
            }
            else if (ops[i] == "D") {
                st.push(2 * st.top());
            }
            else {
                int x = stoi(ops[i]);
                st.push(x);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }

   


    // 11. Sort the People
    // Time complexity: O(n logn)
    // Space complexity: O(n)
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> A;
        int N = names.size();
        for (int i = 0; i < N; i++) {
            A.push_back({ heights[i], names[i] });
        }

        sort(A.rbegin(), A.rend());

        vector<string> ans;
        for (int i = 0; i < N; i++) {
            ans.push_back(A[i].second);
        }
        return ans;
    }

    // 12. First Unique Character in a String
      // Time: O(n^2)
    // Space: O(1)
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool Unique = true;

            for (int j = 0; j < s.length(); j++) {

                if (i == j) {
                    continue;
                }
                if (s[i] == s[j]) {
                    Unique = false;
                    break;
                }
            }
            if (Unique) {
                return i;
            }
        }
        return -1;
    }
    //13.Largest Odd Number
    // Time: O(n)
    // Space: O(1)
    string largestOddNumber(string num)
    {
        int n = num.size();   // size of the string
        // first run a for loop from the end of the string to the beginning
        for (int i = n - 1; i >= 0; i--)
        {
            // if it is an even number
            if (num[i] % 2 == 0)
                num.pop_back();
            // this pop_back funtion will remove the last char from the string, decreasing
            // its length by one
            else       // else we know that the number is odd and we break out of the loop
                break;
        }
        return num;
    }
        // we return num 

        //14.Largest Perimeter in Triangle
     // Time: O(n logn)
    // Space: O(1)

        int largestPerimeter(vector<int>&nums) {
            // sort the elements 
            sort(nums.begin(), nums.end());
            // iterate in everse order to get maximum perimeter
            for (int i = nums.size() - 2; i >= 1; i--) {
                //Triangle is formed if sum of two sides is greater than third side
                if (nums[i] + nums[i - 1] > nums[i + 1])return (nums[i] + nums[i + 1] + nums[i - 1]); // return perimeter which is sum of three sides
            }
            return 0; // when no triangle possible it will come out of loop so return 0 here

        }
        //15. Count negativ Numbers in a Matrix
        // Time: O(n x m)
    // Space: O(1)

        int countNegatives(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] < 0)
                        cnt++;  }
            }
            return cnt;
        }
       
        //16.Sqrt(x)
          // Time: O(logx)
    // Space: O(1)
        int mySqrt(int x) {
            if (x == 0 || x == 1)
            {
                return x;}
            int result = 0;
            int left = 1;
            int right = x;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (mid <= x / mid)
                {
                    result = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return result;
        }
        //17.Remove Linked List Elements
//Time:O(n)
//Space:O(1)
        ListNode* removeElements(ListNode* head, int val) {
            // Rast i veçantë: lista është e zbrazët
            if (head == nullptr) {
                return nullptr;
            }

            // Funksionojmë me dy pointera: prev dhe current
            // Prev ndjek elementin para current, ndërsa current ndjek elementin aktual
            ListNode* prev = nullptr;
            ListNode* current = head;

            while (current != nullptr) {
                // Nëse gjejmë një element me vlerën e dhënë, e heqim nga lista
                if (current->val == val) {
                    // Rasti kur elementi për të hequr është në fillim të listës
                    if (prev == nullptr) {
                        head = current->next;
                    }
                    else {
                        prev->next = current->next;
                    }
                }
                else {
                    // Kalojmë tek elementi tjetër
                    prev = current;
                }

                current = current->next;
            }

            return head;
        }
        //18.Implement Queue using Stacks
        //Time:
        //Push: O(n) (ndërsa në rastin më të mirë është O(1))
        //Pop : O(1)
        //Peek : O(1)
        //Empty : O(1)
        //Space:O(n)
        class MyQueue {
        private:
            stack<int> s1;
            stack<int> s2;
        public:
            MyQueue() {

            }

            void push(int x) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(x);
                while (!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
            }

            int pop() {
                int a = s1.top();
                s1.pop();
                return a;
            }

            int peek() {
                return s1.top();
            }

            bool empty() {
                return s1.empty();
            }
        };
        MyQueue queue;
        //19.Minimum Sum of Four Digit Number After Splitting Digits
        /*Time:
            Konvertimi i numrit në një vektor : O(log n)
            Sortimi i vektorit : O(n log n)
            Gjetja e shumës minimale : O(1)
            Hapsira :
            Vektori i numrave : O(log n)
            */

        int minimumSum(int num) {
            vector<int> v;

            while (num != 0) {
                int rem = num % 10;
                v.push_back(rem);
                num /= 10;
            }

            sort(v.begin(), v.end());

            int num1 = v[0] * 10 + v[3];
            int num2 = v[1] * 10 + v[2];

            int ans = num1 + num2;
            return ans;
        }

        

        //20.Same Tree
        /*Time:
           Në rastin më të mirë, kur dy pema janë identike, kompleksiteti kohor është O(1).
           Në rastin më të keq, kur dy pema janë krejtësisht të ndryshme, funksioni do të shkojë në thellësi të gjatë të dy pemave dhe do të krahasojë secilën gjëndje të tyre.Kompleksiteti kohor është O(n).
         */
         //  Hapsira : O(1)

        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == nullptr && q == nullptr) {
                return true;
            }
            if (p == nullptr || q == nullptr || p->val != q->val) {
                return false;
            }
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
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
void write_matrix(vector<vector<int>>& mat) {
    cout << "\n{";
    for (int i = 0; i < mat.size(); i++) {
        if (i != 0)
            cout << setw(2);
        cout << "{";
        for (int j = 0; j < mat[i].size(); j++) {
            if (j < mat.size() - 1) {
                cout << setw(2) << mat[i][j] << ", ";
            }
            else {
                cout << setw(2) << mat[i][j] << "}";
            }
        }
        if (i < mat[i].size() - 1) {
            cout << ", ";
            cout << endl;
        }
    }
    cout << "}";
}

void write_vectorstring(vector<string>& v)
{

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ',';
        }
    }
}

void write_string(string v)
{

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
}
int main() {
    
    
    //1.
    LeetCode2 b;
string s = "()";
    bool isValidString = b.isValid(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << (isValidString ? "true" : "false") << endl;
    //------------------------------------------------------------------
   //2.
    LeetCode2 w;
string s = "leetcode";
    int index = w.firstUniqChar(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << index << endl;
    //-------------------------------------------------------------------
   //4.
     vector<int> tickets = {2, 3, 2};
     int k = 2;
     LeetCode2 timeRequired;
     cout << "Time required is: " << timeRequired.timeRequiredToBuy(tickets, k) << endl;
   //---------------------------------------------------------------------
    
    //5.
    LeetCode2 m;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missingNum = m.missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;
    //---------------------------------------------------------------------
    



    // 6. Find Target Indices After Sorting Array

     vector<int> nums = {1, 2, 5, 2, 3};
     int target = 2;
     LeetCode2 i;
     vector<int> indices = i.targetIndices(nums, target);
     for (int i = 0; i < indices.size(); i++)
     {
         cout << indices[i] << " ";
     }
    //---------------------------------------------------------------------
   
// ----------------------------------------------------------------------------
// 7. Search in a Binary Search Tree
    /* TreeNode* node1 = new TreeNode(1);
     TreeNode* node3 = new TreeNode(3);
     TreeNode* node2 = new TreeNode(2, node1, node3);
     TreeNode* node7 = new TreeNode(7);
     TreeNode* rootNode = new TreeNode(4, node2, node7);

     LeetCode2 searchBST;
     TreeNode* result = searchBST.searchBST(rootNode, 2);


     if (result != nullptr){
         cout << "Result: " << result->val << endl;
         cout << "Result: " << result->left->val << endl;
         cout << "Result: " << result->right->val << endl;
     }
     else
         cout << "Result: Not found" << endl;

     delete node1;
     delete node3;
     delete node2;
     delete node7;
     delete rootNode;*/

// ------------------------------------------------------------------------------
// 8. Maximum Depth of Binary Tree
     TreeNode* node15 = new TreeNode(15);
     TreeNode* node7 = new TreeNode(7);
     TreeNode* node20 = new TreeNode(20, node15, node7);
     TreeNode* node9 = new TreeNode(9);
     TreeNode* rootNode = new TreeNode(3, node9, node20);

     LeetCode2 maxDepth;
     int result = maxDepth.maxDepth(rootNode);

     cout << "Max Depth: " << result << endl;

     delete node15;
     delete node7;
     delete node20;
     delete node9;
     delete rootNode;

    //-------------------------------------------------------------------------------------
    
    // 9. Reverse Linked List
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(3);
     head->next->next->next = new ListNode(4);
     head->next->next->next->next = new ListNode(5);

     LeetCode2 r;
     ListNode* reversedHead = r.reverseList(head);

     ListNode* current = reversedHead;
     while (current != nullptr) {
         cout << current->val << " ";
         current = current->next;
     }

     current = reversedHead;
     while (current != nullptr) {
         ListNode* next = current->next;
         delete current;
         current = next;
     }

     vector <int> V;
     int target;
     LeetCode2 m;
     //10. Baseball Game
     vector<string> ops; int i;
     ops = { "5", "2", "C", "D", "+" };
     cout << "\n1. Baseball Game:";
     cout << "\n ops="; write_vectorstring(ops);
     ;
     cout << "\nAnswer:" << m.calPoints(ops);



     // 11. Sort the People
     cout << "\n2.Sort the People";
     vector<string> vs = { "Mary", "John", "Emma" };
     V = { 180, 165, 170 };

     cout << "\nnames = [\"Mary\", \"John\", \"Emma\"],\nheights = [180, 165, 170]";
     vector <string> ans = m.sortPeople(vs, V);
     cout << "\nPeople sorted by height:";
     cout << "["; write_vectorstring(ans); cout << "]";



     //12.First Unique Character in a String
     string s, n;
     s = "loveleetcode";
     cout << endl << "\n8.First Unique Character in a String";
     cout << "\ns="; write_string(s);
     n = m.firstUniqChar(s);
     cout << "\n Index of the first non-repeating character in it is:" << n;

     //13.
     string num = "35462198";

     LeetCode2 solution;
     string result = solution.largestOddNumber(num);

     cout << "Largest Odd Number: " << result << endl;
     //14.
     vector<int> nums = { 3, 6, 2, 8, 1, 4, 7, 5 };
     int largestPerim = m.largestPerimeter(nums);
     cout << "Largest perimeter: " << largestPerim << endl;
     //15.
     vector<vector<int>> grid = { { 4, 3, -1, -2 },
                                 { 3, 2, -1, -2 },
                                 { 1, 1, -1, -3 },
                                 { -1, -1, -2, -4 } };
     int negativeCount =m. countNegatives(grid);
     cout << "Negative Count: " << negativeCount << endl;
     //16.
     int number = 25;
     int squareRoot = m.mySqrt(number);
     cout << "Square root of " << number << " is: " << squareRoot << endl;

     //17.
     LeetCode2 lnode;
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(6);
     head->next->next->next = new ListNode(3);
     head->next->next->next->next = new ListNode(4);
     head->next->next->next->next->next = new ListNode(5);
     head->next->next->next->next->next->next = new ListNode(6);

     int valToRemove = 6;

     cout << "Lista fillestare: ";
     ListNode* current = head;
     while (current != nullptr) {
         cout << current->val << " ";
         current = current->next;
     }
     cout << endl;
     // Heqim elementet me vlerën 6 nga lista
     ListNode* newHead = lnode.removeElements(head, valToRemove);

     cout << "Lista pasi heqim elementet me vlerën " << valToRemove << ": ";
     current = newHead;
     while (current != nullptr) {
         cout << current->val << " ";
         current = current->next;
     }
     cout << endl;

     // Lirimi i memorjes
     ListNode* temp;
     while (newHead != nullptr) {
         temp = newHead;
         newHead = newHead->next;
         delete temp;


         //18
         LeetCode2 w;
         w.queue.push(1);
         w.queue.push(2);
         w.queue.push(3);
         cout << w.queue.peek() << endl;
         cout << w.queue.pop() << endl;
         cout << w.queue.empty() << endl;

         //19
         LeetCode2 m;
         int number = 1234;
         int result = m.minimumSum(number);
         cout << "The minimum sum of digits is: " << result << endl;

         //20
         //
         // Krijimi i pemës s1
         TreeNode* s1 = new TreeNode(1);
         s1->left = new TreeNode(2);
         s1->right = new TreeNode(3);

         // Krijimi i pemës s2
         TreeNode* s2 = new TreeNode(1);
         s2->left = new TreeNode(2);
         s2->right = new TreeNode(3);
         LeetCode2 same;
         bool sameTree = same.isSameTree(s1, s2);
         if (sameTree) {
             cout << "Pemat jane te njejta." << endl;
         }
         else {
             cout << "Pemat nuk jane te njejta." << endl;
         }
         // Lirimi i memorjes
         delete s1->left;
         delete s1->right;
         delete s1;
         delete s2->left;
         delete s2->right;
         delete s2;
         return 0;


    return 0;
}


