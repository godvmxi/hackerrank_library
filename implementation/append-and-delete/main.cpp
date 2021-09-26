#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int len_s = s.length();
    int len_t = t.length();
    int short_len = len_s < len_t ? len_s : len_t;

    int len_match = 0;

    for(int i =0; i < short_len; i++)
    {
        //cout << "compare: " << i << "->" << s[i] << "<-  "<< "->" << t[i] << "<-  " << endl;
        if(s[i] != t[i])
        {
            //len_match = i;
            break;
        }
        else
        {
            len_match = i+1;
        }
    }
    cout << "src: " << s << endl;
    cout << "dst: " << t << endl;
    cout << "src: " << len_s
            << " dst: " << len_t
            << " min: " << short_len
            << " match: " << len_match
            << " limit:"<< k <<endl;
    int tot = (len_s - len_match) + (len_t -len_match);
    //cout << "result: " << result << endl;
    //return tot <= k ? "Yes": "No";
    return (tot == k) || ( ( tot < k) && ( (tot - k)%2 ==0 ) || (tot + (2 * len_match) <= k) )  ? "Yes": "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    cout << result << "\n";

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
