// CPP program to reverse a stack  
#include<bits/stdc++.h> 
using namespace std;

int main () 
{ 
    stack <int> s1, s2;
    int n,val;

    cout << "Enter number of values to be stored in the stack: \n";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value: \n";
        cin >> val;
        s1.push(val);
    }
    cout << "\n\nValues being pushed into the reverse stack:\n";
    //Pop values from stack1 and push it into stack2. This way
    //the values will be stored into stack 2 in reverse order.
    for (int i = 0; i < n; i++) {
        val = s1.pop();
        cout << val << endl;
        s2.push(val);
    }
}