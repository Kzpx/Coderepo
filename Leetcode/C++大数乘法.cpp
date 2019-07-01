// c++大数乘法

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length()-1;
        int n2 = num2.length()-1;
        if(n1 < 0 || n2 < 0) return "";
        int mul[n1 + n2 + 2];
        memset(mul, 0, sizeof(mul));
        for(int i = n1; i >= 0; --i) {
            for(int j = n2; j >= 0; --j) {
                int bitmul = (num1[i]-'0') * (num2[j]-'0');      
                bitmul += mul[i+j+1]; // 先加低位判断是否有新的进位
                
                mul[i+j] += bitmul / 10;
                mul[i+j+1] = bitmul % 10;
            }
        }
        
       string ans;
        int i = 0;
        // 去掉前导0
        while(i < n1 + n2 + 1 && mul[i] == 0) 
            i++;
        int st = i;
        for(; i <= n1 + n2 + 1; ++i)
            ans += mul[i] + '0';
        return ans;
    }
};
