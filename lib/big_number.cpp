#include <iostream>
using namespace std;

class BigNumber {
    private:
        string data;

    public:
        BigNumber(const char *s = NULL);
        BigNumber(const string &s);
        string& toString();
        size_t size(); 
        BigNumber& operator=(const BigNumber &num);
        BigNumber operator+(const BigNumber &num);
        BigNumber operator*(const BigNumber &num);
        BigNumber pow(int n);
};

BigNumber::BigNumber(const char *s) : data(s == NULL ? string("0") : string(s)) {
}

BigNumber::BigNumber(const string &s) : data(s) {
}

string& BigNumber::toString() {
    return data;
}

size_t BigNumber::size() {
    return data.size();
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
    if (p > 0) {
        tmpData[k] = '0' + p;
        k--;
    }
    return BigNumber(tmpData.substr(k+1, tmpData.size() - k - 1));
}

BigNumber BigNumber::operator*(const BigNumber &num) {
    BigNumber newNum; 
    string tmpData;
    int i, j, k; 
    tmpData.resize(data.size() + num.data.size());
    int n, p;
    for (i = num.data.size() - 1; i >= 0; i--) {
        k = tmpData.size() - 1;
        for (int l = num.data.size() - 1; l > i; l--, k--) {
            tmpData[k] = '0'; 
        }
        p = 0;
        for (j = data.size() - 1; j >= 0; j--, k--) {
            n = (num.data[i] - '0') * (data[j] - '0') + p;
            p = n / 10;
            tmpData[k] = '0' + n % 10;
        }
        if (p > 0) {
            tmpData[k] = '0' + p;
            k--;
        }
        newNum = newNum + BigNumber(tmpData.substr(k+1, tmpData.size() - k - 1)); 
    }
    return newNum;
}

BigNumber BigNumber::pow(int n) {
    BigNumber newNum("1"); 
    BigNumber tmpNum;
    tmpNum.data = data;
    while (n > 0) {
        if (n & 1) {
            newNum = newNum * tmpNum; 
        } 
        tmpNum = tmpNum * tmpNum;
        n = n >> 1;
    }
    return newNum;
}

int main() {
    BigNumber b("111");
    b = b.pow(100);
    cout << b.toString() << endl;
    return 0;
}
