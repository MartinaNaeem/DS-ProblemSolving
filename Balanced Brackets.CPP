#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    int i, j, size=s.length(), flag=size;
    if(size%2 !=0)   return "NO";
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++) {
            if((s[i]=='(' && s[j]==')') || (s[i]=='{' && s[j]=='}') || (s[i]=='[' && s[j]==']')) {              
                
                s.erase(j,1);
                s.erase(i,1);
                i--;
                size-=2;
                // s[i]=s[j]='0';
                // flag-=2;  
            }    
        }
    }
    if(size==0) return "YES";
    
    return "NO";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
