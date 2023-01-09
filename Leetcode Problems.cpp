#include<iostream>
#include<string>
#include <vector>
#include<unordered_map>
#include <iomanip>
#include<algorithm>

using namespace std;
struct Leetcode
{   // Arrays
    // 1.1Two sum solution with vector
    vector<int> twoSum(vector<int>& nums, int target);
    // 1.2Two sum solution with hash tabel
    vector<int>twoSum(vector<int>& nums, double target);
    // 2  Running Sum of 1d Array
    vector<int> runningSum(vector<int>& nums);
    // 3. Build Array from Permutation
    vector<int> buildArray(vector<int>& nums);
    // 4. Concatenation of Array
    vector<int> getConcatenation(vector<int>& nums);
    // 5. Shuffle the Array
    vector<int> shuffle(vector<int>& nums, int n);
    // 6. Matrix Diagonal Sum
    int diagonalSum(vector<vector<int>>& mat);
    // 7.How Many Numbers Are Smaller Than the Current Number
    vector<int> smallerNumbersThanCurrent(vector<int>& nums);
    // 8. Check if Matrix Is X-Matrix
    bool checkXMatrix(vector<vector<int>>& grid);
    //9.Find Target Indices After Sorting Array
    vector<int>targetIndices(vector<int>& nums, int target);
    //10.Spiral Matrix II
    vector<vector<int>> generateMatrix(int n);
    //String
    // 1. Count Asterisks
    int countAsterisks(string s);
    // 2. Sort the People
    vector<string> sortPeople(vector<string>& names, vector<int>& heights);
    // 3. To Lower Case
    string toLowerCase(string s);
    // 4. Shuffle String
    string restoreString(string s, vector<int>& indices);
    // 5. Length of Last Word
    int lengthOfLastWord(string s);
    //6. Robot Return to Origin 
    bool judgeCircle(string moves);
    // 7. Percentage of Letter in String
    int percentageLetter(string s, char ch);
    // 8. First Unique Character in a String
    int firstUniqChar(string s);
    // 9.Check If Two String Arrays are Equivalent
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2);


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
    for (int i = 0; i < mat.size(); i++){
        if (i != 0)
            cout << setw(2);
        cout  << "{";
        for (int j = 0; j < mat[i].size(); j++){
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
    Leetcode Lcd;
    // Arrays
    // 1.1 Two sum using vector
    cout << "1.1 Solution of Two sum using vector" << endl;
    int target = 9;
    vector<int> V = { 2,7,11,15 };

    cout << "Numbers in the vector are: " << endl;
    write_vector(V);

    V = Lcd.twoSum(V, target);
    cout << "Indices of the two numbers such that they add up to target " << target << " are:" << endl;
    write_vector(V);
    cout << endl;

    // 1.2 Two sum using hash tabel
    cout << "1.2 Solution of Two sum using hash tabel" << endl;
    target = 6;
    V = { 3,2,4 };

    cout << "Numbers in the vector are: " << endl;
    write_vector(V);

    V = Lcd.twoSum(V, target);
    cout << "Indices of the two numbers such that they add up to target " << target << " are:" << endl;
    write_vector(V);
    cout << endl;

    // 2 Running Sum of 1d Array
    V = { 1,2,3,4 };

    cout << "2.Running Sum of 1d Array" << endl;
    cout << "nums =";
    write_vector(V);
    V = Lcd.runningSum(V);
    //Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
    cout << "The numbers in the vector after running the sum are: " << endl;
    write_vector(V);

    // 3. Build Array from Permutation
    cout << "\n3.Build Array from Permutation" << "\n nums = ";
    V = { 0, 2, 1, 5, 3, 4 };
    write_vector(V);
    // Explanation ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
   // = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    V = Lcd.buildArray(V);
    cout << "ans =";
    write_vector(V);
    cout << endl;

    // 4. Concatenation of Array
    V = { 1,2,3 };
    cout << "4. Concatenation of Array \nnums =";
    write_vector(V);
    Lcd.getConcatenation(V);
    cout << "Ans is the concatenation of two nums arrays."
        << endl
        << "In this case ans=";
    write_vector(V);

    // 5. Shuffle the Array
    // Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
    //Return the array in the form[x1, y1, x2, y2, ..., xn, yn].
    V = { 2,5,1,3,4,7 };
    int n = 3;
    cout << "\n5. Shuffle the Array \nnums =";
    write_vector(V);
    //Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
    V = Lcd.shuffle(V, n);
    cout << "ans=";
    write_vector(V);

    // 6. Matrix Diagonal Sum
    vector<vector<int>> mat = { {1, 2, 3},{4, 5, 6}, {7, 8, 9} };
    cout << "\n6. Matrix Diagonal Sum";
    cout << "\n Matrix is"; write_matrix(mat);
    n = Lcd.diagonalSum(mat);
    cout << "\n Diagonals sum of Matrix is:" << n << endl;

    // 7.How Many Numbers Are Smaller Than the Current Number
    V = { 8,1,2,2,3 };
    cout << "\n7.How Many Numbers Are Smaller Than the Current Number";
    cout << "\nnums="; write_vector(V);
    V = Lcd.smallerNumbersThanCurrent(V);
    cout << "Answer is:"; write_vector(V);

    // 8. Check if Matrix Is X-Matrix
    mat = { {2, 0, 0, 1},{0, 3, 1, 0},{0, 5, 2, 0},{4, 0, 0, 2} };
    cout << "\n8. Check if Matrix Is X-Matrix";
    cout << "\n Matrix is"; write_matrix(mat);
    cout <<endl<< "\nIs this Matrix a X-Matrix:";
    if (Lcd.checkXMatrix(mat))
        cout << " True";
    else cout << " False";
    cout << endl;

    //9.Find Target Indices After Sorting Array
    V = { 1,2,5,2,3 }; target = 2;
    cout << "\n 9.Find Target Indices After Sorting Array";
    cout << "\nnums="; write_vector(V);
    cout << "Target=" << target;
    V = Lcd.targetIndices(V, target);
    cout << "\nAfter sorting the array in  non-decreasing order Indices of nums that are equale to target are:";
    write_vector(V);

    //10.Spiral Matrix II
    n = 5;
    cout << endl << "10.Spiral Matrix II";
    mat = Lcd.generateMatrix(n);
    cout << "\n n=" << n;
    cout << "\nIt generates an n x n matrix filled with elements from 1 to n2 in spiral order:";
    write_matrix(mat);
    cout << endl;
    //String
    // 1. Count Asterisks
    //You are given a string s, where every two consecutive vertical bars '|' are grouped into a pair. In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.
   //Return the number of '*' in s, excluding the '*' between each pair of '|'.
    cout << endl << "String";
    cout << endl << "1. Count Asterisks";
    string  s = "yo|uar|e**|b|e***au|tifu|l";
    cout << "\n s="; printf("yo|uar|e**|b|e***au|tifu|l");
    n = Lcd.countAsterisks(s);
    cout << endl << "There are " << n << " asterisks consideret.";
    cout << endl;

    // 2. Sort the People
    cout << "\n2.Sort the People";
    vector<string> vs = { "Mary", "John", "Emma" };
    V = { 180, 165, 170 };

    cout << "\nnames = [\"Mary\", \"John\", \"Emma\"],\nheights = [180, 165, 170]";
    vector <string> ans = Lcd.sortPeople(vs, V);
    cout << "\nPeople sorted by height:";
    cout << "["; write_vectorstring(ans); cout << "]";

    // 3. To Lower Case

    cout << endl << "\n3. To Lower Case";
    s = "LOVELY";
    cout << endl << "s="; printf("LOVELY");
    s = Lcd.toLowerCase(s);
    cout << endl << "After function toLowerCase:"; write_string(s);

    // 4. Shuffle String
    /*/You are given a string sand an integer array indices of the same length.
    The string s will be shuffled such that the character at the ith position moves
    to indices[i] in the shuffled string/**/

    s = "codeleet";
    V = { 4, 5, 6, 7, 0, 2, 1, 3 };
    cout << endl << "\n4. Shuffle String";
    cout << "\nBefore shuffled: "; write_string(s);
    cout << "\nIndices:"; write_vector(V);
    s = Lcd.restoreString(s, V);
    cout << "After shuffle: "; write_string(s);

    // 5. Length of Last Word

    s = " fly me to the moon";
    cout << endl << "\n5. Length of Last Word";
    cout << "\nString is:"; write_string(s);
    n = Lcd.lengthOfLastWord(s);
    cout << "\nThe length of last word is:" << n;

    // 6. Robot Return to Origin 

    cout << endl << "\n6. Robot Return to Origin";
    string move = "UD";
    cout << "\nMoves of the Robot are:"; write_string(move);
    bool b = Lcd.judgeCircle(move);
    cout << endl;
    if (b) {
        cout << "Robot is back to the Origin:True";
    }
    else
        cout << "Robot is back to the Origin:False";
    cout << "\nExplanation: The robot moves up once, and then down once."
        << "\nAll moves have the same magnitude,so it ended up at the origin where it started. "
        << "\nTherefore, we return true.";

    // 7. Percentage of Letter in String

    s = "foobar";
    char letter = 'o';
    cout << endl << "\n 7. Percentage of Letter in String";
    cout << "\n s="; write_string(s);
    cout << "\nCharacter is: \"o\"";
    n = Lcd.percentageLetter(s, letter);
    cout << "\nThe persentage of 'o' in s is:" << n << "%";
    cout << "\nExplanation :The percentage of characters in s that equal the letter 'o' "
        << "\nis 2 / 6 * 100 % = 33 % when rounded down, so we return 33.";

    //8.First Unique Character in a String

    s = "loveleetcode";
    cout << endl << "\n8.First Unique Character in a String";
    cout << "\ns="; write_string(s);
    n = Lcd.firstUniqChar(s);
    cout << "\n Index of the first non-repeating character in it is:" << n;

    // 9.Check If Two String Arrays are Equivalent

    vector<string> word1 = { "abc", "d", "defg" }, word2 = { "abcddefg" };
    cout << endl << "\n9.Check If Two String Arrays are Equivalent";
    cout << "\nWord 1=["; write_vectorstring(word1); cout << "]";
    cout << "\nWord 2=["; write_vectorstring(word2); cout << "]";
    b = Lcd.arrayStringsAreEqual(word1, word2);
    cout << "\nWord 1 and Word 2 equales:";
    if (b)
        cout << "True";
    else
        cout << "False";
    cout << endl
        << endl
        << endl;

}

// Arrays
// 1.1 Two sum - vector
vector<int>Leetcode::twoSum(vector<int>& nums, int target) {

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
// 1.2 Two sum - hash tabel
vector<int> Leetcode::twoSum(vector<int>& nums, double target) {

    unordered_map<int, int> indekset;
    for (int i = 0; i < nums.size(); i++) {
        if (indekset.find(target - nums[i]) != indekset.end()) {
            return { indekset[target - nums[i]], i };
        }
        indekset[nums[i]] = i;
    }
    return {};
}
// 2  Running Sum of 1d Array
vector<int> Leetcode::runningSum(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        count += nums[i];
        ans.push_back(count);
    }
    return ans;
}
// 3. Build Array from Permutation
vector<int>  Leetcode::buildArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = nums[nums[i]];
    }
    return ans;
}
// 4. Concatenation of Array
vector<int> Leetcode::getConcatenation(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size; ++i)
        nums.push_back(nums[i]);

    return nums;
}
// 5. Shuffle the Array
vector<int>  Leetcode::shuffle(vector<int>& nums, int n) {
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(nums[i]);
        v.push_back(nums[n + i]);
    }
    return v;
}
// 6. Matrix Diagonal Sum
int Leetcode::diagonalSum(vector<vector<int>>& mat) {
    int gjatesia = mat.size();
    int shuma = 0;
    for (int i = 0; i < gjatesia; i++) {
        for (int j = 0; j < mat[i].size(); j++) {

            if (i == j)
                shuma += mat[i][j];

            else if (i == gjatesia - 1 - j)
                shuma += mat[i][j];

        }
    }

    return shuma;
}
// 7.How Many Numbers Are Smaller Than the Current Number
vector<int> Leetcode::smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }
        }
        answer.push_back(count);
    }
    return answer;
}
// 8. Check if Matrix Is X-Matrix
bool Leetcode::checkXMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (j == i || j == n - i - 1) {

                if (grid[i][j] == 0) {
                    return false;
                }
            }
            else {
                if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}
