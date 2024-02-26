

/*Palindromic Decomposition Of A String
Find all palindromic decompositions of a given string s.

A palindromic decomposition of string is a decomposition of the string into substrings,
 such that all those substrings are valid palindromes.

Example
{
"s": "abracadabra"
}
Output:

["a|b|r|a|c|ada|b|r|a", "a|b|r|aca|d|a|b|r|a", "a|b|r|a|c|a|d|a|b|r|a"]

Notes
Any string is its own substring.
Output should include ALL possible palindromic decompositions of the given string.
Order of decompositions in the output does not matter.
To separate substrings in the decomposed string, use | as a separator.
Order of characters in a decomposition must remain the same as in the given string. For example, for s = "ab", return ["a|b"] and not ["b|a"].
Strings in the output must not contain whitespace. For example, ["a |b"] or ["a| b"] is incorrect.

basically we will go through string one char at a time.
for each char, we will check if we want it to add to slate or "|" partition it.
also for each partition addition we added palindrome check as it will optimize the solution.

*/

bool is_palindrome(string str)
{
    int len = str.length();
    // cout<<str<<"  enter "<<len<<endl;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - (i + 1)])
        {
            // cout<<str[i]<<"   "<<str[len-(i+1)]<<endl;
            return false;
        }
    }
    // cout<<str<<"  is true "<<endl;
    return true;
}

void helper(string s, int index, string slate, string last_string, vector<string> &result)
{
    // base_case
    if (index == s.length())
    {
        cout << index << "  " << last_string << endl;
        if (is_palindrome(last_string))
        {
            result.push_back(slate);
        }
        return;
    }

    // concat case

    slate += s[index];
    // last_string = last_string+s[index];
    // cout<<slate<<"  "<<last_string<<endl;
    helper(s, index + 1, slate, last_string + s[index], result);
    slate.pop_back();

    // partition case, when we try to add "|"
    if (!(is_palindrome(last_string)))
        return;

    slate = slate + "|" + s[index];
    // cout<<slate;
    last_string = s[index];
    helper(s, index + 1, slate, last_string, result);
    // Need to pop back two times as we added 2 chars.
    slate.pop_back();
    slate.pop_back();
}

vector<string> generate_palindromic_decompositions(string &s)
{
    vector<string> result;
    string slate = "";
    slate = slate + s[0];
    string last_string = "";
    last_string += s[0];
    helper(s, 1, slate, last_string, result);
    return result;
}
