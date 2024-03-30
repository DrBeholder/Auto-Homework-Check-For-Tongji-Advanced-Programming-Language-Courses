#include <iostream>
#include <string>
using namespace std;

static string check(int a, string b) {
    string c;
    c = c + "@echo off\n";
    c = c + "get_input_data " + b + "-0-data.txt " + b + "-01" + " | " + b + "-demo.exe > " + b + "-0-result.log" + "\n";
    for (int i = 2; i <= a; i++) {
        if (i < 10) {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-0" + to_string(i) + " | " + b + "-demo.exe >> " + b + "-0-result.log" + "\n";
        }
        else {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-" + to_string(i) + " | " + b + "-demo.exe >> " + b + "-0-result.log" + "\n";
        }
    }
    c = c + "\n" + "get_input_data " + b + "-0-data.txt " + b + "-01" + " | " + b + "-1.exe > " + b + "-1-answer.log" + "\n";
    for (int i = 2; i <= a; i++) {
        if (i < 10) {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-0" + to_string(i) + " | " + b + "-1.exe >> " + b + "-1-answer.log" + "\n";
        }
        else {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-" + to_string(i) + " | " + b + "-1.exe >> " + b + "-1-answer.log" + "\n";
        }
    }
    c = c + "\n" + "get_input_data " + b + "-0-data.txt " + b + "-01" + " | " + b + "-1-VS.exe > " + b + "-1-VS-answer.log" + "\n";
    for (int i = 2; i <= a; i++) {
        if (i < 10) {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-0" + to_string(i) + " | " + b + "-1-VS.exe >> " + b + "-1-VS-answer.log" + "\n";
        }
        else {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-" + to_string(i) + " | " + b + "-1-VS.exe >> " + b + "-1-VS-answer.log" + "\n";
        }
    }
    c = c + "\n" + "get_input_data " + b + "-0-data.txt " + b + "-01" + " | " + b + "-2.exe > " + b + "-2-answer.log" + "\n";
    for (int i = 2; i <= a; i++) {
        if (i < 10) {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-0" + to_string(i) + " | " + b + "-2.exe >> " + b + "-2-answer.log" + "\n";
        }
        else {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-" + to_string(i) + " | " + b + "-2.exe >> " + b + "-2-answer.log" + "\n";
        }
    }
    c = c + "\n" + "get_input_data " + b + "-0-data.txt " + b + "-01" + " | " + b + "-2-VS.exe > " + b + "-2-VS-answer.log" + "\n";
    for (int i = 2; i <= a; i++) {
        if (i < 10) {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-0" + to_string(i) + " | " + b + "-2-VS.exe >> " + b + "-2-VS-answer.log" + "\n";
        }
        else {
            c = c + "get_input_data " + b + "-0-data.txt " + b + "-" + to_string(i) + " | " + b + "-2-VS.exe >> " + b + "-2-VS-answer.log" + "\n";
        }
    }
    c = c + "txt_compare --file1 " + b + "-1-answer.log --file2 " + b + "-0-result.log --display detailed > " + b + "-comparison.log" + "\n";
    c = c + "txt_compare --file1 " + b + "-1-VS-answer.log --file2 " + b + "-0-result.log --display detailed >> " + b + "-comparison.log" + "\n";
    c = c + "txt_compare --file1 " + b + "-2-answer.log --file2 " + b + "-0-result.log --display detailed >> " + b + "-comparison.log" + "\n";
    c = c + "txt_compare --file1 " + b + "-2-VS-answer.log --file2 " + b + "-0-result.log --display detailed >> " + b + "-comparison.log" + "\n";
    return c;
}