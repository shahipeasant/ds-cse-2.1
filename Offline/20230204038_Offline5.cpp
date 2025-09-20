#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 30;
    if (c == '*' || c == '/')
        return 20;
    if (c == '+' || c == '-')
        return 10;
    return -1;
}

vector<string> infixToPostfix(const string &infix)
{
    vector<string> postfix;
    stack<char> st;
    int n = infix.size();

    for (int i = 0; i < n; i++)
    {
        char symbol = infix[i];

        if (symbol == ' ')
            continue;

        if (isdigit(symbol))
        {
            string num;
            while (i < n && isdigit(infix[i]))
            {
                num += infix[i];
                i++;
            }
            i--; 
            postfix.push_back(num);
        }

        else if (symbol == '(')
        {
            st.push(symbol);
        }

        else if (symbol == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            while (!st.empty() && precedence(st.top()) >= precedence(symbol))
            {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(symbol);
        }
    }

    while (!st.empty())
    {
        postfix.push_back(string(1, st.top()));
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(const vector<string> &postfix)
{
    stack<int> st;

    for (auto &token : postfix)
    {
        // If number, push to stack
        if (token[0] >= '0' && token[0] <= '9')
        {
            st.push(stoi(token));
        }
        // Operator
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int res = 0;
            if (token == "+")
                res = a + b;
            else if (token == "-")
                res = a - b;
            else if (token == "*")
                res = a * b;
            else if (token == "/")
                res = a / b;
            st.push(res);
        }
    }

    return st.top();
}

int main()
{
    string infix;
    cout << "Enter Infix Expression: " << endl;
    getline(cin, infix);

    vector<string> postfix = infixToPostfix(infix);

    cout << "Postfix Expression: ";
    for (auto &p : postfix)
        cout << p << " ";
    cout << "\n";

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << "\n";

    return 0;
}
