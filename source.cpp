#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "datapack.cpp"
#include "Check.cpp"
using namespace std;

int main() {
	cout << "Auto-Homework_Check [版本 0.1.1-Alpha]" << endl;
	cout << "Copyright (c) 2024 Beholder. " << endl << endl;
	string name, full_Name_Data, full_Name_Bat;    //作业代号，数据集文件名和批处理文件名
	string data_Pack, bat_Pack;          //生成的数据集和批处理文件
	char data_Type;       //需要的数据类型
	int place, size;            //\n位置


	//作业代号
	cout << "输入作业代号" << endl;
	cin >> name;


	//数据类型
	input:
	cout << "输入需要的数据类型（整型为n，浮点型为f）" << endl;
	cin >> data_Type;

	if (cin.fail()) {
		cout << "输入错误，请重新输入" << endl;
		cin.clear();
		cin.ignore();
		goto input;
	}

	if ((data_Type != 'f') && (data_Type != 'n')) {
		cout << "数据类型无效，请重新输入" << endl;
		goto input;
	}

	//数据集生成
    data_Pack_Creating:
	data_Pack = datapack(data_Type, name);   //生成数据集并存放在变量中
	place = data_Pack.find("\n");            //找出\n的位置

	if (data_Pack.substr(0, place) == "错误") {
		cout << "哎呀，出错了" << endl;
		return 1;
	}

	size = stoi(data_Pack.substr(0, place)); //读取数据集大小
	data_Pack.erase(0, place + 1);           //将数据集大小的值从字符串中移除
	full_Name_Data = name + "-0-data.txt";     //利用作业代号生成数据集文件名

	
	if (size >= 500) {    //判断数据集大小是否过大
		bool confirm;
	    confirmA:
		cout << "生成的数据集过大，运行时间可能很长，是否继续？（1或0）" << endl;
		cin >> confirm;
		if (cin.fail()) {
			cout << "是否继续 回答不正确 请重新回答" << endl;
			cin.clear();
			cin.ignore();
			goto confirmA;
		}
		if (!confirm) {
			goto data_Pack_Creating;
		}
	}
		
	
	//批处理文件生成
	bat_Pack = check(size, name);            //生成批处理文件并存放在变量中
	full_Name_Bat = name + "-check.bat";     //利用作业代号生成批处理文件名


	//将包含数据集的字符串输入到txt文件中
	ofstream dataFile;
	dataFile.open(full_Name_Data, ofstream::trunc);
	dataFile << data_Pack << endl;
	dataFile.close();


	//将包含批处理文件的字符串输入到bat文件中
	ofstream batFile;
	batFile.open(full_Name_Bat, ofstream::trunc);
	batFile << bat_Pack << endl;
	batFile.close();

	system("cls");
	cout << "请稍等，程序正在运行" << endl;
	const char* c = full_Name_Bat.c_str();
	system(c);
	system("del *.bat");
	system("cls");

	cout << "运行完成，以下四项依次为"<< name << "-1.exe, "<< name << "-1-VS.exe, "<< name << "-2.exe, "<< name << "-2-VS.exe与"<< name << "-demo.exe运行结果的比较：\n" << endl;
	string log = "type " + name + "-comparison.log";
	system(log.c_str());
	cout << endl;
	cout << "本次运行生成的数据集可在" << name << "-0-data.txt中找到\n老师示范程序的输出可在" 
		 << name << "-0-result.log中找到\n被检程序的输出可在(各自名称)-answer.log中找到\n完整比较结果可在"
		 << name << "-compaison.log中找到\n" << endl;
	cout << "程序运行结束，按任意键退出\n注意：退出后将清理本次生成的数据集，程序输出结果和比较结果";
	system("pause > nul");
	system("del *.txt");
	system("del *.log");
	return 0;
}