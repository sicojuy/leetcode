#include <iostream>
#include <string>
using namespace std;

class BigNumber {
    private:
        string data;

    public:
        BigNumber(const char *s = NULL);
        BigNumber(const string &s);
        string& toString();
        void trimPrefixZero();
        BigNumber& operator=(const BigNumber &num);
        BigNumber operator+(const BigNumber &num);
        BigNumber operator*(const BigNumber &num);
        BigNumber pow(int n);
};

BigNumber::BigNumber(const char *s): data(s == NULL ? string("0") : string(s)) {
}

BigNumber::BigNumber(const string &s): data(s) {
}

string& BigNumber::toString() {
    return data;
}

void BigNumber::trimPrefixZero() {
    int i;
    for (i = 0; i < data.size(); i++) {
        if (data[i] != '0') break;
    }
    if (i == data.size()) {
        data = "0";
    } else if (i > 0) {
        data = data.substr(i, data.size() - i);
    }
}

BigNumber& BigNumber::operator=(const BigNumber &num) {
    if (this == &num) {
        return *this;
    }
    data = num.data;
    return *this;
}

BigNumber BigNumber::operator+(const BigNumber &num) {
    string tmpData;
    int i, j, k;
    i = data.size();
    j = num.data.size();
    k = (i > j ? i : j) + 1;
    tmpData.resize(k);
    int n, p;
    p = 0;
    for (i = i - 1, j = j - 1, k = k - 1; i >= 0 && j >= 0 && k >= 0; i--, j--, k--) {
        n = data[i] - '0' + num.data[j] - '0' + p;
        p = n / 10;
        tmpData[k] = '0' + n % 10;
    }
    while (i >= 0) {
        n = data[i] - '0' + p;
        p = n / 10;
        tmpData[k] = '0' + n % 10;
        i--;
        k--;
    }
    while (j >= 0) {
        n = num.data[j] - '0' + p;
        p = n / 10;
        tmpData[k] = '0' + n % 10;
        j--;
        k--;
    }
    tmpData[k] = p > 0 ? '0' + p : '0';
    BigNumber result(tmpData);
    result.trimPrefixZero();
    return result;
}

BigNumber BigNumber::operator*(const BigNumber &num) {
    BigNumber result; 
    string tmpData;
    int i, j, k; 
    tmpData.resize(data.size()+1);
    int n, p;
    for (i = num.data.size() - 1; i >= 0; i--) {
        k = tmpData.size() - 1;
        p = 0;
        for (j = data.size() - 1; j >= 0; j--, k--) {
            n = (num.data[i] - '0') * (data[j] - '0') + p;
            p = n / 10;
            tmpData[k] = '0' + n % 10;
        }
        tmpData[k] = p > 0 ? '0' + p : '0';
        result = result + BigNumber(tmpData + string(num.data.size() - i - 1, '0'));
    }
    return result;
}

BigNumber BigNumber::pow(int n) {
    BigNumber result("1"); 
    BigNumber tmpNum;
    tmpNum.data = data;
    while (n > 0) {
        if (n & 1) {
            result = result * tmpNum; 
        } 
        tmpNum = tmpNum * tmpNum;
        n = n >> 1;
    }
    return result;
}

int main() {
    BigNumber b("111");
    b = b.pow(100);
    cout << b.toString() << endl;
    return 0;
}
