#include <iostream>
#include <string>
using namespace std;

string datapack(char a, string b)  //char a 需要的数据类型，string b 作业代码
{
	

	//当需要整型时
	if (a == 'n') {    
		int min, max;//需要的数据最小值，最大值
		string c;
		cout << "请依次输入最小值，最大值" << endl;
		cin >> min >> max;

		//生成需要的字符串
		c = c + to_string(max - min + 1) + "\n";
		for (int i = min; i <= max; i++) {
			if (i-min+1 < 10) {
				c = c + "[" + b + "-0" + to_string(i - min + 1) + "]\n";
				c = c + to_string(i) + "\n";
			}
			else {
				c = c + "[" + b + "-" + to_string(i - min + 1) + "]" + "\n";
				c = c + to_string(i) + "\n";
			}
		}
		return c;
	}

	//当需要浮点值时
	else if (a == 'f') {     
		double min, max;   //需要的数据最小值，最大值（精确到小数点后两位）
		string c;
		cout << "请依次输入最小值，最大值" << endl;
		cin >> min >> max;

		//生成需要的字符串
		c = c + to_string(int(100 * max -100 * min) + 1) + "\n";
		for (int i = int(min * 100); i <= int(max * 100); i++) {
			if (i - int(min * 100) + 1 < 10) {
				c = c + "[" + b + "-0" + to_string(i - int(min * 100) + 1) + "]" + "\n";
				c = c + to_string(i * 0.01) + "\n";
			}
			else {
				c = c + "[" + b + "-" + to_string(i - int(min * 100) + 1) + "]" + "\n";
				c = c + to_string(i * 0.01) + "\n";
			}
		}
		return c;
	}
	else if (a == 'c'){
		char min, max;
		cout << "请依次输入最小值，最大值（以ASCII码为准）" << endl;
		string c;
		cin >> min >> max;
		for (int i = min; i <= max; i++) {
			if (i - min + 1 < 10) {
				c = c + "[" + b + "-0" + to_string(i - min + 1) + "]\n";
				c = c + to_string(char(i)) + "\n";
			}
			else {
				c = c + "[" + b + "-" + to_string(i - min + 1) + "]" + "\n";
				c = c + to_string(char(i)) + "\n";
			}
		}
		return c;
	}
	return "错误";
}