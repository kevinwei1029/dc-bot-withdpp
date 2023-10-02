#include <bits/stdc++.h>ostream>
using namespace std;

//自定義抽卡函式
string pcrgacha(string times) {
    int pcrga[3] = { 0 };
    mt19937 mt(time(nullptr));

    for (int k = 0; k < stoi(times); k++) {
        int r = mt() % 33;

        switch (r) {
        case 27:
            pcrga[0]++;
            break;

        case 15: case 9: case 31:
            pcrga[1]++;
            break;

        default:
            pcrga[2]++;
            break;
        }
    }

    string silver = to_string(pcrga[2]);
    string golden = to_string(pcrga[1]);
    string rainbow = to_string(pcrga[0]);
    return ("一共抽到了：\n" + silver + "張銀卡 <:pcr1:1117798654548377641>\n"
        + golden + "張金卡 <:pcr2:1117798436427804754>\n" + rainbow + "張彩卡 <:pcr3:1117798715957194923>\n");
}
string fgogacha(string times) {
    int fgoga[3] = { 0 };
    mt19937 mt(time(nullptr));

    for (int k = 0; k < stoi(times); k++) {
        int r = mt() % 100;

        switch (r) {
        case 47:
            fgoga[0]++;
            break;

        case 85: case 98: case 6:
            fgoga[1]++;
            break;

        default:
            fgoga[2]++;
            break;
        }
    }
    string silver = to_string(fgoga[2]);
    string golden = to_string(fgoga[1]);
    string rainbow = to_string(fgoga[0]);
    return ("先說，我沒有保底\n\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
        + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n");
}
string arkgacha(string times) {
    mt19937 mt(time(nullptr));
    int arkga[4] = { 0 };

    for (int i = 0; i < stoi(times); i++) {
        int r = mt() % 50;

        switch (r) {
        case 27:  //六星
            arkga[0]++;
            break;

        case 35: case 43: case 15: case 1:  //五星
            arkga[1]++;
            break;

        case 5: case 29: case 45: case 18: case 20: case 3: case 26: case 48: case 32: case 40: case 39: case 16: case 8: case 21: case 4:  //四星
            arkga[2]++;
            break;

        default:  //三星
            arkga[3]++;
            break;
        }
    }
    string bronze = to_string(arkga[3]);
    string silver = to_string(arkga[2]);
    string golden = to_string(arkga[1]);
    string rainbow = to_string(arkga[0]);
    return ("先說，我沒有保底\n\n一共抽到了：\n" + bronze + "張三星<:ark3:1107953947353808947>\n"
        + silver + "張四星<:ark4:1107953907377901579>\n" + golden + "張五星<:ark5:1107953865602637824>\n"
        + rainbow + "張六星<:ark6:1107953803057188905>\n");
}
string pcrget() {
    int pcrga[3] = { 0 };
    int k = 0;
    mt19937 mt(time(nullptr));

    while (pcrga[0] == 0 && k < 199) {
        int r = mt() % 33;

        switch (r) {
        case 27:
            pcrga[0]++;
            break;

        case 15: case 9: case 31:
            pcrga[1]++;
            break;

        default:
            pcrga[2]++;
            break;
        }
        k++;
    }
    string times = to_string(k);
    string silver = to_string(pcrga[2]);
    string golden = to_string(pcrga[1]);
    string rainbow = to_string(pcrga[0]);

    if (k < 199)
        return ("一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n"
            + golden + "張金卡<:pcr2:1117798436427804754>\n1張彩卡<:pcr3:1117798715957194923>\n");
    else
        return ("so sad你保底了\n\n一共抽了200抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n"
            + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n");
}
string fgoget() {
    int fgoga[3] = { 0 };
    int k = 0;
    mt19937 mt(time(nullptr));

    while (fgoga[0] == 0 && k < 329) {
        int r = mt() % 100;
        switch (r) {
        case 47:
            fgoga[0]++;
            break;

        case 85: case 98: case 6:
            fgoga[1]++;
            break;

        default:
            fgoga[2]++;
            break;
        }
        k++;
    }
    string times = to_string(k);
    string silver = to_string(fgoga[2]);
    string golden = to_string(fgoga[1]);
    string rainbow = to_string(fgoga[0]);

    if (k < 329)
        return ("一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
            + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n");
    else
        return ("so sad你保底了\n\n一共抽了330抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
            + golden + "張金卡<:fgo_K2:1107145363795746977>\n1張彩卡<:fgo_K1:1107145268681519114>\n");
}

//自定義函式
string qre(string tkusing, string tk0, string tk1) {
    if (tkusing == tk0)
        return "但......チョコラ不知道主人在說什麼欸？";
    //return "現在登入的是チョコラ";
    else if (tkusing == tk1)
        return "再鬧\n我就叫M3捅爆你屁眼";
    //return "現在登入的是凱爾希";
    else
        return "哇程式竟然抓不到是哪一隻機器人登入\n可以趕快回報給開發者這個bug";
}
string mjnre(int size) {
    switch (size) {
    case 0:
        return "現在沒有人在等候";
        break;

    case 1: case 2:
        return "還缺 " + to_string(3-size) + " 人才能夠開局";
        break;

    case 3:
        return "現在有三人在等待開局、可以打三麻";
        break;

    case 4:
        return "現在有四人在等待開局、可以打四麻或修羅了";
        break;

    case 5: case 6:
        return "如果已經開局了，記得要清空序列喔？\n不然就趕緊開始遊戲吧？";
        break;

    default :
        return "奇怪的vector長度出現了，快叫我老木過來看";
    }
};
//只是看行數自爽用