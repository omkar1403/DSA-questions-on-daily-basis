#include <bits/stdc++.h> 
long long titleToNumber(string str) {
    long long titleNumber = 0;

    for (int i = 0; i < str.size(); ++i) {
        titleNumber *= 26;
        titleNumber += str[i] - 'A' + 1;
    }

    return titleNumber;
}