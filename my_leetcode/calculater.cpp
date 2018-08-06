#include <string>
#include <iostream>
using namespace std;

class Cal {
public:
    int calculate(string s) {
        int res = 0, current_ans = 0, num = 0, n = s.size();
        char op = '+';//初始化操作符为+

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            //转换成十进制数
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            //遇到操作符,先判断上次的操作符,进行操作
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {//计算上一次的结果
                    case '+': current_ans += num; break;
                    case '-': current_ans -= num; break;
                    case '*': current_ans *= num; break;
                    case '/': current_ans /= num; break;
                }
                //如果操作符为-+,累加当前结果
                if (c == '+' || c == '-' || i == n - 1) {
                    res += current_ans;
                    current_ans = 0;
                }
                op = c;
                num = 0;
            } 
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Cal cal;
    string s;
    while(getline(cin,s)){
        cout<<cal.calculate(s)<<endl;
    }
    return 0;
}
