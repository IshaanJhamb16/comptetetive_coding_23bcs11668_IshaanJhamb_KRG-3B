#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokens;
vector<string> result;
int curr = 0;
bool possible = true;

void build() {
    
    if (curr >= tokens.size()) {
        possible = false;
        return;
    }

    string type = tokens[curr++];
    if (type == "pair") {
        result.push_back("pair<");
        build(); 
        result.push_back(",");
        build(); 
        result.push_back(">");
    } else {
       
        result.push_back("int");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string s;
    while (cin >> s) {
        tokens.push_back(s);
    }

    build();

    
    if (!possible || curr < tokens.size()) {
        cout << "Error" << endl;
    } else {
        for (const string& part : result) {
            cout << part;
        }
        cout << endl;
    }

    return 0;
}