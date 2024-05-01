#include <iostream>
#include <string>
using namespace std;

void output(string name, bool c) {
	if (c) {
		cout << "运行完成，以下四项依次为" << name << "-1.exe, " << name << "-1-VS.exe, " << name << "-2.exe, " << name << "-2-VS.exe与" << name << "-demo.exe运行结果的比较：\n" << endl;
		string log = "type " + name + "-comparison.log";
		system(log.c_str());
		cout << endl;
		cout << "本次运行生成的数据集可在" << name << "-0-data.txt中找到\n老师示范程序的输出可在"
			<< name << "-0-result.log中找到\n被检程序的输出可在(各自名称)-answer.log中找到\n完整比较结果可在"
			<< name << "-compaison.log中找到\n" << endl;
	}
	else {
		cout << "运行完成，以下两项依次为" << name << ".exe, " << name << "-VS.exe与" << name << "-demo.exe运行结果的比较：\n" << endl;
		string log = "type " + name + "-comparison.log";
		system(log.c_str());
		cout << endl;
		cout << "本次运行生成的数据集可在" << name << "-0-data.txt中找到\n老师示范程序的输出可在"
			<< name << "-0-result.log中找到\n被检程序的输出可在(各自名称)-answer.log中找到\n完整比较结果可在"
			<< name << "-compaison.log中找到\n" << endl;
	}
}