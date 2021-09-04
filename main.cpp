#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int dig;

long long result;
long long last(int num) {//num digits magic number
//    if(num == 1){
//        return 10;
//    } else{
//        if(num % 2 == 0){//even
//            return pow(10,num / 2 - 1)*9;
//        } else{//odd
//            return pow(10,num / 2 )*9;
//        }
//    }

    if (num > dig) {
//        cout << result << endl;
        return result;
    } else {
        if (num == 1) {
            result = 10;
        } else {
            if (num % 2 == 0) {//even
                result += pow(10, num / 2 - 1) * 9;
            } else {//odd
                result += pow(10, num / 2) * 9;
            }
//            cout << result <<endl;
        }
        last(num + 1);
    }

}

long long endLarger(string str) {
    int num = 0;
    if (str.length() % 2 == 0) {//even
        num = str.length() / 2;
    } else {
        num = str.length() / 2 + 1;
    }

    string newString = str.substr(0, num);
//    cout << stoi(newString) -  pow(10,newString.length() - 1) + 1  <<endl;
    return stoi(newString) - pow(10, newString.length() - 1) + 1;
}

long long frontLarger(string str) {
//    int tempString;
//    cout << str.length() << endl;

    if(str.length() % 2 == 0 ) {//even
//        cout << "even" << endl;
        long long a = stoll(str.substr(0, str.length()/2)) - 1;
        stringstream ss ;
        ss << a;
        string b = ss.str();
        string c = b;
        reverse(c.begin() , c.end());
//        cout <<"even"+ b + c << endl;
        return endLarger(b + c);

//        string b = a;
//        reverse(b.begin(), b.end());

    } else{
        long long a = stoll(str.substr(0, str.length()/2 + 1)) - 1;
        stringstream ss;
        ss << a;
        string b = ss.str();
        string c = b;
        reverse(c.begin(), c.end());
        string d = c.substr(1, c.length() - 1);
//        cout << b + d << endl;
        return endLarger(b + d);
    }

//    if (str.length() % 2 == 0) {//even
//        string newString1;
//        string newString2;
//        if (str.substr(str.length() / 2, 1) >=
//            str.substr(str.length() / 2 - 1, 1)) {//the first one of two middle num is larger
//            tempString = stoi(str.substr(str.length() / 2, 1)) - 1;
//        } else {
//            tempString = stoi(str.substr(str.length() / 2, 1));
//        }
//
//        stringstream ss;
//        ss << tempString;
//
//        newString1 = str.substr(0, str.length() / 2 - 1) + ss.str();
//        newString2 = newString1;
//        reverse(newString1.begin(), newString1.end());
//         cout << newString2 + newString1<< endl;
//
//        return endLarger(newString2 + newString1);
//    } else {
//        string newString1 = str.substr(0, str.length() / 2);//front digits
//        string newString2 = str.substr(str.length() / 2, 1);//middle digit
//
//
//        int tempNum = stoi(newString2) - 1;
//        if (newString2 == "0") {
//            tempNum = 9;
//            long long tempFront = stoll(newString1) - 1;
//            stringstream s;
//            s << tempFront;
//            newString1 = s.str();
//        }
//        string newString3 = newString1;
//        reverse(newString3.begin(), newString3.end());
//
//        stringstream ss;
//        ss << tempNum;
////        cout << newString1 + ss.str() + newString3 << endl;
//        return endLarger(newString1 + ss.str() + newString3);
//    }
}

bool comp(string str) {
//    string reString = str;
//    reverse(reString.begin(), reString.end());
//    if(stoll(str.substr(0,str.length()/2)) <= stoll(reString.substr(0, str.length()/2)) ){//endLarger
//        return true;
//    } else{
//        return false;
//    }
    long long comEnd;
    long long comFront;
    if (str.length() % 2 == 0) {//even
        comEnd = stoll(str.substr(str.length() / 2, str.length() / 2));

    } else {
        comEnd = stoll(str.substr(str.length() / 2 + 1, str.length() / 2));

    }
    string temp = str.substr(0, str.length() / 2);
    reverse(temp.begin(), temp.end());
    comFront = stoll(temp);
    if (comEnd >= comFront) {//endLarger
        return true;

    } else {
        return false;
    }

}

long long magic(string str) {
    if (comp(str)) {
        return endLarger(str);
    } else {
        return frontLarger(str);
    }

}

bool check(string str){
    if(pow(10, str.length() - 1) == stoll(str)){
        return true;
    } else{
    return false;
    }
}

int main() {
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        string str;
        cin >> str;
        dig = str.length() - 1;
        if(str == "10"){
            cout << 10 << endl;
            continue;
        }
        if (dig == 0) {//one digit number
            cout << 1 + stoi(str) << endl;
        } else {
            if(check(str)){//100000
                long long temp = stoll(str) - 1;
                stringstream ss;
                ss <<  temp;
                str = ss.str();
                dig = dig -1;
//                cout << "change to " << str << endl;
            }
                cout << last(1) + magic(str) << endl;
        }

    }
    return 0;
}


