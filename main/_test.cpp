
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto idx = std::find(seoul.begin(), seoul.end(), "Kim");
    answer = "김서방은 " + static_cast<int>(std::distance(seoul.begin(), idx)) + "에 있다.";

    return answer;
}

int main()
{


    return 0;
}