// 9.Find Target Indices After Sorting Array
vector<int> Leetcode::targetIndices(vector<int>& nums, int target) {
    int temp;
    vector<int> res;
    int gjatesiaVargut = nums.size();
    for (int i = 0; i < gjatesiaVargut; i++) {
        for (int j = i + 1; j < gjatesiaVargut; j++) {
            if (nums[j] < nums[i]) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }

    for (int i = 0, lmt = nums.size(), n; i < lmt; i++) {
        n = nums[i];
        if (n == target) res.push_back(i);
        else if (n > target) break;
    }
    return res;
}
// 10.Spiral Matrix II
vector<vector<int>> Leetcode::generateMatrix(int n) {
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = n - 1;
    int val = 0;

    // result matrix
    vector<vector<int>> v(n, vector<int>(n));
    while (r1 <= r2 && c1 <= c2)
    {
        // left to right (row will be fixed)
        for (int i = c1; i <= c2; ++i)
            v[r1][i] = ++val;

        // move down(column will be fixed)
        for (int i = r1 + 1; i <= r2; ++i)
            v[i][c2] = ++val;

        // move right to left
        // move  up
        if (r1 < r2&& c1 < c2)
        {
            // move right to left (row will be fixed)
            for (int i = c2 - 1; i > c1; --i)
                v[r2][i] = ++val;

            // move up (column will be fixed)
            for (int i = r2; i > r1; --i)
                v[i][c1] = ++val;
        }
        ++r1;
        --r2;
        ++c1;
        --c2;
    }
    return v;
}
//String
// 1. Count Asterisks
int Leetcode::countAsterisks(string s) {
    int count = 0, vBar = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '|')
            vBar++;
        if (vBar % 2 == 0)
        {
            if (s[i] == '*')
                count++;
        }
    }
    return count;
}
// 2. Sort the People
vector<string> Leetcode::sortPeople(vector<string>& names, vector<int>& heights) {
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
// 3. To Lower Case
string  Leetcode::toLowerCase(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] = s[i] + 32;
    }
    return s;
}
// 4. Shuffle String
string Leetcode::restoreString(string s, vector<int>& indices) {
    string shuffled(s.size(), ' ');
    for (int i = 0; i < s.size(); i++) {
        shuffled[indices[i]] = s[i];
    }
    return shuffled;
}
// 5. Length of Last Word
int Leetcode::lengthOfLastWord(string s) {
    int length = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ' && length > 0)
            break;
        if (s[i] != ' ')
            length++;
    }
    return length;
}
// 6. Robot Return to Origin 
bool Leetcode:: judgeCircle(string moves) {

    int left = 0, right = 0, down = 0, up = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        if (moves[i] == 'L')
            left++;
        if (moves[i] == 'R')
            right++;
        if (moves[i] == 'U')
            up++;
        if (moves[i] == 'D')
            down++;
    }
    if ((left == right) && (up == down))
        return true;


    return false;

}
// 7. Percentage of Letter in String
int Leetcode::percentageLetter(string s, char ch)
{
    double count = 0;
    double length = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ch)
        {
            count++;
        }
    }
    double percentage = (count / length) * 100;

    return percentage;
}
// 8. First Unique Character in a String
int Leetcode::firstUniqChar(string s) {
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
// 9.Check If Two String Arrays are Equivalent
bool Leetcode::arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string one = ""; string two = "";
    for (int i = 0; i < word1.size(); i++) {
        one += word1[i];
    }
    for (int i = 0; i < word2.size(); i++) {
        two += word2[i];
    }
    return(one == two);
}