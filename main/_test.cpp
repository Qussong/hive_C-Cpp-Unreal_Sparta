
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto idx = std::find(seoul.begin(), seoul.end(), "Kim");
    answer = "�輭���� " + static_cast<int>(std::distance(seoul.begin(), idx)) + "�� �ִ�.";

    return answer;
}

int main()
{


    return 0;
}