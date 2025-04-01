#include <iostream>
#include <string>
#include <regex>
using namespace std;
 
int main () {
 
   if (regex_match ("aaa@bbb", regex(R"(^[a-zA-Z0-9.]+@[a-zA-Z0-9-.]+$)"))) //使用R"()"是C++11新增的一种原始字符串字面量的方式，以便
        cout << "string:literal => matched\n";                              //直接使用正则表达式中的特殊字符([,],^,$,etc.)
        //`^`: 表示匹配字符串的起始位置
        // `[a-zA-Z0-9.]+`: 表示匹配至少一个大写字母、小写字母、数字或者点号的字符
        //`@`: 表示匹配一个 '@' 符号
        // `[a-zA-Z0-9-.]+`: 表示匹配至少一个大写字母、小写字母、数字、连字符或者点号的字符
        // `$`: 表示匹配字符串的结束位置，必须加，不然报错。。。
 
   return 0;
}

//gpt nb!
/* 
用于判断字符串开头第一个字符和结尾最后一个字符是否为-号
   bool starts = str.front() == '-';
   bool ends = str.back() == '-';  

截取字符串中@前和@后的字符串
   string s;
   cin >> s;  //例：输入aaa@bbb
   string s1 = s.substr(0, s.find('@'));
   string s2 = s.substr(s.find('@') + 1);
   cout << s1 << endl;  //输出aaa
   cout << s2 << endl;  //输出bbb
 */
