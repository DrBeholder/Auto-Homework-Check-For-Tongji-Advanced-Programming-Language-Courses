#include <iostream>
#include <string>
using namespace std;

static string datapack(char a, string b)  //char a ��Ҫ���������ͣ�string b ��ҵ����
{
	cout << "������������Сֵ�����ֵ" << endl;

	//����Ҫ����ʱ
	if (a == 'n') {    
		int min, max;//��Ҫ��������Сֵ�����ֵ
		string c;
		cin >> min >> max;

		//������Ҫ���ַ���
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

	//����Ҫ����ֵʱ
	else if (a == 'f') {     
		double min, max;   //��Ҫ��������Сֵ�����ֵ����ȷ��С�������λ��
		string c;
		cin >> min >> max;

		//������Ҫ���ַ���
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
	return "����";
}