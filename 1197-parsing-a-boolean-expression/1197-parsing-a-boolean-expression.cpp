class Solution {
public:
    void parse_not(string &e) {
        // NOT should flip a single character.
        e = (e == "f") ? "t" : "f";
    }

    void parse_and(string &e) {
        // AND should result in 't' if all are 't', otherwise 'f'
        bool result = true;
        for (char c : e) {
            if (c == 'f') {
                result = false;
                break;
            }
        }
        e = result ? "t" : "f";
    }

    void parse_or(string &e) {
        // OR should result in 't' if any character is 't', otherwise 'f'
        bool result = false;
        for (char c : e) {
            if (c == 't') {
                result = true;
                break;
            }
        }
        e = result ? "t" : "f";
    }

    bool parseBoolExpr(string exp) {
        int n = exp.size();
        if (n == 0) return false;
        
        stack<char> ops;           // Stack to store operators
        stack<string> values;      // Stack to store evaluated results

        for (int i = 0; i < n; ++i) {
            char c = exp[i];

            if (c == 't' || c == 'f') {
                values.push(string(1, c));  // Push 't' or 'f' as a string
            } else if (c == '&' || c == '|' || c == '!') {
                ops.push(c);  // Push the operator to the stack
            } else if (c == '(') {
                values.push("(");  // Mark the beginning of a new sub-expression
            } else if (c == ')') {
                // Process the expression inside the parentheses
                string sub_expr = "";
                while (!values.empty() && values.top() != "(") {
                    sub_expr += values.top();
                    values.pop();
                }
                values.pop();  // Remove the '(' from the stack

                char op = ops.top();
                ops.pop();

                // Apply the operation
                if (op == '&') {
                    parse_and(sub_expr);
                } else if (op == '|') {
                    parse_or(sub_expr);
                } else if (op == '!') {
                    parse_not(sub_expr);
                }

                // Push the result back to the values stack
                values.push(sub_expr);
            }
        }

        // The last element in the values stack is the final result
        return values.top() == "t";
    }
};
