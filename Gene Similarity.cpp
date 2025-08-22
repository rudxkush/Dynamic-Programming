#include <bits/stdc++.h>
using namespace std;

vector<pair<char, long long>> tokenise(string& s) {
    vector<pair<char, long long>> ans;
    int n = s.length();
    int i = 0;

    while (i < n) {
        int j = i;
        while (j < n && isdigit(s[j])) j++;
        long long count = stoll(s.substr(i, j - i));
        char ch = s[j];
        ans.emplace_back(ch, count);
        i = j + 1;
    }
    return ans;
}

string geneSimilarity(string s1, string s2) {
    auto tokenisedGene1 = tokenise(s1);
    auto tokenisedGene2 = tokenise(s2);

    int i = 0, j = 0;
    long long c1 = 0, c2 = 0;
    char ch1 = '\0', ch2 = '\0';

    long long total = 0, matched = 0;

    while (i < tokenisedGene1.size() || c1 > 0) {
        if (c1 == 0 && i < tokenisedGene1.size()) {
            ch1 = tokenisedGene1[i].first;
            c1 = tokenisedGene1[i].second;
            i++;
        }
        if (c2 == 0 && j < tokenisedGene2.size()) {
            ch2 = tokenisedGene2[j].first;
            c2 = tokenisedGene2[j].second;
            j++;
        }

        if (c1 == 0 || c2 == 0) continue;

        long long common = min(c1, c2);
        total += common;
        if (ch1 == ch2) matched += common;
        c1 -= common;
        c2 -= common;
    }

    return to_string(matched) + "/" + to_string(total);
}

int main() { 
    cout << geneSimilarity("3T2G4A1C", "6T1A2C1G") << endl;
    return 0;
}
