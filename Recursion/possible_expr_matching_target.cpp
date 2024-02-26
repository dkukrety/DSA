/*

Asymptotic complexity in terms of `n` = size of the input string.
* Time: O(n * 3^n).
* Auxiliary space: O(n * 3^n).
* Total space: O(n * 3^n).


int n;

// Function to convert string to long long int, e.g. "123" -> 123.
long long int str_to_ll(string &str) {
    long long int val = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        val = val * 10LL + (str[i] - '0');
    }
    return val;
}


Function to generate all valid expressions that evaluate to the given target value.

Parameters:
all_expressions_container -> will contain the answer.
cur_expr -> will contain the expression built until now.
s -> given string.
target -> given target value.
pos -> in cur_expr we have already included digits from s[0, pos - 1];
    digits from s[pos, n - 1] remain to be processed.
cur_expr_val -> value of cur_expr.
cur_expr_val_after_rightmost_addition_sign -> value of cur_expr after the rightmost '+'.

Why this last parameter is needed will be explained below. Some examples of its value:
Suppose cur_expr = 52 then cur_expr_val_after_rightmost_addition_sign = 52.
Suppose cur_expr = 52+47 then cur_expr_val_after_rightmost_addition_sign = 47.
Suppose cur_expr = 52+3*4 then cur_expr_val_after_rightmost_addition_sign = 12.
Suppose cur_expr = 52+3*4*2 then cur_expr_val_after_rightmost_addition_sign = 24.
Suppose cur_expr = 52+3*4*2+78 then cur_expr_val_after_rightmost_addition_sign = 78.

If one of the final expressions is 1+2*3*4+5+6*7+8, it will be built in "cur_expr" parameter like so:
    -> 1 (First time we will not add any operator with the number.)
    -> 1+2 (Afterwards we will add one operator, '+' or '*', with number.)
    -> 1+2*3
    -> 1+2*3*4
    -> 1+2*3*4+5
    -> 1+2*3*4+5+6
    -> 1+2*3*4+5+6*7
    -> 1+2*3*4+5+6*7+8

    void generate_all_expressions_util(
    vector<string> &all_expressions_container,
    string cur_expr,
    string &s,
    long long int target,
    int pos,
    long long int cur_expr_val,
    long long int cur_expr_val_after_rightmost_addition_sign) {
    // If processed the whole string.
    if (pos == n) {
        // Check if generated expression evaluates to the target value or not.

        if (cur_expr_val == target) {
            // If generated expression evaluates to the target value then store it.
            all_expressions_container.push_back(cur_expr);
        }
        return;
    }

    As mentioned earlier we will build "cur_expr" in stages like so:
        -> 1 (First time we will not add any operator with the number.)
        -> 1+2 (Afterwards we will add one operator, '+' or '*', with number.)
        -> 1+2*3
        -> .....

    The following loop will consider all possible tails/remainders of the string
    (s[pos, i] where i runs from pos to the end of the string)
    as a number and use that number in cur_expr with different operations.

    Considering all possible tails/reminders takes care of trying the "join" operator in
    all possible places. As for '+' and '*' in all possible places, the explicit recursive
    calls of generate_all_expressions_util() inside this loop take care of those.


    for (int i = pos; i < n; i++) {
        // Get the string s[pos, i] (both inclusive).
        string number_to_add_as_str = s.substr(pos, i - pos + 1);
        // Convert it to number.
        long long int number_to_add = str_to_ll(number_to_add_as_str);
        // If we have just started then first we will add the number without an operator.
        if (pos == 0) {
            generate_all_expressions_util(all_expressions_container, number_to_add_as_str, s, target,
                                          i + 1, number_to_add, number_to_add);
        } else {

            Add the number with '+' operator before it.

            For the next call variables will be:

            - cur_expr = cur_expr + '+' + number_to_add_as_str
              (we are adding number with '+' operator before the tail)

            - pos = i + 1
              (we included s[pos, i]; now remaining string to add is s[i + 1, n - 1])

            - cur_expr_val = cur_expr_val + number_to_add
              (we have added the number in the cur_expr with '+' operator, value of the cur_expr
              must be increased accordingly)

            - cur_expr_val_after_rightmost_addition_sign = number_to_add
              (We added number in the cur_expr with '+' operator. The value of the expression
              after the rightmost '+' operator is the number that we added.)


      generate_all_expressions_util(all_expressions_container, cur_expr + '+' +

                                                                         number_to_add_as_str,
                                          s, target, i + 1, cur_expr_val + number_to_add, number_to_add);

     Add the number with '*' operator before it.

            For the next call variables will be:

            - cur_expr = cur_expr + '*' + number_to_add_as_str
              (we are adding number with '*' operator before it)

            - pos = i + 1
              (we included s[pos, i]; now remaining string to add is s[i + 1, n - 1])

            Now let's take one example before we mention other variables.
            Suppose we already have built cur_expr = "1+3" then cur_expr_val will be 4 and
            cur_expr_val_after_rightmost_addition_sign will be 3.
            Now if we want to add 4 with '*' operator then cur_expr will be "1+3*4".

            How can we find the value of "1+3*4" using the value of the previous expression "1+3"?
            Notice how due to higher precedence of '*' over '+', digit 3 now has to be used for
            multiplication instead of addition.
            So to find value of "1+3*4" from "1+3":
            - start with the value of the previous expression (that is 1+3=4),
            - subtract the value of expression after the right most '+' sign (that is 3),
            - multiply that "value of expression after the right most '+' sign" (that is 3),
              by the new number we are processing (that is 4, and so the product would be 3*4=12)
            - and add that product (12) to what we had so far.

            In other words: 4 - 3 + (3 * 4) = 13. And in terms of the parameters:

            - cur_expr_val = cur_expr_val - cur_expr_val_after_rightmost_addition_sign +
              (cur_expr_val_after_rightmost_addition_sign * number_to_add)

            After doing all that, now our "value after right most '+' sign" becomes 3*4=12:

            - cur_expr_val_after_rightmost_addition_sign =
            cur_expr_val_after_rightmost_addition_sign * number_to_add

             generate_all_expressions_util(
                all_expressions_container,

                cur_expr + '*' + number_to_add_as_str, s, target, i + 1,

                cur_expr_val - cur_expr_val_after_rightmost_addition_sign +

                    (cur_expr_val_after_rightmost_addition_sign * number_to_add),

                cur_expr_val_after_rightmost_addition_sign * number_to_add);
        }
    }
}

vector<string> generate_all_expressions(string s, long long int target) {
    // Store length of given string in a global variable because we will be accessing it lots of times.
    n = s.length();

    // This vector will store the answer.
    vector<string> all_expressions_container;
    generate_all_expressions_util(all_expressions_container, "", s, target, 0, 0LL, 0LL);
    return all_expressions_container;
}


*/